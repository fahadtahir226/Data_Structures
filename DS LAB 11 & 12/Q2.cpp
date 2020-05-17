#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
    public: 
    int data; 
    node* left; 
    node* right; 
}; 

bool isFullTree ( node* root) 
{ 
    
    if (root == NULL) 
        return true; 
   
    // If leaf node 
    if (root->left == NULL && root->right == NULL) 
        return true; 
   
    // If both left and right are not NULL, and left & right subtrees 
    // are full 
    if ((root->left) && (root->right)) 
        return (isFullTree(root->left) && isFullTree(root->right)); 
   
    // We reach here when none of the above if conditions work 
    return false; 
} 
   



bool isCompleteBT(node* root) 
{ 

    if (root == NULL) 
        return true; 
 
    queue<node *> q; 
    q.push(root); 

    bool flag = false; 

    while(!q.empty()) 
    { 
        node *temp =q.front(); 
        q.pop(); 
  
        /* Check if left child is present*/
        if(temp->left) 
        { 

        if (flag == true) 
            return false; 
  
        q.push(temp->left);// Enqueue Left Child 
        } 
        else // If this a non-full node, set the flag as true 
        flag = true; 
  
        /* Check if right child is present*/
        if(temp->right) 
        { 

        if(flag == true) 
            return false; 
  
        q.push(temp->right); // Enqueue Right Child 
        } 
        else // If this a non-full node, set the flag as true 
        flag = true; 
    } 

    return true; 
} 

node* newNode(int data) 
{ 
    node* Node = new node(); 
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
  
    return(Node); 
} 



int findADepth(node *node) 
{ 
   int d = 0; 
   while (node != NULL) 
   { 
      d++; 
      node = node->left; 
   } 
   return d; 
} 

bool isPerfectRec(node* root, int d, int level = 0) 
{ 
    // An empty tree is perfect 
    if (root == NULL) 
        return true; 

    if (root->left == NULL && root->right == NULL) 
        return (d == level+1); 
  
    // If internal node and one child is empty 
    if (root->left == NULL || root->right == NULL) 
        return false; 

    return isPerfectRec(root->left, d, level+1) && 
           isPerfectRec(root->right, d, level+1); 
} 
  
bool isPerfect(node *root) 
{ 
   int d = findADepth(root); 
   return isPerfectRec(root, d); 
} 



void cBT(){
	node *root = newNode(1); 
    root->left     = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
  
    if ( isCompleteBT(root) == true ) 
        cout << "Complete Binary Tree\n"; 
    else
        cout << "NOT Complete Binary Tree\n"; 
}

void fBT(){
	node *root = newNode(1); 
    root->left     = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    
     if (isFullTree(root)) 
        cout << "The Binary Tree is full\n"; 
    else
        cout << "The Binary Tree is not full\n"; 
   
}



void pBT(){
	node *root = newNode(1); 
    root->left     = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    
    if (isPerfect(root)) 
        printf("The Binary Tree is perfect\n"); 
    else
        printf("The Binary Tree is not perfect\n\n"); 
	
}



int main() 
{ 
   cBT();
   fBT();
   pBT();
    
  
    return 0; 
}