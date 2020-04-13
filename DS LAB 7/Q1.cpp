#include<iostream>
using namespace std;

class Queue {
    int first,last,limit;
    bool isEmpty, isFull;
    int array[5];
    public:
    Queue(){
        first = 0;
        last = 0;
        limit = 5;
        isEmpty = true;
        isFull = false; 
        for(int i=0;i<5;i++){
            array[i] = 0;
        }
    }
    // bool isFull(){
    //     // cout<< " => ( "<< first << " "<< last<< " ) "<<endl;
    //     if( first == (last + 1) || (last == (limit)  && (first <= 0))) return true;
    //     return false;
    // }
    // bool isEmpty(){
    //     if(last == first) return true;
    //     return false;
    // }
    void enque(int val){
        if(!isFull){
            array[last] = val;
            last++;
            isEmpty = false;
            if(last >= limit) last = 0; 
            if(first == last) isFull = true;
            return;
        }

        cout<< "It is already full!, Can't insert: "<< val;
    }
    int dequeu(){
        if(!isEmpty){
            int temp = array[first];
            array[first] = 0;
            first++;
            isFull = false;
            if(first >= limit) first = 0;
            if(first == last) isEmpty = true;
            return temp;
        }
        cout<< "It is already empty!" <<endl;
        return 0;
    }
    void displayQueue(){
        int current = first;
        while(current != last){
            cout<< array[current]<< " - ";
            current++;
            if(current >= limit) current = 0;
        }
        cout<<endl;
    }
    void displayArry(){
        for(int i=0;i<5;i++){
            cout<< array[i] << " - ";
        }
        cout<< "( " << first << " " << last<< " )"<<endl;
    }
};

int main(){
    Queue Q1;
    Q1.enque(1);
    Q1.enque(2);
    Q1.enque(3);
    Q1.enque(4);
    Q1.enque(5);
    Q1.displayArry();
    Q1.dequeu();
    Q1.enque(6);
    Q1.displayArry();


    Q1.dequeu();
    Q1.displayArry();

    Q1.enque(7);
    Q1.enque(8);
    Q1.displayArry();

    return 0;
}