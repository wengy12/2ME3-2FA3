#include "GameBoard.h"
#include <vector>
#include <iostream>


using namespace std;

#define B BoardT
#define C CategoryT
#define CS CardStackT
#define forn for (int i = 0; i < n; i++)
#define for10 for (int i = 0; i < 10; i++)
#define for8 for (int i = 0; i < 8; i++)
#define fors for (int i = Heart; i <= Spade; i++)
#define forr for (RankT j = ACE; j <= KING; j++)

bool B::two_decks(vector <CS> t, vector <CS> f, CS d, CS w){
    fors{
        forr{
            int r = cnt_cards(t,f,w,d,
                [=](CardT c) {return c.r == j && c.s == i;});
            if (r != 2){
                //cerr << r << " " << i << " " << j << endl;
                return false;
            }
        }
    }
    return true;
}

int B::cnt_cards_seq(vector <CS> s, function<bool(CardT)> foo){
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        res += cnt_cards_stack(s[i], foo);
    }
    return res;
}

int B::cnt_cards_stack(CS s, function<bool(CardT)> foo){
    vector <CardT> v = s.toSeq();
    int res = 0;
    for (int i = 0; i < v.size(); i++){
        //cerr << foo(v[i]) << " " << v[i].s << " " <<  v[i].r << endl;
        if (foo(v[i])){
            res++;
        }
    }
    return res;
}

int B::cnt_cards(vector <CS> t, vector <CS> f, CS d, CS w,
                 function<bool(CardT)> foo){
    int res = cnt_cards_seq(t, foo) + cnt_cards_seq(f, foo) +
              cnt_cards_stack(w, foo) + cnt_cards_stack(d, foo);
    return res;
}

vector <CS> B::init_seq(int n){
    vector <CS> res;
    forn{
        res.push_back(CS());
    }
    return res;
}

vector <CS> B::tab_deck(vector <CardT> deck){
    int cnt = 0;
    vector <CS > res;
    for10{
        CS n;
        for (int j = 0; j < 4; j++){
            n.push(deck[cnt++]);
        }
        res.push_back(n);
    }
    return res;
}

bool B::is_valid_pos(C c, int n){
    if (c == Tableau && (n < 0 || n > 9)){
        return false;
    }
    if (c == Foundation && (n < 0 || n > 7)){
        return false;
    }
    return true;
}

bool B::valid_tab_tab(int x, int y){
    if (T[x].size() == 0){
        return false;
    }
    if (T[y].size() == 0){
        return true;
    }
    return tab_placeable(T[x].top(), T[y].top());
}

bool B::valid_tab_foundation(int x, int y){
    if (T[x].size() == 0){
        return false;
    }
    if (F[y].size() == 0){
        return T[x].top().r == ACE;
    }
    return foundation_placeable(T[x].top(), F[y].top());
}

bool B::valid_waste_tab(int x){
    if (W.size() == 0){
        return false;
    }
    if (T[x].size() == 0){
        return true;
    }
    return tab_placeable(W.top(), T[x].top());
}

bool B::valid_waste_foundation(int x){
    if (W.size() == 0){
        return false;
    }
    if (F[x].size() == 0){
        return W.top().r == ACE;
    }
    return foundation_placeable(W.top(), F[x].top());
}

bool B::tab_placeable(CardT c, CardT d){
    return c.s == d.s && c.r == d.r-1;
}

bool B::foundation_placeable(CardT c, CardT d){
    return c.s == d.s && c.r == d.r+1;
}

B::B(vector <CardT> v){
    if (!two_decks(init_seq(10),init_seq(8),CS(v),CS())){
        //cerr << v.size() << endl;
        throw invalid_argument("boardT init");
    }
    T = tab_deck(vector <CardT> (v.begin(), v.begin() + 40));
    F = init_seq(8);
    D = CS(vector <CardT> (v.begin()+40, v.end()));
    W = CS();
}

bool B::is_valid_tab_mv(C c, int x, int y){
    if (c == Tableau){
        if (!(is_valid_pos(c,x) && (is_valid_pos(c,y) ) ) ){
            throw out_of_range("is_valid_tab_mv to tab");
        }
        return valid_tab_tab(x, y);
    }
    if (c == Foundation){
        if (!(is_valid_pos(Tableau,x) && (is_valid_pos(c,y) ) ) ){
            throw out_of_range("is_valid_tab_mv found");
        }
        return valid_tab_foundation(x, y);
    }
    return false;
}

bool B::is_valid_waste_mv(C c, int x){
    if (W.size() == 0){
        throw invalid_argument("is_valid_waste_mv");
    }
    if (!(is_valid_pos(c,x))){
        throw out_of_range("is_valid_waste_mv");
    }
    if (c == Tableau){
        return valid_waste_tab(x);
    }
    if (c == Foundation){
        return valid_waste_foundation(x);
    }
    return false;
}

bool B::is_valid_deck_mv(){
    return D.size() > 0;
}

void B::tab_mv(C c, int x, int y){
    if (!is_valid_tab_mv(c,x,y)){
        throw invalid_argument("tab_mv");
    }
    if (c == Tableau){
        T[y] = T[y].push(T[x].top());
        T[x] = T[x].pop();
    }
    if (c == Foundation){
        F[y] = F[y].push(T[x].top());
        T[x] = T[x].pop();
    }
}

void B::waste_mv(C c, int x){
    if (!is_valid_waste_mv(c, x)){
        throw invalid_argument("waste_mv");
    }
    if (c == Tableau){
        T[x] = T[x].push(W.top());
        W = W.pop();
    }
    if (c == Foundation){
        F[x] = F[x].push(W.top());
        W = W.pop();
    }
}

void B::deck_mv(){
    if (!is_valid_deck_mv()){
        throw invalid_argument("deck_mv");
    }
    W = W.push(D.top());
    D = D.pop();
}

CS B::get_tab(int n){
    if (!(is_valid_pos(Tableau, n))){
        throw out_of_range("get_tab");
    }
    return T[n];
}

CS B::get_foundation(int n){
    if (!(is_valid_pos(Foundation, n))){
        throw out_of_range("get_foundation");
    }
    return F[n];
}

CS B::get_deck(){
    return D;
}

CS B::get_waste(){
    return W;
}

bool B::valid_mv_exists(){
    for10{
        for (int j = i+1; j < 10; j++){
            if (is_valid_tab_mv(Tableau, i, j)){
                return true;
            }
        }
        for (int j = 0; j < 8; j++){
            if (is_valid_tab_mv(Foundation, i, j)){
                return true;
            }
        }
    }
    for10{
        if (W.size() != 0 && is_valid_waste_mv(Tableau, i)){
            return true;
        }
    }
    for8{
        if (W.size() != 0 && is_valid_waste_mv(Foundation, i)){
            return true;
        }
    }
    if (is_valid_deck_mv()){
        return true;
    }
    return false;
}

bool B::is_win_state(){
    for8{
        if (F[i].size() == 0 || F[i].top().r != KING){
            return false;
        }
    }
    return true;
}
