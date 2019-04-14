/**
 * \file Gui.h
 * \author wengy12
 * \brief the GUI
 */

#ifndef A4_GUI_H_
#define A4_GUI_H_

#include <vector>

#include "GameBoard.h"

/**
 * \brief GUI headler
 */

class gui{
private:
    Gameboard board;
    void clear();
    void print_help_massage();
    void print_current_board();
    void output_to_file(string f);
    void print_error_massage();
public:
    /**
     * \brief just run it and enjoy :)
     */
    void action();
};

#endif
