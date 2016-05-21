//https://www.hackerrank.com/challenges/tree-top-view/

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
    int i=0,j=0;
    vector<int>v;
    vector<int>r;
    //node *temp, *temp1; 
    node *temp = root;
    node *temp1 = root;
 while(temp != NULL)
 {
     v.push_back(temp->data);
     temp = temp->left;
    //i++;
 }
  while(temp1 != NULL)
  {
      r.push_back(temp1->data);
      temp1 = temp1->right;
      //j++;
  }
  for(int k=v.size()-1;k>=0;k--)
    cout<<v[k]<<" ";
  for(int l=1; l<r.size();l++)
    cout<<r[l]<<" ";
  cout<<endl;
}
