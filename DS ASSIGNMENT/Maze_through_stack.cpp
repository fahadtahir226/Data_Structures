#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void display(char maze[][10], int row, int col){
    for(int i = 0; i < row ; i++){
        for(int j=0; j < col; j++){
            cout<< maze[i][j]<< " ";
        }
        cout<< endl;
    }

}

class Point {
    public: 
    int x, y;
    Point(){
        x=0;
        y=0;
    }
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
    void display(){
        cout << "(" << y << " , "<< x << ")"<<endl;
    }
};

class Stack {
    Point arry[100];
    int size;
    public:
    Stack(){
        size = 0;
    }
    bool isEmpty(){
        if(size) return false;
        return true;
    }
    bool isFull(){
        if(size>=100) return true;
        return false;
    }
    void push(Point p){
        if(isFull()) {
            cout<< "Stack is already full"<<endl;
            return;
        };
        // cout<< "Pushing: ( x = "<<p.x << " , y = "<< p.y << " )" <<endl;
        arry[size].x =p.x;
        arry[size].y =p.y;
        size++;
    }
    Point pop() {
        if(isEmpty()) {
            cout<< "Stack is already empty"<<endl;
            return Point(0,0);
        }
        return arry[ --size ];
    }
    void display(){
        cout<<"Displaying Stack"<<endl;
        for(int i=0;i < size;i++) arry[i].display();
        cout<<"Stack End here"<<endl;
    }
    int getSize(){ return size;}
};

bool isPath(char maze[][10],int row,int col, Point finalPoint){
    if(maze[row][col] != 'o' || row < 0 || col  < 0 || row > finalPoint.y || col > finalPoint.x ) return false;
    // cout<< "Yes ( x = "<< col << " , y = "<< row << ')' <<endl;
    return true;
}

bool solveMaze(char maze[][10], Stack path, Point finalPoint, int row, int col, bool pathFound, Stack PossiblePath){
    if(finalPoint.x == col && finalPoint.y == row) {
        path.push(Point(col, row ));
        maze[row][col] = 'v';
        return true;
    }

    //Pushing posibilities to 
    bool right =false ,left = false,top = false,bottom = false;
    if(isPath(maze, row ,col - 1, finalPoint)){                // checking left
        path.push(Point(col - 1,row ));
        PossiblePath.push(Point(col - 1, row));
        left = true;
    }
    if(isPath(maze, row - 1, col, finalPoint)) {               // checking top
        path.push(Point(col ,row - 1));
        PossiblePath.push(Point(col, row - 1));
        top = true;
    }   
    if(isPath(maze, row ,col + 1, finalPoint)) {               // checking right
        path.push(Point(col + 1,row ));
        PossiblePath.push(Point(col + 1, row));
        right = true;
    } 
    if(isPath(maze, row + 1, col, finalPoint)) {               // checking bottom
        path.push(Point(col , row + 1));
        PossiblePath.push(Point(col, row + 1));
        bottom = true;
    }

    if(top || right || left || bottom)    maze[row][col] = 'v';
    else {
        maze[row][col] = 'd';
        PossiblePath.pop();
    }
    // Point toMove
    if(path.isEmpty()) return false;
    Point p = path.pop();
    return solveMaze(maze,path,finalPoint,p.y, p.x, false, PossiblePath);

}

void extractVisited(char maze[][10], int row, int col){
    ofstream onfile;
    onfile.open ("Q1_output.txt");

    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            if(maze[i][j] == 'v') {
                cout<< "( " << i << " , " << j << " )"<<endl ;
                onfile << i <<" "<< j <<endl;
            }
        }
    }
}

int main (){
  
  int row, col;

  ifstream infile;
  infile.open ("Q1.txt");
  infile >> row >> col;
  char maze[row][10];
//   cout << "Number of Rows: " << row << endl <<"Number of Coloumns: "<<  col << endl;

  char val;
  for(int i = 0; i < row; i++){
    for (int j = 0; j < col ; j++){
      infile >> val;
      maze[i][j] = val;
    }
  }
  infile.close();


  display(maze,row,col);
    Stack path, FinalPath;
    if(solveMaze(maze, path, Point(col - 1,row - 1), 0, 0, false, FinalPath)){
        cout<<"Path Exist"<<endl;
    }
    else{
        cout<< "Path Does Not Exists"<<endl;
    }
    cout<< "'b' means Block"<<endl<<"'o'means open which are later changed into "<<endl<<"'v' if visited and posible "<<endl<<"'d' if dead end"<<endl;

      display(maze,row,col);


extractVisited(maze, row, col);



//   Stack s1;
// s1.push(Point(2,4));
// s1.push(Point(4,5));
// s1.push(Point(6,6));
// s1.push(Point(8,7));

// s1.display();
// s1.pop().display();
// s1.display();

    return 0;
}