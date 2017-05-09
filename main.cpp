//main
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<conio.h>

using namespace std;

#include "hospital.cpp"
#include "medicine.cpp"
#include "login2.cpp"


int main()
{    	system("mode 170,300");
   while (1) 
   { trip:
     system("cls");
	 cout<<"\n";
	 for(int i=0;i<170;i++)
        cout<<"-";
        cout<<"\n\n\t\t\t\t\t\t\t::DRUGS AND MEDICINE - MANAGEMENT & DISTRIBUTION  ::\n\n";
        for(int i=0;i<170;i++)
        cout<<"-";
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MAIN MENU ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Admin";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. Hospital Employee";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. Guest User";
    	cout<<"\n\t\t\t\t\t\t\t\t\t4. Exit";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	int ch;
    	cin>>ch;
    
		                    cout<<"\n";    
                            for(int j=0;j<170;j++)
                            cout<<"#";
    	int x;
   switch(ch)
   {
   	case 1:{   while (1)
	           { //system("cls");
	             x=0;
			     x=login(2);
			     if(x==1)
			     {
			     cout<<"\n\n\t\t\t\t\t\t\t\t\tLogin Successful!";
			     break;
			     }
			     else 
				 {
				 cout<<"\n\n\t\t\t\t\t\t\t\t\t::WRONG CREDENTIALS:: ";
				 getch();
				 goto trip;
			    }
			   }
			   while(1)
			   {
			   cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1. HOSPITAL";
			   cout<<"\n\t\t\t\t\t\t\t\t\t2. MEDICINE";
			   cout<<"\n\t\t\t\t\t\t\t\t\t3. EXIT";
			   cout<<"\n\t\t\t\t\t\t\t\t\tCHOICE:: ";
			   int choice; cin>>choice;
			   if (choice==1)
			   hospitalfunctions();
			   else if (choice==2)
			   medicinefunctions();
			   else if (choice==3);
			   break;
		       }
                 		
		       break;
	       }
	       
    case 2: {   while (1)
	           { //system("cls");
	             x=0;
			     x=login(1);
			     if(x==1)
			     {
			     cout<<"\n\t\t\t\t\t\t\t\t\tLogin Successful!";
			     break;
			     }
			     else 
				 {
				 cout<<"\n\n\t\t\t\t\t\t\t\t\t::WRONG CREDENTIALS:: ";
				 getch();
				 goto trip;
			    }
			   }
			   while(1)
			   {
			   cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1. HOSPITAL";
			   cout<<"\n\t\t\t\t\t\t\t\t\t2. MEDICINE";
			   cout<<"\n\t\t\t\t\t\t\t\t\t3. EXIT";
			   cout<<"\n\t\t\t\t\t\t\t\t\tCHOICE:: ";
			   int choice; cin>>choice;
			   if (choice==1)
			   hospitalfunctions_hos();
			   else if (choice==2)
			   medicinefunctions_hos();
			   else if (choice==3);
			   break;
		       }
    	
		break;
	}
	
case 3: {   while(1)
           {
   
	    	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t1. Search for Medicine in Hospitals";
    	    cout<<"\n\t\t\t\t\t\t\t\t2. Search for Hospitals having a medicine";
    	    cout<<"\n\t\t\t\t\t\t\t\t3. Exit";
    	    cout<<"\n\t\t\t\t\t\t\t\tCHOICE:: ";
    	    int choic;
    	    cin>>choic;
    	    Medicine med;
    	    if(choic==1)
    	    {
    	    	med.med_in_hos();
			}
			else if(choic==2)
			{
				med.hos_for_med();
			}
			else if(choic==3)
			{
				break;
			}
		   }
    	    
         	break;
        }
case 4: exit(0);
default: continue;

		   
   }
}
	
}

