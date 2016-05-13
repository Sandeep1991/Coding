//https://www.hackerrank.com/challenges/30-inheritance/

#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};
class Student :  public Person{
	private:
		vector<int> testScores; 
		//int testScores = (testtestScores[0] + testtestScores[1])/2; 
	public:
		char ch;
		int mean;// = (testScores[0] + testScores[1])/2;
		Student(string firstName, string lastName, int id, vector<int> testScores): Person(firstName, lastName, id)
		{	mean = 0;
			this->testScores = testScores;
            for(int i=0; i<this->testScores.size(); i++){
            	cout << testScores[i];
				mean = (mean+this->testScores[i]);
			}
			mean /= testScores.size();
			cout<<mean<<endl;
		} 
  		char calculate()
        {
            //int this->score=0;
            //this->score = (testScores[0] + testScores[1])/2;
            //char ch;
            if (mean >= 90) return ch = 'O';
            else if(mean>=80 && mean <90) return ch = 'E';
            else if(mean>=70 && mean <80) return ch = 'A';
            else if(mean>=55 && mean <70) return ch = 'P';
            else if(mean>=40 && mean <55) return ch = 'D';
            else return ch = 'T';
        }
};
int main() {
	string firstName;
  	string lastName;
	int id;
  	int numtestScores;
	cin >> firstName >> lastName >> id >> numtestScores;
  	vector<int> testScores;
  	for(int i = 0; i < numtestScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		testScores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, testScores);
	s->printPerson();
	cout << "Grade : " << s->calculate() << "\n";
	return 0;
}
