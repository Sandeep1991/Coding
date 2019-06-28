#include <bits/stdc++.h>

/*
Constraints:
1. Can use Dynamic array - No STLs
2. Use hash function for the index - hash function can be used, but I have written a simple function that does that
3. Maintain a LL for the hash index
4. Return a value for that key Ariz = Calif same key

TC
Depends on the collision of the hashes. So it will take time to traverse the list. 
If range is very long and the collisions are rare then we can insert and find key in O(1)
It can be approximated as k*O(1) because of LL involved.
*/
using namespace std;
struct Node{
	char *key;
	char *value;
	Node(const char *rkey, const char *rval)
	{
		key = new char[strlen(rkey)];
		value = new char[strlen(rval)];
		strcpy(key,rkey);
		strcpy(value,rval);
	}
	Node *next;
};
struct Hashtable{
	Hashtable(int range):range(range)
    {
      //malloc(hash_array,range*sizeof(int));
      hash_array = new Node*[range];
      for (int i=0;i<range;i++)
    	  hash_array[i] = NULL;
    }

    ~Hashtable()
    {
      for (int i=0;i<range;i++)
    	  delete (Node*)hash_array[i];
    }

	int hash(const char* key){
		return (key[0]-'a');
	}
	void insert(const char *key, void *val)
    {
      int index = (hash(key))%range; 
      const char *cval = (char*)val;
      if (hash_array[index]==NULL)
      {
        Node *temp = new Node(key,cval);
        temp->next = NULL;
        hash_array[index] = temp;
      }
      else
      {
        Node *temp = new Node(key,cval);
        Node *head = hash_array[index];
        temp->next = head;
        hash_array[index] = temp;
      }
    }

    // Find the given key in the table. If it does not exist return NULL.
    void *find(const char *key)
    {
      int index = (hash(key))%range;
      Node *temp = hash_array[index];
      while (temp!=NULL)
      {
      	if (strcmp(temp->key,key)==0)
      	{
      		return temp->value;
      	}
      	temp = temp->next;
      }
      return NULL;
    }
private:
    // Put private class members here
    int range;
    Node** hash_array;
};
int main() {
	// your code goes here
	//Node n1("apple","good");
	//cout<<n1.key<<" "<<n1.value<<endl;
	Hashtable h(26);
	h.insert("apple",(void*)"good");
	h.insert("apricot",(void*)"fiber");
	h.insert("almond",(void*)"zinc");
	h.insert("banana",(void*)"potassium");
	h.insert("butter fruit",(void*)"fat");
	//h.insert("apple",(void*)"healthy");
	cout<<(char*)h.find("apple")<<endl;
	cout<<(char*)h.find("apricot")<<endl;
	cout<<(char*)h.find("almond")<<endl;
	cout<<(char*)h.find("banana")<<endl;
	//cout<<(char*)h.find("watermelon")<<endl;
	cout<<(char*)h.find("butter fruit")<<endl;
	return 0;
}
