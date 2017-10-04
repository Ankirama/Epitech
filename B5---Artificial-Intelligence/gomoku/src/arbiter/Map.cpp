//
// Created by Bubu on 23-Nov-15.
//

#include "Map.h"

//region Constructor functions
///////////////////////////
/* CONSTRUCTOR FUNCTIONS */
///////////////////////////

Map::Map() {
    this->m_error = 0;
}

Map::Map(std::map<int, int>map) {
    this->m_error = 0;
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it) {
        this->setCellMap(it->first, it->second);
    }
}

Map::~Map() {
}

//endregion

//region Public functions
///////////////////////
/* PUBLIC FUNCTIONS  */
///////////////////////

//region Getters / setters
//---------------------//
//  GETTERS / SETTERS  //
//---------------------//

void Map::setCellMap(int x, int y, int value) {
    if (x >= 0 && x < WIDTH_BOARD && y >= 0 && y < WIDTH_BOARD) {
        this->m_map[y * WIDTH_BOARD + x] = value;
    }
}

void Map::setCellMap(int pos, int value) {
    this->m_map[pos] = value;
}
void Map::setCellPlayer(int x, int y, int type) {
    this->setCellMap(x, y, type);
}

void Map::setCellOpponent(int x, int y) {
    this->setCellMap(x, y, OPPONENT(this->getCellMap(x, y)));
}

void Map::setCellCatchable(int x, int y, int orientation) {
    this->setCellMap(x, y, SET_CATCHABLE(this->getCellMap(x, y), orientation));
}

void Map::setCellChecked(int x, int y, int orientation) {
    this->setCellMap(x, y, CHECK_CASE(this->getCellMap(x, y), orientation));
}

void Map::setCellChecked(int pos, int orientation) {
    this->setCellMap(pos, CHECK_CASE(this->getCellMap(pos), orientation));
}

void Map::setCellResetChecked(int pos) {
    this->setCellMap(pos, RESET_CHECKED(this->getCellMap(pos)));
}

void Map::setCellResetChecked(int x, int y) {
    this->setCellMap(x, y, RESET_CHECKED(this->getCellMap(x, y)));
}

void Map::setCellTriple(int x, int y) {
    this->setCellMap(x, y, CHANGE_NEAR_TRIPLE_CASE(this->getCellMap(x, y)));
}

std::map<int, int> Map::getCellsType(int type) {
    std::map<int, int> cells;
    for (std::map<int, int>::iterator it = this->m_map.begin(); it != this->m_map.end(); ++it) {
        if (it->second == type) cells.insert(std::make_pair(it->first, it->second));
    }

    return cells;
}

int Map::getCellPlayer(int position) {
    int tmp = this->getCellMap(position);

    if (tmp == -1)
        return -1;
    else
        return GET_PLAYER(tmp);
}

int Map::getCellPlayer(int x, int y) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1)
        return -1;
    else
        return GET_PLAYER(tmp);
}

bool Map::isCellType(int x, int y, int type) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1) {
        return false;
    }
    else
        return GET_PLAYER(tmp) == type;
}

bool Map::isCellType(int pos, int type) {
    int tmp = this->getCellMap(pos);

    if (tmp == -1) {
        return false;
    }
    else
        return GET_PLAYER(tmp) == type;
}

std::map<int, int> Map::getCellsTypeInverse() {
    std::map<int, int> cells;

    for (std::map<int, int>::iterator it = this->m_map.begin(); it != this->m_map.end(); ++it) {
        if (this->isCellType(it->first, CASE_BLACK)
            || this->isCellType(it->first, CASE_WHITE))
            cells.insert(std::make_pair(it->first, it->second));
    }
    return this->addAroundAll(cells, 2);
}

std::map<int, int> Map::addAroundAll(std::map<int, int> &cells, int radius) {
    std::map<int, int> finale;

    for (std::map<int, int>::iterator it = cells.begin(); it != cells.end(); ++it) {
        for (int j = -radius; j <= radius; ++j) {
            for (int i = -radius; i <= radius; ++i) {
                int tmp;
                if ((tmp = this->getCellMap(it->first + j * WIDTH_BOARD + i)) != -1)
                    finale.insert(std::make_pair(it->first + (j * WIDTH_BOARD + i),
                                                 tmp));
            }
        }
    }
    return finale;
}

void Map::addAround(int pos, std::map<int, int> &finale, int radius) {
        for (int j = -radius; j <= radius; ++j) {
            for (int i = -radius; i <= radius; ++i) {
                int tmp;
                if ((tmp = this->getCellMap(pos + j * WIDTH_BOARD + i)) != -1)
                    finale.insert(std::make_pair(pos + (j * WIDTH_BOARD + i),
                                                 tmp));
            }
        }
}

bool Map::isCellCheckedDirection(int pos, int direction) {
    int tmp = this->getCellMap(pos);

    return tmp == -1 ? false : IS_CHECKED(tmp, direction);
}

bool Map::isCellCheckedDirection(int x, int y, int direction) {
    int tmp = this->getCellMap(x, y);

    return tmp == -1 ? false : IS_CHECKED(tmp, direction);
}

bool Map::isCellEmpty(int x, int y) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1)
        return false;
    else
        return tmp == 0;
}

bool Map::isCellCatchable(int x, int y) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1)
        return false;
    else
        return IS_CATCHABLE(tmp);
}

bool Map::isCellCatchableOrientation(int x, int y, int orientation) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1)
        return false;
    else
        return IS_CATCHABLE_ORIENTATION(tmp, orientation);
}

bool Map::isCellTriple(int x, int y) {
    int tmp = this->getCellMap(x, y);

    if (tmp == -1)
        return false;
    else
        return IS_NEAR_TRIPLE(tmp);
}

void Map::setMapError(int value) {
    this->m_error = value;
}

int Map::getCellMap(int x, int y)  const {
    if (x < 0 || x >= WIDTH_BOARD || y < 0 || y >= WIDTH_BOARD) return -1;
    if (this->m_map.find(y * WIDTH_BOARD + x) == this->m_map.end())
        return -1;
    return this->m_map.find(y * WIDTH_BOARD + x)->second;
}

int Map::getCellMap(int pos) const {
    if (this->m_map.find(pos) == this->m_map.end())
        return -1;
    return this->m_map.find(pos)->second;
}

bool Map::isInMap(int x, int y) const{
    return (x >= 0 && x < WIDTH_BOARD) && (y >= 0 && y < HEIGHT_BOARD);
}

bool Map::isInMap(int pos) const {
    return this->m_map.find(pos) != this->m_map.end();
}

std::map<int, int> Map::getMap() {
    return this->m_map;
}

int Map::getMapError() const {
    return this->m_error;
}

void Map::resetCatchableCase(int x, int y, int orientation) {
    this->setCellMap(x, y, UNSET_CATCHABLE(this->getCellMap(x, y), orientation));
}

std::map<t_point *, int> &Map::getCellsToUpdate() {
    return this->m_toUpdate;
};

void Map::addCellToUpdate(int x, int y, int value) {
    t_point *tmp = new t_point;

    tmp->x = x;
    tmp->y = y;
    this->m_toUpdate[tmp] = GET_PLAYER(value);
}

void Map::addCellToUpdate(t_point *pos, int value) {
    this->m_toUpdate[pos] = GET_PLAYER(value);
}

void Map::cleanMapUpdate() {
    for (std::map<t_point *, int>::iterator itr = this->m_toUpdate.begin(); itr != this->m_toUpdate.end(); ++itr)
        delete itr->first;
    m_toUpdate.clear();
}

//-------------------------//
//  END GETTERS / SETTERS  //
//-------------------------//
//endregion

void Map::displayMap() {
    for (int i = 0; i < WIDTH_BOARD * HEIGHT_BOARD; ++i) {
        //std::cout << this->getCellMap(i) << " ";
        if ((i + 1) % (WIDTH_BOARD) == 0)
            std::cout << std::endl;
    }
}

void Map::initMap() {
    this->cleanMapUpdate();
    for (int i = 0; i < WIDTH_BOARD * HEIGHT_BOARD; ++i) {
        this->setCellMap(i, 0);
    }
}
////////////////////////////
/*  END PUBLIC FUNCTIONS  */
////////////////////////////
//endregion

