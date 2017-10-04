//
// Created by ankirama on 5/12/15.
//

#include "GenerateMaze.hh"

static std::random_device   _rd;
static std::mt19937         _gen(_rd());

GenerateMaze    GenerateMaze::m_instance = GenerateMaze();

GenerateMaze::GenerateMaze() {
  this->m_width = 0;
  this->m_height = 0;
  this->m_maze = 0;
}

GenerateMaze::~GenerateMaze() {
    if (this->m_maze)
        delete this->m_maze;
}

void					GenerateMaze::init(int width, int height) {
  this->m_width = width + 2;
  this->m_height = height + 2;
  if (this->m_maze)
    delete this->m_maze;
  this->m_maze = new char[this->m_width * this->m_height];
  for (int i = 0; i < this->m_width; ++i) {
    for (int j = 0; j < this->m_height; ++j) {
      if (i == 0 || i == (this->m_width - 1) || j == 0 || j == (this->m_height - 1))
	  this->m_maze[j * this->m_width + i] = ID_WALL;
      else if (i % 2 == 0 && j % 2 == 0)
	this->m_maze[j * this->m_width + i] = ID_WALL;
      else
	this->m_maze[j * this->m_width + i] = ID_BLOCK;
    }
  }
}

void					GenerateMaze::initRandom(int width, int height) {
  this->m_width = width;
  this->m_height = height;
  if (this->m_maze)
    delete this->m_maze;
  this->m_maze = new char[this->m_width * this->m_height];
  for (int i = 0; i < this->m_width * this->m_height; ++i) {
    if (i % this->m_width == 0 || i < this->m_width ||
	(i % this->m_width == this->m_width - 1) || i > (this->m_height * this->m_width - this->m_width))
      this->m_maze[i] = ID_WALL;
    else if (this->randomDirection() % 2 == 0) {
      this->m_maze[i] = ID_WALL;
    }
    else {
      this->m_maze[i] = ID_BLOCK;
    }
  }
}

bool					GenerateMaze::setWall(int x, int y, int xModifier, int yModifier) {
  if (x + xModifier < 0 || y + yModifier < 0 ||
    x + xModifier >= this->m_width ||
    y + yModifier >= this->m_height ||
    this->m_maze[(y + yModifier) * this->m_width + x + xModifier] == ID_EMPTY)
    return true;
  else {
    this->m_maze[(y + yModifier) * this->m_width + x + xModifier] = ID_EMPTY;
    return false;
  }
}

void                    GenerateMaze::create(int width, int height) {
  this->init(width, height);
}

void					GenerateMaze::createRandom(int width, int height) {
  std::list <std::pair <int, int> >	openWalls;
  bool					isRemoveWall;

  this->initRandom(width, height);
  openWalls.push_back(std::make_pair(this->m_width / 2, this->m_height / 2));
  while (!openWalls.empty()) {
    std::list <std::pair <int, int> >::iterator tmp;
    tmp = openWalls.begin();
    while (tmp != openWalls.end()) {
      isRemoveWall = false;
      switch (this->randomDirection()) {
      case 0:
	    isRemoveWall = this->setWall(tmp->first, tmp->second -= 2, 0, 1);
        break;
      case 1:
	    isRemoveWall = this->setWall(tmp->first, tmp->second += 2, 0, -1);
	    break;
      case 2:
	    isRemoveWall = this->setWall(tmp->first -= 2, tmp->second, 1, 0);
	    break;
      case 3:
	    isRemoveWall = this->setWall(tmp->first += 2, tmp->second, -1, 0);
	    break;
      }
      if (isRemoveWall)
	    tmp = openWalls.erase(tmp);
      else {
	    openWalls.push_back(std::make_pair(tmp->first, tmp->second));
        if (this->randomDirection() % 2 == 0)
	      openWalls.push_back(std::make_pair(tmp->first, tmp->second));
        this->m_emptyCell.push_back(std::make_pair(tmp->first, tmp->second));
        this->m_maze[tmp->second * this->m_width + tmp->first] = ID_EMPTY;
	    ++tmp;
      }
    }
  }
}

std::vector <std::pair <int, int> >& GenerateMaze::getEmptyCells() {
  return this->m_emptyCell;
}

void GenerateMaze::setCell(int x, int y, int id_cell) {
  if (this->m_maze[y * this->m_width + x] == ID_EMPTY) {
    std::pair<int, int> tmp = std::make_pair(x, y);
    unsigned int i = 0;
    while (i < this->m_emptyCell.size() &&
            !(this->m_emptyCell[i].first == tmp.first &&
                    this->m_emptyCell[i].second == tmp.second))
      ++i;
    if (i < this->m_emptyCell.size())
      this->m_emptyCell.erase(this->m_emptyCell.begin() + i);
  }
  this->m_maze[y * this->m_width + x] = id_cell;
  if (id_cell == ID_EMPTY)
    this->m_emptyCell.push_back(std::make_pair(x, y));
}

int GenerateMaze::getCell(int x, int y) {
  return this->m_maze[y * this->m_width + x];
}

char           *GenerateMaze::getMap() const {
    return this->m_maze;
}

int                     GenerateMaze::randomDirection() const {
    static std::uniform_int_distribution<> disCell(0, 3);
    return static_cast<int>(disCell(_gen));
}

GenerateMaze&   GenerateMaze::getInstance() {
    return m_instance;
}
