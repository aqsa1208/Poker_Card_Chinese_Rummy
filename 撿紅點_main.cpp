#include "¾ß¬õÂI.h"
#include <iostream>
using namespace std;
int main(){
    game g;
    g.setvalue();
    g.shuffle();
    g.dealcard();
    while(1){
        g.player1_move();
        if(g.check_end()!=0){
            g.player2_move();
            if(g.check_end()!=0){
                g.player3_move();
                if(g.check_end()!=0){
                    g.user_choose();

                }
                else{
                    cout<<g;
                    g.findwiner();
                    break;
                }
            }
            else{
                cout<<g;
                g.findwiner();
                break;
            }
        }
        else{
            cout<<g;
            g.findwiner();
            break;
        }
    }
}
