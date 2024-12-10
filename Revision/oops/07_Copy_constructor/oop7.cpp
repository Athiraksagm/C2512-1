/*Copy Constructor
Task: Create a class Book with a copy constructor
to duplicate an object.*/
#include<iostream>
using namespace std;
class Book{
	private:
		int bookid;
	public:
		Book(int bid);
		Book(Book& page);
		void print(){
			cout << bookid << endl;
		}
};
int main(){
	Book book(3);
	Book book1(book);
        book.print();
	book1.print();
	return 0;
}
Book::Book(int bid)
{
	bookid=bid;
}
Book::Book(Book& page)
{
	bookid=page.bookid;
}


