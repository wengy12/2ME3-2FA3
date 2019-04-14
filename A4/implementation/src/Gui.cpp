#include "Gui.h"

using namespace std;

gui::gui(){
    board = Gameboard();
}

void gui::action(){
    print_help_massage();
    string input;
    while(true){
        getline(cin,input);
        if (input.substr(0, 6) == "start "){
            board.clear();
            board = Gameboard(input.substr(6, input.size()));
            clear();
            print_current_board();
        }
        else if (input == "u"){
            board.update();
            clear();
            print_current_board();
        }
        else if (input.substr(0, 2) == "o "){
            output_to_file(input.substr(2, input.size()));
        }
        else if (input == "q"){
            return;
        }
        else if (input == "HELP"){
            print_help_massage();
        }
        else{
            print_error_massage();
        }
    }
}

void gui::clear(){
    system("clear");
}

void gui::print_help_massage(){
    cout << "please type what you want and press enter:\n";
    cout << "\"u\" - update and refresh the showing board\n";
    cout << "\"o filename\" - output the current state to the file\n";
    cout << "\"start filename\" - restart the game with the initial configuration specified in file\n";
    cout << "\"q\" - quit without saving\n";
    cout << "\"HELP\" - print help massage\n";
    cout << "P.S. file should be in the root of implementation folder with the makefile\n";
}

void gui::print_current_board(){
    cout << "current game board\n";
    cout << board.get() << endl;
    cout << "what next?\n";
}

void gui::print_error_massage(){
    cout << "try again, you can do it! If you have any questions, you";
    cout << "can massage me wengyunbing@gmail.com\n";
}

void gui::output_to_file(string f){
    ofstream file;
    file.open(f);
    file << board.get();
    file.close();
    cout << "it is in the file, what next?\n";
}
