#include "catch.h"

#include "CardStack.h"
#include "CardTypes.h"
#include "GameBoard.h"
#include "Stack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define GameBoard BoardT

TEST_CASE( "random_test, plays the game for you" , "[BoardT]" ) {
    std::vector<CardT> d;
    for (RankT rank = ACE; rank <= KING; rank++) {
      for (unsigned int suit = 0; suit < 4; suit++) {
        CardT n(static_cast<SuitT>(suit), rank);
        d.push_back(n);
        d.push_back(n);
      }
    }
    srand(time(0));
    random_shuffle(d.begin(), d.end());
    for (int i = 0; i < 20; i++){
        cout << d[i].s << " " << d[i].r << endl;
    }
    GameBoard board(d);
    SECTION("best AI"){
        string last_mv = "0000";
        int TT_count = 0;
        bool sad = false;
        while (!board.is_win_state() && board.valid_mv_exists() && !sad){
            sad = true;
            for (int j = 0; j < 10; j++){
                for (int i = 0; i < 8; i++){
                    if (board.get_waste().size() != 0 && board.is_valid_waste_mv(Foundation, i)){
                        cerr << "W F " << i << " " << board.get_waste().top().s << " " << board.get_waste().top().r << endl;
                        board.waste_mv(Foundation, i);
                        sad = false;
                        last_mv = "WF"+to_string(i);
                        TT_count = 0;
                    }
                    if (board.is_valid_tab_mv(Foundation, j, i)){
                        board.tab_mv(Foundation, j, i);
                        cerr << "T " << j << " F " << i << " " << board.get_foundation(i).top().s << " " << board.get_foundation(i).top().r << endl;;;
                        sad = false;
                        last_mv = "T"+to_string(j)+"F"+to_string(i);
                        TT_count = 0;
                    }
                }
                for (int i = 0; i < 10; i++){
                    if (i == j) continue;
                    if (board.get_waste().size() != 0 && board.is_valid_waste_mv(Tableau, i)){
                        cerr << "W T " << i << " " << board.get_waste().top().s << " " << board.get_waste().top().r << endl;
                        board.waste_mv(Tableau, i);
                        sad = false;
                        last_mv = "WT"+to_string(i);
                        TT_count = 0;
                    }
                    if (TT_count != 100 && last_mv != "T"+to_string(j)+"T"+to_string(i) && board.is_valid_tab_mv(Tableau, i, j) && board.get_tab(j).size() != 0){
                        board.tab_mv(Tableau, i, j);
                        cerr << "T " << i << " T " << j << " " << board.get_tab(j).top().s << " " <<  board.get_tab(j).top().r << endl;
                        sad = false;
                        last_mv = "T"+to_string(i)+"T"+to_string(j);
                        TT_count++;
                    }
                }
            }
            if (sad && board.is_valid_deck_mv()){
                board.deck_mv();
                sad = false;
                TT_count = 0;
                cerr << "D " << board.get_waste().top().s << " " << board.get_waste().top().r << endl;
            }
        }
        if (board.is_win_state()){
            cout << "yeeeeeeeeey!";
        }
        else{
            for (int i = 0; i < 8; i++){
                if (board.get_foundation(i).size() == 0){
                    cout << -1 << " " << -1 << endl;
                    continue;
                }
                cout << board.get_foundation(i).top().s << " " << board.get_foundation(i).top().r << endl;
            }
        }
    }
}
