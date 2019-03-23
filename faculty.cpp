 #include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
class student{
public:
char name[50];
float num1=0,num2=0;
int roll;
void getdata()
{
    cout<<"Enter Your Name : "<<endl;
    cin>>gets(name);
    cout<<"Enter your Enrollment Number  : "<<endl;
    cin>>roll;

}
void putdata()
{
    cout<<"Name  : "<<name<<endl<<"Roll Number: "<<roll<<endl<<"Marks in subject 1 : "<<num1<<endl<<"Marks in subject 2: "<<num2<<endl;
}
}s;
void delete1()
{
ifstream fi("input",ios::binary);
int n,a=0;
ofstream fo("temp",ios::binary);
 cout<<"Enter Roll no. of that Student who would be deleted from the Database: "<<endl;
    cin>>n;
while(fi.read((char *)&s,sizeof(s)))
{
    if(s.roll!=n)
fo.write((char *)&s,sizeof(s));
else
    a=1;

}
fi.close();
fo.close();
remove("input");
rename("temp","input");
if(a==0)
    cout<<"---Given Enrollment Number is not Enrolled in our Database---"<<endl<<endl;
if(a==1)
    cout<<"--Record with Enrollment Number "<<n<<" is Deleted "<<endl<<endl;
}

void take()
{
    char ch;
     ofstream fi("input",ios::binary|ios::app);
    do
    {
       // student s;
        s.getdata();
        fi.write((char *)&s,sizeof(s));
        cout<<"Want to enter more (y/n)  : "<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fi.close();
}
void viewdata()
{int n;
     ifstream fi("input",ios::binary);
    //cout<<"------FOR STUDENTS VIEW ONLY-------"<<endl;
    cout<<"Enter Roll no. corrosponding to which you find his/her details : "<<endl;
    cin>>n;
//student s;
    int a=0;
    while(fi.read((char *)&s,(sizeof(s))))
    {
        if(s.roll==n)
        {
            s.putdata();
            a=1;
            cout<<endl;
    }
    }
    if(a==0)
        cout<<"---Given Enrollment Number is not Enrolled in our Database---"<<endl<<endl;
fi.close();
}
void faculty()
{
    int n;
cout<<endl<<"---CHOOSE YOUR OPERATIONS--"<<endl;
cout<<"1. Add marks corrosponding to each subject "<<endl<<"2. Update the Marks of Subject "<<endl<<"3. View the Student Result "<<endl;
cin>>n;
if(n==2)
{
int n1;
    cout<<"Enter Roll no. corrosponding to which you want to update his/her marks: "<<endl;
    cin>>n1;
    fstream fi("input",ios::binary|ios::in|ios::out);
  //   student s;
    int a=0;
    while(fi.read((char *)&s,(sizeof(s))))
    {
        if(s.roll==n1)

          {
a=1;
        int num;
            cout<<"Enter your Subject Choice"<<endl<<"1 . Maths  "<<endl<<"2 . Science "<<endl;
            cin>>num;
            if(num==1)
            {
                int x;
                cout<<"Marks of Maths will modify to : "<<endl;
                cin>>x;
                s.num1=x;
                int pos=fi.tellg()-sizeof(s);
            fi.seekp(pos,ios::beg);
            fi.write((char *)&s,sizeof(s));
                                       cout<<"--MARKS UPDATED--"<<endl<<endl;
            }
            else if(num==2)
            {
                 int x;
                cout<<"Marks of Science will modify to : "<<endl;
                cin>>x;
                s.num2=x;
                int pos=fi.tellg()-sizeof(s);
            fi.seekp(pos,ios::beg);
            fi.write((char *)&s,sizeof(s));
            cout<<"--MARKS UPDATED--"<<endl<<endl;
            }
            else
            {
                cout<<"--INVALID CHOICE---"<<endl<<"TRY AGAIN"<<endl<<endl;
            }
        }

    }
if(a==0)
    cout<<"Given Enrollment Number is not Enrolled in our Database"<<endl<<endl;

}
else if(n==1)
{
    int found=0;
    int n1;
    cout<<"Enter Roll no. corrosponding to which you want to update his/her marks: "<<endl;
    cin>>n1;
    fstream fi("input",ios::binary|ios::in|ios::out);
    // student s;
    int a=0;
    while(fi.read((char *)&s,(sizeof(s))))
    {
        if(s.roll==n1)
        {
            int mark1,mark2;
            cout<<"Enter marks corrosponding to Maths : "<<endl;
            cin>>mark1;
            cout<<"Enter marks corrosponding to Science : "<<endl;
            cin>>mark2;
            cout<<endl;
            s.num1=mark1;
            s.num2=mark2;
            int pos=fi.tellg()-sizeof(s);
            fi.seekp(pos,ios::beg);
            fi.write((char *)&s,sizeof(s));
            a=1;
            break;
            cout<<"---UPDATED---"<<endl<<endl;
                }
    }
    if(a==0)
        cout<<"Given Enrollment Number is not Enrolled in our Database"<<endl;
else
        cout<<"--MARKS UPDATED--"<<endl<<endl;

fi.close();
}
else if(n==3)
{
viewdata();
}
else
{
    cout<<"INVALID CHOICE " <<endl<<"TRY AGAIN"<<endl<<endl;
}
}
void print()
{
    ifstream fi("input",ios::in|ios::binary);
    //student s;
while(!fi.eof())
{
    fi.read((char*)&s,sizeof(s));
    if(fi)
    s.putdata();
    cout<<endl;
}
}
void admin()
{
    char a[30];
    cout<<"Enter Admin Password: ";
    cin>>a;
    char ans[]="admin";
    int s1=strcmp(a,ans);
    if(s1!=0)
    {
        cout<<"!!!!!!!INCORRECT PASSWORD!!!!!!!"<<endl<<"PLEASE TRY AGAIN"<<endl<<endl;
      return;
    }
print();
}
int main()
{
    int n,n1;
    cout<<"-------STUDENT DATABASE-------"<<endl<<endl;
    cout<<"1. Add New Student Record "<<endl<<"2. Student Login"<<endl<<"3. Faculty Login"<<endl<<"4. Admin View"<<endl<<"5. Delete an existing Student Record "<<endl<<"6. Exit"<<endl;
    cin>>n1;
if(n1!=6)
   {
   do
   {
      switch(n1)
    {
    case 1 :
    take();
    break;
    case 2 : viewdata();
    break;
    case 3:faculty();
    break;
    case 4:admin();
    break;
    case 5: delete1();
    break;
    }
    cout<<"1. Add New Student Record "<<endl<<"2. Student Login"<<endl<<"3. Faculty Login"<<endl<<"4. Admin View"<<endl<<"5. Delete an existing Student Record "<<endl<<"6. Exit"<<endl;
    cin>>n1;
   }while(n1!=6);
}
}
