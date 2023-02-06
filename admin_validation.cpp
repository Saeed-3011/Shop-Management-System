#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include "Admin/admin_start.cpp"
using namespace std;
string admin_username="admin 123",admin_password="admin 123";

void admin_validate(string &user_username,string &user_password,string product_name[],int product_price[],int product_quantity[])
{
	system("cls");
	
	line();
	cout<<"\t\t\t\t\tAdmin";
	line();
	
	bool stat=0;
	int tries=3;
	string username,password;
	cin.ignore();
				
				//Attempting login till tries is not equal to zero
				
	while(tries!=0)
	{
						
		cout<<"\nEnter your username : ";     //Asking Username 
		getline(cin,username);
		
		cout<<"Enter your password : ";     //Asking Password
		getline(cin,password);
		
						//Validating The Username And Passowrd
		if(username==""||password=="")
			cout<<"You can't leave any input blank.\n";
			
		else if(username==admin_username&&password==admin_password)
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
					stat=1;  //If OTP is correct then aliving his status
					break;
				}
				else{
					tre--;	//On false OTP Decreasing tries and generating error
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
		
					//If Admin status is alive Then Proceeding To Admin Panel
	
	if(stat==1)
	{
		system("cls");
		line();
		cout<<"\t\tCongrats! You are logged in successfuly in Admin Panel.";
		Admin(admin_password,user_username,user_password,product_name,product_price,product_quantity);
		return ;
	}
					//If all tries are lost returning to main function
	else
	{
		cout<<"\nSorry! Try another time.";
		return ;
	}
}

