#include<iostream>
#include<string>
using namespace std;

int sell_productcode,sell_productquantity,total_bill=0,item_quantity[20],cash=0;
string shop_name="Unique Shopping Center",buy_name,buy_number,item[20];

//**************************************************Start-Selling*************************************************************

void Start_Selling(string product_name[],int product_price[],int product_quantity[])
{
		int x=0,sell_status;
		while(x==0)
		{
			total_bill=0,cash=0;
			cout<<"\t\t\t\tStart Selling";
			line();
			int e=0,order_status=0,qf=0;
					
//								Displaying Menu With Updating Stock Until Selling is Not Closed
			
			while(e==0)
			{
				if(product_name[0]=="")
				{
					cout<<"\nNo item is available for selling.\n";
					return ;
				}
				cout<<"\n\t-----------------------------------------------------------------------------------";
				cout<<"\n\t|"<<setw(10)<<"S No."<<setw(5)<<"|"<<setw(20)<<"Product Name"<<setw(5)<<"|";
				cout<<setw(20)<<"Product Price"<<setw(5)<<"|"<<setw(12)<<"In Stock"<<setw(5)<<"|"<<endl;
				int i=0;
				for(i=0;i<1000;i++)
				{
					if(product_name[i]=="")
					break;
					cout<<"\t-----------------------------------------------------------------------------------\n";
					cout<<"\t|"<<setw(10)<<i+1<<setw(5)<<"|"<<setw(20)<<product_name[i]<<setw(5)<<"|";
		
					cout<<setw(20)<<product_price[i]<<setw(5)<<"|"<<setw(12)<<product_quantity[i]<<setw(5)<<"|"<<endl;
					
				}
				cout<<"\t-----------------------------------------------------------------------------------\n";
			
				cin.ignore();
			
									//Entering serial Of Item for Processing		
							
				cout<<"\nEnter the product serial : ";
				cin>>sell_productcode;
				
									//Validating The inputed serial Of Product
					
				if(sell_productcode>i || sell_productcode<1)
				{
					cout<<"\nNo such item is in Menu.\n";
				}
				else
				{
								//Entering Quantity Of That item If Serial Is Correct
					
					cout<<"\nQuantity of "<<product_name[sell_productcode-1]<<" : ";
					cin>>sell_productquantity;
					
								//Validating the Quantity of item with Stock Of Corresponding Item
					
					if(sell_productquantity>product_quantity[sell_productcode-1])
					{
						cout<<"\nNo much "<<product_name[sell_productcode-1]<<" is available.\n";
								
								//Asking for billing if he already ordered some item
								
						if(qf>0)
						{
							cout<<"\nEnter 1 for more 0 for billing : ";
							cin>>order_status;
						if(order_status==0)
						break;
						}
						
							
					}
					else
					{
								//After Validating The Serial And Quantity
						
						product_quantity[sell_productcode-1]-=sell_productquantity;//Updating the Stock Of Ordered Item
						
						total_bill+=sell_productquantity*product_price[sell_productcode-1];//Calculating Total Bill Of Ordered Item
						
						item[qf]=product_name[sell_productcode-1];	//Adding ordered item in a quee for billing purpose
						
						
						item_quantity[qf]=sell_productquantity;//Adding quantity of ordered item in quee for billing
						qf++;
						
								//Asking From User That He Wants to order more or not.
						
						cout<<"\nEnter 1 for more 0 for billing : ";
						cin>>order_status;
						cout<<endl;
						if(order_status==0)
						break;
					}
				}
			}
			if(order_status==0)
			{
								//Getting Details Of Costumer
				system("cls");
				
				cout<<"\n\n\t\t\t\t-------------------Costumer-Details--------------\n";
				cout<<"\nEnter buyer name : ";
				cin.ignore();
				getline(cin,buy_name);
				cout<<"\nEnter buyer number : ";	
				getline(cin,buy_number);
				cout<<"\nBill : "<<total_bill;
				
				cout<<"\n\nEnter cash amount : ";
				cin>>cash;
				
				if(cash<total_bill)
				{
					int cash2;
					
					while(cash<total_bill)
					{
						cout<<"\nEnter more cash : ";
						cin>>cash2;
						cash+=cash2;
						
					}
				}
				
				
				system("cls");
									//Printing Bill Of Costumer
								
				cout<<"\n\n\t\t\t\t-------------------Billing-Details---------------\n";
				
									//Displaying Shop Name
				
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				cout<<"\t\t\t\t|\t\t"<<shop_name<<"\t\t|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				
									//Displaying Headings Of BIll
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(25)<<"Product Name";
				cout<<right;
				cout<<setw(22)<<"Quantity  "<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
						
									//Displaying Contents Of Bill
				
				for(int i=0;i<20;i++)
				{
					if(item[i]=="")
					break;
					cout<<left;
					cout<<"\t\t\t\t|"<<setw(25)<<item[i];
					cout<<right;
					cout<<setw(22)<<item_quantity[i]<<"|";
					cout<<"\n\t\t\t\t-------------------------------------------------\n";
				}
				
								//Displaying total price
				
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(25)<<"Total-Price :";
				cout<<right;
				cout<<setw(22)<<total_bill<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				
				
								//Displaying Costumer Name
				
				
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(20)<<"Costumer Name : ";
				cout<<right;
				cout<<setw(27)<<buy_name<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
					
					
								//Displaying Costumer Number
					
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(20)<<"Contact No. : ";
				cout<<right;
				cout<<setw(27)<<buy_number<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				
								//Displaying Cash Given
				
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(20)<<"Cash Given : ";
				cout<<right;
				cout<<setw(27)<<cash<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				
								//Displaying Cash Given Back
				
				cout<<left;
				cout<<"\t\t\t\t|"<<setw(20)<<"Cash Back : ";
				cout<<right;
				cout<<setw(27)<<cash-total_bill<<"|";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";
				
							//Displaying Message
							
				cout<<"\t\t\t\t\t\tThanks ! For Coming.	";
				cout<<"\n\t\t\t\t-------------------------------------------------\n";	
			}
			
						//Asking from cashier that he wants to continue selling or not
			
			cout<<"\n\nEnter 1 for continue selling 0 for exit. : ";
			cin>>sell_status;
			
			if(sell_status==0)
			{
				system("cls");
				break;
			}
			
			cout<<endl;
			
			system("cls");
			line();
		}
			
 return ;
}

//***************************************************Changing Cashier Password****************************************************

void C_Password(string &cashier_password)
{
	cout<<"\t\t\t\tChange Your Password";
	line();
	cin.ignore();
			
			//Asking from new password
			
	cout<<"Enter new password : ";
	getline(cin,cashier_password);
	
	system("cls");
	cout<<"Password Changed Successfuly!\n";
	
	return ;
}

