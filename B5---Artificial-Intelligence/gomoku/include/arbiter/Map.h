//
// Created by Bubu on 23-Nov-15.
//

/**
 * @file: Map.h
 * @brief: Map file with the map and functions.
 * @author: bubu
 */

#ifndef GOMOKU_MAP_H
#define GOMOKU_MAP_H

#include <iostream>
#include <map>

# define WIDTH_BOARD 19
# define HEIGHT_BOARD 19

# define CASE_EMPTY         0x00 // 0000 (bin)
# define CASE_WHITE         0x01 // 0001 (bin)
# define CASE_BLACK         0x02 // 0010 (bin)

# define GET_PLAYER(CASE)             (CASE & 0x03)

# define IS_EMPTY_CASE(CASE)          ((CASE & 0x0B) == 0x00)

# define SET_TYPE_CASE(CASE, TYPE)    (CASE & 0x0B | TYPE)

/**
 * @def OPPONENT(CASE)
 * ~ -> reverse 1 -> 0 / 0 -> 1
 * & -> mask to keep only last 2 bits
 * 0x03 = 0011 in binary
 * with CASE & 0x04 we can keep our others variables
 *
 * example: CASE : 0110
 * (~0110 & 0011) | (0110 & 1100)
 * (1001 & 0011) | 1100
 * 0001 | 1100
 * 0101 -> we kept our others variables value and we changed our player
 */
# define OPPONENT(CASE)               (((~CASE) & 0x03) | (CASE & 0x0C))

/**
 * @def CHANGE_NEAR_TRIPLE_CASE(CASE)
 * Macro to set at 1 or 0 the bit CASE_NEAR_TRIPLE (0x04 - 0100)
 * It will switch our CASE_NEAR_TRIPLE value and keep our current player
 *
 * example: CASE: 0010
 * (~0010 & 0100) | (0010 & 0011)
 * (1101 & 0100) | 0010
 * 0100 | 0010
 * 0110 -> we kept our player but changed our CASE_NEAR_TRIPLE value
 */
# define CHANGE_NEAR_TRIPLE_CASE(CASE)  (((~CASE) & 0x04) | (CASE & 0x0A))

/**
 * @def IS_NEAR_TRIPLE
 * right shift to keep only value on CASE_IS_CATCHABLE
 */
# define IS_NEAR_TRIPLE(CASE)           ((CASE >> 2 & 0x01) == 0x01)

/**
 * @def CHANGE_CATCHABLE(CASE, ORIENTATION)
 * Example need to be updated since we have orientation
 * Macro to set at 1 or 0 the bit CASE_IS_CATCHABLE (0x08 or 0000)
 * It will switch our CASE_IS_CATCHABLE value and keep our current player and others informations
 *
 * example: CASE: 0010
 * (~0010 & 1000) | (0010 & 0111)
 * (1101 & 1000) | 0010
 * 1000 | 0010
 * 1010 -> we kept our player but changed our CASE_IS_CATCHABLE value
 */
# define CHANGE_CATCHABLE(CASE, ORIENTATION)        (CASE ^ (0x10 << ORIENTATION))

# define SET_CATCHABLE(CASE, ORIENTATION)           (CASE | (0x10 << ORIENTATION))

# define UNSET_CATCHABLE(CASE, ORIENTATION)         (CASE ^ ((0 ^ CASE) & (1 << (ORIENTATION + 4))))

/**
 * @def IS_CATCHABLE
 * right shift to keep only value on IS_CATCHABLE
 */
# define IS_CATCHABLE(CASE)                             (CASE & 0xF0);

# define IS_CATCHABLE_ORIENTATION(CASE, ORIENTATION)    ((CASE >> (4 + ORIENTATION)) & 0x01)

# define IS_CHECKED(CASE, DIRECTION)                    ((CASE >> (8 + DIRECTION)) & 0x01)

# define RESET_CHECKED(CASE)                            (CASE & 0xFF)

# define CHECK_CASE(CASE, DIRECTION)                    (CASE ^ (0x100 << DIRECTION))

// =============== //
// ERRORS MESSAGES //
// =============== //

# define ERR_NO_ERROR     0x00
# define ERR_UNKNOWN      0x01
# define ERR_SET_CELL_MAP 0x02
# define ERR_GET_CELL_MAP 0x03

typedef struct {
    int x;
    int y;
} t_point;

class Map {
public:
    /**
     * @brief: Basic constructor
     */
    Map();

    Map(std::map<int, int>map);
    /**
     * @brief: Basic destructor
     */
    ~Map();

    /**
     * @brief: travel the map and set every value to 0
     */
    void initMap();

    /**
     * @brief: displays the map
     */

    void displayMap();


    /**
      * @brief: set a cell
      * Does not check if cell is a valid one, you must do it before
      *
      * @param x: x position
      * @param y: y position
      * @param value: must be CASE_EMPTY, CASE_PLAYER_1 or CASE_PLAYER_2
      */
    void setCellMap(int x, int y, int value);

    /**
     * @brief: set a cell
     * Does not check if cell is a valid one, you must do it before
     *
     * @param x: x position
     * @param y: y position
     * @param value: must be CASE_EMPTY, CASE_PLAYER_1 or CASE_PLAYER_2
     */
    void setCellMap(int pos, int value);

    /**
     * @brief: set a cell to player
     * Does not check if cell is a valid one, you must do it before
     *
     * @param x: x position
     * @param y: y position
     * @param type: type
     */
    void setCellPlayer(int x, int y, int type);

    /**
     * @brief: set a cell to opponent
     * Does not check if cell is a valid one, you must do it before
     *
     * @param x: x position
     * @param y: y position
     */
    void setCellOpponent(int x, int y);

    /**
     * @brief: set a cell to catchable
     * Does not check if cell is a valid one, you must do it before
     *
     * @param x: x position
     * @param y: y position
     * @param orientation: define orientation must be between 0 - 3
     */
    void setCellCatchable(int x, int y, int orientation);

    void setCellChecked(int x, int y, int orientation);

    void setCellChecked(int pos, int orientation);

    void setCellResetChecked(int pos);

    void setCellResetChecked(int x, int y);

    /**
     * @brief: set a cell to triple
     * Does not check if cell is a valid one, you must do it before
     *
     * @param x: x position
     * @param y: y position
     */
    void setCellTriple(int x, int y);

    /**
     * @brief: get cell player
     * Does not check if cell is a valid one, you must do it before
     *
     * @param position: position
     * @return: the cell or -1 in case of error
     */
    int getCellPlayer(int position);

    std::map<int, int> getCellsType(int type);

    std::map<int, int> getCellsTypeInverse();

    std::map<int, int> addAroundAll(std::map<int, int> &cells, int radius);

    void addAround(int pos, std::map<int, int> &cells, int radius);

    /**
     * @brief: get cell player
     *
     * @param x: x position
     * @param y: y position
     * @return: the cell or -1 in case of error
     */
    int getCellPlayer(int x, int y);

    /**
     * @brief: check if cell is given type
     *
     * @param x: x position
     * @param y: y position
     * @param type: type
     * @return: true/false
     */
    bool isCellType(int x, int y, int type);

    bool isCellType(int pos, int type);

    bool isCellCheckedDirection(int x, int y, int direction);

    bool isCellCheckedDirection(int pos, int direction);

    /**
     * @brief: check if cell is empty
     *
     * @param x: x position
     * @param y: y position
     * @return: true/false
     */
    bool isCellEmpty(int x, int y);

    /**
     * @brief: check if cell is catchable
     *
     * @param x: x position
     * @param y: y position
     * @return: true/false
     */
    bool isCellCatchable(int x, int y);

    bool isCellCatchableOrientation(int x, int y, int orientation);

    /**
     * @brief: check is cell is triple
     *
     * @param x: x position
     * @param y: y position
     * @return: true/false
     */
    bool isCellTriple(int x, int y);

    /**
     * #brief: set map error
     *
     * @param
     */
    void setMapError(int value);

    /**
     * @brief: get a cell
     * Does not check anything, be careful
     *
     * @param x: x position
     * @param y: y position
     * @return: the cell
     */
    int getCellMap(int x, int y) const;

    /**
     * @brief: get a cell
     * Does not check anything, be careful
     *
     * @param pos: cell position
     * @return: the cell
     */
    int getCellMap(int pos) const;

    /**
     * @brief: check if elem is in given coordinate
     *
     * @return true/false
    */
    bool isInMap(int x, int y) const;

    /**
     * @brief: check if elem is in given position
     *
     * @return true/false
    */
    bool isInMap(int pos) const;

    /**
     * @brief: get the game board
     * Does not check anything, be careful
     *
     * @return: the game board
    */
    std::map<int, int> getMap();

    /**
     * @brief: return map error
     *
     * @return: the map error
    */
    int getMapError() const;

    /**
     * @brief: set to 0 catchable bit
     *
     * @param x: x position
     * @param y: y position
     * @param orientation: orientation catchable (0 - 3)
     */
    void resetCatchableCase(int x, int y, int orientation);

    /**
     * @brief: return cell to update
     *
     * @return: cell to update
     */
    std::map<t_point *, int> &getCellsToUpdate();

    /**
     * @brief: add cell to update
     *
     * @param x: x position
     * @param y: y position
     * @param value: value to set
     */
    void addCellToUpdate(int x, int y, int value);

    /**
     * @brief: add cell to update
     *
     * @param pos: coordinates to cel
     * @param value: value to set
     */
    void addCellToUpdate(t_point *pos, int value);

    /**
     * @brief: clean map to update
     */
    void cleanMapUpdate();


private:
    int m_error; /**< a variable to check any error */
    std::map<int, int> m_map; /**< our map with stones */
    std::map<t_point *, int> m_toUpdate; /**< element to update */
};

#endif //GOMOKU_MAP_H