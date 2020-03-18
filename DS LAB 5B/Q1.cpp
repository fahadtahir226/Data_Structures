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

bool jumpToNext(int maze[4][4], int row, int col, int cleanPath[4][4], bool isEnd){
    if(row > 3 || col > 3 || row < 0 || col < 0){
        return isEnd;
    }
    if(row == 3 && col == 3 && maze[row][col] == 1){
        cleanPath[row][col] = 1;
        cout << "This is The End"<<endl;
        // displayOutPutPath(cleanPath);
        return true;
    }
    if(maze[row][col]!=1){
        cout<<"Dead Here so going back: ( "<< row<<" , "<< col<< " ) "<<endl;
    // maze[y][x] = 2;
        return false;
    }
    else{
        cout <<"Moving Forward From Here: ( "<< row << " , "<< col << " ) "<<endl;
        cleanPath[row][col] = 1;
        maze[row][col] = 2;
        // Check For Right
        isEnd = jumpToNext(maze, row , col + 1, cleanPath, isEnd);        
        if(isEnd) return true;

        // Check For Bottom
        else {
            isEnd = jumpToNext(maze, row + 1, col, cleanPath, isEnd);
        }
        if(isEnd) return true;

        // Check for Left
        else{
            isEnd = jumpToNext(maze, row, col - 1, cleanPath, isEnd);
        }
        
        // Check for Top
        if(isEnd) return true;
        else{
            isEnd = jumpToNext(maze, row - 1, col, cleanPath, isEnd);
        }
        // else cout<< " It is a End end!!!"<<endl;
        return isEnd ;
    } 
}


int main(){
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    },
    cleanPath[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(jumpToNext(maze, 0, 0, cleanPath, false)){
        displayOutPutPath(cleanPath);
        cout<<endl<<"Path Found!!!"<<endl;
    }
    else{
        displayOutPutPath(cleanPath);
        cout<<endl<<"Path Not Found!!!"<<endl;
    }
    return 0;
}