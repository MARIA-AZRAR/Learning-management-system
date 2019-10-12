
// MARIA AZRAR
// 2018-CS-50

#include<iostream>        //to take input output
#include<string>          //to use string datatype
#include<conio.h>         // used for getch
#include<fstream>         //to open file
#include<sstream>         //to input string from file
#include<cstring>

using namespace std;

int fcount=0;             //counter for file input
int p=0;                  //p is a flag for deleted courses
int flag=0;               //flag for deletd students
int counter=0;            //counter for courses
int filestd=0;            //counter for student file input
int regc=0;               //counter for registered students
string cCode[100];        //arrays
string cName[100];
int semester[100];
int CH[100];
string stdName[100];
string stdRegNo[100];
const int No_of_rows=100;
const int No_of_columns=50;
string StdCourseList[No_of_rows][No_of_columns];

bool isValidCourse(string a){               //to check if a course code is valid i.e[CS101]

    int m=0;
	int A=0;                   //counter for alphabet
	int D=0;                   //counter for numaeric data
	for(int i=0;i<2; i++)                                
	{
	if(a[i]>='A'&&a[i]<='Z')
		A=A+1;
}
for(int i=2;i<5;i++)
	 {
	 if(a[i]>='0'&&a[i]<='9')	
		D=D+1;
	}
	for(int i=0;a[i]!='\0';i++)
	   m++;

	
	
   {  
		if(A==2&&D==3&&m==5)
		return 1;
		else
		return 0;
   }
}
bool isValidCreditHour(int a)                        //to check if a credit hour is valid i.e[1-3]
{
if(a==1||a==2||a==3)                        
         return 1;                              
return 0;                              
}

bool isValidSmester(int a)                              //to check if a smester is valid i.e[1-8]
{
         if(a>=0&&a<=8)
         return 1;
return 0;
}
bool isValidCourseName(string b)                      //to check if a course name is valid or not

{
int f=0;
for(int i=0;b[i]!='\0';i++)
{

     	 if(b[i]>='a'&&b[i]<='z'||b[i]>='A'&&b[i]<='Z'||b[i]==' ')
     	{
     	 	
		}
    	 else
    	 {
    	     f=2;	
		 }
    	
    	 
}
    	 if(f==2)
    	 {
    	 	return 0;
		 }
         else
            return 1;


}
bool isValidRegistrationNumber(string a){                 //To check if registeration number is valid or not i.e[201X-XX-111]          
    int m=0;
	int A=0;                   
	int D=0; 
	int C=0;                  
     
    if(a[0]=='2')
    A=A+1;
    if(a[1]=='0')
    A=A+1;
    if(a[2]=='1')
    A=A+1;
	if(a[3]>='0'&&a[3]<='9')
	A=A+1;
		
	 if(a[4]=='-')
	   A=A+1;

      for(int i=5;i<7;i++)
	 {
	 if(a[i]>='A'&&a[i]<='Z')	
		D=D+1;
	}
	if(a[7]=='-')
	D=D+1;
	for(int i=8;i<11;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		C=C+1;
	}
	
	for(int i=0;a[i]!='\0';i++)
	   m++;

   {  
		if(A==5&&D==3&&C<=3&&m<=11)
		return 1;
		else
		return 0;
   }
}
   
bool isValidStudentName(string b)
{    
        int f=0;                             //flag to check if student name is valid
        for(int i=0;b[i]!='\0';i++)
{

     	 if(b[i]>='a'&&b[i]<='z'||b[i]>='A'&&b[i]<='Z'||b[i]==' ')
     	 {
     	 	
		  }
    	 else
    	  f=2;
    
}
    	 if(f==2)
    	 {
    	 	return 0;
		 }
         else
            return 1;

}

   
   
void AddCourse(string a[],int b[],int c[],string d[],string code,int ch,int s,string name)
{
    
	static int l=fcount;                //static int l is used as a counter to store value into arrays
	int m=0;                               //m is used as a counter to check if details entered by the users are correct
	if(isValidCourse(code))
	{
		m++;
	}else
	{
		cout<<"invalid course code"<<endl;
	}
		if(isValidCreditHour(ch))
	{
		m++;
	}else
	{
		cout<<"invalid credit hour"<<endl;
	}	if(isValidSmester(s))
	{
		m++;
	}else
	{
		cout<<"invalid smester"<<endl;
	}
	if(isValidCourseName(name))
	{
		m++;
	}
	else
	{
		cout<<"invalid course name"<<endl;
	}
	if(m==4)
	{
	 if(p==0)                                    
	 {
		                                 //if user only Adds courses without deleting
	  cCode[l]=code;
	 CH[l]=ch;
	 semester[l]=s;
	 cName[l]=name;
	 cout<<"course has been added successfully."<<endl;
	 counter++;                            //counters increment each time a course is added
      }
      else if(p==1)
      {                                       //if user delets the courses and adds new courses after deleting
      	l=counter-1;
      	cCode[l]=code;
	    CH[l]=ch;
	   semester[l]=s;
	   cName[l]=name;
	   cout<<"course has been added successfully."<<endl;
	   counter++;
      	
	  }
	 
	}
	
	  l++;                         //l increments to update the index in an array
	  
}

void EditCourse(string a[],int b[],int c[],string d[],string cod)
{
	
	string co,name;
	int ch,s;
	int index;
	int f=0;              //flag is used in case if a course enterd exsists in the array
	int m=0;
	for(int i=0;i<counter;i++)
	{
		if(a[i]==cod)
	           {
					index=i;                //it stores the index of location where i is found
                     f=1;
		        }
	}
	if(f==1)
	{
		cout<<"Enter the updated details of course: ";
		cin>>co>>ch>>s;
	    getline(cin,name);
		int m=0;
		if(isValidCourse(co))
		{
			m++;
		}
		else
		{
		cout<<"invalid course code"<<endl;
		}
		if(isValidCreditHour(ch))
		{
		m++;
		}
		else
		{
		cout<<"invalid credit hour"<<endl;
		}	
		if(isValidSmester(s))
		{
			m++;
		}
		else
		{
			cout<<"invalid smester"<<endl;
		}
	if(isValidCourseName(name))
	{
		m++;
	}
	else
	{
		cout<<"invalid course name"<<endl;
	}	
		if(m==4)
		{
			a[index]=co;
			b[index]=ch;
			c[index]=s;
			d[index]=name;
			cout<<"course has been Updated successfully."<<endl;
		}	
}
}
void DeleteCourse( string l[], int b[], int c[], string d[],string cod)
{   
       
	   int index;
	   for(int i=0;i<counter;i++)
	{
	 	if(l[i]==cod)
	    {
	    	index=i;           //it findes the index where value is stored
		}
    }
      for(int i=index;i<counter;i++)
      {
      	
      	l[i]=l[i+1];
      	b[i]=b[i+1];
      	c[i]=c[i+1];
      	d[i]=d[i+1];
      	p=1;

	  }
	
	  cout<<"course have been sucessfully deleted."<<endl;
	  
}


void ViewCourse(string a[],int b[], int c[],string d[])
{
     		    
					cout<<"\tCOURSE CODE\t\t";
					cout<<"CREDIT HOUR\t\t";
					cout<<"SEMESTER\t\t";
					cout<<" NAME";
					cout<<endl;
			     	for(int i=0;i<counter;i++)
			{
					cout<<"\t"<<a[i]<<"\t\t\t";
					cout<<b[i]<<"\t\t\t";			
					cout<<c[i]<<"\t\t\t";
					cout<<d[i];
					cout<<endl;
			}	
}
void ViewSemesterCourses(string a[], int b[], int c[], string d[], int s)           //to view the courses f a specific smester

{
	
	if(isValidSmester(s))
	   {
	   	        	cout<<"\tCOURSE CODE\t\t";
					cout<<"CREDIT HOUR\t\t";
					cout<<" NAME";
					cout<<endl;
	     	for( int i=0;i<counter;i++)
	   	    {
	   		   if(c[i]==s)                //to check if the semester is found 
	   		  {
				 	cout<<"\t"<<a[i]<<"\t\t\t";
					cout<<b[i]<<"\t\t\t";			
					cout<<d[i];
					cout<<endl;	
			  }
	     	}
	   	
	   	
	  }
	  else
	  {
	  	cout<<"Invalid Semester";
	  }
}

bool SaveCourses(string a[],int b[],int c[],string d[])                 //used to save courses in a file
{
             	ofstream outdata;
             	outdata.open("Courses.txt");               //used to oppen the text file
             	
                if(p==0)
             	{
				 for (int i=0;i<counter;i++)
             	{
             	   outdata<<a[i]<<","<<d[i]<<","<<b[i]<<","<<c[i]<<endl;	
				}
			    }
			    
			    if(p==1)
             	{
				 for (int i=0;i<counter-1;i++)
             	{
             	   outdata<<a[i]<<","<<d[i]<<","<<b[i]<<","<<c[i]<<endl;	
				}
			    }
				outdata.close();              //used to close the opened file
			 }
			 


bool  LoadCourses(string a[],int b[],int c[],string d[])
{
             	ifstream ifile("Courses.txt");
                 if(ifile) 
                 {
                 	int creditH,smes;
                 	string line,ccode,cname,temp1,temp2;
                 	
                    while(getline(ifile,line))         // this code will sore first line of the file in variable line
				      {
				      	
				        stringstream ss(line);              //stringstream is a stream class to operate on strings.
				 		getline(ss, ccode, ',');            //this will store the text in course code until it encounters comma
				 		getline(ss, cname, ',');
				 		getline(ss, temp1, ',');
				 		creditH=stoi(temp1);              //this will convert string to integer
				 		getline(ss, temp2, ',');
				 		smes=stoi(temp2);
				 		a[fcount]=ccode;
				 		d[fcount]=cname;
				 		b[fcount]=creditH;
				 		c[fcount]=smes;
				 		fcount++;                   //it is a file counter
				 		counter++;                  //counter to count add courses
				 		
				     }
				     ifile.close();                 //to close the file we will use this
    	
				 }
                else
                  cout<<"File does not Exist."<<endl<<endl;

			 }
	
bool LoadUsers(string usersList[], string passwordsList[])           //this is used in order to load the courses
            {
	           int c=0;
	           ifstream ufile("Users.txt");               //this will open the text file
	           if(ufile)
	              {
	              	string uname,pass,line1;
	              	while(getline(ufile,line1))              
	              	  {
	              	  	stringstream ss(line1); 
	              	  	getline(ss, uname, ',');
	              	  	getline(ss, pass, ',');
	              	  	usersList[c]=uname;
	              	  	passwordsList[c]=pass;
	              	  
	              	  	c++;   
							                     //counter for the users authorized to operate
					  }
					  ufile.close();
					  cout<<endl<<"Dear User, current software is intended for authorized users only."<<endl;
                      cout<<"Login to the system to get access."<<endl;
                      string username,password;
    
                      cout<<"Username : ";
                      cin>>username;
                      cout<<"Password : ";
                      cin>>password;
                      for(int i=0;i<c;i++)
                          {
                          	  if(usersList[i]==username&&passwordsList[i]==password)
                          	        {
                          	        	return 1;
									}
								
					      }
								   
	                     return 0;
			
			      }
	           
	           else
	             {
				    cout<<endl<<"Sorry, we are unable to run the program, as user data does not exist."<<endl;
	               
	             }
            }
            
void addStudent(string stdName[], string stdRegNo[], string studentName, string regNo){
	

	 static int stdl=filestd-1;                //static int stdl to give index to store the student name and registeration number in arrays FILESTD-1 IS WRITTEN AS FIRST WE WILL LOAD COURSES FROM FILE
	 regc=regc-1;
                           
	 int m=0;                         //counter to check if course name and registeration number is valid.
	 
	  if(isValidRegistrationNumber(regNo))
	  {
	  	m++;
	  }
	  else
	  {
	  	cout<<"Invalid Registeration Number. Enter the right syntax i.e[201X-XX-111]."<<endl;
	  }
	  if(isValidStudentName(studentName))
	  {
	  	m++;
	  }
	  else
	  {
	  	cout<<"Invalid student name."<<endl;
	  }
	  if(m==2)
	   {
	   	if(flag==0)
	   	{
		   
	   	    stdRegNo[stdl]=regNo;
	   	    StdCourseList[stdl][0]=regNo;                               //if we add student without deleting
	 	    stdName[stdl]=studentName;
	 		cout<<"Student has been added successfully."<<endl<<endl;
	 		regc++;
	 
	   }
	   else if(flag==1)                                            
	   	{
		    stdl=regc;                                 //if we delete the course then last index will contain garbage value this is done to remove that value
	   	    stdRegNo[stdl]=regNo;
	   	    StdCourseList[stdl][0]=regNo;
	 	    stdName[stdl]=studentName;
	 		cout<<"Student has been added successfully."<<endl<<endl;
	 		regc++;
	
	    }
	    stdl++;
	   }
	
	} 
void updateStudent(string stdName[], string stdRegNo[], string studentName, string regNo){
	 int m=0;
	 int index;                    
	 int f=0;                           //flag in case if registeration number is found.
	 for(int i=0;i<regc;i++)
	{
		if(stdRegNo[i]==regNo)
	           {
					index=i;                //it stores the index of location where i is found
					f=1;
		       }
	}
	 
	 if(f==1)
	  {
		    	cout<<"Enter the updated details of Student: ";
		    	cin>>regNo;
				getline(cin,studentName);
				if(isValidRegistrationNumber(regNo))
	                 {
	  	                  m++;
	                 }
	            else
	  			     {
	  					cout<<"Invalid Registeration Number. Enter the right syntax i.e[201X-XX-111]."<<endl;
	  				 }
	  			if(isValidStudentName(studentName))
					 {
					  	m++;
					 }
			    else
				     {
				  	    cout<<"Invalid student name."<<endl;
				     }
				if(m==2)
				     {
				     	stdName[index]=studentName;
			            stdRegNo[index]=regNo;
			            cout<<"Student has been Edited successfully."<<endl;
					 }
	
	      }
	      else
	        cout<<"Student does not exist";
	
}

void deleteStudent(string stdName[], string stdRegNo[],string courselist[No_of_rows][No_of_columns], string regNo)
{
int f1=0;	 //flag for registered students
int f=0;	
int n=0;                         
int index;
int bindex;
    for(int i=0;i<regc;i++)
		{
		 	if(stdRegNo[i]==regNo)
	    		{
	    			f=1;
	    			index=i;           //it findes the index where value is stored
				}
    	}
    if(f==1)
	   {
    	
	    	for(int i=index;i<regc;i++)
        		{
      	
      				stdRegNo[i]=stdRegNo[i+1];                        
      				stdName[i]=stdName[i+1];
      				flag=1;
	    		}
							
   			for(int i=0;i<regc;i++)
       			{	
					if(StdCourseList[i][0]==regNo)          //to delete student from studentcourse list
				 		{
				   			bindex=i;
				   		    f1=1;
			      		}
			    }
			  
			if(f1==1)              //if student exists in stdcourse list
			    {
			    		for(int i=0; StdCourseList[bindex][i] !="\0" ;i++)
				   	       {        
				   	           n++;
				   	       }
				   	      
				   	  for(int j=bindex;j<regc;j++)
						{
						      
				   	      for(int i=0;i<n;i++)
				   	       {
				   	       	   StdCourseList[bindex][i]=StdCourseList[bindex+1][i];
						   }
						   bindex++;
						   
					    }
					    regc--;
				}

			      	   cout<<"Student have been sucessfully deleted."<<endl;	
	   }
	
	 else
	      cout<<"Student not found"<<endl;
}
void viewStudent(string stdName[], string stdRegNo[],string StdCourselist[No_of_rows][No_of_columns])
{
	int index;
	int f=0;
	cout<<"\tRegistration Number   ";
	cout<<"Student Name\t     ";
	cout<<"Registered Courses"<<endl;
	
		  for(int j=0;StdCourselist[j][0]!="\0";j++)
		  {
		  	    cout<<"\t     "<<StdCourseList[j][0]<<"\t     "<<stdName[j]<<"\t    ";
		  		for(int k=1;StdCourselist[j][k]!="\0";k++)
		  		{
		  			 cout<<StdCourselist[j][k]<<",";
				}
		     cout<<endl;    
		  }

}

void registerCourse(string stdRegNo[], string StdCourselist[No_of_rows][No_of_columns],string cCode[],string regNo,string code)
{   
    int index;
    int k=0;                      //flag to see if user have registered any courses bfore
	int f=0;                      //flag to check if course code exists
	static int l=0;               //counter for rows
	int m=0;                      //Counter for columns
	int n=1;                      //counter for already registered students courses
	int fo=0;   

	for(int i=0;i<regc;i++)
							{
								if(stdRegNo[i]==regNo)               //if student registeration no exists in reg number list
								     {
								     	fo=1;
								     }
							}
							if(fo==1)                     
							   {
							   		cout<<"Enter Course Code to register: ";
							   		cin>>code;
				
							   			for(int i=0;i<counter;i++)                   //to check if course code exsists
				 							{
				 								if(cCode[i]==code)
				 	    						f=1;
				 							}
				 							
										if(f=1)          //if course code is valid and exists
							   				{
							   						for(int i=0;i<regc;i++)
							   		   					{
							   		   	  						if(StdCourseList[i][0]==regNo)          //to check if registration number already exists in course list
							   		   	       						{
							   		   	       							k=1;                   
							   		   	       							index=i;
											   						}
							   		                    }
							   		                 
							   		                 if(k==1)      //in case if regno already in the stdcourse list
																  
							   	                        {
							   	                        	for(int i=1; StdCourseList[index][i] !="\0" ;i++)
							   	                        	        {
							   	                        	           n++;
				                                                    }
					 										StdCourseList[index][n]=code;
					             							cout<<"course have been sucesssfully registerd"<<endl;
								                        }
								                        	
			                                }
								        else
							        	   {
									                 cout<<"Course code does not Exists"<<endl;
									                 
							               }
				               }
				           else
						        cout<<"Student Does not Exist.";
						        
	}

void unRegisterCourse(string stdRegNo[], string StdCourselist[No_of_rows][No_of_columns],string regNo,string code)
{
 int index;
 int bindex;           
 int f=0;              //flag for registration number
 int k=0;              //flag for courses
 int n=0;
       for(int i=0;i<regc;i++)
			{
				if(StdCourseList[i][0]==regNo)          //to check if registration number already exists in course list
				   	{
				   		f=1;                   
			            index=i;
	                }
	    	}
	    if(f==1)          //if registration number is valid
	       {
	       	   cout<<"Enter Course Code to unregister:";
	       	   cin>>code;
	       	   for(int i=1;StdCourseList[index][i]!="\0";i++)                                          //to check if course code exist
	       	          {
	       	          	if(StdCourseList[index][i]==code)
	       	          	    {
	       	          	    	bindex=i;
	       	          	        k=1;
	                		}
					  }
			    if(k==1)                                       //if course code is valid
				    {
				    	for(int i=bindex;StdCourseList[index][i]!="\0";i++)
				    	   {
				    	   	    StdCourseList[index][i]=StdCourseList[index][i+1];
						   }
						cout<<"Course has been unregistered."<<endl;
		   		    }	
					else
					  cout<<"course code does not exist"<<endl;	  
		   }
		   else
		   cout<<"Registration number does not exist"<<endl;	
}


void saveStudents(string stdRegNo[], string stdName[], string StdCourselist[No_of_rows][No_of_columns])
{
	
		ofstream stdData;
        stdData.open("Students.txt");               //used to oppen the text file
        for(int i=0;i<regc;i++)
         {
         	stdData<<stdRegNo[i]<<","<<stdName[i]<<endl;
         	for(int l=1;StdCourselist[i][l]!="\0";l++)
         	{
         	stdData<<StdCourselist[i][l]<<",";
            }
             
            stdData<<endl;
		 }
		 stdData.close();

}

void LoadStudents(string stdRegNo[], string stdName[], string StdCourselist[No_of_rows][No_of_columns])
{
	string line,line1;    //for students   & for courses
	string course,name,regno;
		
	ifstream stdfile;
	stdfile.open("Students.txt");
	while(getline(stdfile,line))
	{
		
		stringstream ss(line);
		getline(ss , regno , ',');
		getline(ss , name , ',');
		stdRegNo[filestd]=regno;
		StdCourselist[filestd][0]=regno;
		stdName[filestd]=name;
		
		getline(stdfile,line1);
		stringstream ss2(line1);
		for(int i=1;i<5;i++)
		{
			getline(ss2,StdCourselist[filestd][i],',');
		
		}
		filestd++;
    	regc++;

}

}
int main()                                                                                                  

{   
                        
    cout<<endl<<endl<<"\t\t\t*************Welcome to University Learning Management System**************" <<endl;
	cout<<endl<<"\t\t\t                               By MARIA AZRAR"<<endl<<endl;
	   
   string UsersList[30],passwordsList[30];                   //arrays for users list and password list
   LoadCourses(cCode,CH,semester,cName);                     //in order to load all course 
   LoadStudents(stdRegNo,stdName, StdCourseList); 
   int choice,caseindex,caseflag=0;
   string stdname,stdreg,pass;
   int passwordflag=0; 
   cout<<"Choose the option for Login"<<endl<<"1 for Admin" <<endl<<"2 for student"<<endl<<"Enter option:";
   cin>>choice;
   switch(choice)
   	{

   case 1:
     {
	    
   if(LoadUsers(UsersList,passwordsList))                     //used in order to give access to the user
    	
  {
  	cout<<endl<<"You have sucessfully logged into the system"<<endl;
  	
  }
  	 else
  {
  	  cout<<endl<<"Dear User, Username/password is incorrect. Enter the"<<endl;
      cout<<endl<<"username/password again to get access to the system"<<endl;
      main();
  }
  
   
  while(0>-1)                          //infinite loop so that user can exit according to his will
 {
 	cout<<"Choose the following option"<<endl;
	cout<<"1     Add Course"<<endl;
	cout<<"2     Edit Course"<<endl;
	cout<<"3     Delete Course"<<endl;
	cout<<"4     View All Courses"<<endl;
	cout<<"5     View Courses of a Smester"<<endl;
	cout<<"6     Add New Student"<<endl;
	cout<<"7     Update Student"<<endl; 
	cout<<"8     Delete Student"<<endl;
	cout<<"9     View All Students"<<endl; 
	cout<<"10    Register the course for student"<<endl;
	cout<<"11    Unregister the course for student"<<endl;
	cout<<"12    Logout of the System"<<endl;
	cout<<"13    Exit Program"<<endl;
	
	
	string code;
	string name;
	int s,c;
	string stdname,stdreg;
	
	int n;
	cout<<"Choose the option:"<<endl;                    

	cin>>n;

	switch(n)
	{
		
		case 1:
			{
				
				cout<<"Enter the details of the course  ";
				cin>>code>>c>>s;
             	getline(cin,name);
				AddCourse(cCode,CH,semester,cName,code,c,s,name);
				getch();                         //in order to pause the console until user presses the key
				break;
		     
		
				
			}
		case 2:
			{   cout<<"Enter the Course to Edit:";           
	            cin>>code;
			    EditCourse(cCode,CH,semester,cName,code);
                getch();
			    break;
				
			}
		case 3:
			{
				cout<<"Enter the Course code to delete:";
				cin>>code;
				DeleteCourse(cCode,semester,CH,cName,code);
				getch();
				break;
			}
		case 4:
	
	     	{
		     	ViewCourse(cCode,CH,semester,cName);
			    getch();
				break;
				
			}
		case 5:
			{
				cout<<"Enter The Smester:";
	            cin>>s;
				ViewSemesterCourses(cCode,CH,semester,cName,s);
				getch();
				break;
			}
		case 6:
			{
				
				cout<<"Enter details of Student: ";
				cin>>stdreg;
				getline(cin,stdname); 
				addStudent(stdName,stdRegNo,stdname,stdreg);
				getch();
				break;
				
			}
		case 7:
			{
				cout<<"Enter registration Number of the student to edit: ";
				cin>>stdreg; 
				updateStudent(stdName,stdRegNo,stdname,stdreg);
				getch();
				break;
		    	
			}
				
		case 8:
			{
				cout<<"Enter registration Number of the student to delete: ";
				cin>>stdreg; 
			   	deleteStudent(stdName,stdRegNo,StdCourseList,stdreg);
			   	getch();
			   	break;
			}
		case 9:
			{
				viewStudent(stdName,stdRegNo,StdCourseList);
				getch();
				break;
			}
		case 10:
			{
				cout<<"Enter registration Number of the student for course registration: ";
				cin>>stdreg;
				registerCourse(stdRegNo,StdCourseList,cCode,stdreg,code);
			    getch();
			    break;
			     
			 }
			
		case 11:
			{
		         cout<<"Enter registration Number of the student: ";
				 cin>>stdreg;
				 unRegisterCourse(stdRegNo,StdCourseList,stdreg,code);
		    	 getch();
			     break;
			   
		    
				
			}
		case 12:
			{
				main();                   //in order to logout from system this will take us to the main
			}
			
		case 13:
			{
				SaveCourses(cCode,CH,semester,cName);              // this will save the courses before exiting the program
				saveStudents(stdRegNo,stdName, StdCourseList);
				
			    return 0;                                   //this will exit us from the program
			}
		
	    default:
			{
				cout<<"Enter valid option. "<<endl;
				getch();
				break;
			}
     	}
    
      
 
    }
    break;
    
  }
  
   		case 2:
   			{  
   			    int q=0;
			   int count=0;
   				cout<<"Enter registration Number: ";
   				cin>>stdreg;
   				while(1)
   				{
   				cout<<"Enter password: ";
   				cin>>pass;
   				for(int i=0;i<regc;i++)
   				{ 
   					if(stdRegNo[i]==stdreg)
   					 {
   					 	caseindex=i;
   					 	caseflag=1;                           // it will search the index of value
					 }
				}
				if(caseflag==1)
				{
					string a=stdName[caseindex];                       //assigns student name to another string to find value
					int l=a.length();           //it will find the length of string in which student name isstored
					int k=0;
					for(int i=l-3;i<l;i++)
					{
						if(pass[k]==a[i])
						{
						q++;                              //if the value matches password
					    }                             
					   k++;
				 	} 
					 if(q==3)
					{
			     
   					int option;
   					while(1)
   					{
					
   					cout<<endl<<"Enter 1 to view registered course"<<endl<<"Enter 2 to logout of the system"<<endl<<"Enter 3 to exit"<<endl<<"Choose option:";
   				 
   					cin>>option;
   					switch(option)
   					{
   						case 1:
				     	  {
							   	cout<<"\tRegisteration Number\t Registered Courses"<<endl;
							   	
				
									  	    cout<<"\t  "<<StdCourseList[caseindex][0];                          //THIS WILL SHOW US THE REGISTERD COURSES BY THE STUDENT
									  	    cout<<"\t          ";
									  		for(int k=1;StdCourseList[caseindex][k]!="\0";k++)
									  		{
									  			 cout<<StdCourseList[caseindex][k]<<",";
											}
									        
									  
	                            break;
			     	      }  
			     	    case 2:
			     	    	{
			     	    		main();
			     	    		break;
							}
						case 3:
							{
							    return 0;	
							}
						default:
							{
								cout<<"Enter a valid option"<<endl;
							}
					}
   	
					}
			    	}
				    else
					{		
					cout<<"invalid password. Try Again"<<endl;
					q=0;
			     	}
			        }
			    }
	
   				break;
			}
   default:
   	  cout<<"Invalid option";
}
}
