/****************************************************

      ***** Final Project Fisrt Semester *****
Project Name :: Library Management System 
Language Use :: C++
Group Member :: Nimra Ali, Mahliqa Amjad ,Rida eman

*****************************************************/

#include <iostream> // For input and output operations
#include <vector>   // For using the vector container to store dynamic lists
#include <string>   // For using the string class to handle text data
#include <iomanip>  // For formatting the table view
#include <cstdlib>  // For system("cls") to clear screen
using namespace std;
// *********************** Mahliqa Amjad Work Start ***********************
// User Class    
class User {
public:
    string username;
    string email;

    User(string name, string mail) : username(name), email(mail) {}

    void display() {
        cout << "Username: " << username << ", Email: " << email << endl;
    }
};
// *********************** Mahliqa Amjad Work end ***********************
// Book Class
class Book {
public:
    string title;
    string author;
    string isbn;
    string category;
    bool isAvailable;

    Book(string t, string a, string i, string c) 
        : title(t), author(a), isbn(i), category(c), isAvailable(true) {}

    void display() {
        cout << left << setw(20) << title
             << setw(20) << author
             << setw(15) << isbn
             << setw(15) << category
             << (isAvailable ? "Available" : "Not Available") << endl;
    }
};

// Library Class
class Library {
private:
    vector<User> users;
    vector<Book> books;

public:
	// *********************** Mahliqa Amjad Work Start ***********************
    // FR-1 Manage User Accounts
    void addUser(string username, string email) {
        users.push_back(User(username, email));
        cout << "\n\n                          User added successfully!\n";
    }

    void updateUser(string username, string newEmail) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].username == username) {
                users[i].email = newEmail;
                cout << "\n\n                          User updated successfully!\n";
                return;
            }
        }
        cout << "\n\n                          User not found!\n";
    }

    // FR-2 Add Books
    void addBook(string title, string author, string isbn, string category) {
        books.push_back(Book(title, author, isbn, category));
        cout << "\n\n                          Book added successfully!\n";
    }

    // FR-3 Issue Books
    void issueBook(string isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                if (books[i].isAvailable) {
                    books[i].isAvailable = false;
                    cout << "\n\n                          Book issued successfully!\n";
                } else {
                    cout << "\n\n                          Book is already issued.\n";
                }
                return;
            }
        }
        cout << "\n\n                          Book not found!\n";
    }

    void returnBook(string isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                if (!books[i].isAvailable) {
                    books[i].isAvailable = true;
                    cout << "\n\n                          Book returned successfully!\n";
                } else {
                    cout << "\n\n                          Book was not issued.\n";
                }
                return;
            }
        }
        cout << "\n\n                          Book not found!\n";
    }
    // *********************** Mahliqa Amjad Work End ***********************
    
    // *********************** Nimra Ali Work Start *************************
    // FR-4 Search Books
    void searchBook(string keyword) {
        cout << "\n\n\n         * * * * * * * * * *  Search Results:  * * * * * * * * *     \n\n\n";
        cout << left << setw(20) << "Title"
             << setw(20) << "Author"
             << setw(15) << "ISBN"
             << setw(15) << "Category"
             << "Availability" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].title.find(keyword) != string::npos || 
                books[i].author.find(keyword) != string::npos || 
                books[i].isbn.find(keyword) != string::npos) {
                books[i].display();
            }
        }
    }

    // FR-5 Update Book Records
    void updateBook(string isbn, string newTitle, string newAuthor, string newCategory, bool newAvailability) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                books[i].title = newTitle;
                books[i].author = newAuthor;
                books[i].category = newCategory;
                books[i].isAvailable = newAvailability;
                cout << "\n\n                          Book updated successfully!\n";
                return;
            }
        }
        cout << "\n\n                          Book not found!\n";
    }

    // FR-6 Delete Book Records
    void deleteBook(string isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                cout << "\n\n                          Book deleted successfully!\n";
                return;
            }
        }
        cout << "\n\n                          Book not found!\n";
    }
    // *********************** Nimra Ali Work End *****************************
    
    // *********************** Rida Eman Work Start ***************************
    // FR-7 View All Books
    void viewAllBooks() {
        cout << "\n\n\n         * * * * * * * * * *  Books List:  * * * * * * * * *     \n\n\n";
        cout << left << setw(20) << "Title"
             << setw(20) << "Author"
             << setw(15) << "ISBN"
             << setw(15) << "Category"
             << "Availability" << endl;
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
        }
        cout << "\n\n         * * * * * * * * * * * * * * * * * * * * * * * *     \n\n";
    }

    // FR-8 Check Availability
    void checkAvailability(string isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                cout << "\n\n                          The book '" << books[i].title << "' is "
                     << (books[i].isAvailable ? "Available" : "Not Available") << ".\n";
                return;
            }
        }
        cout << "\n\n                          Book not found!\n";
    }
    
    // *********************** Rida Eman Work End ***************************
    
        
    // *********************** Mahliqa Amjad Work Start ***********************
    // Find user by username
    User* findUserByUsername(string username) {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].username == username) {
                return &users[i];
            }
        }
        return nullptr;
    }
    // *********************** Mahliqa Amjad Work Start ***********************
};
// **** Main function combine work done by Nimra Ali ,Mahliqa Amjad, Rida Eman *****

// Main Function
int main() {
    Library library;
    int choice;

    do {
        // Clear the screen
        system("cls"); // For Windows; use system("clear") for Linux/Mac
cout << "\n\n\n********************* Final Project Fisrt Semester *****************************\n"
     << "****              Project Name :: Library Management System                 ****\n"
     << "****              Language Use :: C++                                       ****\n"
     << "****              Group Member :: Nimra Ali, Mahliqa Amjad ,Rida Eman       ****\n"
     << "********************************************************************************\n\n\n";
        cout << "\n         * * * * * * Library Management System * * * * * *     \n\n\n";
        cout << "         *              1. Add User                      *\n\n";
        cout << "         *              2. Update User                   *\n\n";
        cout << "         *              3. Add Book                      *\n\n";
        cout << "         *              4. Issue Book                    *\n\n";
        cout << "         *              5. Return Book                   *\n\n";
        cout << "         *              6. Search Book                   *\n\n";
        cout << "         *              7. Update Book                   *\n\n";
        cout << "         *              8. Delete Book                   *\n\n";
        cout << "         *              9. View All Books                *\n\n";
        cout << "         *              10. Check Book Availability      *\n\n";
        cout << "         *              0. Exit                          *\n\n";
        cout << "\n         * * * * * * * * * * * * * * * * * * * * * * * * *     \n\n\n";
        cout << "                          Enter your choice: ";
        cin >> choice;

        string name, email, title, author, isbn, category;
        bool availability;
        User* user = nullptr;  // Declare the user pointer outside of the switch block

        switch (choice) {
            case 1:
                cout << "                          Enter username: ";
                cin >> name;
                cout << "                          Enter email: ";
                cin >> email;
                library.addUser(name, email);
                break;

            case 2:
                cout << "                          Enter username: ";
                cin >> name;

                // Display current user details
                user = library.findUserByUsername(name); // Assign user here
                if (user) {
                    cout << "                          Current details: \n";
                    user->display();
                    cout << "                          Enter new email: ";
                    cin >> email;
                    library.updateUser(name, email);
                } else {
                    cout << "                          User not found!\n";
                }
                break;

            case 3:
                do {
                    cout << "                          Enter book title: ";
                    cin >> title;
                    cout << "                          Enter author: ";
                    cin >> author;
                    cout << "                          Enter ISBN: ";
                    cin >> isbn;
                    cout << "                          Enter category: ";
                    cin >> category;
                    library.addBook(title, author, isbn, category);

                    cout << "\n\n                          Do you want to add another book? (y/n): ";
                    char option;
                    cin >> option;
                    if (option != 'y') break;

                } while (true);
                break;

            case 4:
                do {
                    cout << "                          Enter ISBN to issue the book: ";
                    cin >> isbn;
                    library.issueBook(isbn);

                    cout << "\n\n                          Do you want to issue another book? (y/n): ";
                    char option;
                    cin >> option;
                    if (option != 'y') break;

                } while (true);
                break;

            case 5:
                do {
                    cout << "                          Enter ISBN to return the book: ";
                    cin >> isbn;
                    library.returnBook(isbn);

                    cout << "\n\n                          Do you want to return another book? (y/n): ";
                    char option;
                    cin >> option;
                    if (option != 'y') break;

                } while (true);
                break;

            case 6:
                cout << "                          Enter search keyword: ";
                cin >> title;  // Use title as a search keyword
                library.searchBook(title);
                break;

            case 7:
                do {
                    cout << "                          Enter ISBN to update the book: ";
                    cin >> isbn;
                    cout << "                          Enter new title: ";
                    cin >> title;
                    cout << "                          Enter new author: ";
                    cin >> author;
                    cout << "                          Enter new category: ";
                    cin >> category;
                    cout << "                          Is the book available? (1 for Yes, 0 for No): ";
                    cin >> availability;
                    library.updateBook(isbn, title, author, category, availability);

                    cout << "\n\n                          Do you want to update another book? (y/n): ";
                    char option;
                    cin >> option;
                    if (option != 'y') break;

                } while (true);
                break;

            case 8:
                do {
                    cout << "                          Enter ISBN to delete the book: ";
                    cin >> isbn;
                    library.deleteBook(isbn);

                    cout << "\n\n                          Do you want to delete another book? (y/n): ";
                    char option;
                    cin >> option;
                    if (option != 'y') break;

                } while (true);
                break;

            case 9:
                library.viewAllBooks();
                break;

            case 10:
                cout << "                          Enter ISBN to check availability: ";
                cin >> isbn;
                library.checkAvailability(isbn);
                break;

            case 0:
                cout << "                          Exiting...\n";
                break;

            default:
                cout << "                          Invalid choice! Please try again.\n";
        }

        // Wait for user to press a key to continue
        cout << "\n\n                          Press any key to return to the main menu.";
        cin.ignore();
        cin.get();

    } while (choice != 0);

    return 0;
}

