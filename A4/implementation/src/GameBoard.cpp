#include "GameBoard.h"

using namespace std;

#define gb Gameboard

gb::gb(){

}

gb::gb (string f){
    ifstream file;
    cout << f << endl;
    file.open(f);
    if (!file){
        cerr << "sad" << endl;
    }
    string line;
    //cout << line << endl;
    while(getline(file, line) && line.size() != 0){
        cout << line << endl;
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
            if (nl.size() != board[board.size()-1].size()){
                throw invalid_argument("wrong number of elements");
            }
        }
        board.push_back(nl);
        nl.clear();
    }
}

string gb::get(){
    string res;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j]){
                res += '#';
            }
            else{
                res += '*';
            }
        }
        res += '\n';
    }
    return res;
}

int gb::size_c(){
    return board[0].size();
}

int gb::size_r(){
    return board.size();
}

void gb::update(){
    board = updated_buffer();
}

void gb::clear(){
    board.clear();
}

vector < vector <bool> > gb::updated_buffer(){
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

bool gb::update_cell(int i, int j){
    int n = neighbors_number(i,j);
    if (board[i][j] == true){
        if (n > 1 && n < 4){
            return true;
        }
        if (n < 2 || n > 3){
            return false;
        }
    }
    if (board[i][j] == false){
        if (n == 3){
            return true;
        }
        else{
            return false;
        }
    }
}

int gb::neighbors_number(int i, int j){
    int x[3] = {-1, 0, 1};
    int y[3] = {-1, 0, 1};
    int res = 0;
    for (int a = 0; a < 3; a++){
        for (int b = 0; b < 3; b++){
            if (a == 1 && b == 1){
                continue;
            }
            if (i + x[a] > board.size()-1 || i + x[a] < 0 ||
                j + y[b] > board[0].size()-1 || j + y[b] < 0){
                    continue;
                }
            res += board[i + x[a]][j + y[b]] ? 1 : 0;
        }
    }
    return res;
}
