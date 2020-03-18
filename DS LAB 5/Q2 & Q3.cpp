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

class SinglyList{
    public:
    Node *head;
    Node *tail;
    int size;
    SinglyList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add_at_head(int d){
        Node *current = new Node(d);
        if(head==NULL){
            head = current;
            tail = current;
        }
        else{
            current->next = head;
            head = current;
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
//            while(curr->next != NULL){
//                curr = curr->next;
//            }
            tail->next = new Node(d);
            tail->next = tail->next;
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
	void movOddRight(){
		Node *curr = head, *temp;
		for(int i=0; i < size ; i++){
			temp = curr->next;
            
			if(curr->data % 2 != 0){

				this->add_at_tail(curr->data);
				this->deleteNode(curr->data);
			}
			curr = temp;
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
    void treverse(Node *curr){
    	if(curr != NULL){    		
			cout<< curr->data;
			if(curr->next != NULL){
                cout << " - > ";
        	}
			treverse(curr->next);
		}
	}
	void reverse(Node *curr){
    	if(curr != NULL){    		
			reverse(curr->next);
			cout<< curr->data;
			if(curr->next != head){
                cout << " - > ";
        	}
		}
	}


};

int main () {
	
    SinglyList list;

    
    list.add_at_tail(17);
    list.add_at_tail(15);
    list.add_at_tail(8);
    list.add_at_tail(12);
    list.add_at_tail(10);
    list.add_at_tail(5);
    list.add_at_tail(4);
    list.add_at_tail(1);
    list.add_at_tail(7);
    list.add_at_tail(6);
//    list.display();
    list.treverse(list.head);
    cout<<endl;
    list.reverse(list.head);

//	list.movOddRight();
//	list.display();


    return 0;
}
 
