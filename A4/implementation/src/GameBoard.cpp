#include "GameBoard.h"

using namespace std;

#define gb Gameboard

gb::gb (string f){
    ifstream file;
    file.open(f);
    stirng line;
    while(getline(file, line) && line.size() != 0){
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
        nl.clear();
    }
}

string bg::get(){
    string res;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j]){
                res += '#';
            }
            else{
                res += '*'
            }
        }
        res += '\n';
    }
    return res;
}

int bg::size_c(){
    return board[0].size();
}

int bg::size_r(){
    return board.size();
}

void bg::update(){
    board = updated_buffer();
}

void bg::clear(){
    board.clear();
}

vector < vector <bool> > bg::updated_buffer(){
    vector < vector <bool> > res;
    for (int i = 0 ; i < board.size(); i++){
        vector <bool> nl;
        for (int j = 0; j < board[i].size(); j++){
            nl.push_back(update_cell(i,j));
        }
        res.push_back(nl);
        nl.clear();
    }
    return res;
}

bool update_cell(int i, int j){
    if (board[i][j] == true){
        if()
    }
}
