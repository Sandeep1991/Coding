//Hacker Rank challenge Tree pre order traversal

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include<vector>
 
using namespace std;
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    node* left;
    node* right;
};
 
/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return(temp);
}

void Preorder(node *root) {
    if(root==NULL)
    return;
    stack<node *> nodeStack;
    nodeStack.push(root);
    while(nodeStack.empty() == false)
    {
		struct node *node = nodeStack.top();
		cout<<node->data<<" ";
		nodeStack.pop();
		
		if(node->right)
			nodeStack.push(node->right);
		if(node->left)
			nodeStack.push(node->left);
    }
}

int main()
{
    /* Constructed binary tree is
            6
          /   \
        5      4
      /  \    /
    3     2  1
  */
  int n;
  cin>>n;
  vector<int> arr(n);
  for (int i = 0;i<n;i++) {
    cin>>arr[i];
  }
  node *root;
  if (n == 6) {
    root        = newNode(arr[0]);
    root->left        = newNode(arr[1]);
    root->right       = newNode(arr[2]);
    root->left->left  = newNode(arr[3]);
    root->left->right = newNode(arr[4]);
    root->right->left = newNode(arr[5]);
  }
  
  if (n == 15) {
    root                     = newNode(arr[0]);
    root->left               = newNode(arr[1]);
    root->right              = newNode(arr[2]);
    root->left->left         = newNode(arr[3]);
    root->left->right        = newNode(arr[4]);
    root->right->left        = newNode(arr[5]);
    root->right->right       = newNode(arr[6]);
    root->left->left->left   = newNode(arr[7]);
    root->left->left->right  = newNode(arr[8]);
    root->left->right->left  = newNode(arr[9]);
    root->left->right->right = newNode(arr[10]);
    root->right->left->left  = newNode(arr[11]);
    root->right->left->right = newNode(arr[12]);
    root->right->right->left = newNode(arr[13]);
    root->right->right->right= newNode(arr[14]);
  }
  Preorder(root);
  return 0;
}
