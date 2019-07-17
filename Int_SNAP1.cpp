/*
This is another ingenious way of creating the graph when multiple children exists i.e. not a typical binary tree.
Alternatively adj way works as well. But for others reviewing the code this might seem easy to parse. Useful especially
when working with codepair.
In an intuitive way we can parse multidimensional input vector to corresponding parent child tree relationship
Keeping a parent pointer is much helpful to iterate the tree.
Keeping unordered_map helps in locating any node to respective value in O(1)
*/
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Node{
	struct Node* parent;
	char c;
	Node(char c):c(c){
		struct Node* parent = NULL;
	}
	vector<Node*>children;
};

bool same_chain(struct Node* source, struct Node* target, unordered_map<char,Node*>&um)
{
	if (source==NULL)
		return false;
	if (source==target)
		return true;
	same_chain(um[source->c]->parent,target,um);
}


int main() {
	// your code goes here
	unordered_map<char,Node*>um;
	vector<vector<char>>adj = {{'A','B','C','X','Y','Z'},{'B','D','E'},{'C','F','G'}};
	for (auto x:adj)
	{
		if (!um[x[0]])
		{
			um[x[0]] = new Node(x[0]);
		}
		for (int i=1;i<x.size();i++)
		{
			if (!um[x[i]])
			{
				um[x[i]] = new Node(x[i]);
				um[x[i]]->parent = um[x[0]];
			}
			um[x[0]]->children.push_back(um[x[i]]);
		}
	}
	for (auto x:um['A']->children)
		cout<<x->c<<" ";
	cout<<endl;
	cout<<um['X']->parent->c<<endl;
	same_chain(um['D'],um['A'],um) == 1 ? cout<<"same chain\n" : cout<<"different chain\n";
	return 0;
}
