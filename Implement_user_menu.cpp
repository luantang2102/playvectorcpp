#include <iostream>
#include <vector>
#include <string>
#include "Implement_function_menu.cpp"

using namespace std;

//prototypes
void implement_user_menu();
void display_user_menu();

void sign_in();
void create_new_account();
void sign_as_guest();
//==================================================//

//Implement
void implement_user_menu() {
    char user_choice;
    do {
        display_user_menu();
        get_user_choice(user_choice);
        if (user_choice == '1') {
            sign_in();
        } else if (user_choice == '2') {
            create_new_account();
        } else if (user_choice == '3') {
            sign_as_guest();
        } else if (user_choice == 'q') {
            cout << "Goodbye!";
        } else {
            cout << "Unknown! Please try again!\n\n";
        }
    } while (user_choice != 'q');
}
void display_user_menu() {
    cout << ">>>- Welcome - What you want to do? -<<< \n";
    cout << "1 - Sign in \n";
    cout << "2 - Create new account\n";
    cout << "3 - Sign as guest\n";
    cout << "Q - Quit\n";
}

void sign_in() {
    if (all_accounts.size() == 0) {
        cout << "No accounts exist...\n\n";
    } else {
        cout << "user: ";
        string entering_user_name;
        cin >> entering_user_name;
        for (auto user : all_accounts) {
            if (entering_user_name == user.user_name) {
                cout << "password: ";
                string entering_password;
                cin >> entering_password;
                if (entering_password == user.password) {
                    implement_function_menu(user, 1);
                } else {
                    cout << "Incorrect password, please try again.\n";
                    cout << "=====================================\n";
                    break;
                }
            } else {
                cout << "Incorrect username, please try again.\n";
                cout << "=====================================\n";
                break;
            }
        }
    }
}
void create_new_account() {
    Account NEW_USER;
    string duplicate_check;
    bool duplicate;
    do {
        duplicate = 0; 
        cout << "New user_name: ";
        cin >> duplicate_check;
        for (auto user : all_accounts) {
            if (user.user_name == duplicate_check) {
                cout << "This username has been used! Try again...\n";
                duplicate = 1;
                break; 
            }
        }
    } while (duplicate == 1);
    NEW_USER.user_name = duplicate_check;   
    cout << "New password: ";
    cin >> NEW_USER.password;
    implement_function_menu(NEW_USER, 2);
}
void sign_as_guest() {
    Account NEW_USER;
    implement_function_menu(NEW_USER, 3);
}
//==================================================//