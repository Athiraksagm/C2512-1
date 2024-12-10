/*Basic Class Definition
Task: Define a class Animal with data members name and age. 
Create 3 objects of this class and print their details.*/

#include<iostream>
#include<string>
using namespace std;
class Animal{
       friend int main();
	public:
		string name;
		int age;
	public:
		void print();
		
	     };
int main(){
	Animal ani;
	ani.name="tinku";
	ani.age=22;
	ani.print();

       return 0;
}

void Animal::print(){
	cout <<name;
	cout <<age;
}
