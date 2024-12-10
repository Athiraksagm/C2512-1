/*Overloading Functions
Task: Write a class Calculator that overloads the function
add to handle addition of two integers, two double, and two strings.*/

#include<iostream>
#include<string>
using namespace std;
class Calculator
{
	public:
		string add(string s1, string s2);
		int add(int n1 , int n2);
		double add(double f1 , double f2);
};


int main(){
Calculator calc;

cout << calc.add("ab","el") << endl;
cout << calc.add(2,3) << endl;
cout << calc.add(1.73,2.54) << endl;
}
 string Calculator::add(string s1 , string s2){
	 return (s1+s2);
 }

 int Calculator::add(int n1 , int n2){
	 return (n1+n2);
 }

 double Calculator::add(double f1 , double f2){
	 return (f1+f2);
 }


