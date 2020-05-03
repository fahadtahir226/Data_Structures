#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *next;

	Node(){
		next = NULL;
	}
    Node(int d){
        data = d;
        next = NULL;
    }
};

class SLL{
    public:
    Node *head;
    Node *tail;
    int size;
    SLL(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void add_at_head(int d){
        Node *curr = new Node(d);
        if(head==NULL){
            head = curr;
            tail = curr;
        }
        else{
            curr->next = head;
            head = curr;
        }
        size++;
    }
    
    
    void add_at_tail(int d){
        Node *curr = head;
        if(head==NULL){
            head = new Node(d);
            tail = head;
        }
        else{
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node(d);
            tail = curr->next;
        }
        size++;
    }
    

    void display(){
        Node *curr = head;
        if(curr == NULL)  cout<< 0;
        while(curr !=NULL){
            cout << curr->data;
            if(curr->next != NULL){
                cout << " ";
            }
            curr = curr->next;
            
        }
        cout<< endl;
    }
    void doubleSize(){
        size = size * 2;
    }

};
class HashTable {
    int size, lamda;
    SLL table[100];
    public:
    HashTable(int size, int data[]){
        this->size = size;
        lamda = size;
        for(size_t j = 0; j < size; j++){
            table[ data[j] % size ].add_at_tail(data[j]);
            if(table[ data[j] % size ].size >= lamda ) lamda = lamda * 2;
        }
    }
    void Display(){
        for(size_t j = 0; j < size; j++){
            table[j].display();
        }
    }

};
void displayHashTable(SLL table[], int size){

}

int main () {
	int data[10] = { 39, 45, 67, 23, 12, 13, 15, 18, 19, 34 };
    HashTable myTable(10, data);
    myTable.Display();

    return 0;
}