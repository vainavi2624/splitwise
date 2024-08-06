# splitwise
Cash Flow Minimiser

This project is a simple implementation of a Splitwise-like application in C++. The main goal of this application is to manage expenses among a group of people and help them settle their debts. Let's break down the key components and functionality of the project:

### Classes and Data Structures

1. **Expense Class**:
   - Represents an individual expense.
   - Stores details like the expense name, amount, type of split (Equal, Exact, Percentage), and the person who paid.
   - When an expense is created, it updates the net amounts for each user involved in the expense based on the type of split.

2. **Splitwise Class**:
   - Manages users and expenses.
   - Contains methods to add users, add expenses, settle debts, and display the final transactions.
   - Uses two priority queues (`positivePQ` and `negativePQ`) to efficiently settle debts by keeping track of users who owe money and users who are owed money.

### Main Functionalities

1. **Adding a User**:
   - Users can be added to the system, and their net balance is initialized to zero.
   - If a user already exists, an appropriate message is displayed.

2. **Adding an Expense**:
   - An expense can be added by specifying its name, amount, and type (Exact, Equal, or Percentage).
   - The user who paid for the expense must be specified.
   - Based on the type of expense, the net balances of the users involved are updated:
     - **Exact**: Users specify the exact amount each person owes.
     - **Equal**: The expense amount is divided equally among the users involved.
     - **Percentage**: Users specify the percentage of the total amount each person owes.

3. **Settling Debts**:
   - The application calculates and displays the transactions needed to settle all debts.
   - It uses priority queues to determine who should pay whom and how much.

4. **Displaying Final Transactions**:
   - Shows the final net balance of each user after all expenses and settlements.

5. **User Interface**:
   - A simple console menu allows users to interact with the application.
   - Users can choose to add a user, add an expense, settle debts, display final transactions, or exit the application.

### Example Usage

1. **Adding Users**:
   - Users like Alice, Bob, and Charlie can be added to the system.
   
2. **Adding Expenses**:
   - Alice pays $120 for dinner to be split equally among all users.
   - Bob pays $50 for a gift, where exact amounts are specified for each user.
   - Charlie pays $200 for groceries, split by specified percentages.

3. **Settling Debts**:
   - The system calculates and displays who owes money to whom and how much they owe.
   - For example, if Alice is owed money by Bob and Charlie, and Bob owes money to Charlie, the system will provide the simplest transactions to settle all debts.

4. **Displaying Final Transactions**:
   - The final net balance for each user is displayed, showing how much they owe or are owed.

### Conclusion

This project demonstrates the core functionality of a Splitwise-like application, including user management, expense tracking, and debt settlement. It highlights the use of data structures like maps and priority queues to efficiently handle financial transactions and user interactions. The application provides a simple yet effective way to manage shared expenses and ensure fair settlements among users.
