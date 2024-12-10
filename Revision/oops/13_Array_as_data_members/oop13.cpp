/*
Task: Create a class Student with an array of marks as a data member.
Write functions to calculate the average marks. 

*/
#include<iostream>
using namespace std;
class student{
	private:
		int mark[5];
	public:
                student(int n){
			cout << "enter your marks of 5 students"<<endl;
			for(int i=0;i<n;i++)
			{
				cin >> mark[i];
			}
		}
		int averagemarks(){
		        int average=0;
			for(int i=0;i<5;i++)
			{
				average += mark[i];
			}
			return average;
		}
		void print(){
			cout <<"The average marks of 5 students is: " << averagemarks() << endl;
		}
	};

int main(){
	student s1(5);
        s1.print();
	return 0;
}	
