#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include "Account.h"

using namespace std;

vector <Account> all_accounts;

//prototypes
void display_interface();
void implement(Account USER, int number_chosen);
void display_menu();
void get_user_choice(char&);
void function_1();
void function_2();
void function_3();
void function_P(vector <int> &vec);
void function_A(vector <int> &vec);
void function_M(vector <int> &vec);
void function_S(vector <int> &vec);
void function_L(vector <int> &vec);
void function_Q(Account USER, int number_chosen);
//==================================================//

//Implementing Functions
void display_interface() {
    cout << "-->-Welcome to Vecterator!-<-- \n";
    cout << "1 - Sign in \n";
    cout << "2 - Create new account\n";
    cout << "3 - Sign as guest\n";
    cout << "Q - Quit\n";
}
void display_menu() {
    cout << "\n<<<<<<<<MENU>>>>>>>>\n";
    cout << "P - Print numbers\n";
    cout << "A - Add a number\n";
    cout << "M - Display mean of the numbers\n";
    cout << "S - Display the smallest number\n";
    cout << "L - Display the largest number\n";
    cout << "Q - Quit the menu\n";
}
void get_user_choice(char &user_choice) {
    cout << "\nEnter your choice: ";
    cin >> user_choice;
    user_choice = tolower(user_choice);
}
void function_1() {
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
                    implement(user, 1);
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
void function_2() {
    Account NEW_USER;
    string duplicate_check;
    bool duplicate;
    do {
        //comment
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
    implement(NEW_USER, 2);
}
void function_3() {
    Account NEW_USER;
    implement(NEW_USER, 3);
}
void implement(Account USER, int number_chosen) {
    char user_choice;
    do {
        display_menu();
        get_user_choice(user_choice);
        cout << "\n=====================================\n";
        if (user_choice == 'p') {
            function_P(USER.user_vec);
        } else if (user_choice == 'a') {
            function_A(USER.user_vec);
        } else if (user_choice == 'm') {
            function_M(USER.user_vec);        
        } else if (user_choice == 's') {
            function_S(USER.user_vec);
        } else if (user_choice == 'l') {
            function_L(USER.user_vec);    
        } else if (user_choice == 'q') {
            function_Q(USER, number_chosen);
        } else {
            cout << "Unknown! Please try again!\n";
        }
        cout << "=====================================\n\n";
    } while (user_choice != 'q');
}
void function_P(vector <int> &vec) {
    if(vec.size()==0) { 
        cout << "Empty!\n";
    }
    else {
        cout << "[ ";
        for (auto element : vec) { 
            cout << element << " ";
        }
        cout << "]\n";
    } 
}
void function_A(vector <int> &vec) {
    int add_number{0};
    cout << "Enter your number to add: ";
    cin >> add_number;
    vec.push_back(add_number);
    cout << add_number << " Added!\n";
}
void function_M(vector <int> &vec) {
    if (vec.size()==0) {
        cout << "Nothing to calculate! You should enter several numbers to execute this!\n";
    } else {
        int sum{0};
        for (auto element : vec) {
            sum+=element;
        }
        double average=sum/vec.size();
        cout << "Average = " << average << endl;
    }
}
void function_S(vector <int> &vec) {
    if (vec.size()==0) {
        cout << "Nothing to compare! Please enter a number!\n";
    } else {
        int min{INT_MAX};
        for (auto element : vec) {
            if (element<min) {
                min=element;
            } 
        }
        cout << "The smallest number is: " << min << endl;
    }
}
void function_L(vector <int> &vec) {
    if (vec.size()==0) {
        cout << "Nothing to compare! Please enter a number!\n";
    } else {
        int max{INT_MIN};
        for (auto element : vec) {
            if (element>max) {
                max=element;
            } 
        }
        cout << "The largest number is: " << max << endl;
    }  
}
void function_Q(Account USER, int number_chosen) {
    if (number_chosen != 3) {
        all_accounts.push_back(USER);
    }
    cout << "Goodbye! Have a nice day!\n";
}
//==========================================================//

int main() {
    //test github
    char user_choice;
    do {
        display_interface();
        get_user_choice(user_choice);

        if (user_choice == '1') {
            function_1();
        } else if (user_choice == '2') {
            function_2();
        } else if (user_choice == '3') {
            function_3();
        } else if (user_choice != 'q' && user_choice != 'Q') {
            cout << "Unknown! Please try again!\n\n";
        }
    } while (user_choice != 'q');
    return 0;
}