#include <iostream>
using namespace std;


bool checkDigonal(int i, int j, int arry[4][4]){
    while(i > 0  && j > 0){
        i--;
        j--;
    };
    while( i < 4 && j < 4 ){
        if (arry[i][j] != 0) return false;
        i++; 
        j++;
    } 
    return true;   
}

bool checkAntiDigonal(int i, int j,int arry[4][4]){
    while(i < 3  && j > 0){
        i++;
        j--;
    }
    while(i >= 0 && j < 4){
        if (arry[i][j] != 0) return false;
        i--;
        j++;
    }
    return true;
}

void display(int arry[4][4]){
    for(int i = 0;i <4; i++){
        cout<< " { "<< arry[i][0] <<" , "<< arry[i][1] <<" , " <<arry[i][2] <<" , " << arry[i][3] <<" }"<<endl;
    }
}

bool checkPlace(int arry[4][4], int row,int col){
    //checking current Row
    for(int i = 0 ; i < 4 ; i++) if (arry[row][i] != 0) return false;

    return checkDigonal(row, col, arry) && checkAntiDigonal(row, col, arry);
}
bool nQueen(int arry[4][4], int col, int allQueenReady, int currentQueen){
    if(allQueenReady){
        return allQueenReady;
    }
    if( currentQueen > 4) return true;
    else{

        if(checkPlace(arry,0,col)){
            arry[0][col] = 1;
            cout<< "Queen no. "<<currentQueen<<" Placed at [ 0 ][ "<<col<<" ]"<<endl;
            allQueenReady = nQueen(arry,col + 1 ,allQueenReady, currentQueen + 1); 
            if(allQueenReady) return true;
            arry[0][col] = 0;
        }
        if(checkPlace(arry,1,col)){
            arry[1][col] = 1;
            cout<< "Queen no. "<<currentQueen<<" Placed at [ 1 ][ "<<col<<" ]"<<endl;
            allQueenReady = nQueen(arry,col + 1 ,allQueenReady, currentQueen + 1);
            if(allQueenReady) return true; 
            arry[1][col] = 0;
        }
        if(checkPlace(arry,2,col)){
            arry[2][col] = 1;
            cout<< "Queen no. "<<currentQueen<<" Placed at [ 2 ][ "<<col<<" ]"<<endl;
            allQueenReady = nQueen(arry,col + 1 ,allQueenReady, currentQueen + 1); 
            if(allQueenReady) return true;
            arry[2][col] = 0;
        }
        if(checkPlace(arry,3,col)){
            arry[3][col] = 1;
            cout<< "Queen no. "<<currentQueen<<" Placed at [ 3 ][ "<<col<<" ]"<<endl;
            allQueenReady = nQueen(arry,col + 1 ,allQueenReady, currentQueen + 1); 
            if(allQueenReady) return true;
            arry[3][col] = 0;
        }
        cout<<"This Queen Number : "<<currentQueen<<" and further can not be placed!!!"<<endl;
    return false;
    }
}

int main(){

    int arry[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    if(nQueen(arry,0, false, 1)){
        display(arry);
    }
    else{
        cout<<"u did some error"<<endl;
    }
    // if(checkPlace(arry,0,0)) cout<< "yes";
    // else cout<<"no";
    return 0;
}