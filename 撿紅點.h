#include <iostream>
using namespace std;
class game {
    friend ostream& operator<<(ostream& out, const game& g);
private:
    int card [13][4];
    int p1_n[13],p1_s[13];
    int p2_n[13],p2_s[13];
    int p3_n[13],p3_s[13];
    int user_n[13],user_s[13];
    int card_deck_n[24],card_deck_s[24];
    int seabed_n[13],seabed_s[13];
    int p1_point,p2_point,p3_point,user_point;
public:
    void setvalue();
    void shuffle();
    void dealcard();
    void player1_move();
    void player2_move();
    void player3_move();
    void user_choose();
    int check(int *);
    int check_end();
    void print_card(int *,int *);
    void print_cover_card(int *,int *);
    void findwiner();
    void printtest();
};
