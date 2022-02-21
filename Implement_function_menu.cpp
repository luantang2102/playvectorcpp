#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "Account.h"

using namespace std;

vector <Account> all_accounts;

//Prototypes
void implement_function_menu(Account USER, int number_chosen);
void display_fuction_menu();
void get_user_choice(char&);

void print_numbers(vector <int> &vec);
void add_number(vector <int> &vec);
void mean_of_the_numbers(vector <int> &vec);
void smallest_number(vector <int> &vec);
void largest_number(vector <int> &vec);
void quit(Account USER, int number_chosen);
//==================================================//

//Implementing
void implement_function_menu(Account USER, int number_chosen) {
    char user_choice;
    do {
        display_fuction_menu();
        get_user_choice(user_choice);
        cout << "\n=====================================\n";
        if (user_choice == 'p') {
            print_numbers(USER.user_vec);
        } else if (user_choice == 'a') {
            add_number(USER.user_vec);
        } else if (user_choice == 'm') {
            mean_of_the_numbers(USER.user_vec);        
        } else if (user_choice == 's') {
            smallest_number(USER.user_vec);
        } else if (user_choice == 'l') {
            largest_number(USER.user_vec);    
        } else if (user_choice == 'q') {
            quit(USER, number_chosen);
        } else {
            cout << "Unknown! Please try again!\n";
        }
        cout << "=====================================\n\n";
    } while (user_choice != 'q');
}
void display_fuction_menu() {
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

void print_numbers(vector <int> &vec) {
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
void add_number(vector <int> &vec) {
    int add_number{0};
    cout << "Enter your number to add: ";
    cin >> add_number;
    vec.push_back(add_number);
    cout << add_number << " Added!\n";
}
void mean_of_the_numbers(vector <int> &vec) {
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
void smallest_number(vector <int> &vec) {
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
void largest_number(vector <int> &vec) {
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
void quit(Account USER, int number_chosen) {
    if (number_chosen != 3) {
        all_accounts.push_back(USER);
    }
    cout << "Goodbye! Have a nice day!\n";
}
//==================================================//
