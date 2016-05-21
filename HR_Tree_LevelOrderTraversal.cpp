#include<list>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
  list<node*> nodes;
  if(root) nodes.push_back(root);
  for(list<node*>::iterator it = nodes.begin(); it!=nodes.end();it++)
  {
      cout<<(*it)->data<<" ";
      if((*it)->left){
          nodes.push_back((*it)->left);
      }
      if((*it)->right){
          nodes.push_back((*it)->right);
      }
  }
  
}
