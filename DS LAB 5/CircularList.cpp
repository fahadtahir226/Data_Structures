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

class CircularList{
    public:
    Node *head;
    Node *tail;
    int size;
    CircularList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add_at_head(int d){
        Node *curr = new Node(d);
        if(head==NULL){
            head = curr;
            tail = curr;
            head->next = tail;
            tail->next = head;
        }
        else{
            curr->next = head;
            head = curr;
            tail->next = head;
        }
        size++;
    }
    
    
    void add_at_tail(int d){
        Node *curr = head;
        if(head==NULL){
            head = new Node(d);
            tail = head;
            head->next = tail;
            tail->next = head;
        }
        else{
            while(curr->next != head){
                curr = curr->next;
            }
            curr->next = new Node(d);
            tail = curr->next;
            tail->next = head;
        }
        size++;
    }
    void add_accending(int d){
        Node *curr = head;
        if(head==NULL){
            head = new Node(d);
            head->next = head;
            tail = head;
            tail->next = head;
        }
        else{
            while(curr->next != head && curr->next->data < d){
                curr = curr->next;
            };
            Node *temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
            if(temp->next == head){
                tail = temp;
            }
            
        }
        size++;

    }
    
    void deleteNode(int d){
    	Node *curr = head, *temp = NULL;
    	if(head != NULL){
    		
    		if(head->data == d){
    			temp = head;
    			head = head->next;
    			tail->next = head; 
	    		delete temp;
	    		temp = 0;
			}
    		else{
    			while(curr->next->data != d){
    				curr = curr->next;
				}
    			temp = curr->next;
    			curr->next = curr->next->next;
    			if(curr->next == head){
    				tail = curr;
				}
    			delete temp;
    			temp = 0;
			}
    		
    		size--;
		}
	}

	
	
	void search(int d){
		Node *curr = head;
		int i = 1;
    	if(head != NULL){
    		if(head->data == d){
				cout<< " Data: " <<curr->next->data;	
			}
			else{
	    		while(curr->next->data != d){
	    			++i;
    				curr = curr->next;
				}
				cout<< "Found it!!! Index: " << i << " - Data: " <<curr->next->data;
			}
		}
	}

    void display(){
        Node *curr = head;
        do{
            cout << curr->data;
            if(curr != tail){
                cout << " -> ";
            }
            curr = curr->next;
            
        }while(curr!=head);
        cout<< endl;
    }

	void delete_Odd(){
		Node *curr = head, *temp = NULL;
		
		while(curr->next != head){
			if(curr->data % 2 != 0 ) {	
				this->deleteNode(curr->data);
				curr = head;
			}
			curr = curr->next;
		}
	}



};




int main () {
	
    CircularList circularLinkedList;
    circularLinkedList.add_at_tail(572);
    circularLinkedList.add_at_tail(112);
    circularLinkedList.add_at_tail(21);
    circularLinkedList.add_at_tail(5);
    circularLinkedList.add_at_tail(1);
    circularLinkedList.add_at_tail(6);
    circularLinkedList.display();
    circularLinkedList.delete_Odd();
    circularLinkedList.display();


    return 0;
}
 
