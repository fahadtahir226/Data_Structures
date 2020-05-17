#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node *left, *right;
  Node(){
    data = 0;
    left = 0;
    right = 0;
  }
  Node(int d,Node* l,Node* r){
    data = d;
    left = l;
    right = r;
  }
};

class BST {
  public:
  Node *root;
  int size;
  BST(){
    root = 0;
    size = 0;
  }
  void insertion(int data, Node *currNode){
    if(currNode == 0) {
        root = new Node(data,0,0);
        size++;
        return;
    }
    else{
      if(currNode->data >= data ) {
        if(currNode->left == 0) {
          currNode->left = new Node(data,0,0);
          size++;
        }
        else insertion(data,currNode->left);
        return;
      }
      if(currNode->data < data) {
        if(currNode->right == 0) {
          currNode->right = new Node(data,0,0);
          size++;
        }
        else insertion(data,currNode->right);
        return;
      }
    }
  }
  void inorder(Node *currNode){
    if(currNode == 0) {
      cout<< " Tree is Empty "<< endl;
      return;
    }
    else{
      if(currNode->left != 0){
        inorder(currNode->left);
      }
      cout<< currNode->data << " - ";
      if(currNode->right != 0){
        inorder(currNode->right);
      }

    }
  }
  void preorder(Node *currNode){
    if(currNode == 0) {
      cout<< " Tree is Empty "<< endl;
      return;
    }
    else{
      cout<< currNode->data << " - ";
      if(currNode->left != 0){
        inorder(currNode->left);
      }
      if(currNode->right != 0){
        inorder(currNode->right);
      }

    }
  }
    void postorder(Node *currNode){
    if(currNode == 0) {
      cout<< " Tree is Empty "<< endl;
      return;
    }
    else{
      if(currNode->left != 0){
        inorder(currNode->left);
      }
      if(currNode->right != 0){
        inorder(currNode->right);
      }
      cout<< currNode->data << " - ";
    }
  }
};

int main(){
  BST myTree;
  myTree.insertion(13, myTree.root);
  myTree.insertion(45, myTree.root);
  myTree.insertion(65, myTree.root);
  myTree.insertion(76, myTree.root);
  myTree.insertion(87, myTree.root);
  myTree.insertion(78, myTree.root);
  myTree.insertion(98, myTree.root);
  myTree.insertion(33, myTree.root);
  myTree.insertion(34, myTree.root);
  myTree.insertion(36, myTree.root);
  myTree.insertion(12, myTree.root);
  myTree.insertion(14, myTree.root);
  myTree.insertion(54, myTree.root);
  myTree.insertion(65, myTree.root);
  myTree.insertion(70, myTree.root); 
  myTree.insertion(90, myTree.root);
  myTree.insertion(99, myTree.root); 
  cout<<"In order: "<<endl;
  myTree.inorder(myTree.root); 
  cout<<endl;
  cout<<"Post order: "<<endl;
  myTree.postorder(myTree.root); 
  cout<<endl;
  cout<<"Pre order: "<<endl;
  myTree.preorder(myTree.root); 
  cout<<endl;
  // cout<< myTree.size<<endl << myTree.root->data;
return 0;
}