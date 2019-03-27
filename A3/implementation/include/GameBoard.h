/**
 * \file GameBoard.h
 * \author wengy12
 * \brief Game Board
 */

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include <vector>
#include "CardTypes.h"
#include "CardStack.h"

#include <functional>
#include <utility>
#include <stdexcept>

/**
 * \brief BoardT headler
 */

class BoardT{
private:
    /**
     * \brief Tableau and Foundation
     */
    vector <CardStackT> T, F;
    /**
     * \brief Deck and Waste
     */
    CardStackT D, W;
    /**
     * \brief count the total number of cards with some restrictions
     * \eg epecific suit or specific card
     */
    int cnt_cards(vector <CardStackT> t, vector <CardStackT> f, CardStackT d, CardStackT w, function<bool(CardT)> foo = [](CardT c){return true;});
    /**
     * \brief check if there two decks exists on GameBoard
     */
    bool two_decks(vector <CardStackT> t, vector <CardStackT> f, CardStackT d, CardStackT w);
    /**
     * \brief count cards in sequance of cardStack with restrictions
     */
    int cnt_cards_seq(vector <CardStackT> s, function<bool(CardT)> foo);
    /**
     * \brief count cards in CardStack with some restrictions
     */
    int cnt_cards_stack(CardStackT s, function<bool(CardT)> foo);
    /**
     * \brief creation of sequence of n CardStacks
     */
    vector <CardStackT> init_seq(int n);
    /**
     * \brief trow the cards onto GameBoard
     */
    vector <CardStackT> tab_deck(vector <CardT> deck);
    /**
     * \brief check is the index exeed the existing foundations and tableaus
     */
    bool is_valid_pos(CategoryT c, int n);
    /**
     * \brief check can we move card from tab x to tab y
     */
    bool valid_tab_tab(int x, int y);
    /**
     * \brief check can we move card from tab x to foundation y
     */
    bool valid_tab_foundation(int x, int y);
    /**
     * \brief check can we move card from waste to tab y
     */
    bool valid_waste_tab(int x);
    /**
     * \brief check can we move card from waste to foundation y
     */
    bool valid_waste_foundation(int x);
    /**
     * \brief check can we put card a on card b on tableau
     */
    bool tab_placeable(CardT c, CardT d);
    /**
     * \brief check can we put card a on card b on foundation
     */
    bool foundation_placeable(CardT c, CardT d);
public:
    /**
     * \brief constructor for BoardT
     */
    BoardT(vector <CardT> v);
    /**
     * \brief check is the move of card from tab x to c y valid
     */
    bool is_valid_tab_mv(CategoryT c, int x, int y);
    /**
     * \brief check is the move of card from waste to c y valid
     */
    bool is_valid_waste_mv(CategoryT c, int x);
    /**
     * \brief check is the move of card from deck to waste valid
     */
    bool is_valid_deck_mv();
    /**
     * \brief move card from tab x to c y
     */
    void tab_mv(CategoryT c, int x, int y);
    /**
     * \brief move card from waste to c x
     */
    void waste_mv(CategoryT c, int x);
    /**
     * \brief move card from deck to waste
     */
    void deck_mv();
    /**
     * \brief get the sequance of cards on tab n
     */
    CardStackT get_tab(int n);
    /**
     * \brief get the sequance of cards on foundation n
     */
    CardStackT get_foundation(int n);
    /**
     * \brief get the sequance of cards on deck
     */
    CardStackT get_deck();
    /**
     * \brief get the sequance of cards on waste
     */
    CardStackT get_waste();
    /**
     * \brief check if there valid move exists
     */
    bool valid_mv_exists();
    /**
     * \brief check the winning status
     */
    bool is_win_state();
};

#endif
