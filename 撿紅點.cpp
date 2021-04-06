#include "撿紅點.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void game::setvalue(){
    int i,j;
    for(i=0;i<13;i++){
        for(j=0;j<4;j++){
            card[i][j] = {0};
        }
    }
    for(i=0;i<13;i++){
        p1_n[i] = p1_s[i] = {0};
        p2_n[i] = p2_s[i]= {0};
        p3_n[i] = p3_s[i] = {0};
        user_n[i] = user_s[i] = {0};
        seabed_s[i]=seabed_n[i]={0};
    }
    p1_point=p2_point=p3_point=user_point=0;
}

void game::shuffle(){
    int i,n,s;
    srand(time(NULL));
    for(i=1;i<=52;i++){
        n = rand()%13;
        s = rand()%4;
        if(card[n][s]==0){
            card[n][s] = i;
        }
        else
            i--;
    }
}

void game::dealcard(){
    int i,j,k;
    for(i=1;i<=6;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p1_n[i-1] = j+1;
                    p1_s[i-1] = k+1;
                }
            }
        }
    }
    for(i=7;i<=12;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p2_n[i-7] = j+1;
                    p2_s[i-7] = k+1;
                }
            }
        }
    }
    for(i=13;i<=18;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    p3_n[i-13] = j+1;
                    p3_s[i-13] = k+1;
                }
            }
        }
    }
    for(i=19;i<=24;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    user_n[i-19] = j+1;
                    user_s[i-19] = k+1;
                }
            }
        }
    }
    for(i=25;i<=28;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    seabed_n[i-25] = j+1;
                    seabed_s[i-25] = k+1;
                }
            }
        }
    }
    for(i=29;i<=52;i++){
        for(j=0;j<13;j++){
            for(k=0;k<4;k++){
                if(card[j][k]==i){
                    card_deck_n[i-29] = j+1;
                    card_deck_s[i-29] = k+1;
                }
            }
        }
    }

}

void game::print_card(int *p_n,int *p_s){
    int i,j,k,r;
    for(r=1;r<=11;r++){
            switch(r){
            case 1:
                for(j=1;j<=13;j++){
                    if(p_n[j-1]&&p_s[j-1]!=0){
                        if(j<10)
                            cout<<j<<". ";
                        else if(j>=10)
                            cout<<j<<".";
                        cout<<"──────────"<<"   ";
                    }
                    else
                        cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 2:
                for(j=0;j<13;j++){
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"   ";
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"▏";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"▕";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ▕";
                        cout<<"  ";
                    }
                }
                else
                    cout<<"   "<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 3:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        cout<<"▏        ▕"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 4:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                        if(p_s[j]==2){
                            cout<<"▏ *   *  ▕"<<"  ";
                        }
                        else {
                            cout<<"▏   *    ▕"<<"  ";
                        }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 5:
                for(j=0;j<13;j++){
                    cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                    else if(p_s[j]==2){
                        cout<<"▏*  *  * ▕"<<"  ";
                    }
                    else if(p_s[j]==3){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"▏* * * * ▕"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 6:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==2||p_s[j]==3){
                        cout<<"▏ *   *  ▕"<<"  ";
                    }
                    else if(p_s[j]==4){
                        cout<<"▏ * * *  ▕"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 7:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"▏   *    ▕"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"▏  * *   ▕"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 8:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_s[j]==1||p_s[j]==4){
                        cout<<"▏  ***   ▕"<<"  ";
                    }
                    else if(p_s[j]==2||p_s[j]==3){
                        cout<<"▏   *    ▕"<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout <<endl;
                break;
            case 9:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"▏        ▕"<<"  ";
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout<<endl;
                break;
            case 10:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    if(p_n[j]>=2&&p_n[j]<10){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                           cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 10){
                        cout<<"▏";
                        for(i=0;i<2;i++){
                            cout<<p_n[j]<<" ";
                        }
                        cout<<p_n[j]<<"▕";
                        cout << "  ";
                    }
                    else if(p_n[j] == 1){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"A ";
                        }
                        cout<<"A"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 11){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"J ";
                        }
                        cout<<"J"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 12){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"Q ";
                        }
                        cout<<"Q"<<" ▕";
                        cout<<"  ";
                    }
                    else if(p_n[j] == 13){
                        cout<<"▏";
                        for(i=0;i<3;i++){
                            cout<<"K ";
                        }
                        cout<<"K"<<" ▕";
                        cout<<"  ";
                    }
                    }
                    else
                        cout<<"           "<<"   ";
                }
                cout << endl;
                break;
            case 11:
                for(j=0;j<13;j++){
                        cout<<"   ";
                    if(p_n[j]&&p_s[j]!=0){
                    cout<<"──────────"<<"   ";
                    }
                    else
                        cout<<"            "<<"   ";
                }
                cout << endl;
                break;
            }
        }
        cout<<endl;
}

int game::check(int *p_n){
    int i,j,flag;
    flag = 0;
    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            if(seabed_n[j]!=0 && p_n[i]!=0){
                if(p_n[i]<10){
                    if(p_n[i]+seabed_n[j]==10){
                        flag = 1;
                    }
                }
                else if(p_n[i]>=10){
                    if(p_n[i]==seabed_n[j]){
                        flag = 1;
                    }
                }
            }
        }
    }
    return flag;
}

int game::check_end(){
    if(card_deck_n[23]==0){
        return 0;
    }
}

ostream& operator<<(ostream& out, const game& g){
    out<<endl;
    out<<"GAME OVER!!!!"<<endl;
    out<<"Player1's points is:"<<g.p1_point<<endl;
    out<<"Player2's points is:"<<g.p2_point<<endl;
    out<<"Player3's points is:"<<g.p3_point<<endl;
    out<<"Your points is:"<<g.user_point<<endl;
    out<<endl;
    return out;
}

void game::findwiner(){

    if(p1_point>p2_point&&p1_point>p3_point&&p1_point>user_point){
        cout<<"Winer is Player1! You are lose~"<<endl;
        cout<<endl;
    }
    if(p2_point>p1_point&&p2_point>p3_point&&p2_point>user_point){
        cout<<"Winer is Player2! You are lose~"<<endl;
        cout<<endl;
    }
    if(p3_point>p1_point&&p3_point>p2_point&&p3_point>user_point){
        cout<<"Winer is Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(user_point>p1_point&&user_point>p2_point&&user_point>p3_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1_point==p2_point&&p1_point>p3_point&&p1_point>user_point){
        cout<<"Winer is Player1 and Player2! You are lose~"<<endl;
        cout<<endl;
    }
    if(p1_point==p3_point&&p1_point>p2_point&&p1_point>user_point){
        cout<<"Winer is Player1 and Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(p1_point==user_point&&p1_point>p3_point&&p1_point>p2_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p2_point==p3_point&&p2_point>p1_point&&p2_point>user_point){
        cout<<"Winer is Player2 and Player3! You are lose~"<<endl;
        cout<<endl;
    }
    if(p2_point==user_point&&p2_point>p3_point&&p2_point>p1_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p3_point==user_point&&p3_point>p1_point&&p3_point>p2_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1_point==p2_point&&p2_point==p3_point&&p1_point>user_point){
        cout<<"You are lose~"<<endl;
        cout<<endl;
    }
    if(user_point==p2_point&&user_point==p3_point&&user_point>p1_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p1_point==user_point&&p1_point==p3_point&&user_point>p2_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }
    if(p1_point==p2_point&&p1_point==user_point && user_point>p3_point){
        cout<<"You are win!"<<endl;
        cout<<endl;
    }

    if(p1_point==p2_point&&p2_point==p3_point&&p3_point==user_point){
        cout<<"No one is winer~~~"<<endl;
        cout<<endl;
    }
}

void game::user_choose(){
    int a,b,c,i,j;
    cout<<"海底牌為："<<endl;
    print_card(seabed_n,seabed_s);
    cout<<"你的牌為："<<endl;
    print_card(user_n,user_s);
    if(check(user_n)==0){
        cout<<"目前無法收回牌，請選擇要把哪張當海底牌？";
        cin>>c;
        c=c-1;
        for(i=0;i<13;i++){
            if(seabed_n[i]==0){
                break;
            }
        }
        for(j=0;j<24;j++){
            if(card_deck_n[j]!=0){
                break;
            }
        }
        if(j!=24){
            seabed_n[i] = user_n[c];
            seabed_s[i] = user_s[c];
            user_n[c] = card_deck_n[j];
            user_s[c] = card_deck_s[j];
            card_deck_n[j] = card_deck_s[j] = 0;
        }
        else{
            seabed_n[i] = user_n[c];
            seabed_s[i] = user_s[c];
            user_n[c] = 0;
            user_s[c] = 0;
        }

    }
    else{
        cout<<"請選擇要用自己的哪張牌收回牌面上哪張牌？(請輸入兩個數字)：";
        cin >>a>>b;
        a=a-1;
        b=b-1;
        if(user_n[a]==0||a>6||a<0||seabed_n[b]==0||b<0||b>13){
            cout<<"請輸入正確的數字"<<endl;
            user_choose();
        }
        if(user_n[a]<10){
            if(user_n[a]+seabed_n[b]!=10){
                cout<<"你不能收回這張牌，請重新選擇"<<endl;
                user_choose();
            }
            else if(user_n[a]!=9&&seabed_n[b]!=9&&user_n[a]!=1&&seabed_n[b]!=9){
                if(user_s[a]==2||user_s[a]==3){
                    user_point += user_n[a];
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    user_point += seabed_n[b];
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = user_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    user_n[a] = user_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = card_deck_n[i+1];
                    user_s[a] = card_deck_s[i+1];
                    card_deck_n[i] = card_deck_s[i] = card_deck_n[i+1] = card_deck_n[i]=0;
                }
           }
           else{
                if(user_n[a]==1){
                    if(user_s[a]==1){
                        user_point += 10;
                    }
                    else if(user_s[a]==2||user_s[a]==3){
                        user_point +=20;
                    }
                    if(seabed_s[b]==2||seabed_s[b]==3){
                        user_point += 10;
                    }
                }
                else if(seabed_n[b]==1){
                    if(seabed_s[b]==1){
                        user_point += 10;
                    }
                    else if(seabed_s[b]==2||seabed_s[b]==3){
                        user_point +=20;
                    }
                    if(user_s[a]==2||user_s[a]==3){
                        user_point += 10;
                    }
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = user_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    user_n[a] = user_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = card_deck_n[i+1];
                    user_s[a] = card_deck_s[i+1];
                    card_deck_n[i] = card_deck_s[i] = card_deck_n[i+1] = card_deck_n[i]=0;
                }
           }
        }
        else if(user_n[a]>=10){
            if(user_n[a]!=seabed_n[b]){
                cout<<"你不能收回這張牌，請重新選擇"<<endl;
                user_choose();
            }
            else{
                if(user_s[a]==2||user_s[a]==3){
                    user_point += 10;
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p1_point += 10;
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = user_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    user_n[a] = user_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    user_n[a] = card_deck_n[i+1];
                    user_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i+1]=0;
                }
            }
        }
        if(seabed_n[0]==0){
            findwiner();
        }
    }

}

void game::player1_move(){
    int a,b,c,i,j;
    if(check(p1_n)==0){
        c = rand()%6;
        for(i=0;i<13;i++){
            if(seabed_n[i]==0){
                break;
            }
        }
        for(j=0;j<24;j++){
            if(card_deck_n[j]!=0){
                break;
            }
        }
        if(j!=24){
            seabed_n[i] = user_n[c];
            seabed_s[i] = user_s[c];
            p1_n[c] = card_deck_n[j];
            p1_s[c] = card_deck_s[j];
            card_deck_n[j] = card_deck_s[j] = 0;
        }
        else{
            seabed_n[i] = p1_n[c];
            seabed_s[i] = p1_s[c];
            p1_n[c] = 0;
            p1_s[c] = 0;
        }
    }
    else{
        a=rand()%6;
        b=rand()%6;
        if(p1_n[a]<10){
            if(p1_n[a]!=9&&seabed_n[b]!=9&&p1_n[a]!=1&&seabed_n[b]!=9){
                if(p1_s[a]==2||p1_s[a]==3){
                    p1_point += p1_n[a];
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p1_point += seabed_n[b];
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = p1_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p1_n[a] = p1_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = card_deck_n[i+1];
                    p1_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i]=0;
                }
           }
           else{
                if(p1_n[a]==1){
                    if(p1_s[a]==1){
                        p1_point += 10;
                    }
                    else if(p1_s[a]==2||p1_s[a]==3){
                        p1_point +=20;
                    }
                    if(seabed_s[b]==2||seabed_s[b]==3){
                        p1_point += 10;
                    }
                }
                else if(seabed_n[b]==1){
                    if(seabed_s[b]==1){
                        p1_point += 10;
                    }
                    else if(seabed_s[b]==2||seabed_s[b]==3){
                        p1_point +=20;
                    }
                    if(user_s[a]==2||user_s[a]==3){
                        p1_point += 10;
                    }
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = p1_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p1_n[a] = p1_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = card_deck_n[i+1];
                    p1_s[a] = card_deck_s[i+1];
                    card_deck_n[i] = card_deck_s[i] = card_deck_n[i+1] = card_deck_n[i]=0;
                }
           }
        }
        else if(p1_n[a]>=10){
                if(p1_s[a]==2||p1_s[a]==3){
                    p1_point += 10;
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p1_point += 10;
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = p1_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p1_n[a] = p1_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p1_n[a] = card_deck_n[i+1];
                    p1_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i+1]=0;
                }
        }
    }

}

void game::player2_move(){
    int a,b,c,i,j;
    if(check(p2_n)==0){
        c = rand()%6;
        for(i=0;i<13;i++){
            if(seabed_n[i]==0){
                break;
            }
        }
        for(j=0;j<24;j++){
            if(card_deck_n[j]!=0){
                break;
            }
        }
        if(j!=24){
            seabed_n[i] = p2_n[c];
            seabed_s[i] = p2_s[c];
            p2_n[c] = card_deck_n[j];
            p2_s[c] = card_deck_s[j];
            card_deck_n[j] = card_deck_s[j] = 0;
        }
        else{
            seabed_n[i] = p2_n[c];
            seabed_s[i] = p2_s[c];
            p2_n[c] = 0;
            p2_s[c] = 0;
        }
    }
    else{
        a=rand()%6;
        b=rand()%6;
        if(p2_n[a]<10){
            if(p2_n[a]!=9&&seabed_n[b]!=9&&p2_n[a]!=1&&seabed_n[b]!=9){
                if(p2_s[a]==2||p2_s[a]==3){
                    p2_point += p2_n[a];
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p2_point += seabed_n[b];
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = p2_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p2_n[a] = p2_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = card_deck_n[i+1];
                    p2_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i]=0;
                }
           }
           else{
                if(p2_n[a]==1){
                    if(p2_s[a]==1){
                        p2_point += 10;
                    }
                    else if(p2_s[a]==2||p2_s[a]==3){
                        p2_point +=20;
                    }
                    if(seabed_s[b]==2||seabed_s[b]==3){
                        p2_point += 10;
                    }
                }
                else if(seabed_n[b]==1){
                    if(seabed_s[b]==1){
                        p2_point += 10;
                    }
                    else if(seabed_s[b]==2||seabed_s[b]==3){
                        p2_point +=20;
                    }
                    if(user_s[a]==2||user_s[a]==3){
                        p2_point += 10;
                    }
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = p2_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p2_n[a] = p2_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = card_deck_n[i+1];
                    p2_s[a] = card_deck_s[i+1];
                    card_deck_n[i] = card_deck_s[i] = card_deck_n[i+1] = card_deck_n[i]=0;
                }
           }
        }
        else if(p2_n[a]>=10){
                if(p2_s[a]==2||p2_s[a]==3){
                    p2_point += 10;
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p2_point += 10;
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = p2_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p2_n[a] = p2_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p2_n[a] = card_deck_n[i+1];
                    p2_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i+1]=0;
                }
        }
    }
}

void game::player3_move(){
    int a,b,c,i,j;
    if(check(p3_n)==0){
        c = rand()%6;
        for(i=0;i<13;i++){
            if(seabed_n[i]==0){
                break;
            }
        }
        for(j=0;j<24;j++){
            if(card_deck_n[j]!=0){
                break;
            }
        }
        if(j!=24){
            seabed_n[i] = p3_n[c];
            seabed_s[i] = p3_s[c];
            p3_n[c] = card_deck_n[j];
            p3_s[c] = card_deck_s[j];
            card_deck_n[j] = card_deck_s[j] = 0;
        }
        else{
            seabed_n[i] = p3_n[c];
            seabed_s[i] = p3_s[c];
            p3_n[c] = 0;
            p3_s[c] = 0;
        }
    }
    else{
        a=rand()%6;
        b=rand()%6;
        if(p3_n[a]<10){
            if(p3_n[a]!=9&&seabed_n[b]!=9&&p3_n[a]!=1&&seabed_n[b]!=9){
                if(p3_s[a]==2||p3_s[a]==3){
                    p3_point += p3_n[a];
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p3_point += seabed_n[b];
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = p3_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p3_n[a] = p3_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = card_deck_n[i+1];
                    p3_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i]=0;
                }
           }
           else{
                if(p3_n[a]==1){
                    if(p3_s[a]==1){
                        p3_point += 10;
                    }
                    else if(p3_s[a]==2||p3_s[a]==3){
                        p3_point +=20;
                    }
                    if(seabed_s[b]==2||seabed_s[b]==3){
                        p3_point += 10;
                    }
                }
                else if(seabed_n[b]==1){
                    if(seabed_s[b]==1){
                        p3_point += 10;
                    }
                    else if(seabed_s[b]==2||seabed_s[b]==3){
                        p3_point +=20;
                    }
                    if(p3_s[a]==2||p3_s[a]==3){
                        p3_point += 10;
                    }
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = p3_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p3_n[a] = p3_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = card_deck_n[i+1];
                    p3_s[a] = card_deck_s[i+1];
                    card_deck_n[i] = card_deck_s[i] = card_deck_n[i+1] = card_deck_n[i]=0;
                }
           }
        }
        else if(p3_n[a]>=10){
                if(p3_s[a]==2||p3_s[a]==3){
                    p3_point += 10;
                }
                if(seabed_s[b]==2||seabed_s[b]==3){
                    p3_point += 10;
                }
                for(i=0;i<24;i++){
                    if(card_deck_n[i]!=0){
                        break;
                    }
                }
                if(i==23){
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = p3_s[a] = card_deck_n[i] = card_deck_s[i]=0;
                }
                else if(i==24){
                    p3_n[a] = p3_s[a] = seabed_n[b] = seabed_s[b] = 0;
                }
                else{
                    seabed_n[b] = card_deck_n[i];
                    seabed_s[b] = card_deck_s[i];
                    p3_n[a] = card_deck_n[i+1];
                    p3_s[a] = card_deck_s[i+1];
                    card_deck_n[i]=card_deck_s[i]=card_deck_n[i+1]=card_deck_n[i+1]=0;
                }
        }
    }
}

