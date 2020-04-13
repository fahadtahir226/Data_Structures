#include<iostream>
using namespace std;

class Task{
    public:
    string task;
    int time;
};
class Queue{
    int first,last,limit;
    bool isEmpty, isFull;
    Task array[7];
    public:
    Queue(){
        first = 0;
        last = 0;
        limit = 7;
        isEmpty = true;
        isFull = false; 
        for(int i=0;i<7;i++){
            array[i].task = "-";
            array[i].time = 0;
        }
    }
    void enque(string val,int time){
        if(!isFull){
            array[last].task = val;
            array[last].time = time;
            last++;
            isEmpty = false;
            if(last >= limit) last = 0; 
            if(first == last) isFull = true;
            return;
        }
        cout<< "It is already full!, Can't insert: "<< val << endl;
    }
    Task dequeu(){
        if(!isEmpty){
            Task temp;
            temp.task =  array[first].task;
            temp.time =  array[first].time; 
            array[first].task = "-";
            first++;
            isFull = false;
            if(first >= limit) first = 0;
            if(first == last) isEmpty = true;
            return temp;
        }
        cout<< "It is already empty!" <<endl;
        Task t;
        return t;
    }
    // void displayQueue(){
    //     int current = first;
    //     while(current != last){
    //         cout<< array[current].task<< " - ";
    //         current++;
    //         if(current >= limit) current = 0;
    //     }
    //     cout<<endl;
    // }
    void displayArry(){
        for(int i=0;i<limit;i++){
            cout<< array[i].task << " ( "<< array[i].time <<" ) " << " - "<<endl;
        }
        cout<< "( " << first << " " << last<< " )"<<endl;
    }
    void cycle(){
        for(int i=0;i<limit;i++){
            array[i].time -=2;
        }
        int i = 0;
            if(array[first].time <= 0)
            while(!isEmpty && array[i].time<=0 ){
                Task temp = this->dequeu();
                if(temp.time < 0)
                cout<<"Extra Time Needed for: "<<temp.task<<" => "  <<temp.time * -1<<endl;
                else cout<<"Time Needed :"<< temp.task<<" => "<<temp.time <<endl;
                
            }

    }
};


int main(){
    Queue QTask;
    QTask.enque("Google", 10);
    QTask.enque("VSCode", 5);
    QTask.enque("VLC", 6);
    QTask.enque("MS-Word", 4);
    QTask.enque("PDF", 8);
    QTask.enque("Jupyter", 10);
    QTask.enque("Pycharm", 10);

    QTask.displayArry();
    QTask.cycle();
    QTask.cycle();
    QTask.cycle();
    QTask.cycle();
    QTask.cycle();
    // QTask.displayArry();
    // while(!Qtask.isEmpty){
        // for(int i = 0; i<)
        // time[i] -= 2;
    // }


    return 0;
}