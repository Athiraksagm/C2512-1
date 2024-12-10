/*Static Members
Task: Write a class Counter with a static member to count
the number of objects created.

Static Functions
Task: Add a static function to Counter that returns the count
of objects created. */

#include<iostream>
using namespace std;
class counter{
	private:
		static int count;
	public:
		counter(){
			count++;
		}
	static int getcount(){
		return count;
	}
};
int counter::count=0;
int main(){
	counter c1 , c2;
	cout << "count: "<< counter::getcount() << endl;

	return 0;
}

