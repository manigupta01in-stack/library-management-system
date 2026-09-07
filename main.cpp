#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        issued = false;
    }
};

class Member {
public:
    int id;
    string name;

    Member(int memberId, string memberName) {
        id = memberId;
        name = memberName;
    }
};

vector<Book> books;
vector<Member> members;

void addBook() {
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));
    cout << "Book added successfully!\n";
}

void addMember() {
    int id;
    string name;

    cout << "Enter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));
    cout << "Member added successfully!\n";
}

void issueBook() {
    int bookId, memberId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    cout << "Enter Member ID: ";
    cin >> memberId;

    for (Book &book : books) {
        if (book.id == bookId) {
            if (!book.issued) {
                book.issued = true;
                cout << "Book issued successfully to Member ID "
                     << memberId << "!\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook() {
    int bookId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    for (Book &book : books) {
        if (book.id == bookId) {
            if (book.issued) {
                book.issued = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

void searchBook() {
    int choice;
    string keyword;

    cout << "Search by:\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter search keyword: ";
    getline(cin, keyword);

    bool found = false;

    for (const Book &book : books) {
        if ((choice == 1 && book.title.find(keyword) != string::npos) ||
            (choice == 2 && book.author.find(keyword) != string::npos)) {

            cout << "\nBook ID: " << book.id;
            cout << "\nTitle: " << book.title;
            cout << "\nAuthor: " << book.author;
            cout << "\nStatus: "
                 << (book.issued ? "Issued" : "Available") << "\n";

            found = true;
        }
    }

    if (!found) {
        cout << "No matching book found.\n";
    }
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- Library Books ---\n";

    for (const Book &book : books) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Status: "
             << (book.issued ? "Issued" : "Available")
             << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                addMember();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                searchBook();
                break;

            case 6:
                displayBooks();
                break;

            case 7:
                cout << "Thank you for using Library Management System!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
