/*Friend Class
Task: Write two classes A and B, where B is declared
as a friend of A. Allow B to access private members of A.*/
#include <iostream>
using namespace std;
class volume;
class box
{
	friend class volume;

	private:
		int length;
		int breadth;
		int height;
	public:
	        box(int l,int b,int h){
			length=l;
			breadth=b;
			height=h;
		}
		
};
class volume{
	public:
       int findvolume(const box& b){
         	return (b.length*b.breadth*b.height);
}
	void print(const box& b);
	};
void volume::print(const box& b){
	cout <<"Volume of the box: "<<findvolume(b);
}

int main(){
	box b1(12,11,13);
        volume b;
	b.print(b1);
        return 0;
}
