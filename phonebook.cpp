
#include <iostream>
#include <windows.h>

using namespace std;

// initialize app
void init() {
    system("TITLE PhoneBook");
}

// file existence checker
bool db_exists(char* filePath) {
		DWORD fileAtt = GetFileAttributesA(filePath);
		if(fileAtt == INVALID_FILE_ATTRIBUTES)
			throw GetLastError();
		return ( ( fileAtt & FILE_ATTRIBUTE_DIRECTORY ) == 0 ); 
}

 // create new db if "contacts.dat" does not exist
void create_db() {
	if (!(db_exists("contacts.dat")))
		system("type NUL > contacts.dat");
}

// display options
void display_options() {
    cout << "Hello," << endl << endl;
    int count = 1;
    string options[] = {"Add", "Del", "Edit", "View all", "Search"};
    for (int i = 0; i < 5; i++) {
        cout << "\t" << count++ << ". " << options[i] << endl;
    }
    cout << "\tAny other number to quit" << endl << endl << "Enter number for operation: ";
}

// add to contact
 void add() {
    cout << endl << "Enter name: "; 
    string name; cin >> name;

    cout << endl << "Enter number: "; 
    string number; cin >> number;

    string entry = name + ": " + number;
	system(string("echo " + entry + " >> contacts.dat").c_str());
 }

 // show all contacts
 void display_contacts() {
 	cout << endl;
    system("more contacts.dat");
 }

 
// search keyword in phonebook
void search() {
    cout << endl << "Enter name to search: ";
    string name; cin >> name;
    system(string("find \"" + name + "\" contacts.dat /i").c_str());
}

 // handke user's option
void handle_option() {
    int operationum; cin >> operationum;

    switch(operationum) {
        case 1: add(); break;
        case 4: display_contacts(); break;
        case 5: search(); break;
    }
}



// run app

int main() {
    init();
    create_db();
    display_options();
    handle_option();
}
