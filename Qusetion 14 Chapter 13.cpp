/*Question 14
Define the class bankAccount to store a bank customer’s account
number and balance. Suppose that account number is of type int, and
balance is of type double. Your class should, at least, provide the
following operations: set the account number, retrieve the account
number, retrieve the balance, deposit and withdraw money, and print
account information. Add appropriate constructors.
1
3
Programming Exercises | 791
b. Every bank offers a checking account. Derive the class
checkingAccount from the class bankAccount (designed in
part (a)). This class inherits members to store the account number
and the balance from the base class. A customer with a checking
account typically receives interest, maintains a minimum balance,
and pays service charges if the balance falls below the minimum
balance. Add member variables to store this additional information.
In addition to the operations inherited from the base class, this class
should provide the following operations: set interest rate, retrieve
interest rate, set minimum balance, retrieve minimum balance, set
service charges, retrieve service charges, post interest, verify if the
balance is less than the minimum balance, write a check, withdraw
(override the method of the base class), and print account information. Add appropriate constructors.
c. Every bank offers a savings account. Derive the class
savingsAccount from the class bankAccount (designed in part
(a)). This class inherits members to store the account number and
the balance from the base class. A customer with a savings account
typically receives interest, makes deposits, and withdraws money. In
addition to the operations inherited from the base class, this class
should provide the following operations: set interest rate, retrieve
interest rate, post interest, withdraw (override the method of the
base class), and print account information. Add appropriate constructors.
Muhammad Sharjeel Husnain
4345
compiler used MS Visual Studio (Community Eddition)
*/
#include <iostream>
#include <string>
using namespace std;
class bankAccount {
protected:
	unsigned int accNo;
	double amount;
public:
	bankAccount() {
		accNo = 0;
		amount = 0.0;
	}
	void set();
	void deposit();
	void withdraw();
};
void bankAccount::set()
{
	cout << "enter account number" << endl;
	cin >> accNo;
}
void bankAccount::deposit()
{
	double fund;
	cout << "enter amount to deposit" << endl;
	cin >> fund;
	amount = amount + fund;
	cout << "Deposited" << endl;
}
void bankAccount::withdraw()
{
	double fund;
	cout << "enter amount to withdraw" << endl;
	cin >> fund;
	amount = amount - fund;
	cout << "withdraw successful!" << endl;
}
class checkingAccount :public virtual bankAccount {
public:
	checkingAccount() {
		accNo = 0;
		amount = 0.0;
	}
	void printAcc();
};


void checkingAccount::printAcc()
{
	cout << "Account Number is :" << accNo << endl;
	cout << "Account Balance is :" << amount << endl;
}
class savingAccount :public virtual bankAccount {
public:
	savingAccount() {
		accNo = 0;
		amount = 0.0;
	}
	void sDeposit();
};
void savingAccount::sDeposit() {
	double sFund;
	cout << "enter ammount to deposit" << endl;
	cin >> sFund;
	double intrest;
	intrest = (2 * sFund) / 100;
	amount = amount + sFund + intrest;
	cout << "2% Profit added " << endl;
}
int main() {
	checkingAccount p;
	savingAccount s;
	char choice;
	do {
		cout << "Press 1: Current Account" << endl;
		cout << "Press 2: Saving Account" << endl;
		cout << " Press 3: Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Press 1: Open Account" << endl;
			cout << "Press 2: Deposit" << endl;
			cout << "Press 3: Withdraw " << endl;
			cout << "Press 4: check Account " << endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				p.set();
				p.deposit();
				break;
			case '2':
				p.deposit();
				break;
			case '3':
				p.withdraw();
				break;
			case '4':
				p.printAcc();
				break;
			}
			break;
			
		case '2':
			cout << "Press 1: Open Account" << endl;
			cout << "Press 2: Deposit" << endl;
			cout << "Press 3: Withdraw " << endl;
			cout << "Press 4: check Account " << endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				p.set();
				s.sDeposit();
				break;
			case '2':
				s.sDeposit();
				break;
			case '3':
				p.withdraw();
				break;
			case '4':
				p.printAcc();
				break;
			}
			break;
		case '3':
			exit(0);
		}
		system("pause");
		system("cls");
	} while (true);
	return 0;
}
