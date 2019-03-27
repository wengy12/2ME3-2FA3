#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

#include "CardStack.h"
#include "CardTypes.h"
#include "GameBoard.h"
#include "Stack.h"

#define GameBoard BoardT

int main(){
    std::vector<CardT> d;
    for (RankT rank = ACE; rank <= KING; rank++) {
      for (unsigned int suit = 0; suit < 4; suit++) {
        CardT n(static_cast<SuitT>(suit), rank);
        d.push_back(n);
        d.push_back(n);
        cout << n.s << " " << n.r << endl;
      }
    }
}
