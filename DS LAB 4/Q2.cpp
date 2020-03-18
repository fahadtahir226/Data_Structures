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
    
    void deleteNode(int d){
    	Node *curr = head;
    	if(head != NULL){
    		
    		while(curr->next->data != d){
    			curr = curr->next;
			}
    		Node *temp = curr->next;
    		curr->next = curr->next->next;
    		
    		delete temp;
    		temp = 0;
    		size--;
		}
	}
	void deletehead(){
		Node *curr=head;
		head = head->next;
		delete curr;
		curr = 0;
		size--;
	}
		
	void swapNodes(Node *curr){
		Node *temp = curr->next;
		curr->next = curr->next->next;
		temp->next = curr->next->next;
		curr->next->next = temp;
	}
	
	void bubblesort(){
		Node *curr = head;
		if(head!=NULL){
			this->add_at_head(0);	
			if(head->data > head->next->data){
				this->swapNodes(head);
			}
			while(curr->next->next != NULL){
				if(curr->next->data > curr->next->next->data){
					this->swapNodes(curr);
					curr = head;
				}
				else{
					curr = curr->next;
				}
			}
			this->deletehead();
		}
	}
	
	void search(int d){
		Node *curr = head;
		int i = 1;
    	if(head != NULL){
    		if(head->data == d){
				cout<< "Data Found At Head at Index 0 - Data: " <<curr->next->data;	
			}
			else{
	    		while(curr->next->data != d){
	    			++i;
    				curr = curr->next;
				}
				cout<< "Data Found At Index: " << i << " - Data: " <<curr->next->data;
			}
		}
	}

    void display(){
        Node *curr = head;
        while(curr !=NULL){
            cout << curr->data;
            if(curr->next != NULL){
                cout << " - > ";
            }
            curr = curr->next;
            
        }
        cout<< endl;
    }

};

int main () {
	
    SLL mylist;
//    mylist.add_at_head(2);
//    mylist.add_at_head(3);
//    mylist.add_at_head(5);
//    mylist.add_at_head(7);
//    mylist.add_at_head(8);
//    mylist.add_at_head(9);
    
    mylist.add_at_tail(7);
    mylist.add_at_tail(12);
    mylist.add_at_tail(10);
    mylist.add_at_tail(5);
    mylist.add_at_tail(4);
    mylist.add_at_tail(1);
    mylist.add_at_tail(6);
   
    mylist.display();
    
//    mylist.deleteNode(7);
//    mylist.display();

//	mylist.movOddRight();
//	mylist.display();


//	mylist.swapNodes(mylist.head->next);


	mylist.bubblesort();
	mylist.display();

    return 0;
}
 
