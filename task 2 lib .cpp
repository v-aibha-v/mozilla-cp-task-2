#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Book {
    int id;
    string title;
    string author;
};
struct Member {
    int id;
    string name;
};
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook() {
        Book book;
        cin >> book.id;
        cin.ignore(); //  newline character
        getline(cin, book.title);
        cout << "Enter Book Author: ";
        getline(cin, book.author);
        books.push_back(book);
    }
    void viewBooks() {
        if (books.empty()) {
            cout << "No books \n";
            return;
        }
        cout << "\nList";
        for (const auto &book : books) {
            cout << book.id << book.title <<  book.author << endl;
        }
    }
    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                return;
            }
        }
        cout << "Book not found!\n";
    }
};
int main() {
    Library lib;
    Book b1 = {101, "aa", "Author1"}, b2 = {102, "bb", "Author2"}, b3 = {103, "cc", "Author3"};
    lib.addBook(); lib.addBook(); lib.addBook();
    lib.viewBooks();
    lib.deleteBook();
    lib.viewBooks();
    return 0;
}

