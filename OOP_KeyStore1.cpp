#include <bits/stdc++.h>
#include <unordered_map>
#include <fstream>

using namespace std;

/*
Separating concerns namely KeyStore collection from the IOObject
Exploring the filestreams - ifstream and ofstream
Splitting the string based on stringstream and output it in json format.
*/

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
public:
	unordered_map<int,vector<string> >IDPathCollection;
	unordered_map<int,int>CollectionKeys;
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

class IOObject{
	ofstream outfile;
	ifstream infile;
public:
	int WriteFile(KeyContainer &KC, string file);
	int ReadFileJson(KeyContainer &KC, string file);

};

int IOObject::WriteFile(KeyContainer &KC, string file)
{
	outfile.open(file);
	//outfile<<"This works!"<<endl;
	unordered_map<int,vector<string> >::iterator uit;
	for (uit=KC.IDPathCollection.begin();uit!=KC.IDPathCollection.end();uit++)
		outfile<<uit->first<<" "<<uit->second<<endl;
	outfile.close();
	return 0;
}
int IOObject::ReadFileJson(KeyContainer &KC, string file)
{
	int noKeys = KC.IDPathCollection.size();
	infile.open(file,ios::in);
	if (!infile)
	{
		cerr<<"Can't open input file"<<endl;
		return -1;
	}
	int cnt = 0;
	cout<<"KeyStore"<<endl;
	cout<<"{"<<endl;
	string line;
	string token;
	while (getline(infile, line))
	{
		cnt++;
		cout<<" {"<<endl;
		stringstream ss(line);
		int i=0;
		while (ss>>token)
		{
			if (i==0)
				cout<<"  keyId: ";
			if (i==1)
				cout<<"  keyType: ";
			if (i==2)
				cout<<"  keyPath: ";
			cout<<token<<","<<endl;	
			i++;
		}
		cout<<" }";
		if (cnt!=noKeys)
			cout<<","<<endl;
		else
			cout<<endl;
	}
	cout<<"}"<<endl;
	infile.close();
	return 0;
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
	IOObject IO;
	IO.WriteFile(KC, "ooptest.txt");
	IO.ReadFileJson(KC, "ooptest.txt");
	return 0;
}
