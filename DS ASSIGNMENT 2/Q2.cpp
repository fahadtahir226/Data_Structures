#include <iostream>
#include <fstream>
// #include <string>
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

class Queue{
    int first,last,limit;
    Point arry[100];
    int size;
    public:
    bool isEmpty, isFull;
    Queue(){
        first = 0;
        last = 0;
        limit = 100;
        isEmpty = true;
        isFull = false; 
        size = 0;
    }
    void enque(Point p){
        if(!isFull){
            size++;
            arry[last] = p;
            last++;
            isEmpty = false;
            if(last >= limit) last = 0; 
            if(first == last) isFull = true;
            return;
        }
        cout<< "It is already full!, Can't insert " << endl;
    }
    Point dequeu(){
        if(!isEmpty){
            size--;
            Point p;
            p.x = arry[first].x;
            p.y = arry[first].y;
            first++;
            isFull = false;
            if(first >= limit) first = 0;
            if(first == last) isEmpty = true;
            return p;
        }
        cout<< "It is already empty!" <<endl;
        Point p;
        return p;
    }
    void display(){
        cout<<"Displaying Queue"<<endl;
        for(int i=0;i < size;i++) arry[i].display();
        cout<<"Queue End here"<<endl;
    }
    int getSize(){ return size;}
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
    if(maze[row][col] == 'b' || row < 0 || col  < 0 || row > finalPoint.y || col > finalPoint.x ) return false;
    // cout<< "Yes ( x = "<< col << " , y = "<< row << ')' <<endl;
    return true;
}

bool solveMaze(char maze[][10], Queue path, Point finalPoint, int row, int col, bool pathFound, Stack PossiblePath){
    if(maze[row][col] == 'e') {
        cout<<"returning from here"<<endl;
        PossiblePath.push(Point(col, row ));
        // maze[row][col] = 'p';
        return true;
    }

    //Pushing posibilities to 
    bool right =false ,left = false,top = false,bottom = false;
    if(isPath(maze, row ,col - 1, finalPoint)){                // checking left
        path.enque(Point(col - 1,row ));
        // PossiblePath.push(Point(col - 1, row));
        left = true;
    }
    if(isPath(maze, row - 1, col, finalPoint)) {               // checking top
        path.enque(Point(col ,row - 1));
        // PossiblePath.push(Point(col, row - 1));
        top = true;
    }   
    if(isPath(maze, row ,col + 1, finalPoint)) {               // checking right
        path.enque(Point(col + 1,row ));
        // PossiblePath.push(Point(col + 1, row));
        right = true;
    } 
    if(isPath(maze, row + 1, col, finalPoint)) {               // checking bottom
        path.enque(Point(col , row + 1));
        // PossiblePath.push(Point(col, row + 1));
        bottom = true;
    }

    if(top || right || left || bottom)    maze[row][col] = 'v';

    // Point toMove
    if(path.isEmpty) return false;
    Point p = path.dequeu();
      // cout<<"going to: " << " row: " << p.y << " col: " << p.x  << endl;
    if(solveMaze(maze, path, finalPoint, p.y, p.x, false, PossiblePath)){

    //   maze[row][col] = 'p';
    //   PossiblePath.push(Point(col, row));
    //  PossiblePath.display();
      return true;  
    }
    return false; 


}

void extractVisited(char maze[][10], int row, int col){
    ofstream onfile;
    onfile.open ("Q1_output.txt");

    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
                cout<< "( " << i << " , " << j << " )"<<endl ;
                onfile << i <<" "<< j <<endl;
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


//   display(maze,row,col);
    Queue path;
    Stack FinalPath;
    if(solveMaze(maze, path, Point(col - 1,row - 1), 0, 0, false, FinalPath)){
        cout<<"Path Exist"<<endl;
    }
    else{
        cout<< "Path Does Not Exists"<<endl;
    }
    // cout<<"'o'means open which are later changed into "<<endl<<"'v' if visited and posible "<<endl<<"'d' if dead end"<<endl;

      display(maze,row,col);

    FinalPath.display();
// extractVisited(maze, row, col);


    return 0;
}