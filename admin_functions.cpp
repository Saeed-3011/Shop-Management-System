#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
static int user_add_counter=0,product_add_counter=0,limit=0;
static string user;

	
//**************************************************************Registring-Cashier**************************************************
	
void Register_Cashier(string &user_username,string &user_password)
{
	cout<<"\t\t\t\tRegister Cashier";
	line();
	
	cin.ignore();
					
					//If 1 cashier already exists then You can't add more
					
		if(user_add_counter==1)
		{
			cout<<"\n\n\t\t\t\tYou can't add more Cashiers.\n";
			return ;	
		}
					
					//If No Cashier Is Registered
					
		cout<<"Enter Cashier name : ";			//Asking Cashier Name
		getline(cin,user);
		
		cout<<"Enter Cashier username : ";     //Asking username for cashier
		getline(cin,user_username);
		
		cout<<"Enter Cashier password : ";		//Asking password for cashier
		getline(cin,user_password);
		user_add_counter++;
		
		system("cls");
		
		cout<<"\nCashier Added Successfuly!";	//Displaying Message 
	
	

 return ;
}

//**************************************************Viewing Cashier Details********************************************************					

void View_Cashier(string &user_username,string &user_password)
{
	cout<<"\t\t\t\tView Cashier";
	line();
	
				//If no cashier is registered then displaying a message
	
	if(user_add_counter==0)
	{
		cout<<"No user Available";
		return ;
	}
		
				//Displaying Cashier Details
		
	for(int i=0;i<user_add_counter;i++)
	{
		cout<<"Name : "<<user<<endl;
		cout<<"Username : "<<user_username<<endl;
		cout<<"Password : "<<user_password<<endl;
		
	}
	
	
}

//******************************************************Deleting Cashier********************************************************
						
void Delete_Cashier(string &user_username,string &user_password)
{
	cout<<"\t\t\t\tDelete Cashier";
	line();
	
					//If no cashier is registered then displaying a message
	
	if(user_add_counter==0)
	{
		cout<<"No user Available";
		return ;
	}
			
				//For Deleting Reseting All variables relating cashier details
			
	user_add_counter=0;
	user_username="";
	user_password="";
	
	system("cls");
	cout<<"\nCashier Deleted Successfuly!"; //Displaying Message
}


//*****************************************************Adding Product***********************************************************


void Add_Product(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tAdd Product";
	line();
	
		cin.ignore();
		
				//If limit of product is zero then displaying a message
		
		if(limit==0)
		{
			cout<<"\n\t\t\tSet Product Limit First.\n";
			return ;
		}
		
				//If product list reach his maximum value then generating message
		
		if(product_add_counter==limit)
		{
			cout<<"\n\t\t\tYou can't add more Products than "<<limit<<"\n";
			cout<<"\t\t\tIncrease your List Limit.\n";
			return ;	
		}
		
//					Getting Details Of Product
				
		cout<<"Enter Product Name : ";
		getline(cin,product_name[product_add_counter]);
		
		cout<<"Enter Product Price : ";
		cin>>product_price[product_add_counter];
		
		cout<<"Enter Quantity : ";
		cin>>product_quantity[product_add_counter];
		
		product_add_counter++;
		
		system("cls");
		cout<<"\nProduct Added Successfuly!";
	
}
	

//**************************************************Displaying Menu****************************************************************

//void Display



//***************************************************Viewing Stock******************************************************************
			
void View_Stocks(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tView Stocks";
	line();
	
			//If there is no product added then displaying message and returning back
	
	if(product_add_counter==0)
	{
		cout<<"No Product Available";
		return ;
	}
	
	
		cout<<"\n\t-----------------------------------------------------------------------------------";
		cout<<"\n\t|"<<setw(10)<<"S No."<<setw(5)<<"|"<<setw(20)<<"Product Name"<<setw(5)<<"|";
		cout<<setw(20)<<"Product Price"<<setw(5)<<"|"<<setw(12)<<"In Stock"<<setw(5)<<"|"<<endl;

		for(int i=0;i<product_add_counter;i++)
		{
			if(product_name[i]=="")
			break;
			cout<<"\t-----------------------------------------------------------------------------------\n";
			cout<<"\t|"<<setw(10)<<i+1<<setw(5)<<"|"<<setw(20)<<product_name[i]<<setw(5)<<"|";

			cout<<setw(20)<<product_price[i]<<setw(5)<<"|"<<setw(12)<<product_quantity[i]<<setw(5)<<"|"<<endl;
			
		}
		cout<<"\t-----------------------------------------------------------------------------------\n";
	
		
}

//******************************************************Empty Menu*****************************************************************
			
void Empty_Menu(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tEmpty Menu";
	line();
	
			//If no product is added then displaying message
	
	if(product_add_counter==0)
	{
		cout<<"Menu is already empty.";
		return ;
	}
	
			//Resetting all variables relating product 
	
	for(int i=0;i<product_add_counter;i++)
	{
		product_name[i]="";
		product_price[i]=0;
		product_quantity[i]=0;
	}
	
			//Resetting the product counter
	product_add_counter=0;
	
	system("cls");
	cout<<"\nMenu Refreshed Successfuly!";
	
}

//*********************************************************Updating Stock*************************************************************
			
void Update_Stock(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tUpdate Stock Of Product";
	line();
	
			//If no product is added then displaying message
	
	if(product_add_counter==0)
	{
		cout<<"Menu is empty.";
		return ;
	}
	
		cout<<"\n\t-----------------------------------------------------------------------------------";
		cout<<"\n\t|"<<setw(10)<<"S No."<<setw(5)<<"|"<<setw(20)<<"Product Name"<<setw(5)<<"|";
		cout<<setw(20)<<"Product Price"<<setw(5)<<"|"<<setw(12)<<"In Stock"<<setw(5)<<"|"<<endl;

		for(int i=0;i<product_add_counter;i++)
		{
			if(product_name[i]=="")
			break;
			cout<<"\t-----------------------------------------------------------------------------------\n";
			cout<<"\t|"<<setw(10)<<i+1<<setw(5)<<"|"<<setw(20)<<product_name[i]<<setw(5)<<"|";

			cout<<setw(20)<<product_price[i]<<setw(5)<<"|"<<setw(12)<<product_quantity[i]<<setw(5)<<"|"<<endl;
			
		}
		cout<<"\t-----------------------------------------------------------------------------------\n";
	
	int i,amount;
				//Getting Serial Of Product
	cout<<"Enter the serial of Product : ";
	cin>>i;
	
				//Checking validity of product serial
	
	if(i>product_add_counter || i<1)
	{
		cout<<"\nNo Item in Menu With This Serial "<<i;
	}
//					If serial is valid than asking for new quantity
	else
	{
		cin.ignore();
		cout<<"Enter the new quantity of "<<product_name[i-1]<<" : ";
		cin>>amount;
		
		product_quantity[i-1]+=amount;
		
		system("cls");
		cout<<"\n"<<product_name[i-1]<<" Stock Updated Successfuly!";
	}
	
	return;
}

//***************************************************Updating Price Of product***************************************************8			
			
void Update_Price(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tUpdate Price Of Product";
	line();
	
				//If no product is added then displaying message
	
	if(product_add_counter==0)
	{
		cout<<"Menu is empty.";
		return ;
	}
	
		cout<<"\n\t-----------------------------------------------------------------------------------";
		cout<<"\n\t|"<<setw(10)<<"S No."<<setw(5)<<"|"<<setw(20)<<"Product Name"<<setw(5)<<"|";
		cout<<setw(20)<<"Product Price"<<setw(5)<<"|"<<setw(12)<<"In Stock"<<setw(5)<<"|"<<endl;

		for(int i=0;i<product_add_counter;i++)
		{
			if(product_name[i]=="")
			break;
			cout<<"\t-----------------------------------------------------------------------------------\n";
			cout<<"\t|"<<setw(10)<<i+1<<setw(5)<<"|"<<setw(20)<<product_name[i]<<setw(5)<<"|";

			cout<<setw(20)<<product_price[i]<<setw(5)<<"|"<<setw(12)<<product_quantity[i]<<setw(5)<<"|"<<endl;
			
		}
		cout<<"\t-----------------------------------------------------------------------------------\n";
	
	int i;
	
	cout<<"Enter the serial of Product : ";
	cin>>i;
	
						//Checking validity of product serial
	
	if(i>product_add_counter || i<1)
	{
		cout<<"\nNo Item in Menu With Serial "<<i;
	}
	
				//If serial is valid then asking for new price
	
	else
	{
		cin.ignore();
		cout<<"Enter the new price of "<<product_name[i-1]<<" : ";
		cin>>product_price[i-1];
		
		system("cls");
		cout<<"\n"<<product_name[i-1]<<" Price Updated Successfuly!";	
	}
	
	
	return ;
}

//*****************************************************Edit Product**************************************************************     
     
void Edit_Product(string product_name[],int product_price[],int product_quantity[])
{
	cout<<"\t\t\t\tEdit Product";
	line();
	
				//If no product is added then displaying message
	
	if(product_add_counter==0)
	{
		cout<<"You can't edit without adding product.";
		return ;
	}
	
		cout<<"\n\t-----------------------------------------------------------------------------------";
		cout<<"\n\t|"<<setw(10)<<"S No."<<setw(5)<<"|"<<setw(20)<<"Product Name"<<setw(5)<<"|";
		cout<<setw(20)<<"Product Price"<<setw(5)<<"|"<<setw(12)<<"In Stock"<<setw(5)<<"|"<<endl;

		for(int i=0;i<product_add_counter;i++)
		{
			if(product_name[i]=="")
			break;
			cout<<"\t-----------------------------------------------------------------------------------\n";
			cout<<"\t|"<<setw(10)<<i+1<<setw(5)<<"|"<<setw(20)<<product_name[i]<<setw(5)<<"|";

			cout<<setw(20)<<product_price[i]<<setw(5)<<"|"<<setw(12)<<product_quantity[i]<<setw(5)<<"|"<<endl;
			
		}
		cout<<"\t-----------------------------------------------------------------------------------\n";
	
	int i;
	
	cout<<"Enter the serial of Product : ";
	cin>>i;
	
				//Checking validity of product serial
	
	if(i>product_add_counter || i<1)
	{
		cout<<"\nNo Item in Menu With Serial "<<i;
	}
	
				//If serial is valid then asking for new details for that serial
	
	else
	{
		cin.ignore();
		cout<<"Enter new name of product : ";
		getline(cin,product_name[i-1]);
		
		cout<<"Enter price of "<<product_name[i-1]<<" : ";
		cin>>product_price[i-1];
		
		cout<<"Enter stock of "<<product_name[i-1]<<" : ";
		cin>>product_quantity[i-1];
		
		system("cls");
		cout<<"\nSerial : "<<i<<" is replaced by "<<product_name[i-1]<<" Successfuly!";	
	}
	return ;
	
}

//*************************************************Changing Password Of Admin*******************************************

void Change_Password(string &admin_password)
{
	cout<<"\t\t\t\tChange Your Password";
	line();
	cin.ignore();
	
	cout<<"Enter new password : ";  //Asking For New Password
	getline(cin,admin_password);
	
	system("cls");
	cout<<"\nPassword Changed Successfuly!";
	return ;
}

//***************************************************Setting Number Of Products************************************************						
						
void Set_Product()
{
	cout<<"\t\t\t\tChoose Number Of Product";
	line();
	
			//Asking for the number of list that how how much product u can add
	int a;
	cout<<"No. of Items in List : ";
	cin>>a;
	limit+=a;
	
	system("cls");
	cout<<"\nProduct Limit is Updated!";
}
