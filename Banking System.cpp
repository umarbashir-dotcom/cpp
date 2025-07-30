//						*****Our Project (BANKING SYSTEM) in Structured Programming.
#include <iostream>
using namespace std;
void showMenu(){
	cout<<"1. Create New Account\n"
		<<"2. Display All Accounts\n"
		<<"3. Search Account\n"
		<<"4. Deposit Money\n"
		<<"5. Withdraw Money\n"
		<<"6. Modify Account\n"
		<<"7. Delete Account\n"
		<<"8. Exit\n";		
}
void createAccount(string names[],string type[],int number[],double balance[],int & count){
	cout<<"*Please Enter the Following Details to create new account:-\n";
	cout<<"Enter Name: ";
	getline(cin,names[count]);
	cout<<"Enter Type of Account: ";
	getline(cin,type[count]);
	static int accountNumber=10001;
	cout<<"Your Account is successfully created.\n";
	number[count]=accountNumber;
	cout<<"Your Account Number is "<<accountNumber<<endl;
	double deposit;
	cout<<"Enter initial deposit to Activate the Account(Initial deposit should be greater than Rs.500): ";
	cin>>deposit;
	cin.ignore();
	balance[count]=deposit;
	while (deposit<=500){ 
		cout<<"Invalid initial deposit.Please Deposit Amount greater than Rs.500: ";
		cin>>deposit;
		cin.ignore();
		balance[count]=deposit;
	}
	accountNumber++;
	count++;
}
void displayAccounts(string names[],string type[],int number[],double balance[],int count){
	if(count<1){
		cout<<"No account is created yet.Please!Create Account First.\n";
		return;
	}
	
	cout<<"=== Displaying All Accounts ===\n";
	cout<<"   Name\t\tType\tBalance\tAccount Number\n";
	for(int i=0;i<count;i++){
		cout<<i+1<<". "<<names[i]<<"   "<<type[i]<<"   "<<balance[i]<<"\t"<<number[i]<<endl;
	}
	cout<<"*************************************************************\n";
}
void searchAccount(string names[],string type[],int number[],double balance[],int count){
	if(count<1){
		cout<<"No account is created yet.Please!Create Account First.\n";
		return;
	}
	cout<<"Enter Account Number of person whose information you want to see: ";
	int accountNumber;
	cin>>accountNumber;
	cin.ignore();
	int i;
	for ( i=0;i<count;i++){
		if(number[i]==accountNumber){
			cout<<"Person found:\n";
			cout<<names[i]<<"	 "<<type[i]<<"		"<<balance[i]<<"   "<<number[i]<<endl;
			break;
		}
	}
	if (i==count){	
		cout<<"Invalid Account Number!Account with this Account Number does not exist!\n";
	}
}
double positiveDeposit(double deposit,double balance[],int i){
	balance[i]=balance[i]+deposit;
	return deposit;
}
double negativeDeposit(double deposit,double balance[],int i){
	while (deposit<1){
		cout<<"Invalid Amount!Please Enter correct Amount: ";
		cin>>deposit;
		cin.ignore();
	}
	balance[i]=balance[i]+deposit;
	return deposit;
}
void depositMoney(int number[],double balance[],int count){
	if(count<1){
		cout<<"Your account is not created yet.Please!Create Account First.\n";
		return;
	}
	cout<<"Enter Account Number of person in whom account you want to deposit Money: ";
	int accountNumber;
	cin>>accountNumber;
	cin.ignore();
	int i;
	double deposit;
	for ( i=0;i<count;i++){
		if(number[i]==accountNumber){
		
			
			cout<<"Enter Amount: ";
			cin>>deposit;
			cin.ignore();
			if (deposit>0)
				deposit=positiveDeposit(deposit,balance,i);
			else if (deposit<1)
				deposit=negativeDeposit(deposit,balance,i);
			break;
		}
	}
	if (i==count){
		cout<<"Invalid! Account Number.Again ";
		depositMoney(number,balance,count);
	}
	else 
		cout<<"Amount ("<<deposit<<") is deposited successfully.\n";
	return ;
}
void withdrawMoneylessThanzero(double withdrawAmount,double balance[],int i);
void withdrawMoneygreaterThanbalance(double withdrawAmount,double balance[],int i){
	while (withdrawAmount>balance[i]){
			cout<<"You cannot withdraw Amount greater than your balance.\n"
				<<"Your balance is "<<balance[i]<<".Please enter valid transaction amount: ";
			cin>>withdrawAmount;
			cin.ignore();
	}
	if(withdrawAmount<0)
		withdrawMoneylessThanzero(withdrawAmount,balance,i); 
	else
		balance[i]=balance[i]-withdrawAmount;
	return;
}
void withdrawMoneylessThanzero(double withdrawAmount,double balance[],int i){
	while (withdrawAmount<0){
		cout<<"Invalid Amount!Please Enter correct Amount: ";
		cin>>withdrawAmount;
		cin.ignore();		
	}
	if (withdrawAmount>balance[i])
		withdrawMoneygreaterThanbalance(withdrawAmount,balance,i);
	else 
		balance[i]=balance[i]-withdrawAmount;
	return;
}

void withdrawMoney(int accNumber[],double balance[],int count){
	if(count<1){
		cout<<"Your account is not created.Please!Create Account First.\n";
		return;
	}
	cout<<"Enter Account Number of person from whose  account you want to withdraw Money: ";
	int accountNumber;
	cin>>accountNumber;
	cin.ignore();
	int i;
	for ( i=0;i<count;i++){
		if(accNumber[i]==accountNumber){
			double withdrawAmount;
			cout<<"Enter Withdraw Amount : ";
			cin>>withdrawAmount;
			cin.ignore();
			
			if(withdrawAmount>balance[i]){
				withdrawMoneygreaterThanbalance(withdrawAmount,balance,i);
			}
			else if(withdrawAmount<0){
				withdrawMoneylessThanzero(withdrawAmount,balance,i);
			}
			else
				balance[i]=balance[i]-withdrawAmount;
				
			cout<<"Transaction Performed Successfully.\n";
			break;
		}		
	}
	if(i==count){
		cout<<"Wrong Account Number!\n";
		cout<<"Again ";
		withdrawMoney(accNumber,balance,count);
	}
	return ;
}
void modifyName(string names[],int i){
	cout<<"Enter new name: ";
	getline(cin,names[i]);
	cout<<"Your name is modified successfully.\n";
	return;
}
void modifyType(string type[],int i){
	cout<<"Enter Account Type: ";
	getline(cin,type[i]);
	cout<<"Your account Type is modified successfully.\n";
	return;
}
void modifyAccount(string names[],string type[],int number[],int count){
	if(count==0){
		cout<<"You have not created account.Please!Create Account first.\n";
		return;
	}
	cout<<"Enter Account Number: ";
	int accNumber;
	cin>>accNumber;
	cin.ignore();
	for(int i=0;i<count;i++){
		if(accNumber==number[i]){
			cout<<"You can only modify name and type :";
			string choice;
			cout<<"Which you want to modify (name/type or both): ";
			cin>>choice;
			cin.ignore();
			if(choice=="name" || choice=="Name")
				modifyName(names,i);
			if(choice=="type" || choice=="Type")
				modifyType(type,i);
			if(choice=="both" || choice=="Both")
			    {
			    modifyName(names,i);
			    modifyType(type,i);
				}
			break;	
		}
	}
}

void deleteAccount(string names[],string type[],int number[],double balance[],int &count){
	if(count<1){
		cout<<"No Account is created yet!Please Create Account first.\n";
		return;
	}
	int accNumber;
	cout<<"Enter Account Number which you want to delete: ";
	cin>>accNumber;
	int i;
	for( i=0;i<count;i++){
		if(accNumber==number[i]){
			for(i=i;i<count;i++){
				number[i]=number[i+1];
				names[i]=names[i+1];
				type[i]=type[i+1];
				balance[i]=balance[i+1];
			}
		count--;
		cout<<"Account deleted Successfully.\n";
		return;
		}
	}
	if(i==count){
		cout<<"Wrong Account Number!Again ";
		deleteAccount(names,type,number,balance,count);
	}
	
}
int main(){
	cout<<"**** BANKING SYSTEM ****\n";
	const int maxAccounts=100;
	string  names[maxAccounts];
	string accountType[maxAccounts];
	int accountNumbers[maxAccounts];
	double balance[maxAccounts];
	int count=0;
	int choice;
	
	while(true){
		showMenu();
		cout<<"Enter your choice: ";
		cin>>choice;
		cin.ignore();
		switch (choice){
			case 1:{
				createAccount(names,accountType,accountNumbers,balance,count);
				break;
			}
			case 2:{
				displayAccounts(names,accountType,accountNumbers,balance,count);
				break;
			}
			case 3:{
				searchAccount(names,accountType,accountNumbers,balance,count);
				break;
			}
			case 4:{
				depositMoney(accountNumbers,balance ,count);
				break;
			}
			case 5:{
				withdrawMoney(accountNumbers,balance,count);
				break;
			}
			case 6:{
				modifyAccount(names,accountType,accountNumbers,count);
				break;
			}
			case 7:{
				deleteAccount(names,accountType,accountNumbers,balance,count);
				break;
			}
			case 8:{
				cout<<" ------------EXITING THE PROGRAM-------------\n";
				exit(0);
				break;
			}
			default:
				cout<<"Invaid Input!Please See MENU with open eyes ** \n";
		}	
	}
	return 0;
}
