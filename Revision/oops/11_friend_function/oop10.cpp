#include <iostream>
using namespace std;
class box
{
	friend int findvolume(const box& b);

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
			void print();
};
void box::print(){
	cout <<"Volume of the box: "<<findvolume(*this);
}
int findvolume(const box& b){
	return (b.length*b.breadth*b.height);
}
int main(){
	box b1(12,11,13);
	b1.print();
        return 0;
}
