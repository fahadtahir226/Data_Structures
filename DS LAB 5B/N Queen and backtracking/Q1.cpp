 
#include <iostream>
using namespace std;

void display(int arry[4][4]){
    for(int i = 0;i <4; i++){
        cout<< " { "<< arry[i][0] <<" , "<< arry[i][1] <<" , " <<arry[i][2] <<" , " << arry[i][3] <<" }"<<endl;
    }
}

bool nextStep(int maze[4][4], int row, int col, int cleanPath[4][4], bool last){
    if(row > 3 || col > 3 || row < 0 || col < 0){
        return last;
    }
    if(row == 3 && col == 3 && maze[row][col] == 1){
        cleanPath[row][col] = 1;
        display(cleanPath);
        return true;
    }
    if(maze[row][col]!=1){
        cout<<"Going back : Array[ "<< row<<" ][ "<< col<< " ] "<<endl;
    // maze[y][x] = 2;
        return false;
    }
    else{
        cout <<"Moving Forward: Array[ "<< row << " ][ "<< col << " ] "<<endl;
        cleanPath[row][col] = 1;
        maze[row][col] = 2;
        // Check For Right
        last = nextStep(maze, row , col + 1, cleanPath, last);        
        if(last) return true;

        // Check For Bottom
        else {
            last = nextStep(maze, row + 1, col, cleanPath, last);
        }
        if(last) return true;

        // Check for Left
        else{
            last = nextStep(maze, row, col - 1, cleanPath, last);
        }
        
        // Check for Top
        if(last) return true;
        else{
            last = nextStep(maze, row - 1, col, cleanPath, last);
        }
        return last ;
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
    if(nextStep(maze, 0, 0, cleanPath, false)){
        display(cleanPath);
        cout<<endl<<"Path Exist!!!"<<endl;
    }
    else{
        display(cleanPath);
        cout<<endl<<"Path does Not Exist!!!"<<endl;
    }
    return 0;
}