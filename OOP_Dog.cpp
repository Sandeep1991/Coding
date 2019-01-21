#include <bits/stdc++.h>

using namespace std;

/*
@MagicWish
01/20/2019

Heap allocation of object
Constructor initializer list
Shallow copy of objects
Inheritance
Polymorphism - Virtual function 
*/

typedef long long ll;

class Dog{
    int size;
    string breed;
public:
    Dog(int num=10, string sstr="Labrador"):size(num),breed(sstr){}
    void printDog();
    virtual void barks();
};
void Dog::printDog()
{
    cout<<size<<" "<<breed<<endl;
}
void Dog::barks()
{
    if (size==1)
    cout<<"bow ..."<<endl;
    if (size>=10)
    cout<<"woof ..."<<endl;
}

class Pamarion:public Dog{
public:
    void barks() override
    {
        cout<<"bowww ...."<<endl;
    }
};

int main()
{
    Dog *d1 = new Dog;
    //d1->size = 10;
    //d1->breed = "Labrador";
    d1->printDog();
    d1->barks();
    Dog *d2 = new Dog(1, "Golden Ret");
    d2->printDog();
    d2->barks();
    Dog *d3 = d2;
    d3->printDog();
    Pamarion *d4 = new Pamarion();
    d4->barks();
    delete(d1);
    delete(d2);
    delete(d4);
    //delete(d3);
    return 0;
}
