//Overview: A program that emulates an ATM.
//Author: John Garcia

#include <string>
#include <iostream>
using namespace std;


//***Class Development***
class CheckingAccount
{
private:
	string name, accountNum; double amount; int pin;
public:
	//Constructor
	CheckingAccount(string n, string acc, double amnt, int p)
	{name = n; accountNum = acc; amount = amnt; pin = p;}

	//Set
	void setAmount(double amnt)
	{amount = amnt;}

	//Get
	string getName()
	{return name;}

	string getAccountNumber()
	{return accountNum;}

	double getAmount()
	{return amount;}

	int getPin()
	{return pin;}
}; //class CheckingAccount


class SavingsAccount
{
private:
	string name, accountNum; double amount; int pin;
public:
	//Constructor
	SavingsAccount(string n, string acc, double amnt, int p)
	{name = n; accountNum = acc; amount = amnt; pin = p;}

	//Set
	void setAmount(double amnt)
	{amount = amnt;}

	//Get
	string getName()
	{return name;}

	string getAccountNumber()
	{return accountNum;}

	double getAmount()
	{return amount;}

	int getPin()
	{return pin;}
}; //class SavingsAccount


//***Function Development***
int main()
{
	//Initialize Users Checking Accounts
	const int num = 3;
	CheckingAccount user[num] = 
	{
		CheckingAccount("John", "1", 5000.00, 1111),
		CheckingAccount("Laurel", "2", 5000.00, 2222),
		CheckingAccount("Josh", "3", 1.00, 3333)
	};

	//Initialize Users Savings Accounts
	const int sNum = 2;
	SavingsAccount sUser[sNum] = 
	{
		SavingsAccount("John", "1", 2000.00, 1111),
		SavingsAccount("Laurel", "2", 3000.00, 2222)
	};

	//Begin ATM session
	bool isSessionOn = true, isCustomer = false, isSelect = false;
	string accountNumber;

	while(isSessionOn == true)
	{
		//ATM Introduction and get account number
		cout << "\n";
		cout << "-ATM-" << endl;
		cout << "Welcome to the 24 hour ATM service." << endl;
		cout << "Please insert your card." << endl;
		cout << "Enter your account number: ";
		cin >> accountNumber;

		//Check if match to anyone in our user base
		string username; double balance; int id, pin; //id for identifying which user
		for(int i = 0; i < num; i++)
		{
			//Account number check
			if(accountNumber == user[i].getAccountNumber())
			{
				cout << "Enter your PIN: ";
				cin >> pin;

				//Pin check
				if(user[i].getPin() == pin)
				{
					isCustomer = true;
					id = i;
					username = user[i].getName();
					balance = user[i].getAmount();
				}

				//Pin error
				else
				{
					cout << "\n";
					cout << "***Error***" << endl;
					cout << "PIN is incorrect." << endl;
					cout << "Please try again." << endl;
				}
			}
		}

		//Customer logs in
		if(isCustomer == true)
		{
			//Prompt user to account options
			int select = 0; char selectAnother = ' ';
			while(isSelect == false)
			{
				cout << "\n";
				cout << "-Menu-" << endl;
				cout << "Welcome " << username << "!" << endl;
				cout << "Select the number for that option." << endl;
				cout << "1. View balance." << endl;
				cout << "2. Deposit money into your account." << endl;
				cout << "3. Withdraw money from your account." << endl;
				cout << "4. Exit" << endl;
				cout << "Select: ";
				cin >> select;

				//*Selected options*

				//1. View balance
				if(select == 1)
				{
					cout << "\n";
					cout << "-View balance-" << endl;
					cout << "Your balance: $" << balance << endl;

					//Prompt user if they want to do another option
					cout << "\n";
					cout << "Would you like to select another option? Y or N?" << endl;
					cout << "Your Answer: ";
					cin >> selectAnother;

					if(selectAnother == 'N')
					{
						cout << "\n";
						cout << "Goodbye." << endl;
						return(0);
					}

					else
						; //Prompts user back to options menu
				} //View balance

				//2. Deposit
				double deposit = 0, d_Amount = 0;
				if(select == 2)
				{
					cout << "\n";
					cout << "-Deposit-" << endl;
					cout << "Current balance: $" << balance << endl;
					cout << "Enter the amount to deposit: ";
					cin >> deposit;

					if(deposit == 0)
					{
						cout << "\n";
						cout << "No changes made. Balance remains the same." << endl;
					}

					else
					{
						d_Amount = balance + deposit;
						user[id].setAmount(d_Amount); //Set the new amount for user

						cout << "\n";
						cout << "Deposit successful!" << endl;
						cout << "Your new balance is $" << d_Amount << endl;
					}
					
					//Prompt user if they want to do another option
					cout << "\n";
					cout << "Would you like to select another option? Y or N?" << endl;
					cout << "Your Answer: ";
					cin >> selectAnother;

					if(selectAnother == 'N')
					{
						cout << "\n";
						cout << "Goodbye." << endl;
						return(0);
					}

					else
						; //Prompts user back to options menu
				} //Deposit

				//3. Withdraw
				double withdraw = 0, w_Amount = 0;
				if(select == 3)
				{
					cout << "\n";
					cout << "-Withdraw-" << endl;
					cout << "Current balance: $" << balance << endl;
					cout << "Enter the amount to withdraw: ";
					cin >> withdraw;

					if(withdraw == 0)
					{
						cout << "\n";
						cout << "No changes made. Balance remains the same." << endl;
					}

					else if(withdraw <= balance)
					{
						w_Amount = balance - withdraw;
						user[id].setAmount(w_Amount); //Set the new amount for user

						cout << "\n";
						cout << "Withdraw successful!" << endl;
						cout << "Your new balance is $" << w_Amount << endl;
					}

					//Withdrawing more than what user has
					else
					{
						cout << "***Error***";
						cout << "You do not have enough money to withdraw that amount." << endl;
					}

					//Prompt user if they want to do another option
					cout << "\n";
					cout << "Would you like to select another option? Y or N?" << endl;
					cout << "Your Answer: ";
					cin >> selectAnother;

					if(selectAnother == 'N')
					{
						cout << "\n";
						cout << "Goodbye." << endl;
						return(0);
					}

					else
						; //Prompts user back to options menu
				} //Withdraw

				//4. Exit
				else if(select == 4)
				{
					cout << "\n";
					cout << "Goodbye." << endl;
					return(0);
				} //Exit

				//Not a correct option
				/*else
				{
					cout << "***Error***" << endl;
					cout << "Please select from the options shown." << endl; 
					cout << "\n";
				}*/
			} //while isSelect is false
		} //if isCustomer is true

		//Login error
		else
		{
			cout << "***Error***" << endl;
			cout << "Found no match for this account number." << endl;
			cout << "Please try again." << endl;
			//Prompts user back to beginning here
		} //otherwise isCustomer is false
	} //ATM session running
	return 0;
} //main()