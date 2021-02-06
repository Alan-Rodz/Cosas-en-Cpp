#include <iostream>

using namespace std;

class Book{
    public:
        string title;
        string author;
        int pages;

        //First Constructor
        Book(){
            title = "no title";
            author = "no author";
            pages = 0;
        }

        //Second Constructor
        Book(string aTitle, string aAuthor, int aPages){
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }

};

int main()
{
    Book book1("Roadside Picnic", "Arkadi Strugratski", 226);
    Book book2("Lord of The Rings", "Tolkien", 900);

    Book book3 ;

    cout << book1.title << endl;
    cout << book2.title << endl;
    cout << book3.title << endl;
    return 0;
}
