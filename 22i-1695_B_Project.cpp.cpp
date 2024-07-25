#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;

int main()

{
	//-----------------------------------------------------PROJECT-22i-1695-CYS_B-------------------------------------------------------------------------------
	
	
	string arr[38][3],symbol[38]={"0"}, name[38]={"0"}, price[38]={"0"},temp;		//initialization variable
	float price1[38],prev[38];
	string username;
	char choice;
	int wallet=0,money=0,num=0,share[37];
	int total,totalshare=0;
	
	//-----------------------------------------------------		File handling-------------------------------------------------------------------------------
	
	fstream companies;
	companies.open("companies.txt",ios::in);						//reading file
	if(!companies)													//bad file
	{
		cout<<"File does'nt load !"<<endl;
	}	
	else	
	{
	int i=0; 	
	   do	
		{	
														//getline(companies,data,'ignore');
		getline(companies,arr[i][0],',');				//separating rows and columns from the file
		getline(companies,arr[i][1],',');
		getline(companies,arr[i][2]);
			
		i=i+1;
			
			
		}
		while (i<38&&!companies.eof());

			
	companies.close();
	}
	//-----------------------------------------------------Storing in 1D array-------------------------------------------------------------------------------
	for(int i=0;i<38;i++)
    {										//store symbol in 1d
    	symbol[i]=arr[i][0];
	}
	
	for(int i=0;i<38;i++)
    {										//storing name in 1d
    	name[i]=arr[i][1];
    	
	}
	
	for(int i=0;i<38;i++)
    {										//store price in 1d
    	price[i]=arr[i][2];
		
	}
		
	for(int i=1;i<38;i++)					//string to float
	{												
		temp=price[i];
		price1[i]=stof(temp);				//using function to store string price in 1D array
		;    	
		
	}	 
		 
	// -------------------------------------------------- random value task -------------------------------------------------------------------------------
	
	
	float max[38],min[38],fifteenper[38],randval[38];
	int sum[38];
	
	
/*	
	for(int i=1;i<38;i++)
	{
		fifteenper[i]=price1[i]*0.15;	
		max[i]=price1[i]+fifteenper[i];
		min[i]=price1[i]-fifteenper[i];
		sum[i]=max[i]+1 -min[i];	
	}
*/	
	srand(time(0));
//	for(int i=1;i<38;i++)
	//{
		

	//randval[i]=min[i] + rand() % sum[i];	

	//	cout<<randval[i]<<endl;

	//cout<<hehe<<endl;
	//}
	
	//--------------------------------------------------------high low ---------------------------------------------------------------------------------
	
	
	float high[38],low[38];
	
	for(int i=1;i<38;i++)
	{
	high[i]=price1[i];
	low[i]=price1[i];
	}
	
	
	for(int i=1;i<38;i++)
	{
		if(randval[i]>high[i])
		{
		high[i]=randval[i];
		}
		
		if(price1[i]<low[i])
		{
		low[i]=randval[i];
		}
				
		
	}
	
	//-----------------------------------------------------Output of stock market--------------------------------------------------------------------
	
	char ch;

	cout<<"\t\t\t\tKarachi Stock Market(Live)"<<endl;
	cout<<"Show updates: ENTER\t\tShow portfolio:P\t\tAdd stock:A\t\tRemove stock:R\t\tAdd money to account:M\t\tExit: Esc"<<endl;
	cout<<endl;
	cout<<"SYMBOL\t\t\t NAME\t\t\t\t\t\t\tPRICE"<<endl;


	for(int i=0;i<38;i++)
		{
			prev[i]=0;
		cout<<left<<setw(25)<<symbol[i]<<setw(55)<<name[i]<<setw(20)<<price[i]<<setw(20)<<prev[i]<<endl;
		}
	
		for(int i=1;i<38;i++)
		{
			low[i]=price1[i];

			high[i]=price1[i];
			prev[i]=price1[i];
		}
		
		
	while(ch!=27)
	{
	

				
			
		for(int i=1;i<38;i++)
		{
			fifteenper[i]=price1[i]*0.15;	
			max[i]=price1[i]+fifteenper[i];
			min[i]=price1[i]-fifteenper[i];
			sum[i]=max[i]+1 -min[i];	
		}
	
		
		for(int i=1;i<38;i++)
		{
			randval[i]=min[i] + rand() % sum[i];
				
		}
	
	
	
		for(int i=1;i<38;i++)
		{
				
			if(randval[i]>high[i])
			{
				high[i]=randval[i];
			}
		
			if(low[i]>randval[i])
			{
		
				low[i]=randval[i];
			
			}
		
		
		}
		
		// ---------------------------------------------------------	re	menu
		ch = getch();
		system("cls");
		
			
		
		if(ch == 13)  //if condition for Updating Stocks "Enter key"
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);	//yellow 	
			cout<<"\nShow updates: ENTER\t\tShow portfolio:P\t\tAdd stock:A\t\tRemove stock:R\t\tAdd money to account:M\t\tExit: Esc";
			cout<<endl;
			cout<<endl;
			
			cout<<left<<setw(10)<<"SYMBOL"<<left<<setw(50)<<"Name"<<setw(15)<<"Original"<<setw(15)<<"Previous"<<setw(16)<<"Random"<<setw(15)<<" HIGH"<<setw(15)<<" LOW"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white color
			cout<<endl;
			cout<<endl;
			
			for(int i=1;i<38;i++)
			{
					
			cout<<left<<setw(10)<<left<<symbol[i]<<setw(50)<<name[i]<<setw(15)<<setprecision(4)<<price1[i]<<setw(15)<<prev[i];
		
		
			if(randval[i]>prev[i])
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);	//green color
				cout<<"\x18  "<<setw(15)<<randval[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white color
				
			}
			else if(randval[i]<prev[i])
			{
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	//red color
				cout<<"\x19  "<<setw(15)<<randval[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white color	
			}
			else
			{
				cout<<"   "<<setw(15)<<randval[i];
			}
		
			cout<<setw(15)<<high[i]<<setw(15)<<low[i]<<endl;
		
		
			prev[i]=randval[i];
			
			
			}
			
			for(int i=1;i<38;i++)				//total share today
			{
				totalshare=price1[i] + totalshare;
			}
			cout<<endl;
			cout<<endl;
		cout<<"Total shares traded :  "<<totalshare<<endl;	
		}	
					//end of if statement of stock output
		
     	/*	if(ch= 27)
		{
			return 0;
			
		}/*/
		
	
		
		
		else if(ch == 'p' || ch == 'P')				//portfolio 
		{
				
			fstream folio;
			folio.open("portfolio.txt",ios::out);
			if(!folio)
			{
				cout<<"Portfolio file did'nt created";
			}
			else
			{
								
			
				cout<<"Enter User name:"<<endl;		
				cin>>username;				//user name
				folio<<"**********************************************************"<<endl;
				folio<<"Owner's Name: "<<username<<endl;
				folio<<endl;
			
				money=1+rand() % 1000000;				//generating random money in account
						
				cout<<username<<"'s Available money is: "<<money;		//showing money
			
	
				
				if(choice=13)
				{
					cout<<"\t\t\t\t\t\t"<<username<<" Portfolio(Live)"<<endl;
					cout<<endl;
					cout<<"Show updates: ENTER\t\tShow Live:L\t\tAdd stock:A\t\tRemove stock:R\t\tAdd money to account:M\t\tExit: Esc"<<endl;
					cout<<endl;
					cout<<setw(10)<<"Symbol"<<setw(50)<<"Name"<<setw(15)<<setprecision(4)<<"Current value"<<setw(15)<<"Previous val"<<endl;
					//writing in file
					
					folio<<"\t\t\t\t\t\t"<<username<<" Portfolio(Live)"<<endl;
					folio<<endl;
					
					
					for(int i=1;i<38;i++)
					{
						cout<<left<<setw(10)<<symbol[i]<<setw(50)<<name[i]<<setw(15)<<setprecision(4)<<randval[i]<<setw(15)<<setprecision(4)<<prev[i];
						cout<<endl;
				
					}
					
					cout<<"\n\nAdd money to account:M "<<endl;
					cout<<"Show Live:L"<<endl;
					cout<<"Add stock:A"<<endl;
					cout<<"Remove stock:R"<<endl;
					cout<<"\n\n\nWould you want to perform any  operation from them: ";
					cin>>choice;
					switch(choice)
					{
						case 'm':
						case 'M':
						{
						
						
							
						cout<<"Add amount:"<<endl;
						cin>>wallet;
						wallet=wallet+money;
						cout<<wallet<<" is available"<<endl;
						}
						
						
						case 'l':
						case 'L':
							{
								ch=getch();
								system("cls");
							}
							break;
							
						case 'a':
						case 'A':
						{
							
							//	ch=getch();
								system("cls");
							
							
							
							for(int i=1;i<38;i++)
							{
								cout<<i<<" = "<<symbol[i]<<endl;
							}
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
									cout<<money<<" is available"<<endl;
									folio<<money<<" is available"<<endl;
									
									folio<<"**********************************************************"<<endl;
									
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
									wallet=money;
								do
								{
									cout<<"\n\npress 0 to exit"<<endl;
									cout<<endl;
								
								
									
									cout<<"\n\nenter symbol name for which you want to buy shares: "<<endl;
									cin>>num;
									cout<<endl;
									cout<<endl;
									cout<<setw(10)<<"Symbol "<<setw(50)<<"Name "<<setw(15)<<"current price"<<setw(15)<<"previous "<<endl;
									cout<<left<<setw(10)<<left<<symbol[num]<<setw(55)<<name[num]<<setw(15)<<setprecision(4)<<randval[num]<<setw(15)<<prev[num];
									
									cout<<"\nHow many share do you want :";
									cin>>share[num];	
									total=share[num]*randval[num];
									if(total<=wallet)
									{
									wallet=wallet-total;
										cout<<"\nYou bought "<<share[num]<<" of "<<symbol[num]<<" successfully"<<endl;
										cout<<"\nyour remaining balance is : "<<wallet<<endl;
									
										//writing in file
										folio<<endl;
										folio<<endl;
										folio<<setw(10)<<"symbol"<<setw(55)<<"Name"<<setw(10)<<"Shares"<<setw(15)<<"current val"<<setw(15)<<"previous"<<endl;				
										folio<<left<<setw(10)<<left<<symbol[num]<<setw(55)<<name[num]<<setw(10)<<share[num]<<setw(15)<<setprecision(4)<<randval[num]<<setw(15)<<prev[num];
										cout<<endl;
									}
									
									else 
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
										cout<<"not enough balance in account "<<endl;
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
									}
										folio<<"\nyour remaining balance is : "<<wallet<<endl;	
								}while(num!=0);
								cout<<"press ENTER to return to live screen";
								
							
						}		
					}
					
				
					
					
					
				}
				
			
			
	
		
			}//end of folio else
			
		}// end of first if
		
		
		
		else if(ch == 'a' || ch=='A')
		{
			cout<<"First go to portfolio to enter your details"<<endl;
		}
		else if(ch=='r' || ch=='R')
		{
			cout<<"First go to portfolio to enter your details"<<endl;
		}
		else if(ch=='M' || ch=='m')
		{
			cout<<"First go to portfolio to enter your details"<<endl;
		}
		else
		{
			cout<<"Invalid input Press ENTER to return Esc of exit"<<endl;
		}
		
				
	}		//end of while statement
	
	

	
	
	
	
	
	
	
	return 0;
}