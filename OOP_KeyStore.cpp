#include <bits/stdc++.h>
#include <unordered_map>

/*
General exploration and implementation of class to store all details of the keys in a 
collection.
Things explored 
friend function
operator overloading
enum to string conversion function
*/

using namespace std;

/*
KeyContainer{
	key_id   :
	key_type : SSH-public, Access, RADIUS, PSK etc;
	key_path :
}
*/
enum KeyType{ 
	SSHpublic=1,
	Access=2,
	RADIUS=3,
	PSK=4,
	END
};

KeyType Convert(string& str)
{
	if (str=="SSHpublic") return SSHpublic;
	else if(str=="Access") return Access;
	else if(str=="RADIUS") return RADIUS;
	else if(str=="PSK") return PSK;
	else return END;
}
//unordered_map<int,int>CollectionKeys;
class KeyContainer{
	//const int countTypes = END-SSHpublic;
	unordered_map<int,vector<string> >IDPathCollection;
	unordered_map<int,int>CollectionKeys;
	
public:
	void NoKeys(int type);
	int GenKey(vector<string>&vecKey);
	void AddKeys(vector<string>vecKey);
	void PrintKeys();
	friend ostream& operator<<(ostream os, const vector<string>&vs);
};

ostream& operator<<(ostream &os, const vector<string>&vs)
{
	os<<vs[0]<<" "<<vs[1];
	return os;
}
void KeyContainer::NoKeys(int type)
{
	//int tp = type;
	CollectionKeys[type] = CollectionKeys[type] + 1;
}
int KeyContainer::GenKey(vector<string>&vecKey)
{
	KeyType type = /*SSHpublic;//*/Convert(vecKey[0]);
	int numb = type * 100;
	numb += CollectionKeys[type] + 1;
	return numb;
}
void KeyContainer::AddKeys(vector<string>vecKey)
{
	int keyId = GenKey(vecKey);
	IDPathCollection[keyId] = vecKey;
	KeyType kt = Convert(vecKey[0]);
	NoKeys(kt);
}
void KeyContainer::PrintKeys()
{
	unordered_map<int,vector<string> >::iterator uit;
	for (uit=IDPathCollection.begin();uit!=IDPathCollection.end();uit++)
		cout<<uit->first<<" "<<uit->second<<endl;
}
int main()
{
	KeyContainer KC;
	KC.AddKeys({"SSHpublic","this/is/path"});
	KC.AddKeys({"Access","different/path"});
	KC.AddKeys({"Access","different/path/123"});
	KC.AddKeys({"RADIUS","RAD/this/is/a/path"});
	KC.AddKeys({"PSK","hostapd/this/is/another/path"});
	KC.AddKeys({"SSHpublic","this/is/ssh/path"});
	KC.PrintKeys();
	return 0;
}
