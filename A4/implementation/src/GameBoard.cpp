#include "GameBoard.h"

using namespace std;

#define gb Gameboard

gb::gb (string f){
    ifstream file;
    file.open(f);
    stirng line;
    while(getline(file, line)){
        vector <bool> nl;
        for (int i = 0; i < line.size(); i++){
            if (line[i] == '*'){
                nl.push_back(false);
            }
            else if (line[i] == '#'){
                nl.push_back(true);
            }
            else{
                throw invalid_argument("wrong symbol"+line[i]);
            }
        }
        if (board.size() != 0){
            if (nl.size() != board[board.size()-1].sise()){
                throw invalid_argument("wrong number of elements");
            }
        }
        board.push_back(nl);
    }
}
