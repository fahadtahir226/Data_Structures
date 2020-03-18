#include <iostream>
using namespace std;

void displayOutPutPath(int arry[4][4]){
    for(int i = 0;i <4; i++){

        cout<< " { ";
        for(int j = 0; j < 4; j++){
            cout<< arry[i][j];
            if(j < 3) cout<<" , ";
        }
        cout<< " }"<< endl;
    }
}

bool isSafe(int arry[4][4], int row,int col){
    int i;
    //checking current Row
    for(i = 0 ; i < 4 ; i++){
        if (arry[row][i] != 0){
            // cout << "The Queen from same row : ( " << row <<" , " << i <<" )"<<endl;  
            return false;
        }                         
    }
    // cout<<"row clear"<<endl;
    
    //checking current column
    i = 0;
    for( i = 0 ; i < 4 ; i++){
        if (arry[i][col] != 0) {
            // cout << "The Queen from same coloumn : ( " << i <<" , " << col <<" )"<<endl;  
            return false;
        }
    }
    // cout<<"Coloumn clear"<<endl;

    // checking left bottom to right top digonal
    i = row;
    int j = col;

    while(i < 3  && j > 0){
        i++;
        j--;
    }
    while(i >= 0 && j < 4){
        if (arry[i][j] != 0) {
            // cout << "The Queen from : ( " << i <<" , " << j <<" )"<<endl;  
            return false;
        }
        i--;
        j++;
    }
    // cout<<"left bottom to right top digonal clear"<<endl;
    // checking left top to right bottom digonal
    i = row;
    j = col;

    while(i > 0  && j > 0){
        i--;
        j--;
    }
    while( i < 4 && j < 4 ){
        if (arry[i][j] != 0) {
            // cout << "The Queen from : ( " << i <<" , " << j <<" )"<<endl;  
            return false;
        };
        i++;
        j++;
    }
    // cout<<"left left top to right bottom digonal clear"<<endl;

    return true;
}
bool placeQueen(int arry[4][4], int col, int isPlaced, int queenNo){
    if(isPlaced){
        return isPlaced;
    }
    if( queenNo > 4) return true;
    else{

        if(isSafe(arry,0,col)){
            arry[0][col] = 1;
            cout<< "Q"<<queenNo<<" Placed at "<<"( 0 , "<<col<<" )"<<endl;
            isPlaced = placeQueen(arry,col + 1 ,isPlaced, queenNo + 1); 
            if(isPlaced) return true;
            arry[0][col] = 0;
        }
        if(isSafe(arry,1,col)){
            arry[1][col] = 1;
            cout<< "Q"<<queenNo<<" Placed at "<<"( 1 , "<<col<<" )"<<endl;
            isPlaced = placeQueen(arry,col + 1 ,isPlaced, queenNo + 1);
            if(isPlaced) return true; 
            arry[1][col] = 0;
        }
        if(isSafe(arry,2,col)){
            arry[2][col] = 1;
            cout<< "Q"<<queenNo<<" Placed at "<<"( 2 , "<<col<<" )"<<endl;
            isPlaced = placeQueen(arry,col + 1 ,isPlaced, queenNo + 1); 
            if(isPlaced) return true;
            arry[2][col] = 0;
        }
        if(isSafe(arry,3,col)){
            arry[3][col] = 1;
            cout<< "Q"<<queenNo<<" Placed at "<<"( 3 , "<<col<<" )"<<endl;
            isPlaced = placeQueen(arry,col + 1 ,isPlaced, queenNo + 1); 
            if(isPlaced) return true;
            arry[3][col] = 0;
        }
        cout<<"Q"<<queenNo<<" cannot be placed here, so going back to replace"<<endl;
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
    if(placeQueen(arry,0, false, 1)){
        displayOutPutPath(arry);
    }
    else{
        cout<<"u did some error"<<endl;
    }
    // if(isSafe(arry, 2, 2)){
    //     cout<< " Yes it is safe"<<endl;
    // }
    // else{
    //     cout<<" No it is in Danger"<<endl;
    // }
    return 0;
}