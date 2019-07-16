/*
In the app a person or set of persons can be removed and added dynamically and at will.
The add and remove must happen in O(1) if possible and there is no finite limit to the number of people 
that can be in the group.
*/

#include <bits/stdc++.h>

using namespace std;

struct Node{
	char val;
	Node *left, *right;
	Node(char val):val(val)
	{
		Node *left = NULL;
		Node *right = NULL;
	}
};

vector<Node*> construct_ll(vector<char>&vc,unordered_map<char,Node*>&um)
{
	Node* head = new Node(vc[0]);
	um[vc[0]] = head;
	Node* top = head;
	for (int i=1;i<vc.size();i++)
	{
		Node *present = new Node(vc[i]);
		um[vc[i]] = present;
		present->right = head->right;
		present->left = head;
		head->right = present;
		head = head->right;
	}
	return {top,head}; //head and tail nodes
	/*while (top!=NULL)
	{
		cout<<top->val<<" ";
		top = top->right;
	}
	cout<<endl;*/
	//cout<<um['c']->right->val;
}
void add_ll(char c,unordered_map<char,Node*>&um,vector<Node*>&vnodes)
{
	Node *new_node = new Node(c);
	um[c] = new_node;
	new_node->left = um[vnodes[1]->val];
	um[vnodes[1]->val]->right = new_node;
	vnodes[1] = new_node;
}
void remove_ll(char c, unordered_map<char,Node*>&um,vector<Node*>&vnodes)
{
	if (um[c]==vnodes[0])
		vnodes[0] = um[c]->right;
	if (um[c]==vnodes[1])
		vnodes[1] = um[c]->left;
	if (um[c]->right!=NULL)
		um[c]->right->left = um[c]->left;
	if (um[c]->left!=NULL)
		um[c]->left->right = um[c]->right;
}

int main() {
	// your code goes here
	vector<char>vc = {'a','b','c','d','e','f'};
	unordered_map<char,Node*>um;
	vector<Node*>vnodes = construct_ll(vc,um);
	remove_ll('a',um,vnodes);
	remove_ll('f',um,vnodes);
	add_ll('g',um,vnodes);
	add_ll('h',um,vnodes);
	add_ll('i',um,vnodes);
	remove_ll('i',um,vnodes);
	add_ll('a',um,vnodes);
	Node *top = vnodes[0];
	while (top!=NULL)
	{
		cout<<top->val<<" ";
		top = top->right;
	}
  //Output: b c d e g h a
	return 0;
}
