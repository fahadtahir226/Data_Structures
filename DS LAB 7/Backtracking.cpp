#include <iostream>
using namespace std;
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
    void updateValue(int x, int y){
        this->x = x;
        this->y = y;
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

void display(char maze[][10], int row, int col){
    for(int i = 0; i < row ; i++){
        for(int j=0; j < col; j++){
            cout<< maze[i][j]<< " ";
        }
        cout<< endl;
    }

}

bool findWord(  char crossBoard[][10],Point maxPoint, Point currPoint, Stack wordContainer, string word,int soFarTravelled, bool isfound){
    // cout<< "Called"<<endl;
    if(word.length() == soFarTravelled + 1 &&  word[soFarTravelled] == crossBoard[currPoint.y][currPoint.x]) {
        cout<< "Found "<< word[soFarTravelled]<<" at: ";
        currPoint.display();
        wordContainer.push(currPoint);
        wordContainer.display();
        cout<< "Here It is ending"<<endl;
        return true;
    }
    if(currPoint.x > maxPoint.x || currPoint.y > maxPoint.y || currPoint.x < 0 || currPoint.y < 0) return isfound;
    if(word[soFarTravelled] == crossBoard[currPoint.y][currPoint.x]){
        cout<< "Matched"<<endl;
        cout<< "Found "<< word[soFarTravelled]<<" at: ";
        currPoint.display();
        wordContainer.push(currPoint);
        if(findWord(crossBoard, maxPoint, Point(currPoint.x + 1,currPoint.y), wordContainer, word ,soFarTravelled + 1, isfound)) return true;
        if(findWord(crossBoard, maxPoint, Point(currPoint.x,currPoint.y + 1), wordContainer, word ,soFarTravelled + 1, isfound)) return true;
        if(findWord(crossBoard, maxPoint, Point(currPoint.x + 1,currPoint.y + 1), wordContainer, word ,soFarTravelled + 1, isfound)) return true;

    }
    return false;
}
int main(){
   Point maxPoint(4,4), startingPoint(0,0);
   Stack wordcontainer;
   char crossBoard[][10] = 
   { 
      {'P', 'T', 'Q', 'V'},
      {'S', 'O', 'J', 'K'},
      {'R', 'U', 'G', 'V'},
      {'A', 'C', 'B', 'H'},
   };
   bool isFound = false;
   for(int i = 0; i < 5 ;i++){
       for(int j = 0; j < 5 ; j++){
            startingPoint.updateValue(j , i);
            if(findWord(crossBoard, maxPoint,startingPoint,wordcontainer,"TOUGH",0,false)) {
                cout<< "Word Found"<<endl;
                isFound = true;
                break;
            }
            else{
                cout<< "Starting again from: "<<endl;
                startingPoint.display();
            }

       }
       if(isFound) break;

   }


    return 0;
}