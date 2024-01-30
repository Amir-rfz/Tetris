#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
const int row=10;
const int column=6;
/*making a random number */
int random(){
    srand(clock()+time(NULL)+M_PI);
    return rand()%column;
}

/*making new playground after the last row is full*/
void making_new_playground(int playground[row][column]){
    for(int i=row;i>=1;i--){
        for(int j=0;j<column;j++){
            playground[i][j]=playground[i-1][j];
        }
    }
    for(int j=0;j<column;j++){
        playground[0][j]=0;
    }
}

/*making game board by getting game matris and score*/
void game_board(int n,int playground[row][column]){
    for(int i=0;i<row;i++){
        cout<<"|";
        for(int j=0;j<column;j++){
            if(playground[i][j]==1){
                cout<<"[]";
            }
            else
                cout<<"  ";
        }
        cout<<"|";
        if(i==0){
            cout<<"   score:"<<n;
        }
        cout<<endl;
    }
    for(int i=0;i<column+1;i++){
        cout<<"--";
    }
    cout<<endl;
}

/*making playground matris and show the result*/
int main() {
    int playground[row][column]={0};
    int score=0;
    while(true){
        int start=random();
        if(playground[0][start]==1){
            break;
        }

        bool flag=true;
        for(int i=0;i<column;i++){
            if(playground[row-1][i]==0){
                flag=false;
            }
        }
        if(flag){
            making_new_playground(playground);
            score+=10;
        }

        for(int i=0;i<row;i++){
            if(i!=row && playground[i][start]!=1){
                playground[i][start]=1;
                playground[i-1][start]=0;
                game_board(score,playground);
                Sleep(50);
            }
            else{
                playground[i][start]=1;
                game_board(score,playground);
                break;
            }
        }
    }
    cout<<"GAME OVER";
    return 0;
}