#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define a "\t\t\t\t\t\t"
#define b "\t\t\t\t\t"
#define addressspace 120
//admin
int rec_flag=0,no=0;
char rec_ind[5];


struct record
{
  char ind[5];
  char  id[20],name[20];

  
}rec[20];

struct index
{
    char id[20],ind[20];
}in[20],temp;
//student
int io=0;
char ind1[5],name1[20],age[5],sem[5],branch[5],usn[20],meet[50],ia1[20],ia2[20],ia3[20];
struct record1
{
	char age[5],ind1[5];
	char name1[20],usn[20],branch[5];
	char sem[5],meet[50],ia1[20],ia2[20],ia3[20];
}rec1[addressspace];

//start of functions for login
struct User {
    std::string username;
    std::string password;
};

std::map<std::string, User> LoadUsers(const std::string& filename) {
    std::map<std::string, User> users;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::string username = line;
            std::string password;
            if (getline(file, password)) {
                User newUser;
                newUser.username = username;
                newUser.password = password;
                users[username] = newUser;
            }
        }
        file.close();
    }
    return users;
}

void SaveUsers(const std::string& filename, const std::map<std::string, User>& users) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : users) {
            file << pair.first << "\n";
            file << pair.second.password << "\n";
        }
        file.close();
    }
}

bool SignUp(const std::string& username, const std::string& password, std::map<std::string, User>& users) {
    if (users.find(username) == users.end()) {
        User newUser;
        newUser.username = username;
        newUser.password = password;
        users[username] = newUser;
        return true;
    }
    return false;
}

bool SignIn(const std::string& username, const std::string& password, const std::map<std::string, User>& users) {
    if (users.find(username) != users.end()) {
        const User& existingUser = users.at(username);
        if (existingUser.password == password) {
            std::cout << "Welcome, " << existingUser.username << "!" << std::endl;
            return true;
        }
    }
    return false;
}
//end of login functions



// admin subfunction


void sort_index()
{
    int i,j;
    for(i=0;i<no-1;i++)
    for(j=0;j<no-i-1;j++)
    if(strcmp(in[j].id,in[j+1].id)>0)
    {
       temp=in[j];
       in[j]=in[j+1];
       in[j+1]=temp;
    }

}

void retrive_record(char *ind)
{
    for(int i=0;i<no;i++)
    {
      if(strcmp(rec[i].ind,ind)==0)
      {
      strcpy(rec_ind,ind);
      rec_flag=1;
      cout<<"\n Record found:";
      cout<<rec[i].id<<"|"<<rec[i].name<<"\n";
      return;
      }
    }
}


int search_index(char *id)
{
      int flag=0;
      for(int i=0;i<no;i++)
      {
	  if(strcmp (in[i].id,id)==0)
	  {
	     retrive_record(in[i].ind);
	     flag=1;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

int search_id(char *id,int j)
{
      int flag=0;
      for(int i=0;i<j;i++)
      {
	  if(strcmp (rec[i].id,id)==0)
	  {
	     flag=1;break;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

void delet(char *st_id)
{
      rec_flag=0;
      int fr=0;
      search_index(st_id);
      if(!rec_flag)
      {
	 cout<<"\n Deletion failed record not found";
	 return;
      }
      for(int i=0;i<no;i++)
      {
	 if(strcmp(rec[i].ind,rec_ind)==0)
	  {   fr=i; break;}
      }
      for(int i=fr;i<no-1;i++)
      {
	 rec[i]=rec[i+1];
	 char str[3];
	 //itoa(i,str,10);
	sprintf(str,"%d",i);
	 strcpy(rec[i].ind,str);
      }
      no--;
      fstream f1,f2;
      f1.open("record1.txt",ios::out);
      f2.open("index.txt",ios::out);
      for(int i=0;i<no;i++)
      {
      strcpy(in[i].id,rec[i].id);
      strcpy(in[i].ind,rec[i].ind);
      }
      sort_index();
      for(int i=0;i<no;i++)
      {
      f1<<rec[i].ind<<"|"<<rec[i].id<<"|"<<rec[i].name<<"\n";
      f2<<in[i].id<<"|"<<in[i].ind<<"\n";
      }
      f1.close();
      f2.close();
      cout<<"\n Deletion successful\n";
}
//end of admin subfunctions





//ADMIN FUNCTION
void admin()
{   
    int ch2;
    string user,pass;
    label1: cout<<"Enter username"<<endl;
    cin>>user;
    if(user=="admin")
    {
        cout<<"Enter Password"<<endl;
        cin>>pass;
        for(;;)
        {
        if(pass=="admin")
        {
           fstream file1,file3;
      int choice;
      char ind[5],st_id[20],name[20],id[20];
      int i;
 
      for(;;)
      {

       
      cout<<"\nCHOOSE FROM THE BELOW OPTION\n1:ADD A MENTOR\n2:SEARCH THE MENTOR\n3:DELETE THE MENTOR\n4:DISPLAY ALL MENTORS\n5:EXIT\n";
      cin>>choice;
      switch(choice)
      {
	 case 1:{
		file1.open("record1.txt",ios::app|ios::out);
		if(!file1)
		{
		  cout<<"File creation error\n";
		  exit(0);
		}
		int n;
		cout<<"Enter number of Mentors\n";
		cin>>n;
		cout<<"Enter the details\n";
		for(i=no;i<no+n;i++)
		{
		  cout<<"\nEnter "<<i+1<<" Mentor:";

		  cout<<"\nMentor id:";
		  cin>>rec[i].id;
		  cout<<"\nMentor name:";
		  cin>>rec[i].name;
		  
		   int q=search_id(rec[i].id,i);
		    
		file1<<i<<"|"<<rec[i].id<<"|"<<rec[i].name<<"\n";
         //credentials
        std::string userFile = "users.txt";
        std::map<std::string, User> users = LoadUsers(userFile);
        std::string username, password;
        std::cout << "Enter Sign Up Details for the Mentor" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

    if (SignUp(username, password, users)) {
        std::cout << "Sign up successful!" << std::endl;
        SaveUsers(userFile, users);
    } else {
        std::cout << "Username already exists. Sign up failed." << std::endl;
    }
    //End of credentials
	       }
	       file1.close();
	       no=no+n;
	       fstream file1,file2;
	       file2.open("index1.txt",ios::out);
	       file1.open("record1.txt",ios::in);
	       for(i=0;i<no;i++)
	       {
		  file1.getline(ind,5,'|');
		  file1.getline(id,20,'|');
		  file1.getline(name,20,'\n');
		  
		  strcpy(rec[i].ind,ind);
		  strcpy(in[i].id,id);
		  strcpy(in[i].ind,ind);
	       }
	       sort_index();
	       cout<<"\nAfter sorting Index file contents are\n";
	       for(i=0;i<no;i++)
	       cout<<in[i].id<<" "<<in[i].ind<<endl;
	       for(i=0;i<no;i++)
	       {
		   file2<<in[i].id<<"|"<<in[i].ind<<"\n";
	       }
	       file1.close();
	       file2.close();
	       break;
		}
	 case 2:{
		cout<<"\nEnter Mentor id of the Mentor whose record is to be displayed\n";
		cin>>st_id;
		int q=search_index(st_id);
		if(q==1)
		   cout<<"\nSearch Sucessful\n";
		else
		   cout<<"\nMentor not Found\n";
		break;
		}
	 case 3:{
		cout<<"Enter Mentor id of mentor whose record is to be deleted\n";
		cin>>st_id;
		delet(st_id);
		break;
		}
	 case 4:{
	      fstream f1;
	      f1.open("record1.txt",ios::in);
	      if(!f1)
	      {
	      cout<<"!!!!!!!!!ERROR!!!!!!!!!\n"<<"NO RECORDS FOUND\n";
	      exit(0);
	      }
	      int i=0;
	      while(i!=no)

	    {
		f1.getline(ind,5,'|');
		f1.getline(id,20,'|');
		f1.getline(name,20,'|');
		  
		cout<<"Mentor_id:"<<id<<"\t"<<"Name:"<<name<<"\t"<<endl;
		i++;
	    }
		break;
		}
	case 5:{
		cout<<a<<"##########THANK YOU##########";
        return;
		exit(0);
		 
		}
	 default:
		 cout<<"\nInvalid Choice\n";
         return;
		 break;
	 }
     }
        }
        
        else
        {
            cout<<"Wrong Password"<<endl;
            goto label1;
        }
    }
    }
    else
    {
        cout<<"Wrong Username"<<endl;
        goto label1;
    }
}

//end of admin



//stud sub function
// int srch_usn1(char *usn,int j)
// {
// int flag=0;
// for(int i=0;i<j;i++)
// if(strcmp(rec1[i].usn,usn)==0)
// {
// flag=1;
// }
// if(flag)
// return 1;
// else
// return -1;
// }

void hashinit(){
	for(int i=0;i<addressspace;i++){
		strcpy(rec1[i].usn,"-1");
	}
}

int hsh(char*usn){
	int i = stoi(usn);
	return i%addressspace;
}

void linearprobing(int key){
	int flag=0;
		if(strcmp(rec1[key].usn,"-1")==0){
			strcpy(rec1[key].name1,name1);
			strcpy(rec1[key].usn,usn);
			strcpy(rec1[key].age,age);
			strcpy(rec1[key].sem,sem);
			strcpy(rec1[key].branch,branch);
			strcpy(rec1[key].meet,meet);
			strcpy(rec1[key].ia1,ia1);
			strcpy(rec1[key].ia2,ia2);
			strcpy(rec1[key].ia3,ia3);
			flag=1;
		}
		else{
			cout<<"\nCollision Detected and Resolved\n";
			for(int i=key+1;i<addressspace && flag==0;i++){
				if(strcmp(rec1[i].usn,"-1")==0){
					strcpy(rec1[i].name1,name1);
					strcpy(rec1[i].usn,usn);
					strcpy(rec1[i].age,age);
					strcpy(rec1[i].sem,sem);
					strcpy(rec1[i].branch,branch);
					strcpy(rec1[i].meet,meet);
					strcpy(rec1[i].ia1,ia1);
					strcpy(rec1[i].ia2,ia2);
					strcpy(rec1[i].ia3,ia3);
					flag=1;
					break;
				}
			}

			for(int i=0;i<key-1 && flag==0;i++){
				if(strcmp(rec1[i].usn,"-1")==0){
					strcpy(rec1[i].name1,name1);
					strcpy(rec1[i].usn,usn);
					strcpy(rec1[i].age,age);
					strcpy(rec1[i].sem,sem);
					strcpy(rec1[i].branch,branch);
					strcpy(rec1[i].meet,meet);
					strcpy(rec1[i].ia1,ia1);
					strcpy(rec1[i].ia2,ia2);
					strcpy(rec1[i].ia3,ia3);
					flag=1;
					break;
				}
			}
		}
}


void hashing(){
	
	cout<<"\nStoring the Values for Students using HASHING\n";
	cout<<"\nEnter name of Student: ";
	cin>>name1;
	cout<<"\nEnter USN of Student[*NOTE ENTER LAST 2 OR 3 DIGITS OF YOUR USN*]: ";
	cin>>usn;
	cout<<"\nEnter age of Student: ";
	cin>>age;
	cout<<"\nEnter Sem of Student: ";
	cin>>sem;
	cout<<"\nEnter Branch of Student: ";
	cin>>branch;
	cout<<"\nEnter Meeting details: ";
	cin>>meet;
	cout<<"\nIA1 Marks in the format [Sub=Marks] with comma:\n";
	cin>>ia1;
    cout<<"\nIA2 Marks in the format [Sub=Marks] with comma:\n";
	cin>>ia2;
	cout<<"\nIA3 Marks in the format [Sub=Marks] with comma:\n";
	cin>>ia3;

	int key = hsh(usn);

	linearprobing(key);

}



//start of student
void addstudent()
{   
    fstream file1;
    file1.open("record_stud.txt",ios::app);
    hashinit();
	int choice;
	
	do{	
		hashing();
        io++;
        //cout<<io<<endl;
		cout<<"\nEnter 0 to exit loop: ";
		cin>>choice;
	}while(choice!=0);
	for(int i=0;i<addressspace;i++){
		if(strcmp(rec1[i].usn,"-1")!=0){
			cout<<"USN:"<<rec1[i].usn<<"\n"<<"NAME:"<<rec1[i].name1<<"\n"<<"AGE:"<<rec1[i].age<<"\n"<<"SEM:"<<rec1[i].sem<<"\n"<<"BRANCH:"<<rec1[i].branch<<"\n"<<"MEETING DETAILS:"<<rec1[i].meet<<"\n"<<"IA1:"<<rec1[i].ia1<<"\n"<<"IA2:"<<rec1[i].ia2<<"\n"<<"IA3:"<<rec1[i].ia3<<"\n";
			cout<<"The Record is Stored in Hash Key: "<<i<<endl;
            file1<<i<<"|"<<rec1[i].usn<<"|"<<rec1[i].name1<<"|"<<rec1[i].age<<"|"<<rec1[i].sem<<"|"<<rec1[i].branch<<"|"<<rec1[i].meet<<"|"<<rec1[i].ia1<<"|"<<rec1[i].ia2<<"|"<<rec1[i].ia3<<"\n";
		}
	}
    file1.close();
    

}


void displaystud()
{

            char ind1[5],name1[20],age[5],sem[5],branch[5],usn[20],meet[50],ia1[20],ia2[20],ia3[20];
            fstream file1;
            char usn1[20];
			file1.open("record_stud.txt",ios::in);
            int flag=0;
            cout<<"Enter your usn:\n";
            cin>>usn1;
            for(int i=0;i<=io;i++)
            {
                file1.getline(ind1,5,'|');
				file1.getline(usn,20,'|');
				file1.getline(name1,20,'|');
				file1.getline(age,5,'|');
				file1.getline(sem,5,'|');
				file1.getline(branch,5,'|');
                file1.getline(meet,50,'|');
                file1.getline(ia1,20,'|');
                file1.getline(ia2,20,'|');
                file1.getline(ia3,20,'\n');

                
                if(strcmp(usn,usn1)==0)
                {
                    cout<<"USN:"<<usn<<"\n"<<"NAME:"<<name1<<"\n"<<"AGE:"<<age<<"\n"<<"SEM:"<<sem<<"\n"<<"BRANCH:"<<branch<<"\n"<<"MEETING DETAILS:"<<meet<<"\n"<<"IA1:"<<ia1<<"\n"<<"IA2:"<<ia2<<"\n"<<"IA3:"<<ia3<<"\n";
                    flag=1;
                    break;
                }

            }
            file1.close();
            if(flag==0)
            {
                cout<<"USN not found\n";
            }
			   

}

void student()
{
    //char ind[5],name[20],age[5],sem[5],branch[5],usn[20],meet[50],ia1[20],ia2[20],ia3[20];
    int ch3;
      cout<<b<<"***********WELCOME STUDENT***********"<<endl;
      for(;;)
      {
            cout<<"CHOOSE THE OPTION:"<<endl;
            cout<<"1:ADD STUDENT DETAILS"<<endl;
            cout<<"2:DISPLAY STUDENT DETAILS"<<endl;
            cout<<"3:EXIT"<<endl;
            cin>>ch3;
    switch(ch3)
    {
        case 1: addstudent();
                break;
                
        case 2: displaystud();
                break;
        
        case 3: 
            cout<<a<<"##########THANK YOU##########";
            return;
            exit(0);
            break;

        default:return; 
                exit(0);
    }
      }

}

//end of student function

//start of mentor subfunctions
void displayallstudent()
{
    int l=0;
    int count=0;
    
    string line;
    
    fstream file1;
				file1.open("record_stud.txt",ios::in);
                
                
                //  if(file1.is_open())
                //     {
                //         while(file1.peek()!=EOF)
                //         {
                //             getline(file1,line);
                //             count++;
                //         }
                        
                //     }
                    // cout<<"hello "<<count;
			    if(file1)
                {
                   
                while(!file1.eof())
                {
				// if(l<count)
                // {
                    // while(l<count)
                    // {
                    cout<<"-------------------------------------------------\n";
					file1.getline(ind1,5,'|');
					file1.getline(usn,20,'|');
					file1.getline(name1,20,'|');
					file1.getline(age,5,'|');
					file1.getline(sem,5,'|');
					file1.getline(branch,5,'|');
                    file1.getline(meet,50,'|');
                    file1.getline(ia1,20,'|');
                    file1.getline(ia2,20,'|');
                    file1.getline(ia3,20,'\n');
                if (usn[0] != '\0' && name1[0] != '\0' && age[0] != '\0' && sem[0] != '\0' && branch[0] != '\0' && meet[0] != '\0' && ia1[0] != '\0' && ia2[0] != '\0' && ia3[0] != '\0')
                {
			        cout<<"USN:"<<usn<<"\n"<<"NAME:"<<name1<<"\n"<<"AGE:"<<age<<"\n"<<"SEM:"<<sem<<"\n"<<"BRANCH:"<<branch<<"\n"<<"MEETING DETAILS:"<<meet<<"\n"<<"IA1:"<<ia1<<"\n"<<"IA2:"<<ia2<<"\n"<<"IA3:"<<ia3<<"\n";
			        cout<<"-------------------------------------------------\n";
                }
                // if(l==count)
                // {
                //     break;
                // }
                // }while(y<count);
               // }
                }
			     file1.close();
                
                }
                else
                {
                    cout<<"No records found!!!\n";
                }
                 
}




void removestud()
{
    struct record1
    {
        char age[5],ind1[5];
        char name1[20],usn[20],branch[5];
        char sem[5],meet[50],ia1[20],ia2[20],ia3[20];
    }rec1[addressspace];
    fstream file1;
	file1.open("record_stud.txt",ios::in);
	int i=0;
    char stud_usn[20];
    if(file1)
    {
        cout<<"Enter USN of student whose record is to be deleted\n";
	    cin>>stud_usn;
        
		while(!file1.eof())
		{

			file1.getline(rec1[i].ind1,5,'|');
			file1.getline(rec1[i].usn,20,'|');
			file1.getline(rec1[i].name1,20,'|');
			file1.getline(rec1[i].age,5,'|');
			file1.getline(rec1[i].sem,5,'|');
			file1.getline(rec1[i].branch,5,'|');
            file1.getline(rec1[i].meet,50,'|');
            file1.getline(rec1[i].ia1,20,'|');
            file1.getline(rec1[i].ia2,20,'|');
            file1.getline(rec1[i].ia3,20,'\n');
	        // cout<<"USN:"<<usn<<"\n"<<"NAME:"<<name1<<"\n"<<"AGE:"<<age<<"\n"<<"SEM:"<<sem<<"\n"<<"BRANCH:"<<branch<<"\n"<<"MEETING DETAILS:"<<meet<<"\n"<<"IA1:"<<ia1<<"\n"<<"IA2:"<<ia2<<"\n"<<"IA3:"<<ia3<<"\n";
			i++;

        }
        file1.close();
        int z=0;
        int fl=0;
        file1.open("record_stud.txt",ios::out);
        for(int j=0;j<i-1;j++)
        {
            if(strcmp(rec1[j].usn,stud_usn)==0)
            {
                z=j;
                fl=1;
                break;
            
            }
            
        }
        if(fl!=1)
        {
            cout<<"Record not found with the entered USN\n";
        }
        
        for(int p=z;p<i-1;p++)
        {
            rec1[p]=rec1[p+1];
            strcpy(rec1[p].usn,rec1[p+1].usn);

        }
        i--;
        if(fl==1)
        {
            cout<<"Deletion Sucessfull\n";
        }
        for(int q=0;q<i-1;q++)
        {
            file1<<q<<"|"<<rec1[q].usn<<"|"<<rec1[q].name1<<"|"<<rec1[q].age<<"|"<<rec1[q].sem<<"|"<<rec1[q].branch<<"|"<<rec1[q].meet<<"|"<<rec1[q].ia1<<"|"<<rec1[q].ia2<<"|"<<rec1[q].ia3<<"\n";
        }
        file1.close();
        }
        else
        {
            cout<<"No Records Found to delete the student!!!!\n";
        }

    
	
}

//MENTOR function
void mentor()
{
    string key;
    int ch1;
    cout<<"Enter the Passkey"<<endl;
    cin>>key;
    if(key=="Mentor@123")
    {
    //SIGN UP AND SIGN IN
    label2: std::string userFile = "users.txt";
    std::map<std::string, User> users = LoadUsers(userFile);
    std::string username, password;

    // Sign in
    std::cout << "\nSign In" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (SignIn(username, password, users)) {
        std::cout << "Sign in successful!" << std::endl;
        
    cout<<b<<"***********WELCOME MENTOR***********"<<endl;
    for(;;)
    {
    cout<<"CHOOSE THE OPTION:"<<endl;
    cout<<"1:DISPLAY ALL STUDENT"<<endl;
    cout<<"2:REMOVE THE STUDENT"<<endl;
    cout<<"3:EXIT"<<endl;
    cin>>ch1;
    switch(ch1)
    {
        case 1: 
                displayallstudent();
                break;
                
        case 2: removestud();
                break;
        
        case 3: 
            cout<<a<<"##########THANK YOU##########";
            return;
            exit(0);
            break;

        default:return; 
                exit(0);
    }
    
    }
    } 
    else 
    {
        std::cout << "Invalid username or password, Sign in failed." << std::endl;
        goto label2;
    }
    }
    else
    {
        cout<<"!!!!!!!!You are not the mentor!!!!!!!!"<<endl;
        return;
    }
}
//end of mentor function





// Main funnction of prog
int main()
{
    //char ind[5],name[20],age[5],sem[5],branch[5],usn[20],meet[50],ia1[20],ia2[20],ia3[20];
    int ch;
    cout<<a<<"-----------------------------"<<endl;
    cout<<a<<"***********WELCOME***********"<<endl;
    cout<<a<<"-----------------------------"<<endl;
    for(;;)
    {
    cout<<"\nSELECT THE ROLE BELOW:"<<endl;
    cout<<"1:ADMIN"<<endl;
    cout<<"2:MENTOR"<<endl;
    cout<<"3:STUDENT"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: admin();
                break;
                
        case 2: mentor();
                break;
        
        case 3: student();
                break;

        default: cout<<a<<"##########THANK YOU##########";
                exit(0);
    }
    }
}