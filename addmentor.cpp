// #include<iostream>

// #include<string.h>
// #include<fstream>
// #include<stdio.h>
// #include<iomanip>
// #include<stdlib.h>
// using namespace std;
// int rec_flag=0,no=0;
// char rec_ind[5];

// struct record
// {
//   char ind[5];
//   char  id[20],name[20];

  
// }rec[20];

// struct index
// {
//     char id[20],ind[20];
// }in[20],temp;

// void sort_index()
// {
//     int i,j;
//     for(i=0;i<no-1;i++)
//     for(j=0;j<no-i-1;j++)
//     if(strcmp(in[j].id,in[j+1].id)>0)
//     {
//        temp=in[j];
//        in[j]=in[j+1];
//        in[j+1]=temp;
//     }

// }

// void retrive_record(char *ind)
// {
//     for(int i=0;i<no;i++)
//     {
//       if(strcmp(rec[i].ind,ind)==0)
//       {
//       strcpy(rec_ind,ind);
//       rec_flag=1;
//       cout<<"\n record found:";
//       cout<<rec[i].id<<"|"<<rec[i].name<<"\n";
//       return;
//       }
//     }
// }


// int search_index(char *id)
// {
//       int flag=0;
//       for(int i=0;i<no;i++)
//       {
// 	  if(strcmp (in[i].id,id)==0)
// 	  {
// 	     retrive_record(in[i].ind);
// 	     flag=1;
// 	  }
//       }
//       if(flag)
// 	  return 1;
//       else
// 	  return -1;
// }

// int search_id(char *id,int j)
// {
//       int flag=0;
//       for(int i=0;i<j;i++)
//       {
// 	  if(strcmp (rec[i].id,id)==0)
// 	  {
// 	     flag=1;break;
// 	  }
//       }
//       if(flag)
// 	  return 1;
//       else
// 	  return -1;
// }

// void delet(char *st_id)
// {
//       rec_flag=0;
//       int fr=0;
//       search_index(st_id);
//       if(!rec_flag)
//       {
// 	 cout<<"\n deletion failed record not found";
// 	 return;
//       }
//       for(int i=0;i<no;i++)
//       {
// 	 if(strcmp(rec[i].ind,rec_ind)==0)
// 	  {   fr=i; break;}
//       }
//       for(int i=fr;i<no-1;i++)
//       {
// 	 rec[i]=rec[i+1];
// 	 char str[3];
// 	 //itoa(i,str,10);
// 	sprintf(str,"%d",i);
// 	 strcpy(rec[i].ind,str);
//       }
//       no--;
//       fstream f1,f2;
//       f1.open("record1.txt",ios::out);
//       f2.open("index.txt",ios::out);
//       for(int i=0;i<no;i++)
//       {
//       strcpy(in[i].id,rec[i].id);
//       strcpy(in[i].ind,rec[i].ind);
//       }
//       sort_index();
//       for(int i=0;i<no;i++)
//       {
//       f1<<rec[i].ind<<"|"<<rec[i].id<<"|"<<rec[i].name<<"\n";
//       f2<<in[i].id<<"|"<<in[i].ind<<"\n";
//       }
//       f1.close();
//       f2.close();
//       cout<<"\n deletion successful\n";
// }

// int main()
// {
//       fstream file1,file3;
//       int choice;
//       char ind[5],st_id[20],name[20],id[20];
//       int i;
 
//       for(;;)
//       {
//       cout<<"\nchose\n1:add\n2:search\n3:delete\n4:display\n5:exit\n";
//       cin>>choice;
//       switch(choice)
//       {
// 	 case 1:{
// 		file1.open("record1.txt",ios::app|ios::out);
// 		if(!file1)
// 		{
// 		  cout<<"File creation error\n";
// 		  exit(0);
// 		}
// 		int n;
// 		cout<<"enter no of mentors\n";
// 		cin>>n;
// 		cout<<"enter the details\n";
// 		for(i=no;i<no+n;i++)
// 		{
// 		  cout<<"\nenter "<<i+1<<" mentor:";

// 		  cout<<"\nid:";
// 		  cin>>rec[i].id;
// 		  cout<<"\nname:";
// 		  cin>>rec[i].name;
		  
// 		   int q=search_id(rec[i].id,i);
		    
// 		file1<<i<<"|"<<rec[i].id<<"|"<<rec[i].name<<"\n";
// 	       }
// 	       file1.close();
// 	       no=no+n;
// 	       fstream file1,file2;
// 	       file2.open("index1.txt",ios::out);
// 	       file1.open("record1.txt",ios::in);
// 	       for(i=0;i<no;i++)
// 	       {
// 		  file1.getline(ind,5,'|');
// 		  file1.getline(id,20,'|');
// 		  file1.getline(name,20,'\n');
		  
// 		  strcpy(rec[i].ind,ind);
// 		  strcpy(in[i].id,id);
// 		  strcpy(in[i].ind,ind);
// 	       }
// 	       sort_index();
// 	       cout<<"\nafter sorting index file contents are\n";
// 	       for(i=0;i<no;i++)
// 	       cout<<in[i].id<<" "<<in[i].ind<<endl;
// 	       for(i=0;i<no;i++)
// 	       {
// 		   file2<<in[i].id<<"|"<<in[i].ind<<"\n";
// 	       }
// 	       file1.close();
// 	       file2.close();
// 	       break;
// 		}
// 	 case 2:{
// 		cout<<"\nEnter id of mentor whose rec is to be displayed\n";
// 		cin>>st_id;
// 		int q=search_index(st_id);
// 		if(q==1)
// 		   cout<<"\nsearch sucessful\n";
// 		else
// 		   cout<<"\nnot successful\n";
// 		break;
// 		}
// 	 case 3:{
// 		cout<<"Enter id of mentor whose rec is to be del\n";
// 		cin>>st_id;
// 		delet(st_id);
// 		break;
// 		}
// 	 case 4:{
// 	      fstream f1;
// 	      f1.open("record1.txt",ios::in);
// 	      if(!f1)
// 	      {
// 	      cout<<"err\\\\\\\\\\\\\\\\n";
// 	      exit(0);
// 	      }
// 	      int i=0;
// 	      while(i!=no)

// 	       {
// 		  f1.getline(ind,5,'|');
// 		  f1.getline(id,20,'|');
// 		  f1.getline(name,20,'|');
		  
// 		  cout<<"usn:"<<id<<"\t"<<"name:"<<name<<"\t"<<endl;
// 		  i++;
// 	       }
// 		  break;
// 		}
// 	case 5:{
// 		 cout<<"\n ending program";
		
// 		 exit(0);
// 		}
// 	 default:
// 		 cout<<"\nInvalid\n";
// 		 break;
// 	 }
//      }
// }
#include <iostream>
#include <fstream>
#include <string>

const int MAX_RECORDS = 20;

struct record1 {
    char age[5], ind1[5];
    char name1[20], usn[20], branch[5];
    char sem[5], meet[50], ia1[20], ia2[20], ia3[20];
};

// Custom hash function for record1 structure
size_t customHash(const std::string& str) {
    size_t hash = 0;
    for (char ch : str) {
        hash = (hash * 31) + static_cast<size_t>(ch);
    }
    return hash;
}

int main() {
    record1 rec1[MAX_RECORDS];

    // Read records from a file and populate the structure array
    std::ifstream file("records.txt");
    if (file.is_open()) {
        int recordCount = 0;
        while (file) {
            file.read(reinterpret_cast<char*>(&rec1[recordCount]), sizeof(record1));
            ++recordCount;
        }
        file.close();
        --recordCount;  // Adjust the record count to exclude the last read (empty) record

        // Perform hash-based operations on the records
        std::string searchName;
        std::cout << "Enter a name to search: ";
        std::cin >> searchName;

        size_t hash = customHash(searchName);
        bool recordFound = false;

        for (int i = 0; i < recordCount; ++i) {
            std::string name(rec1[i].name1);
            if (customHash(name) == hash && name == searchName) {
                std::cout << "Record found!" << std::endl;
                // Perform desired operations with the matched record
                recordFound = true;
                break;
            }
        }

        if (!recordFound) {
            std::cout << "Record not found." << std::endl;
        }
    } else {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 10
// void display(int a[MAX]);
// int create(int num);
// void lp(int a[MAX],int key,int num);
// void main()
// {
//     int a[MAX],num,ch,key,i;
//     for(i=0;i<MAX;i++)
//     {
//         a[i]=-1;
//     }
//     do
//     {
//         printf("Enter the value: ");
//         scanf("%d",&num);
//         key = create(num);
//         lp(a,key,num);
//         printf("\nDo you wish to continue? (1/0): ");
//         scanf("%d",&ch);
//     }while(ch);
//     display(a);
// }
// void display(int a[MAX])
// {
//     int i,ch;
//     printf("1:Display all\t2:Filtered Display\n");
//     do
//     {
//         printf("Enter Your choice: ");
//         scanf("%d",&ch);
//         switch(ch)
//         {  
//             case 1: printf("Hash Table is\n");
//                     for(i=0;i<MAX;i++)
//                     {
//                         printf("%d\t%d\n",i,a[i]);
//                     }
//                     break;
//             case 2: printf("Hash Table is\n");
//                     for(i=0;i<MAX;i++)
//                     {
//                         if(a[i]!=-1)
//                         {
//                             printf("%d\t%d\n",i,a[i]);
//                         }
//                     }
//                     break;
//             default: printf("Invalid choice\n");
//         }
//     }while(ch!=0);
// }
// int create(int num)
// {
//     int key;
//     key = num % MAX;
//     return key;
// }
// void lp(int a[MAX],int key,int num)
// {
//     int flag=0,i,c=0;
//     if(a[key]==-1)
//     {
//         a[key]=num;
//     }
//     else
//     {
//         printf("Collision Detected\n");
//         for(i=0;i<MAX;i++)
//         {
//             if(a[i]!= -1)
//             {
//                 c++;
//             }
//         }
//         if(c==MAX)
//         {
//             printf("Hash Table is Full\n");
//             return;
//         }
//         printf("Collisions Avoided by Linear Probing");
//         for(i=key+1;i<MAX;i++)
//         {
//             if(a[i]==-1)
//             {
//                 a[i]=num;
//                 flag = 1;
//                 break;
//             }
//         }
//         i=0;
//         while(i<key && flag==0)
//         {
//             if(a[i]==-1)
//             {
//                 a[i]=num;
//                 flag = 1;
//                 break;
//             }
//             i++;
//  }
// }
// }

// hash func
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#define addressspace 120
using namespace std;


char ind1[5],name1[20],age[5],sem[5],branch[5],usn[20],meet[50],ia1[20],ia2[20],ia3[20];
struct record1
{
	char age[5],ind1[5];
	char name1[20],usn[20],branch[5];
	char sem[5],meet[50],ia1[20],ia2[20],ia3[20];
}rec1[addressspace];

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
	cout<<"\nEnter USN of Student: ";
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


int main(){
	hashinit();
	int choice;
	
	do{	
		hashing();
		cout<<"\nEnter 0 to exit loop: ";
		cin>>choice;
	}while(choice!=0);
	for(int i=0;i<addressspace;i++){
		if(strcmp(rec1[i].usn,"-1")!=0){
			cout<<"USN:"<<rec1[i].usn<<"\n"<<"NAME:"<<rec1[i].name1<<"\n"<<"AGE:"<<rec1[i].age<<"\n"<<"SEM:"<<rec1[i].sem<<"\n"<<"BRANCH:"<<rec1[i].branch<<"\n"<<"MEETING DETAILS:"<<rec1[i].meet<<"\n"<<"IA1:"<<rec1[i].ia1<<"\n"<<"IA2:"<<rec1[i].ia2<<"\n"<<"IA3:"<<rec1[i].ia3<<"\n";
			cout<<"The Record is Stored in Hash Key: "<<i<<endl;
		}
	}
}