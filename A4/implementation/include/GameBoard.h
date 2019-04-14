/**
 * \file Gameboard.h
 * \author wengy12
 * \brief GameBoard
 */

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include <vector>

/**
 * \brief Gameboard headler
 */

class Gameboard{
private:
    /**
     * \brief our Gameboard
     */
    vector <vector <bool> > board;
public:
    /**
     * \brief Gameboard constructor
     * \param f file name
     */
    Gameboard (string f);
    /**
     * \brief get the gameboard in printable string
     */
    string get();
    /**
     * \brief number of columns
     */
    int size_c();
    /**
     * \brief number of raws
     */
    int size_r();
    /**
     * \brief update the gameboard
     */
    void update();
    /**
     * \brief clear the GameBoard
     */
    void clear();
};

#endif
