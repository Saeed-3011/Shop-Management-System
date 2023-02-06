#include<iostream>
#include "admin_functions.cpp"

using namespace std;
void Admin(string &admin_password,string &user_username,string &user_password,string product_name[],int product_price[],int product_quantity[])
{
		
		
					//Displaying Message For Admin If Item List Is'nt Blank
					//And thier stock is less than 5
		
		for(int i=0;i<1000;i++)
		{
			if(product_name[i]=="")
			break;
			
			if(product_name[i]!="" && product_quantity[i]<=5)
			cout<<"\n\t\t\t"<<product_name[i]<<" Stock Is Near To End.";
		}
		
		
		int i=0;
		while(i==0)
		{
			line();
			cout<<"\t\t\t\t\tAdmin";
			
					//Displaying Then Menu Of Different Actions for Admin
			line();
			cout<<"\n\t\t\t\t1.Register Cashier\n";
			cout<<"\t\t\t\t2.View Cashier\n";
			cout<<"\t\t\t\t3.Delete Cashier\n";
			cout<<"\t\t\t\t4.Set Limit Of Product List\n";
			cout<<"\t\t\t\t5.Add Product\n";
			cout<<"\t\t\t\t6.View Stocks\n";
			cout<<"\t\t\t\t7.Update Stock\n";
			cout<<"\t\t\t\t8.Update Price\n";
			cout<<"\t\t\t\t9.Edit Product\n";
			cout<<"\t\t\t\t10.Empty Menu\n";	
			cout<<"\t\t\t\t11.Change Your Password\n";
			cout<<"\t\t\t\t0.Logout\n";
			line();
			
							//Asking the choice of admin from the given menu
			
			int choice;
			cout<<"Enter Your Choice : ";
			cin>>choice;
			
			
							//If choice is 0 then logouts the admin and break the infinite loop
			
			if(choice==0)
			{
				system("cls");
				break;
			}
			
			system("cls");
			line();
							//Transfering Admin Control To Different Section According To Choice
			
			switch(choice)
			{
				case 1:
					Register_Cashier(user_username,user_password);
					break;
				
				case 2:
					View_Cashier(user_username,user_password);
					break;
				
				case 3:
					Delete_Cashier(user_username,user_password);
					break;
				
				case 4:
					Set_Product();
					break;
						
				case 5:
					Add_Product(product_name,product_price,product_quantity);
					break;
					
				case 6:
					View_Stocks(product_name,product_price,product_quantity);
					break;
					
				case 7:
					Update_Stock(product_name,product_price,product_quantity);
					break;
					
					
				case 8:
					Update_Price(product_name,product_price,product_quantity);
					break;	
				
				case 9:
					Edit_Product(product_name,product_price,product_quantity);
					break;
					
				case 10:
					Empty_Menu(product_name,product_price,product_quantity);
					break;
					
				case 11:
					Change_Password(admin_password);
					break;
					
				default :
				cout<<"\nInvalid Choice\n";
			}
		}
}

