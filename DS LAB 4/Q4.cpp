#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *next, *prev;

	Node(){
		next = NULL;
        prev = NULL;
	}
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
    public:
    Node *head, *tail;
    int size;
    DLL(){
        head = NULL;
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
        }
        else{
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = new Node(d);
            curr->next->prev = curr;
            tail = curr->next;
        }
        size++;
    }
    
    void deleteNode(int d){
    	Node *curr = head;
    	if(head != NULL){
    		
    		while(curr->next->data != d){
    			curr = curr->next;
			}
    		Node *temp = curr->next;
            if(curr->next == tail){
                tail = curr;
            }
    		curr->next = curr->next->next;
    		
    		delete temp;
    		temp = 0;
    		size--;
		}
	}	

    void pairOfsumN(int k){
        Node *ptrH = head, *ptrT = tail;
        while(ptrH != ptrT){
            if(ptrH->data + ptrT->data == k) {
                cout << "( " << ptrH->data << " , " << ptrT->data << " )" <<endl;
                ptrT = ptrT->prev;
                if(ptrT == ptrH) return;
                ptrH = ptrH->next;
                }
            else if(ptrH->data + ptrT->data > k) ptrT = ptrT->prev;
            else ptrH = ptrH->next;
        }
    }
	
    void display(){
        Node *curr = head;
        while(curr !=NULL){
            cout << curr->data;
            if(curr->next != NULL){
                cout << " < - > ";
            }
            curr = curr->next;
            
        }
        cout<< endl;
    }

};

int main () {
	
    DLL mylist;
//    mylist.add_at_head(2);
//    mylist.add_at_head(3);
//    mylist.add_at_head(5);
//    mylist.add_at_head(7);
//    mylist.add_at_head(8);
//    mylist.add_at_head(9);
    
    mylist.add_at_tail(1);
    mylist.add_at_tail(2);
    mylist.add_at_tail(4);
    mylist.add_at_tail(5);
    mylist.add_at_tail(6);
    mylist.add_at_tail(8);
    mylist.add_at_tail(9);
   
    mylist.display();
    
    mylist.pairOfsumN(6);


    return 0;
}
 
