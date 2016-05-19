#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node * next;
};

node* head;
void insert(int data)
{
	node* temp1 = new node;
	temp1->data = data;
	temp1->next = head;
	head = temp1;
}

void print()
{
	node* temp1 = head;
	while(temp1 != NULL)
	{
		cout<<" "<<temp1->data;
		temp1 = temp1->next;
	}
	cout<<endl;
} 
	
int main()
{
	head = NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(5);
	print();
}	
	
