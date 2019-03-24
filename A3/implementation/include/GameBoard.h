#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include <vector>
#include "CardTypes.h"
#include "CardStack.h"

#include <functional>
#include <utility>


class BoardT{
private:
    vector <CardStackT> T, F;
    CardStackT D, W;
    int cnt_cards(vector <CardStackT> t, vector <CardStackT> f, CardStackT d, CardStackT w, function<bool(CardT)> foo = [](CardT c){return true;});
    bool two_decks(vector <CardStackT> t, vector <CardStackT> f, CardStackT d, CardStackT w);
    int cnt_cards_seq(vector <CardStackT> s, function<bool(CardT)> foo);
    int cnt_cards_stack(CardStackT s, function<bool(CardT)> foo);
    vector <CardStackT> init_seq(int n);
    vector <CardStackT> tab_deck(vector <CardT> deck);
    bool is_valid_pos(CategoryT c, int n);
    bool valid_tab_tab(int x, int y);
    bool valid_tab_foundation(int x, int y);
    bool valid_waste_tab(int x);
    bool valid_waste_foundation(int x);
    bool tab_placeable(CardT c, CardT d);
    bool foundation_placeable(CardT c, CardT d);
public:
    BoardT(vector <CardT> v);
    bool is_valid_tab_mv(CategoryT c, int x, int y);
    bool is_valid_waste_mv(CategoryT c, int x);
    bool is_valid_deck_mv();
    void tab_mv(CategoryT c, int x, int y);
    void waste_mv(CategoryT c, int x);
    void deck_mv();
    CardStackT get_tab(int n);
    CardStackT get_foundation(int n);
    CardStackT get_deck();
    CardStackT get_waste();
    bool valid_mv_exists();
    bool is_win_state();
};

#endif
