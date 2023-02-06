#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include "Cashier/cashier_start.cpp"

using namespace std;

void cashier_validate(string &user_username,string &user_password,string product_name[],int product_price[],int product_quantity[])
{
	system("cls");
	
	line();
	cout<<"\t\t\t\tCashier";
	line();
	
//				If Cashier is not registered then generating error and returning to main function
	
	if(user_username=="" && user_password=="")
	{
		cout<<"\nCashier Not Registered Yet.!\n";
		return ;
	}
	
	bool stat=0;
	int tries=3;
	string username,password;
	cin.ignore();
	
					//Attempting login till tries is not equal to zero
	
	while(tries!=0)
	{
		
		cout<<"\nEnter your username : ";    //Asking username
		getline(cin,username);
		
		cout<<"Enter your password : ";		//Asking Password
		getline(cin,password);
		
						//Validating The Username And Passowrd					
				
		if(username==""||password=="")
			cout<<"You can't leave any input blank.\n";
			
		else if(username==user_username&&password==user_password)
		{
				//If Username and Password are Correct Then Transfering For OTP Verification
			
			int otp,random,tre=5;
						//OTP has also  5 tries
			while(tre!=0)
			{	
				srand(time(0));
				random=rand();
				cout<<"\nOTP : "<<random<<endl;
				cout<<"Enter the above OTP Code : ";
				cin>>otp;
					
						//Validating the OTP Entered By user
				
				if(otp==random)
				{
					stat=1;			//If OTP is correct then aliving cashier status
					break;
				}
				else
				{
					tre--;			//On false OTP Decreasing tries and generating error
					cout<<"\nTry Again!\n";
					cout<<tre<<" OTP's left.\n";
				}	
			}
			
						//Failing In OTP Returning To Main Function
			
			if(tre==0)
			return ;
			
			break;
			
		}
					//If username and password are not matched then decreasing his tries and generating error
		else
		{
			tries--;
			cout<<"\nEntered Credentials is Incorrect.";
			cout<<"\nYou have left "<<tries<<" attemps.\n";
		}
	}
	
					//If Cashier status is alive Then Proceeding To Cashier Panel
	
	if(stat==1)
	{
		system("cls");
		line();
		cout<<"\t\tCongrats! You are logged in successfuly in Cashier Panel.";
		Cashier(user_password,product_name,product_price,product_quantity);
		return ;
	}
					//If all tries are lost returning to main function
	else
	{
		cout<<"\nSorry! Try another time.";
		return ;
	}
}

