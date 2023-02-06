#include<iostream>
#include "line.cpp"
#include "admin_validation.cpp"
#include "cashier_validation.cpp"

string user_username="",user_password="",product_name[1000];int product_price[1000],product_quantity[1000];


using namespace std;
int main()
{
					line();
					cout<<"\t\t\t\tUnique Shopping Center";
						
	int i=0;
	while(i==0)
	{
						//Displaying Then Menu Of Different Actions for Cashier	
		line();
		cout<<"\n\t\t\t\t\t1.Admin\n";
		cout<<"\t\t\t\t\t2.Cashier\n";
		cout<<"\t\t\t\t\t0.Exit\n";
		line();
		
					//Asking the choice of cashier from the given menu
		
		int choice;
		cout<<"Enter Your Choice : ";
		cin>>choice;
		
					//If choice is 0 then existing the function
		
		if(choice==0)
		break;
		switch(choice)
		{
			case 1:
				admin_validate(user_username,user_password,product_name,product_price,product_quantity);
				break;
			
			case 2:
				cashier_validate(user_username,user_password,product_name,product_price,product_quantity);
				break;
				
			default :
				cout<<"\nInvalid Choice\n";

		}
	}
	
	system("cls");
	cout<<"\n\n\n";
	line();		
	cout<<"\t\t\t\tThanks! for using our service.";
	line();
	cout<<"\n\n\n";
	system("PAUSE");
	
 return 0;
}

