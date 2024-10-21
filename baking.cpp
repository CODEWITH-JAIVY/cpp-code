
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>  // For std::next_permutation
using namespace std;

class Customer {
private:
    string Name;
    int Age;
    string Sex;
    string Vill;
    string Dist;
    string State;
    long int Blance ;

public:
    Customer(string name, int age, string sex, string vill, string dist, string state) {
        Name = name;
        Age = age;
        Sex = sex;
        Vill = vill;
        Dist = dist;
        State = state;
    }

    string get_Name() { return Name; }
    int get_Age() { return Age; }
    string get_Sex() { return Sex; }
    string get_Vill() { return Vill; }
    string get_Dist() { return Dist; }
    string get_State() { return State; }
    long int get_blance() { return Blance ; }
};

// Banking operation class  
class Bank {
private:
    vector<Customer> customers;
    vector<string> account_numbers;
    set<string> used_account_numbers;

    // Helper function to generate all 10-digit permutations from digits 0-9
    void generateAccountNumbers() {
        string digits = "0123456789";
        do {
            account_numbers.push_back(digits);
        } while (next_permutation(digits.begin(), digits.end()));
    }

public:
    Bank() {
        generateAccountNumbers();  // Generate all account numbers once
    }

    // Create a new unique 10-digit account number
    string Account_Number_provider() {
        for (const string& acc_num : account_numbers) {
            if (used_account_numbers.find(acc_num) == used_account_numbers.end()) {
                // Mark the account number as used
                used_account_numbers.insert(acc_num);
                return acc_num;
            }
        }
        return "";  // If all account numbers are used
    }

    // Create a new account for a customer
    void OpenNewAccount() {
        string Name;
        int Age;
        string Sex;
        string Vill;
        string Dist;
        string State;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, Name);

        cout << "Enter Age: ";
        cin >> Age;

        cout << "Enter Sex: ";
        cin >> Sex;

        cout << "Enter Village, District, State: ";
        cin >> Vill >> Dist >> State;

        // Create a new customer
        Customer newCustomer(Name, Age, Sex, Vill, Dist, State);
        customers.push_back(newCustomer);

        // Generate account number
        string account_number = Account_Number_provider();
        if (account_number.empty()) {
            cout << "All account numbers are exhausted!" << endl;
        } else {
            cout << Name << "'s account number is " << account_number << endl;
        }  

        // add mony at the time of open account in account  new account number  
      }
         
         // 
    void   current_Blance() {
     cout<<"Code under development " << endl ;
     // show current blance in account   with account number and password  
    
    }
    int deposite_blance() {
        // depostite blance if  blance is sufficiant other wise show not suffi
        cout<< " Blance cheking code is under progress " ;
    }
int withdrow_blance() {
    // blance with drow 
    cout<< "Blance withdrow is under proccess"<< endl  ;

}
   void get_DetailOF_cutomer(){
    // display detail of customer 
    //  when to be searched with account number 
    cout<< " Get detail of customer " ;
    // only authorised persion can see  deatil of all customer 
   }
      
      int Edit_customerAccount(){
        cout<< "updatetion patr code is under process " ;
        // only authorised persion can change detail of customer 
        // createa  password  if pass word is enter correct than allow to update 
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
                bank.current_Blance();
                break;

            case 3:
                bank.deposite_blance();
                break;

            case 4:
                bank.withdrow_blance();
                break;

            case 5:
                bank.get_DetailOF_cutomer();
                break;

            case 6:
                bank.Edit_customerAccount();
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
