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

class CLL{
    public:
    Node *head;
    Node *tail;
    int size;
    CLL(){
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
    void add_default(int d){
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
        do{
            cout << curr->data;
            if(curr->next != head){
                cout << " - > ";
            }
            curr = curr->next;
            
        }while(curr!=head);
        cout<< endl;
    }

};

int main () {
	
    CLL mylist;
//    mylist.add_at_head(2);
//    mylist.add_at_head(3);
//    mylist.add_at_head(5);
//    mylist.add_at_head(7);
//    mylist.add_at_head(8);
//    mylist.add_at_head(9);


    mylist.add_at_tail(3);
    mylist.add_at_tail(7);
    mylist.add_at_tail(9);
    mylist.add_at_tail(11);
   



    mylist.display();
    mylist.add_default(19);


//    mylist.deleteNode(7);
   mylist.display();
    cout<<endl<< "If inserted at tail New Tail : "<< mylist.tail->data<< " - Head : "<< mylist.tail->next->data << endl;

    return 0;
}
 
