
// Bank Management System in C++
// This repository contains a simple Bank Management System implemented in C++. The system allows you to open new bank accounts, assign unique account numbers to customers, and manage customer details such as name, age, sex, and address. The program ensures that each account number is unique by using all possible permutations of the digits 0-9.

// Features
// Customer Management: Add new customers with details like name, age, sex, village, district, and state.
// Unique Account Number Generation: Generates a unique 10-digit account number for each customer using permutations of digits 0-9. This ensures that no two customers have the same account number.
// Account Operations: Basic menu options are included to open new accounts, check balance, deposit money, withdraw money, and edit customer details (additional functionalities can be expanded).
// Code Overview
// Classes
// Customer: Stores customer details such as name, age, sex, village, district, and state.

// Bank:

// Manages the list of customers and account numbers.
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<map>

using namespace std;

// Customer class definition
class Customer {
private:
    string Name;
    int Age;
    string Sex;
    string Vill;
    string Dist;
    string State;
    long int Balance;

public:
 // default constructor 
     Customer() {
        Name = "";
        Age = 0;
        Sex = "";
        Vill = "";
        Dist = "";
        State = "";
        Balance = 0;
    }



    Customer(string name, int age, string sex, string vill, string dist, string state, long int balance=0 ) {
        Name = name;
        Age = age;
        Sex = sex;
        Vill = vill;
        Dist = dist;
        State = state;
        Balance = balance;
    }

    string get_Name() { return Name; }
    int get_Age() { return Age; }
    string get_Sex() { return Sex; }
    string get_Vill() { return Vill; }
    string get_Dist() { return Dist; }
    string get_State() { return State; }
    long int get_Balance() { return Balance; }
    void set_Balance(long int newBalance) { Balance = newBalance; }
};

// Banking operation class  
class Bank {
private:
    vector<Customer> customers;   // To store new customers
    int account_counter;          // Counter to ensure unique account numbers
    set<string> used_account_numbers;  // Set of used account numbers
    map<string, long int> Deposited_Balance; // Map to store account numbers and their balances
    map<string, Customer> customer_accounts; // Map to link account numbers to Customer objects

    // Create a new unique 10-digit account number using a counter
    string Account_Number_provider() {
        string account_number = to_string(4044068470 + account_counter);  // Ensure 10-digit format
        account_counter++;
        used_account_numbers.insert(account_number);  // Mark as used
        return account_number;
    }

public:
    Bank() {
        account_counter = 0;  // Initialize account number counter
    }

    // Create a new account for a customer
    void OpenNewAccount() {
        string Name;
        int Age;
        string Sex;
        string Vill;
        string Dist;
        string State;
        long int balance;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, Name);

        cout << "Enter Age: ";
        cin >> Age;

        cout << "Enter Sex: ";
        cin >> Sex;

        cout << "Enter Village, District, State: ";
        cin >> Vill >> Dist >> State;

        cout << "Enter initial deposit amount: ";
        cin >> balance;

        // Create a new customer
        Customer newCustomer(Name, Age, Sex, Vill, Dist, State, balance);
        customers.push_back(newCustomer);

        // Generate account number
        string account_number = Account_Number_provider();
        cout << Name << "'s account number is " << account_number << endl;
        Deposited_Balance[account_number] = balance;
        customer_accounts[account_number] = newCustomer;
    }

    // Display current balance for a given account number
    void current_Balance() {
        string account_number;
        cout << "Enter account number: ";
        cin >> account_number;

        if (Deposited_Balance.find(account_number) != Deposited_Balance.end()) {
            cout << "Current balance for account " << account_number << " is: " << Deposited_Balance[account_number] << endl;
        } else {
            cout << "Account number not found!" << endl;
        }
    }

    // Deposit balance into a customer’s account
    void deposit_Balance() {
        string account_number;
        long int deposit;

        cout << "Enter account number: ";
        cin >> account_number;

        if (Deposited_Balance.find(account_number) != Deposited_Balance.end()) {
            cout << "Enter deposit amount: ";
            cin >> deposit;
            Deposited_Balance[account_number] += deposit;
            cout << "New balance is: " << Deposited_Balance[account_number] << endl;
        } else {
            cout << "Account number not found!" << endl;
        }
    }

    // Withdraw balance from a customer’s account
    void withdraw_Balance() {
        string account_number;
        long int withdrawal;

        cout << "Enter account number: ";
        cin >> account_number;

        if (Deposited_Balance.find(account_number) != Deposited_Balance.end()) {
            cout << "Enter withdrawal amount: ";
            cin >> withdrawal;

            if (Deposited_Balance[account_number] >= withdrawal) {
                Deposited_Balance[account_number] -= withdrawal;
                cout << "New balance is: " << Deposited_Balance[account_number] << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
        } else {
            cout << "Account number not found!" << endl;
        }
    }

    // Get details of a customer based on account number
    void get_Details_Of_Customer() {
        string account_number;
        cout << "Enter account number: ";
        cin >> account_number;

        if (customer_accounts.find(account_number) != customer_accounts.end()) {
            Customer customer = customer_accounts[account_number];
            cout << "Customer Details:\n";
            cout << "Name: " << customer.get_Name() << "\n";
            cout << "Age: " << customer.get_Age() << "\n";
            cout << "Sex: " << customer.get_Sex() << "\n";
            cout << "Village: " << customer.get_Vill() << "\n";
            cout << "District: " << customer.get_Dist() << "\n";
            cout << "State: " << customer.get_State() << "\n";
            cout << "Balance: " << Deposited_Balance[account_number] << "\n";
        } else {
            cout << "Account number not found!" << endl;
        }
    }

    // Edit customer details based on account number (with password protection)
    void edit_CustomerAccount() {
        string account_number;
        string password = "admin"; // Password protection for editing

        cout << "Enter admin password to edit account: ";
        string input_password;
        cin >> input_password;

        if (input_password == password) {
            cout << "Enter account number: ";
            cin >> account_number;

            if (customer_accounts.find(account_number) != customer_accounts.end()) {
                string new_name, new_sex, new_vill, new_dist, new_state;
                int new_age;

                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, new_name);

                cout << "Enter new age: ";
                cin >> new_age;

                cout << "Enter new sex: ";
                cin >> new_sex;

                cout << "Enter new village, district, state: ";
                cin >> new_vill >> new_dist >> new_state;

                // Update customer details
                Customer &customer = customer_accounts[account_number];
                customer = Customer(new_name, new_age, new_sex, new_vill, new_dist, new_state, Deposited_Balance[account_number]);

                cout << "Customer details updated!" << endl;
            } else {
                cout << "Account number not found!" << endl;
            }
        } else {
            cout << "Incorrect password!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice = 1, menu_option;

    while (choice) {
        cout << "*-- Select menu --* \n";
        cout << "1. Open New Account\n";
        cout << "2. Check Current Balance\n";
        cout << "3. Deposit Balance\n";
        cout << "4. Withdraw Balance\n";
        cout << "5. Get Details of Customer\n";
        cout << "6. Edit Customer Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> menu_option;

        switch (menu_option) {
        case 1:
            bank.OpenNewAccount();
            break;
        case 2:
            bank.current_Balance();
            break;
        case 3:
            bank.deposit_Balance();
            break;
        case 4:
            bank.withdraw_Balance();
            break;
        case 5:
            bank.get_Details_Of_Customer();
            break;
        case 6:
            bank.edit_CustomerAccount();
            break;
        case 7:
            cout << "Exiting..." << endl;
            choice = 0;
            break;
        default:
            cout << "Select a valid operation." << endl;
            break;
        }

        if (choice) {
            cout << "Do you want to perform more operations (1 for Yes, 0 for No)? ";
            cin >> choice;
        }
    }

    return 0;
}
