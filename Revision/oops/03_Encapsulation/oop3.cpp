/*Encapsulation with Getter/Setter
Task: Implement a class Student with private 
members name and marks. Use getter and setter
 functions for data manipulation.*/

#include<iostream>
#include<string>
using namespace std;

class Student{
	private:
		string name;
		int marks;
	public:
		void setName(string newName);
		void setMarks(int newMarks);
		string getName();
		int getMarks();
};
void Student::setName(string newName){
	name=newName;
}
void Student::setMarks(int newMarks){
         if(newMarks>=0){
        	marks=newMarks;
	 }
	 else{
		 cout <<"invalid marks ";
}
}
string Student::getName(){
	return name;
}
int Student::getMarks(){
	return marks;
}
int main()
{
	Student std1;
	std1.setName("Abel");
        std1.setMarks(22);
	cout << std1.getName()<<endl;
	cout << std1.getMarks();
         return 0;
}

