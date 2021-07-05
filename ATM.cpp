// atm.cpp : Defines the entry point for the console application.
//

#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;
	double balance(500),	deposit, withdraw,transfer;
	int option;

	//balance = 500; //default amount
	vector<pair<int,int>> passbook;
	//vector<string> names;
	string transferid;
void func()
{
			//deposit 0
		//transfered 1
		//withdrawn -1
	int cnt=10;
	cout<<"\n\tTransaction Type              Amount\t \n";

	for (int i = passbook.size()-1; i >=0 ; --i)
	{
		if (passbook[i].first==1)
		{
			cout<<"\t  Transfered              "<<"\t  "<<passbook[i].second<<endl;
		}else if (passbook[i].first==-1)
		{
			cout<<"\t  Withdrew                "<<"\t  "<<passbook[i].second<<endl;
		}else{
			cout<<"\t  Depositied              "<<"\t  "<<passbook[i].second<<endl;
		}
		cnt--;
		if (!cnt)
		{
			break;
		}
	}
}

int main()
{
	//declare variables

	do
	{
		cout <<"\n\t*************MENU****************";
		cout <<"\n\t*                               *";
		cout <<"\n\t*        1. Check Balance       *";
		cout <<"\n\t*        2. Deposit             *";
		cout <<"\n\t*        3. Withdraw            *";
		cout <<"\n\t*        4. Transfer            *";
		cout <<"\n\t*        5. Transaction History *";
		cout <<"\n\t*        6. Exit                *";
		cout <<"\n\t*                               *";
		cout << "\n\t*********************************";
		cout << "\n\t  Please choose an option: ";
		
		cin>> option;

		switch (option){

		case 1: cout << "\n\tYour Balance is: $"<<balance <<endl;
			     break;

		case 2: cout << "\n\tAmount you want to deposit: $";
			    cin>>deposit;
				balance += deposit;
				passbook.push_back({0,deposit});
				cout<<"\n\t Current Balance: $" << balance <<endl;
				break;

		case 3: cout << "\n\tHow much do you want to withdraw?: $";
			cin>> withdraw;

			if(balance < withdraw)
				cout << "\n\tYou do not have enough money in your account to withdraw"<<endl;
			else{
				balance -= withdraw;
				passbook.push_back({-1,withdraw});
			}

			cout<<"\n\t Current Balance: $" << balance <<endl;
			 break;

		case 4: cout << "\n\tEnter the account ID of the recipient: ";
				cin>>transferid;
				//names.push_back(transferid);
				cout << "\n\tHow much do you want to transfer?: $";
				cin>>transfer;
				if(balance < transfer)
				cout << "\n\tYou do not have enough money in your account to transfer"<<endl;
			else{
				balance -= transfer;
				passbook.push_back({1,transfer});
			}
			break;

		case 5: cout<<"\n\t*************RECEIPT****************\n";
				func();
				break;

		default: if(option >6)
					 cout<< "\n\tInvalid option. Please try again" <<endl;;
			break;
		}

	} while (option != 6);


	cout<<"\n\t*************Thank You****************\n";
	return 0;
}
