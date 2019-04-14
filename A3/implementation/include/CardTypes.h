/**
 * \file CardTypes.h
 * \author wengy12
 * \brief Card types
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Suits
 */
enum SuitT {Heart, Diamond, Club, Spade};

/**
 * \brief gameboard sections
 */
enum CategoryT {Tableau, Foundation, Desk, Waste};

/**
 * \brief the card
 */

struct CardT{
    SuitT s;
    RankT r;
    CardT(SuitT s0, RankT r0){
        s = s0;
        r = r0;
    }

};

#endif
