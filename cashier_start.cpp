#include<iostream>
#include "cashier_functions.cpp"
using namespace std;
void Cashier(string &cashier_password,string product_name[],int product_price[],int product_quantity[])
{
	
	
	int i=0;
	while(i==0)
	{
		line();
		cout<<"\t\t\t\tCahier";
					//Displaying Then Menu Of Different Actions for Cashier
		line();		
		cout<<"\n\t\t\t\t1.Start Selling\n";
		cout<<"\t\t\t\t2.Change Password\n";
		cout<<"\t\t\t\t0.Logout\n";
		line();
			
					//Asking the choice of cashier from the given menu
		
		int choice;
		cout<<"Enter Your Choice : ";
		cin>>choice;
					//If choice is 0 then logouts the cashier and break the infinite loop
		if(choice==0)
		{
			system("cls");
			break;
		}
		
		system("cls");
		line();
		
					//Transfering Cashier Control To Different Section According To Choice
		
		switch(choice)
		{
			case 1:
				Start_Selling(product_name,product_price,product_quantity);
				break;
			
			case 2:
				C_Password(cashier_password);
				break;
			
			default :
				cout<<"\nInvalid Choice\n";
		}
	}
 return ;
}

