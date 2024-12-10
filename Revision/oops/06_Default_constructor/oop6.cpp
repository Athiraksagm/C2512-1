/*Task: Create a class Rectangle with default and parameterized
 *  constructors to initialize length and breadth. Add a function
 *   to calculate the area.*/

#include<iostream>
using namespace std;
class Rectangle{
	private:
		int length;
		int breadth;
	public:
		Rectangle();
		Rectangle(int p_length , int p_breadth);
		int area();
};
Rectangle::Rectangle(int p_length,int p_breadth){
     length = p_length;
     breadth = p_breadth;
}
int Rectangle::area(){
	return (length*breadth);


}
Rectangle::Rectangle(){
	length=0;
	breadth=0;
}
int main(){
	Rectangle rect1;
	cout << "Area: " << rect1.area();
	
	Rectangle rect(11 , 10);
	cout << "Area: " << rect.area();
	return 0;
}

