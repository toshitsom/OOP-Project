//medicine

class Medicine:public hospital
{
  protected:
   char name[15];
   int med_id;
   float price;
   long int up_limit;
   long int sale;
   char category[5];

   public:
   void display();
   void edit();
   void add();
   void del();
   void med_in_hos();
   void hos_for_med();
   void check_epidemic();
};

//display
void Medicine::display()
{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t::MEDICINE DETAILS::\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t    CATEGORY\n\n";
	char line[100]; int i=0;
	ifstream f1("medicinedisp.csv");
	f1>>line; 
	while (!f1.eof())
       { i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  
       	  i++;
		}
		cout<<"\n";
		f1>>line;
	}
	getchar();
	f1.close();
}

//add
void Medicine::add()
{  char hos_id_temp[5];
   ofstream fp1("medicine.csv",ios::app|ios::out);
   ofstream fp2("medicinedisp.csv",ios::app|ios::out);
   again: 
      int post=1;
   ifstream fp("hospital.csv");
   char line[100];
   fp>>line;
    cout<<"\n\n\t\t\t\t\t\t\t\tHospital ID:: ";
    cin>>hos_id;
    while (!fp.eof())
{	    int c1=0;
        int i1=0;
        for( ;line[i1]!=',';i1++)
            {
            	hos_id_temp[c1++]=line[i1];
            }
          hos_id_temp[c1]='\0';
          if(strcmpi(hos_id_temp,hos_id)==0)
          {
             post=0;
             break;
          }
          fp>>line;
}
if(post==1)
{
    fp.close();
	cout<<"\n\t\t\t\t\t\t\t\tHOSPITAL DOES NOT EXIST.. ENTER AGAIN.. ";
	goto again;
}
    cout<<"\n\t\t\t\t\t\t\t\tMedicine Name:: ";
    cin>>name;   
    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: ";
    cin>>med_id;
    cout<<"\n\t\t\t\t\t\t\t\tPrice:: ";
    cin>>price;
    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: ";
    cin>>up_limit;
    cout<<"\n\t\t\t\t\t\t\t\tCategory:: ";
    cin>>category;
sale=0;

   fp1<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<up_limit<<","<<sale<<","<<category<<","<<endl;
   fp2<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<category<<","<<endl;
   getchar();
   fp1.close();
   fp2.close();
}


//edit
void Medicine::edit()
{  
   //system("cls");
   char line[100]; 
   int c,i;
   char strn[10];
   
   cout<<"\n\tMEDICINE EDIT";
   cout<<"\n\t1.EDIT with Name";
   cout<<"\n\t2.EDIT with ID";
   cout<<"\n\tChoice:: ";
   int ch;
   cin>>ch;
   int edit=0;                    
   
    ifstream ifs1("medicine.csv");
    ofstream ofs1("temp1.csv");
    ifstream ifs2("medicinedisp.csv");
    ofstream ofs2("temp2.csv");
    
    ifs1>>line; 
    
    	        	         char medname[15];    	        	        
							 int mid;
                   switch(ch)
				   {
				    case 1: {
					         cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine name:: ";
    	        	         cin>>medname;
    	        	         break;
    	        	        }
    	        	case 2: {
					     	cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine ID:: ";
    	        	        cin>>mid;
    	        	        break;
    	        	        }
    	        	default: exit(0);
    	            }
	   
	   while(!ifs1.eof())
    {

        c=0;
        i=0;
       for( ;line[i]!=',';i++)
            {
            	hos_id[c++]=line[i];
            }
          hos_id[c]='\0';

          c=0;
          i++;
          
        for( ;line[i]!=',';i++)
           {
            	name[c++]=line[i];
		   }
		   name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		   med_id = atoi (strn);

    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
            {
            strn[c++]=line[i];
            }
            strn[c]='\0';
            price = atof (strn);
 
        c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
           	strn[c++]=line[i];
           }
          strn[c]='\0';
		  up_limit = atoi (strn);
		  
  
        c=0;
        i++;
        		
        for( ;line[i]!=',';i++)
           {
          strn[c++]=line[i];
           }
          strn[c]='\0';
	      sale = atoi (strn);
 
        c=0;
        i++;        

        for( ;line[i]!=',';i++)
            category[c++]=line[i];
          category[c]='\0';
                    
             
    	        if(ch==2&&mid==med_id)
                  {
    	        	    edit=1;
    	        	    
    	        	    cout<<"\n\n\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCategory:: "<<category;
    	        	    cout<<"\n\n\n\t\t\t\t\t\t\t\t::EDIT MEDICINE DETAILS::";
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Name:: ";
    	        	 	cin>>name;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old ID:: ";
    	        	 	cin>>med_id;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Price:: ";
    	        	 	cin>>price;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Up Limit:: ";
    	        	 	cin>>up_limit;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old category:: ";
    	        	 	cin>>category;
    	        	 	
                        ofs1<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<up_limit<<","<<sale<<","<<category<<","<<endl;
                        ofs2<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<category<<","<<endl;
    	        	 	
					
				 }
				
				
			    else if(ch==1&&(strcmpi(medname,name)==0))
                  {     
                         cout<<"\n\n\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCategory:: "<<category;
    	        	    cout<<"\n\n\n\t\t\t\t\t\t\t\t::EDIT MEDICINE DETAILS::";
                        edit=1;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Name:: ";
    	        	 	cin>>name;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old ID:: ";
    	        	 	cin>>med_id;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Price:: ";
    	        	 	cin>>price;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Up Limit:: ";
    	        	 	cin>>up_limit;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old category:: ";
    	        	 	cin>>category;
    	        	 	
                        ofs1<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<up_limit<<","<<sale<<","<<category<<","<<endl;
                        ofs2<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<category<<","<<endl;
    	        	 	
					 }
                   
				    else
                       {
                        ofs1<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<up_limit<<","<<sale<<","<<category<<","<<endl;
                        ofs2<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<category<<","<<endl;
                       }
                    

        ifs1>>line;
        

     }
     
                    if(edit==1)
                    cout<<"\n\n\t\t\t\t\t\t\t\t::Editing complete::";
                    else
                    cout<<"\n\t\t\t\t\t\t\t\t::No File Found to be Edited::";
                    getchar();
     
     ifs1.close();
     ofs1.close();
     ifs2.close();
     ofs2.close();

    remove("medicine.csv");
    remove("medicinedisp.csv");
    rename("temp1.csv","medicine.csv");
    rename("temp2.csv","medicinedisp.csv");

}

//delete
void Medicine::del()
{
	 char line[100]; 
   int c,i;
   char strn[10];
   
   cout<<"\n\tMEDICINE DELETE";
   cout<<"\n\t1.DELETE with Name";
   cout<<"\n\t2.DELETE with ID";
   cout<<"\n\tChoice:: ";
   int ch;
   cin>>ch;
   int edit=0;                    
   
    ifstream ifs1("medicine.csv");
    ofstream ofs1("temp1.csv");
    ifstream ifs2("medicinedisp.csv");
    ofstream ofs2("temp2.csv");
    
    ifs1>>line; 
    
    	        	         char medname[15];    	        	        
							 int mid;
                   switch(ch)
				   {
				    case 1: {
					         cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine name:: ";
    	        	         cin>>medname;
    	        	         break;
    	        	        }
    	        	case 2: {
					     	cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine ID:: ";
    	        	        cin>>mid;
    	        	        break;
    	        	        }
    	        	default: exit(0);
    	            }
	   
	   while(!ifs1.eof())
    {

        c=0;
        i=0;
       for( ;line[i]!=',';i++)
            {
            	hos_id[c++]=line[i];
            }
          hos_id[c]='\0';

          c=0;
          i++;
          
        for( ;line[i]!=',';i++)
           {
            	name[c++]=line[i];
		   }
		   name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		   med_id = atoi (strn);
    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
            {
            strn[c++]=line[i];
            }
            strn[c]='\0';
            price = atof (strn);
 
        c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
           	strn[c++]=line[i];
           }
          strn[c]='\0';
		  up_limit = atoi (strn);
		  
  
        c=0;
        i++;
        		
        for( ;line[i]!=',';i++)
           {
          strn[c++]=line[i];
           }
          strn[c]='\0';
	      sale = atoi (strn);
 
        c=0;
        i++;        

        for( ;line[i]!=',';i++)
            category[c++]=line[i];
          category[c]='\0';
                    
             
    	        if(ch==2&&mid==med_id)
                  {
    	        	    edit=1;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t::THE MEDICINE BEING DELETE IS:: \n";
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCategory:: "<<category;
    	        	    
				 }
				
				
			    else if(ch==1&&(strcmpi(medname,name)==0))
                  {   
                        edit=1;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t::THE MEDICINE BEING DELETE IS:: \n";    	        	    
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCategory:: "<<category;
                        
					 }
                   
				    else
                       {
                        ofs1<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<up_limit<<","<<sale<<","<<category<<","<<endl;
                        ofs2<<hos_id<<","<<name<<","<<med_id<<","<<price<<","<<category<<","<<endl;
                       }
                    

        ifs1>>line;
        

     }
     
                    if(edit==1)
                    cout<<"\n\n\t\t\t\t\t\t\t\t::Editing complete::";
                    else
                    cout<<"\n\t\t\t\t\t\t\t\t::No File Found to be Edited::";
                    getchar();
     
     ifs1.close();
     ofs1.close();
     ifs2.close();
     ofs2.close();

    remove("medicine.csv");
    remove("medicinedisp.csv");
    rename("temp1.csv","medicine.csv");
    rename("temp2.csv","medicinedisp.csv");
    
    
	
}

void Medicine::check_epidemic()
{
	char line[100];
	char hos_id_hos[5];
	char strn[20];
	int c=0; int i=0; int flag=0;
	ifstream ifs1("medicine.csv");
//	cout<<"enter";
	
	
	    ifs1>>line; 
     // cout<<line<<endl;
	   while(!ifs1.eof())
    {

        c=0;
        i=0;
       for( ;line[i]!=',';i++)
            {
            	hos_id[c++]=line[i];
            }
          hos_id[c]='\0';

          c=0;
          i++;
          
        for( ;line[i]!=',';i++)
           {
            	name[c++]=line[i];
		   }
		   name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		   med_id = atoi (strn);
    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
            {
            strn[c++]=line[i];
            }
            strn[c]='\0';
            price = atof (strn);
 
        c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
           	strn[c++]=line[i];
           }
          strn[c]='\0';
		  up_limit = atoi (strn);
		  
  
        c=0;
        i++;
        		
        for( ;line[i]!=',';i++)
           {
          strn[c++]=line[i];
           }
          strn[c]='\0';
	      sale = atoi (strn);
 
        c=0;
        i++;        

        for( ;line[i]!=',';i++)
            category[c++]=line[i];
          category[c]='\0';
      // cout<<hos_id<<" "<<name<<" "<<price<<" "<<sale<<" "<<up_limit<<endl;   
        if(sale>=up_limit)
        {
        		 flag=1;
				 cout<<"\n\n\n";
	 for(i=0;i<170;i++)
        cout<<"!";
		cout<<"\n\t\t\t\t\t\t\tEPIDEMIC ALERT! EPIDEMIC ALERT! EPIDEMIC ALERT!";
            	         cout<<"\n\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCategory:: "<<category;
    	        	    cout<<"\n\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tHOSPITAL NAME\t\tCODE\t\t         DISTRICT\t\t\t\t   ADDRESS\n\n";
	ifstream fp1("hospital.csv");
	fp1>>line; 
	while (!fp1.eof())
    {    int k=0;
         c=0;
       for( ;line[k]!=',';k++)
            {
            	hos_id_hos[c++]=line[k];
            }
          hos_id_hos[c]='\0';
        if(strcmpi(hos_id_hos,hos_id)==0)
        { i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  i++;
		}
		cout<<"\n";
	   }
	   		fp1>>line;
}
fp1.close();
}
ifs1>>line;
}
ifs1.close();
if(flag==0)
{
	cout<<"\n\n\t\t\t\t\t\t\t\tNO EPIDEMIC DANGER!";
}
cout<<"\n\n\t\t\t\t\t\t\t\t Press any key to return ...... ";
getch();
}

int medicinefunctions()
{  
    Medicine m;
    while (1)
    {   system("cls");
        cout<<"\n";    
        for(int i=0;i<170;i++)
        cout<<"-";
        cout<<"\n\n\t\t\t\t\t\t\t\t:: PLATFORM FOR MEDICINE DATABASE MANAGEMENT ::\n\n";
        for(int i=0;i<170;i++)
        cout<<"-";
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MENU ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. Edit Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t5. Epidemic Check";
    	cout<<"\n\t\t\t\t\t\t\t\t\t6. EXIT";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	int choice;
    	cin>>choice;
    		switch(choice)
    		{
    			case 1: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.add(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
    			case 2: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.edit(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
				case 3: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.del(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
				case 4: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.display(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
						
				case 6: {
				         	return 0;
				         }

				case 5: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	hospital *h;
			            	h=&m;
			            	h->check_epidemic();
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}  
				default: break;		
			}
	}
    return 0;
}

int medicinefunctions_hos()
{  
    Medicine m;
    while (1)
    {   system("cls");
        cout<<"\n";    
        for(int i=0;i<170;i++)
        cout<<"-";
        cout<<"\n\n\t\t\t\t\t\t\t\t:: PLATFORM FOR MEDICINE DATABASE MANAGEMENT ::\n\n";
        for(int i=0;i<170;i++)
        cout<<"-";
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MENU ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. Display Medicine";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. EXIT";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	int choice;
    	cin>>choice;
    		switch(choice)
    		{
    			case 1: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.add();
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}

   			
				case 2: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	m.display(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
						
				case 3: return 0;
				default: break;		
			}
	}
    return 0;
}

void Medicine::med_in_hos()
{
   char line[100];
   char hos_id_med[5];
   int c,i,ch;
   int show=0;
   
   
       	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MEDICINE IN HOSPITALS ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Hospital Name";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. District";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. EXIT";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	cin>>ch;
    	
    	    	   char hos_search[20];    	        	        
                   switch(ch)
				   {
				    case 1: {
					         cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Hospital name:: ";
    	        	         cin>>hos_search;
    	        	         break;
    	        	        }
    	        	case 2: {
					     	cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter District:: ";
    	        	        cin>>hos_search;
    	        	        break;
    	        	        }
    	        	case 3: return;
    	        	default: return;
    	            }
   
   ifstream ifs1("hospital.csv");
   

    ifs1>>line; 
    

	   
	   while(!ifs1.eof())
    {

        c=0;
        i=0;
       for( ;line[i]!=',';i++)
            {
            	hos_id[c++]=line[i];
            }
          hos_id[c]='\0';

          c=0;
          i++;
          
        for( ;line[i]!=',';i++)
           {
            	hos_name[c++]=line[i];
		   }
		    hos_name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {

           }
			   
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
            	district[c++]=line[i];
		   }
		    district[c]='\0';

        c=0;
        i++;        
 
       if(strcmpi(hos_name,hos_search)==0&&ch==1)
       { show=1;
       	    	        cout<<"\n\n\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tDistrict:: "<<district;
    	        	    cout<<"\n";
    	        	            for(int j=0;j<170;j++)
                                cout<<"-";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t::MEDICINE DETAILS::\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t    CATEGORY\n\n";
	ifstream f1("medicinedisp.csv");
	f1>>line; 
	while (!f1.eof())
       { int k=0;
         c=0;
       for( ;line[k]!=',';k++)
            {
            	hos_id_med[c++]=line[k];
            }
          hos_id_med[c]='\0';
    if(strcmpi(hos_id_med,hos_id)==0)
    {   i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  
       	  i++;
		}
		cout<<"\n";
    }
		f1>>line;
   	 
   }
   f1.close();
   break;
  } 
        
     if(strcmpi(district,hos_search)==0&&ch==2)
   { 
   	show=1;
       	    	        cout<<"\n\n\t\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tDistrict:: "<<district;
    	        	    
    cout<<"\n\n\t\t\t\t\t\t\t\t\t::MEDICINE DETAILS::\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t    CATEGORY\n\n";
	ifstream f1("medicinedisp.csv");
	f1>>line; 
	while (!f1.eof())
       { int k=0;
         c=0;
       for( ;line[k]!=',';k++)
            {
            	hos_id_med[c++]=line[k];
            }
          hos_id_med[c]='\0';
    if(strcmpi(hos_id_med,hos_id)==0)
    {   i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  
       	  i++;
		}
		cout<<"\n";
    }
		f1>>line;
   	 
   }
   break;
   }
   ifs1>>line;
}
ifs1.close();
if (show==0)
{
	cout<<"\n\t\t\t\t\t\t\t\t\tNO HOSPITAL FOUND FOR THE GIVEN INPUT";
}
}



void Medicine::hos_for_med()
{
	 char line[100]; 
   char hos_id_hos[5]; 
   int c,i;
   int show=0;
   char strn[10];
   

   cout<<"\n\t\t\t\t\t\t\t\t\tMEDICINE SEARCH";
   int edit=0;                    
    ifstream ifs("medicinedisp.csv");
    
    ifs>>line; 
    
    char medname[15];   
	cout<<"\n\t\t\t\t\t\t\t\t\tEnter Medicine Name:: ";
	cin>>medname;
	while(!ifs.eof())
	{
		
        c=0;
        i=0;
       for( ;line[i]!=',';i++)
            {
            	hos_id[c++]=line[i];
            }
          hos_id[c]='\0';

          c=0;
          i++;
          
        for( ;line[i]!=',';i++)
           {
            	name[c++]=line[i];
		   }
		   name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		   med_id = atoi (strn);

    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
            {
            strn[c++]=line[i];
            }
            strn[c]='\0';
            price = atof (strn);
 
        c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
           	category[c++]=line[i];
           }
          category[c]='\0';
          

    	        if(strcmpi(medname,name)==0)
                  {
    	        	    show=1;
    	        	    
    	        	    cout<<"\n\n\t\t\t\t\t\t\t\t\tMedicine Name:: "<<name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tMedicine ID:: "<<med_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tPrice:: "<<price;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tUp Limit:: "<<up_limit;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t\tCategory:: "<<category;
    	        	    cout<<"\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tHOSPITAL NAME\t\tCODE\t\t         DISTRICT\t\t\t\t   ADDRESS\n\n";
	ifstream fp1("hospital.csv");
	fp1>>line; 
	while (!fp1.eof())
    {    int k=0;
         c=0;
       for( ;line[k]!=',';k++)
            {
            	hos_id_hos[c++]=line[k];
            }
          hos_id_hos[c]='\0';
        if(strcmpi(hos_id_hos,hos_id)==0)
        { i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  i++;
		}
		cout<<"\n";
	   }
		fp1>>line;
	}
	fp1.close();
}

ifs>>line;
}
ifs.close();
if(show==0)
cout<<"\n\t\t\t\t\t\t\t\t\tNO HOSPITAL HAS THIS MEDICINE";
}


