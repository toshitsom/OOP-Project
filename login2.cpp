//login

int login(int login_choice)
{
	   ifstream fp1("employee.csv");
       ifstream fp2("admin.csv");
       char id[20];
       char id_temp[20];
       char pass[20];
       char pass_temp[20];
       char line[100];
       int i=0; int k=0; char ze;
       
    //EMPLOYEE LOGIN
       if(login_choice==1)
{      
       cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter USERNAME:: ";
       cin>>id_temp;
       cout<<"\n\t\t\t\t\t\t\t\t\tEnter PASSWORD:: "; 
       fp1>>line;
         while(ze!='\r')
        {
            ze=getch();
            cout<<"*";
            pass_temp[i++]=ze;
        }
        pass_temp[--i]='\0';
       while(!fp1.eof())
      {
        i=0;
      for(;line[i]!=',';i++)
        {
		  id[k++]=line[i];
        }
      id[k]='\0';

      i++;
      k=0;
     
	  for(;line[i]!=',';i++)
        {
		  pass[k++]=line[i];
        }
      pass[k]='\0';
      i=0;
      k=0;
      
      if(strcmp(pass,pass_temp)==0&&strcmp(id,id_temp)==0)
      	{
		  return 1;
     	}
    
      	
    fp1>>line;
       
       }
       
	   fp1.close();
       fp2.close();
       return 0;
}

    //ADMIN LOGIN
     else if(login_choice==2)
{      
       cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter USERNAME:: ";
       cin>>id_temp;
       cout<<"\n\t\t\t\t\t\t\t\t\tEnter PASSWORD:: ";
         while(ze!='\r')
        {
            ze=getch();
            cout<<"*";
            pass_temp[i++]=ze;
        }
        pass_temp[--i]='\0';
        fp2>>line;
       while(!fp2.eof())
      {
        i=0;
      for(;line[i]!=',';i++)
        {
		  id[k++]=line[i];
        }
      id[k]='\0';

      i++;
      k=0;
     
	  for(;line[i]!=',';i++)
        {
		  pass[k++]=line[i];
        }
      pass[k]='\0';
      i=0;
      k=0;

      if(strcmp(pass,pass_temp)==0 && strcmp(id,id_temp)==0 )
    { 
	   return 1;
     }
       fp2>>line;
       }
       
	   fp1.close();
       fp2.close();
       return 0;
}

return 0;

}

