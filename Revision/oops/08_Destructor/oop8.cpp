/*Destructor
Task: Write a program to demonstrate the use of a destructor
in cleaning up dynamically allocated memory.*/

#include<iostream>
using namespace std;
class Book{
	private:
		int* bookid;
	public:
		Book(int bid);
		
		~Book();
		void print(){
			cout << *bookid << endl;
		}
};
int main(){
	Book book(3);
        book.print();
	return 0;
}
Book::Book(int bid)
{
	bookid=new int(bid);
}


Book::~Book(){
	delete bookid;
        bookid=nullptr;
	cout << "To check if it is deleted";
}
