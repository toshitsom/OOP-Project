//hospital
class hospital
{
  protected:
    char  hos_name[25];
    int code;
    char district[25];
    char hos_id[5];
    char addr[50];

   public:
   void display_hos();
   void edit_hos();
   void add_hos();
   void del_hos();
   virtual void check_epidemic()
   {
   }
};


//display
void hospital::display_hos()
{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t::HOSPITAL DATABASE ::\n\n";
	cout<<"\t\t\tHOSPITAL ID\t\tHOSPITAL NAME\t\tCODE\t\t         DISTRICT\t\t\t\t   ADDRESS\n\n";
	char line[100]; int i=0;
	ifstream fp1("hospital.csv");
	fp1>>line; 
	while (!fp1.eof())
       { i=0;
	    while(line[i]!='\0')
        { cout<<"\t\t\t";
       	  for(;line[i]!=',';i++)
       	  cout<<line[i];
       	  i++;
		}
		cout<<"\n";
		fp1>>line;
	}
	getchar();
	fp1.close();
}

//add
void hospital::add_hos()
{
    ofstream fp1("hospital.csv",ios::app|ios::out);
    cout<<"\n\n\t\t\t\t\t\t\t\tCODE(NUMERIC):: ";
    cin>>code;
    cout<<"\n\t\t\t\t\t\t\t\tDISTRICT:: ";
    cin>>district;   
    cout<<"\n\t\t\t\t\t\t\t\tHOSPITAL NAME:: ";
    cin>>hos_name;
    cout<<"\n\t\t\t\t\t\t\t\tHOSPITAL ID:: ";
    cin>>hos_id;
    cout<<"\n\t\t\t\t\t\t\t\tADDRESS AND CONTACT DETAILS:: ";
    cin>>addr;

   fp1<<hos_id<<","<<hos_name<<","<<code<<","<<district<<","<<addr<<","<<endl;
   getchar();
   fp1.close();
}

//edit
void hospital::edit_hos()
{  
   //system("cls");
    char line[100];
    int c,i;
    char strn[10];
   
   cout<<"\n\t\t\t\t\t\t\t\tHOSPITAL EDIT";
   cout<<"\n\t\t\t\t\t\t\t\t1.EDIT with Hospital Code";
   cout<<"\n\t\t\t\t\t\t\t\t2.EDIT with Hospital Name";
   cout<<"\n\t\t\t\t\t\t\t\tChoice:: ";
   int ch;
   cin>>ch;
   int edit=0;                    
   
    ifstream ifs1("hospital.csv");
    ofstream ofs1("t2.csv");
    
    ifs1>>line; 
    
    	        	         char dis[25];    	        	        
							 int cd;
                   switch(ch)
				   {
				    case 1: {
					         cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Code:: ";
    	        	         cin>>dis;
    	        	         break;
    	        	        }
    	        	case 2: {
					     	cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Name:: ";
    	        	        cin>>dis;
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
            	hos_name[c++]=line[i];
		   }
		    hos_name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		    code = atoi (strn);

    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
            	district[c++]=line[i];
		   }
		    district[c]='\0';

        c=0;
        i++;        

        for( ;line[i]!=',';i++)
            addr[c++]=line[i];
          addr[c]='\0';
                    
             
    	        if(ch==1&&(strcmpi(dis,hos_id)==0))
                  {
    	        	    edit=1;
    	        	    
    	        	    cout<<"\n\n\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tDistrict:: "<<district;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tAddress:: "<<addr;
    	        	    cout<<"\n\n\n\t\t\t\t\t\t\t\t::EDIT HOSPITAL DETAILS::";
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Hospital Name:: ";
    	        	 	cin>>hos_name;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Hospital ID:: ";
    	        	 	cin>>hos_id;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old District:: ";
    	        	 	cin>>district;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Address:: ";
    	        	 	cin>>addr;
    	        	 	
                        ofs1<<hos_id<<","<<hos_name<<","<<code<<","<<district<<","<<addr<<","<<endl;
    
    	        	 	
					
				 }
				
				
			    else if(ch==2&&(strcmpi(dis,hos_name)==0))
                  {    
				        cout<<"\n\n\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tDistrict:: "<<district;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tAddress:: "<<addr;
    	        	    cout<<"\n\n\n\t\t\t\t\t\t\t\t::EDIT HOSPITAL DETAILS::";
    	        	    edit=1;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Hospital Name:: ";
    	        	 	cin>>hos_name;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Hospital ID:: ";
    	        	 	cin>>hos_id;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old District:: ";
    	        	 	cin>>district;
    	        	 	cout<<"\n\t\t\t\t\t\t\t\tEnter New/Old Address:: ";
    	        	 	cin>>addr; 
                         
    	        	 	
    	        	 	
                        ofs1<<hos_id<<","<<hos_name<<","<<code<<","<<district<<","<<addr<<","<<endl;
    	        	 	
					 }
                   
				    else
                       {
						 ofs1<<hos_id<<","<<hos_name<<","<<code<<","<<district<<","<<addr<<","<<endl;
            
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

    remove("hospital.csv");
    rename("t2.csv","hospital.csv");

}

//delete
void hospital::del_hos()
{
	char line[100];
    int c,i;
    char strn[15];
   
   cout<<"\n\t\t\t\t\t\t\t\tHOSPITAL DELETE";
   cout<<"\n\t\t\t\t\t\t\t\t1.DELETE with  Hospital Name";
   cout<<"\n\t\t\t\t\t\t\t\t2.DELETE with Hospital Code";
   cout<<"\n\t\t\t\t\t\t\t\tChoice:: ";
   int ch;
   cin>>ch;
   int edit=0;                    
   
    ifstream ifs1("hospital.csv");
    ofstream ofs1("t2.csv");
    
    ifs1>>line; 
                   char dis[25];    	        	        
    
                   switch(ch)
				   {
				    case 1: {
					         cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital name:: ";
    	        	         cin>>dis;
    	        	         break;
    	        	        }
    	        	case 2: {
					     	cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Code:: ";
    	        	        cin>>dis;
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
            	hos_name[c++]=line[i];
		   }
		    hos_name[c]='\0';

        c=0;
        i++;


        for( ;line[i]!=',';i++)
           {
            strn[c++]=line[i];
            }
            strn[c]='\0';
		    code = atoi (strn);

    
	    c=0;
        i++;

        for( ;line[i]!=',';i++)
           {
            	district[c++]=line[i];
		   }
		    district[c]='\0';

        c=0;
        i++;        

        for( ;line[i]!=',';i++)
            addr[c++]=line[i];
          addr[c]='\0';
                    
                if(ch==2&&(strcmpi(dis,hos_id)==0))
                  {
    	        	    edit=1;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t::THE RECORD BEING DELETE IS:: \n";
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tAddress:: "<<addr;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tDistrict:: "<<district;
    	        	    
				 }
				
				
			    else if(ch==1&&(strcmpi(dis,hos_name)==0))
                  {   
                        edit=1;
    	        	    cout<<"\n\t\t\t\t\t\t\t\t::THE RECORD BEING DELETE IS:: \n";    	        	    
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital Name:: "<<hos_name;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tHospital ID:: "<<hos_id;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tAddress:: "<<addr;
    	        	    cout<<"\n\t\t\t\t\t\t\t\tCode:: "<<code;
                        
					 }
                   
				    else
                       {
						 ofs1<<hos_id<<","<<hos_name<<","<<code<<","<<district<<","<<addr<<","<<endl;
                
                       }
                    

        ifs1>>line;
        

     }
     
                    if(edit==1)
                    cout<<"\n\n\t\t\t\t\t\t\t\t::Deleting complete::";
                    else
                    cout<<"\n\t\t\t\t\t\t\t\t::No File Found to be Edited::";
                    getchar();
     
     ifs1.close();
     ofs1.close();
     getchar();

    remove("hospital.csv");
    rename("t2.csv","hospital.csv");
}
int hospitalfunctions()
{
    hospital h;
    while (1)
    {   system("cls");
        cout<<"\n";    
        for(int i=0;i<170;i++)
        cout<<"-";
        cout<<"\n\n\t\t\t\t\t\t\t\t:: PLATFORM FOR HOSPITAL DATABASE MANAGEMENT ::\n\n";
        for(int i=0;i<170;i++)
        cout<<"-";
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MENU ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. Edit Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t5. EXIT";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	int choice;
    	cin>>choice;
    		switch(choice)
    		{
    			case 1: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.add_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
    			case 2: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.edit_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
				case 3: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.del_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
				case 4: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.display_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
						
				case 5: return 0;
				default: break;		
			}
	}
    return 0;
}

int hospitalfunctions_hos()
{
    hospital h;
    while (1)
    {   system("cls");
        cout<<"\n";    
        for(int i=0;i<170;i++)
        cout<<"-";
        cout<<"\n\n\t\t\t\t\t\t\t\t:: PLATFORM FOR HOSPITAL DATABASE MANAGEMENT ::\n\n";
        for(int i=0;i<170;i++)
        cout<<"-";
    	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t:: MENU ::\n";
    	cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t2. Edit Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t3. Display Hospital";
    	cout<<"\n\t\t\t\t\t\t\t\t\t4. EXIT";
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter Choice:: ";
    	int choice;
    	cin>>choice;
    		switch(choice)
    		{
    			case 1: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.add_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
    			case 2: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.edit_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}
   			
				case 3: {
                            cout<<"\n";    
                            for(int i=0;i<170;i++)
                            cout<<"#";
			            	h.display_hos(); 
			            	cout<<"\n\n\n\t\t\t\t\t\t\t\t\tPress ANY KEY to continue";
			            	getchar();
							break;
						}    			
						
				case 4: return 0;
				default: break;		
			}
	}
    return 0;
}

