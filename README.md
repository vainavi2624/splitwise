### Introduction
**Splitwise Clone** is a C++ application designed to manage and track shared expenses among a group of users. Inspired by the popular Splitwise app, this project aims to simplify the process of expense sharing and debt settlement. It allows users to record expenses, calculate balances, and determine transactions needed to settle debts efficiently.

### Architecture
The project is organized into two primary classes and uses various data structures to handle expense management and user interactions:

1. **Expense Class**:
   - **Purpose**: Represents individual expenses and manages details related to each expense.
   - **Attributes**:
     - `expenseName`: Description of the expense.
     - `amount`: Total amount of the expense.
     - `splitType`: Type of split (Exact, Equal, Percentage).
     - `payer`: User who paid for the expense.
   - **Functionality**: Updates users' net balances based on the type of split when an expense is created.

2. **Splitwise Class**:
   - **Purpose**: Manages users, expenses, and debt settlements.
   - **Attributes**:
     - `users`: Collection of all users in the system.
     - `expenses`: List of all recorded expenses.
     - `positivePQ` and `negativePQ`: Priority queues to track users who are owed money and those who owe money.
   - **Functionality**: Provides methods for adding users, adding expenses, settling debts, and displaying final transactions.

### Functionalities

1. **Adding a User**:
   - Allows for adding new users with an initial balance of zero.
   - Prevents duplication by checking for existing users.

2. **Adding an Expense**:
   - Records expenses with details such as name, amount, and split type.
   - Updates net balances based on the split type:
     - **Exact**: Users specify exact amounts owed.
     - **Equal**: Amount is divided equally among involved users.
     - **Percentage**: Amount is divided based on specified percentages.

3. **Settling Debts**:
   - Calculates transactions needed to settle all debts using priority queues.
   - Determines the optimal way to clear all debts among users.

4. **Displaying Final Transactions**:
   - Shows the final net balance for each user.
   - Details the transactions required to settle all debts, providing a clear summary of who owes whom and how much.

### Implementation

1. **Expense Class Implementation**:
   - Defined attributes and methods to handle expense details and update user balances based on the split type.
   - Implemented logic to adjust net balances for each user involved in the expense.

2. **Splitwise Class Implementation**:
   - Managed user and expense data using maps and lists.
   - Used priority queues to efficiently calculate and display debt settlements.
   - Implemented methods for adding users, recording expenses, and calculating final balances.

3. **User Interface**:
   - Developed a console-based menu system for user interaction.
   - Provided options to add users, add expenses, settle debts, and display transactions.

### Challenges

1. **Efficient Debt Settlement**:
   - **Challenge**: Ensuring optimal debt settlement with minimal transactions.
   - **Solution**: Used priority queues to track and manage debts, allowing for efficient calculation of transactions needed to balance accounts.

2. **Handling Different Split Types**:
   - **Challenge**: Accurately computing balances based on various split types.
   - **Solution**: Implemented separate logic for Exact, Equal, and Percentage splits, ensuring accurate balance updates.

3. **User Management**:
   - **Challenge**: Preventing duplicate users and managing user data.
   - **Solution**: Implemented checks to avoid adding existing users and used appropriate data structures to store and manage user information.

### Conclusion
The Splitwise Clone project demonstrates the core functionalities of a shared expense management application, including user management, expense tracking, and debt settlement. By utilizing data structures such as maps and priority queues, the application efficiently handles financial transactions and user interactions. This project highlights my ability to develop a practical and effective financial management tool in C++, showcasing skills in both algorithm design and application development.

---
