#include<iostream>
using namespace std; 
struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
   
Node* insertLevelOrder(int arr[], Node* root,int i, int n) 
{ 
    if (i < n) 
    { 
    Node* temp = newNode(arr[i]); 
    root = temp; 
    root->left = insertLevelOrder(arr,root->left, 2 * i + 1, n); 
    root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n); 
    } 
    return root; 
} 
void printGivenLevel(Node* root, int level)  
{  
    if (root == NULL)  
    return;  
    if (level == 1)  
    cout << root->data << " ";  
    else if (level > 1)  
    {  
    printGivenLevel(root->left, level-1);  
    printGivenLevel(root->right, level-1);  
    }  
} 
int height(Node* node)  
{  
    if (node == NULL)  
    return 0;  
    else
    {  
    int lheight = height(node->left);  
    int rheight = height(node->right);  
    if (lheight > rheight)  
    return(lheight + 1);  
    else return(rheight + 1);  
    }  
}  
 void printLevelOrder(Node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
    printGivenLevel(root, i);  
}  
  
 
int countNonleaf(Node* root) 
{ 

    if (root == NULL || (root->left == NULL &&  root->right == NULL)) 
    return 0; 
  
    return 1 + countNonleaf(root->left) +  countNonleaf(root->right); 
} 
  
int countleaf(Node* root)  
{  
    if(root == NULL)      
    return 0;  
    if(root->left == NULL && root->right == NULL)  
    return 1;          
    else
    return countleaf(root->left)+  
    countleaf(root->right);  
} 
void findParent(Node* node,int val, int parent) 
{ 
    if (node == NULL) 
    return;  
    if (node->data == val) { 
  cout << parent; 
    } 
    else { 
    findParent(node->left, val, node->data);
    findParent(node->right, val, node->data); 
    } 
}  
int main() 
{ 
    int arr[] = {13,45,65,76,87,78,98,33,34,36,12,14,54,65,70, 90,99 };
    int n = sizeof(arr)/sizeof(arr[0]); 
    int p=1;
    int m[]={12,14,99};
    cout<<"Traverse the complete binary tree using breadth first search:"<<endl;
    Node* root = insertLevelOrder(arr, root, 0, n); 
    printLevelOrder(root);  
   cout<<endl<<endl<<"full nodes:";
   cout<<countNonleaf(root)-1;
   cout<<endl<<"leaf nodes:";
   cout<<countleaf(root)-1;
   cout<<endl<<"Either nodes:";
   cout<<p;
   cout<<endl<<"parent node of 12 is:";
    int node = 12; 
    findParent(root, node, -1);
    cout<<endl<<"parent node of 70 is:";
    node = 70; 
    findParent(root, node, -1);
    cout<<endl;
}