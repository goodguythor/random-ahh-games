#include <bits/stdc++.h>
using namespace std;

string checkWinner(char piece){
    if(piece=='X') return "Player 1";
    return "Player 2";
}

bool check(vector<string>& board,string& result){
    for(int i=0;i<3;i++){
        if(board[i][0]!=' '&&(board[i][0]==board[i][2])&&(board[i][0]==board[i][4])){
            result=checkWinner(board[i][0]);
            return true;
        }
    }
    for(int i=0;i<5;i+=2){
        if(board[0][i]!=' '&&(board[0][i]==board[1][i])&&(board[0][i]==board[2][i])){
            result=checkWinner(board[0][i]);
            return true;
        }
    }
    if(board[1][2]!=' '&&(board[0][0]==board[1][2])&&(board[0][0]==board[2][4])){
        result=checkWinner(board[1][2]);
        return true;
    }
    if(board[1][2]!=' '&&(board[0][4]==board[1][2])&&(board[0][4]==board[2][0])){
        result=checkWinner(board[1][2]);
        return true;
    }
    return false;
}

void printBoard(vector<string>& board){
    for(auto i:board) cout<<i<<'\n';
}

void printMessage(int i){
    cout<<"     TURN "<<i<<"      \n";
    if(i%2==1) cout<<"First Player Turn\n";
    else cout<<"Second Player Turn\n";
}

int main(){
    int choice=1;
    while(choice==1){
        vector<string> board{" | | "," | | "," | | "};
        cout<<"TIC TAC TOE\n";
        cout<<"RULE\n";
        cout<<"I believe that you're already know the rule right? If you really don't know the rule of this game then just google it bro\n";
        cout<<"Player 1 = X\n";
        cout<<"Player 2 = O\n";
        printBoard(board);
        int i=1;
        choice=0;
        string result="Draw";
        while(i<10){
            bool c=false;
            while(!c){
                printMessage(i);
                int x=-1,y=-1;
                while(x<1||x>3){
                    cout<<"Please enter the input correctly!!!\n";
                    cout<<"Please only enter number or you'll get an error!!!\n";
                    cout<<"Choose which row you want to put your piece! (1/2/3): ";
                    cin>>x;
                }
                while(y<1||y>3){
                    cout<<"Please enter the input correctly!!!\n";
                    cout<<"Please only enter number or you'll get an error!!!\n";
                    cout<<"Choose which column you want to put your piece! (1/2/3): ";
                    cin>>y;
                }
                if(board[x-1][y*2-2]==' '){
                    board[x-1][y*2-2]=(i%2==1)?'X':'O';
                    c=true;
                }
                else{
                    cout<<"Sorry, that position is already filled with other piece\n";
                    cout<<"Please enter another row and column!!!\n";
                }
                printBoard(board);
            }
            if(check(board,result)) break;
            i++;
        }
        cout<<"The result is "<<result;
        if(result!="Draw") cout<<" wins";
        cout<<"\n\n";
        while(choice<1||choice>2){
            cout<<"Please enter the input correctly!!!\n";
            cout<<"Please only enter number or you'll get an error!!!\n";
            cout<<"Do you want to play again? (1. Yes, 2. No) ";
            cin>>choice;
        }
        cout<<"\n\n";
    }
    return 0;
}