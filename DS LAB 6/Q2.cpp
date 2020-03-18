#include <iostream>
using namespace std; 

class Stack {
  int arry[100];
  public:
  int size;
    Stack(){
      int i = 0;
      while(i==100) arry[i++] = 0; 
      size = 0;
    }  
    void push(int data) {
      arry[size] = data;
      size++;
    } 
    int pop(){
      int temp = arry[size - 1];
      arry[size] = 0;
      size--;
      return temp;
    }
    void display(){
      for(int i = size - 1 ;i >= 0; i--) cout<<arry[i];
    }
    void displayRev(){
      for(int i = 0 ;i < size; i++) cout<<arry[i]<< " ";
    }
};



int main(){
    Stack s1, s2, s3;
    s1.push(9);
    s1.push(9);
    s1.push(9);
    // cout<<"Stack 1 = ";
    // s1.displayRev();
    // cout<<endl;

    s2.push(9);
    s2.push(9);
    s2.push(9);
    // cout<<"Stack 1 = ";
    // s2.displayRev();
    // cout<<endl;



    int sizeForLoop = 0;
    int sizeForOne;
    if(s1.size>=s2.size) sizeForLoop = s1.size;
    else sizeForLoop = s2.size;
    sizeForOne = sizeForLoop;

    int carry = 0, sum = 0;
    for(int i = 0; i < sizeForLoop; i++){
        if(sizeForOne == sizeForLoop) {
            sum = s1.pop() + s2.pop();
        }
        cout<< "Adding Carry: " << carry<<endl; 
        sum+= carry;
        carry = 0;
        if(sum >= 10){
            carry = sum / 10;
            cout<< "updating carry: "<< carry<<endl;
            sum -= 10;
            s3.push(sum);
            if(i == sizeForLoop - 1 && carry > 0) {
                sizeForLoop++;
                sum = carry;
                carry = 0;
            }
        }
        else{
            s3.push(sum);
            sum = 0;
        }
    }
    s3.display();
    cout<<endl;


    return 0;
}
