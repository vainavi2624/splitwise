#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

map<string,double>netAmounts;

class Expense {
public:
    string name;
    double amount;
    string type;
    string paidBy;

    Expense(const string& name, double amount, string type, const string& paidBy)
        : name(name), amount(amount), type(type), paidBy(paidBy) {
            netAmounts[paidBy] += amount;
            if(type=="Equal"){
                vector<string>shareHolders;
                for(auto &it: netAmounts){
                    cout<<"Does "<<it.first<<" have a share?(y/n)"<<'\n';
                    char temp;
                    cin>>temp;
                    if(temp=='y'){
                        shareHolders.push_back(it.first);
                    }
                }
                double share = amount / shareHolders.size();
                share = round(share*100)/100;
                for(auto i : shareHolders){
                    netAmounts[i] -= share;
                }
            }else if(type=="Exact"){
                double sum = 0;
                map<string,double>eg;
                for(auto &it:netAmounts){
                    cout<<"Does "<<it.first<<" have a share?(y/n)"<<'\n';
                    char temp;
                    cin>>temp;
                    if(temp=='y'){
                        double amt;
                        cout<<"Enter the amount:"<<'\n';
                        cin>>amt;
                        sum += amt;
                        eg[it.first] = amt;
                        //it.second -= amt;
                    }
                }
                if(sum!=amount){
                    netAmounts[paidBy] -= amount;
                    cout<<"Invalid Input"<<'\n';
                    return;
                }else{
                    for(auto &it : eg){
                        netAmounts[it.first] -= it.second;
                    }
                }
            }else{
                double totalPercentage = 0.0;
                map<string,double>eg;
                for (auto &it:netAmounts) {
                    cout << "Enter the percentage for " << it.first << ": ";
                    double percentage;
                    cin >> percentage;
                    totalPercentage += percentage;
                    eg[it.first] = percentage;
                    //it.second -= (percentage / 100.0) * amount;
                }
                if (totalPercentage != 100.0) {
                    netAmounts[paidBy] -= amount;
                    cout << "Total percentage must be 100%. Please try again." << std::endl;
                    return;
                }else{
                    for(auto &it : eg){
                        netAmounts[it.first] -= (it.second/100) * amount;
                    }
                }
            }
    }
};

// Splitwise Class
class Splitwise {
public:
    vector<Expense*> expenses;
    priority_queue<pair<double, string>> positivePQ;
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> negativePQ;
    void addUser(const string& name) {
        if(netAmounts.find(name)!=netAmounts.end()){
            cout<<"User already exists"<<'\n';
        }else{
            netAmounts[name] = 0.0;
            cout<<"User "<<name<<" added successfully"<<'\n';
        }
    }

    void addExpense(const string& name, double amount, string type) {
        cout << "Who paid for the expense? ";
        string paidByName;
        cin >> paidByName;

        if(netAmounts.find(paidByName)==netAmounts.end()){
            cout<<"User doesn't exist"<<'\n';
            return;
        }else{
            Expense* expense = new Expense(name, amount, type, paidByName);
            expenses.push_back(expense);
        }
    }

    void settleDebts() {
        priority_queue<pair<double, string>>positivePQ;
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>>negativePQ;

        for (auto &it:netAmounts) {
            if (it.second > 0) {
                positivePQ.push(make_pair(it.second, it.first));
            } else if(it.second<0){
                negativePQ.push(make_pair(it.second, it.first));
            }
        }
        while (!positivePQ.empty() && !negativePQ.empty()) {
            double positiveAmount = positivePQ.top().first;
            string positiveUser = positivePQ.top().second;
            double negativeAmount = negativePQ.top().first;
            string negativeUser = negativePQ.top().second;

            double settlement = min(positiveAmount, -negativeAmount);
            netAmounts[positiveUser] -= settlement;
            netAmounts[negativeUser] += settlement;

            cout<<negativeUser<<" pays Rs."<<settlement<<" to "<<positiveUser<<'\n';

            if (netAmounts[positiveUser] > 0) {
                positivePQ.pop();
                positivePQ.push(make_pair(netAmounts[positiveUser], positiveUser));
            } else {
                positivePQ.pop();
            }

            if (netAmounts[negativeUser] < 0) {
                negativePQ.pop();
                negativePQ.push(std::make_pair(netAmounts[negativeUser], negativeUser));
            } else {
                negativePQ.pop();
            }
        }
    }

    void displayFinalTable() {
        cout << "Final Table:" << std::endl;
        for (auto &it:netAmounts) {
            std::cout << it.first << ": " << it.second << std::endl;
        }
    }

    void displayMenu() {
        while (true) {
            cout << "Welcome to Splitwise Prototype!" << std::endl;
            cout << "1. Add User" << std::endl;
            cout << "2. Add Expense" << std::endl;
            cout << "3. Settle Debts" << std::endl;
            cout << "4. Display Final Transactions" << std::endl;
            cout << "5. Exit" << std::endl;
            cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    string name;
                    cout << "Enter the user's name: ";
                    cin >> name;
                    addUser(name);
                    break;
                }
                case 2: {
                    string name;
                    double amount;
                    int type;
                    cout << "Enter the expense name: ";
                    cin >> name;
                    cout << "Enter the expense amount: ";
                    cin >> amount;
                    cout << "Select the expense type (0 - Exact, 1 - Equal, 2 - Percentage): ";
                    cin >> type;
                    string expenseType;
                    if(type==0){
                        expenseType = "Exact";
                    }else if(type==1){
                        expenseType = "Equal";
                    }else{
                        expenseType = "Percentage";
                    }
                    addExpense(name, amount, expenseType);
                    break;
                }
                case 3:
                    settleDebts();
                    break;
                case 4:
                    displayFinalTable();
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
    }
};

int main() {
    Splitwise splitwise;
    splitwise.displayMenu();
    return 0;
}