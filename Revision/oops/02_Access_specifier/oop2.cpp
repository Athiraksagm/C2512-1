/*Access Specifiers
Task: Create a class Person with private data 
members name and age. Use public member functions
 to set and get their values.*/

#include<iostream>
#include<string>
using namespace std;

class Person{
	private:
		string name;
		int age;
	public:
		void setName(string newName);
		void setAge(int newAge);
		string getName();
		int getAge();
};
void Person::setName(string newName){
	name=newName;
}
void Person::setAge(int newAge){
         if(newAge>=0){
        	age=newAge;
	 }
	 else{
		 cout <<"invalid age ";
}
}
string Person::getName(){
	return name;
}
int Person::getAge(){
	return age;
}
int main()
{
	Person man1;
	man1.setName("Abel");
        man1.setAge(22);
	cout << man1.getName()<<endl;
	cout << man1.getAge();
         return 0;
}

