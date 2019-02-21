#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#define MAX 200
int num=0,n=-1,i,exp,age,flag=0;
char name[20],designation[20];
long int code;
using namespace std;

class employee
{
    public:
        char name[20];
        long int code;
        char designation[20];
        int exp;
        int age;
    public:
        void getdata(char na[20],long int co,char des[20],int ex,int ag);
        void built_em();
        void insert_em();
        void list_em();
        void delete_em();
        void edit_em();
        void editname(int);
        void editcode(int);
        void editdes(int);
        void editexp(int);
        void editage(int);
        void search_em();
        int cheack();
}emp[MAX],ex;
void menu();
void load();

int employee::cheack()
{
        for(int A=0;A<i;A++)
            if(emp[A].code==emp[i].code)
                return 1;
        return 0;
}

void employee::getdata(char na[20],long int co,char des[20],int ex,int ag)
{
    strcpy(this->name,na);
    this->code=co;
    this->age=ag;
    this->exp=ex;
    strcpy(this->designation,des);
}

void employee::search_em()
{
    system("cls");
    long int code;
    cout<<"\n\n\n\t\tWelcome To Search Of Employee Database "<<endl<<endl;
    cout<<"\t\tYou Can Search Only By Jobcode Of An Employee";
    cout<<endl<<"\t\tEnter Code Of An Employee..........: ";
    cin>>code;
    for(i=0;i<num+n;i++)
        if(emp[i].code==code)
        {
                cout<<"\n\n\n\t\t\t"<<"    EMPLOYEE NAME     "<<"JOB CODE     "<<"    DESIGNATION     "<<"EXPERIENCE  "<<"AGE"<<endl;
                cout<<"\t\t\t"<<"----------------------------------------------------------------------------"<<endl;
                cout<<"\t\t\t"<<setw(22)<<std::left<<emp[i].name<<setw(13)<<emp[i].code<<setw(20)<<std::left<<emp[i].designation<<setw(13)<<emp[i].exp<<setw(3)<<emp[i].age<<endl;
                break;
        }
    if(i==num+n)
    {
        cout<<"\n\t\t\t\tEntered Job code is Invalid ";
        cout<<endl<<"\n\t\t\t";
        system("pause");
        menu();
    }
    cout<<endl<<"\n\t\t\t";
    system("pause");
    menu();

}

void employee::edit_em()
{
    long int code;
    char x;
    system("cls");
    cout<<"\n\n\n\t\tEdit An Entry"<<endl<<"\t\tEnter An JobCode To Edit That Entry.........: ";
    cin>>code;
    for(i=0;i<num+n;i++)
        if(emp[i].code==code)
            break;
    if(i==num+n)
        {
            cout<<"\n\t\t\t\tEntered Job code is Invalid ";
            cout<<endl<<"\n\t\t\t";
            system("pause");
            menu();
        }
    cout<<"\t\t\t\t**** What Do You Want To edit ****"<<endl;
    cout<<endl<<"\t\t\t\t Press  n---->Name ";
    cout<<endl<<"\t\t\t\t Press  c---->Job code  ";
    cout<<endl<<"\t\t\t\t Press  d---->Designation     ";
    cout<<endl<<"\t\t\t\t Press  e---->Experience         ";
    cout<<endl<<"\t\t\t\t Press  a---->Age           ";
    cout<<endl<<endl<<"\t\t\t\tSelect Your Option Please ====> ";
    cin>>x;
    if(x=='n')
        editname(i);
    else if(x=='c')
        editcode(i);
    else if(x=='d')
        editdes(i);
    else if(x=='e')
        editexp(i);
    else if(x=='a')
        editage(i);
    else
        {
            system("cls");
            cout<<"\n\n\t\t\tInvalid Option ";
            cout<<endl<<"\n\t\t\t";
            system("pause");
            menu();
        }
    cout<<endl<<"\n\t\t\t";
    system("pause");
    menu();
}

void employee::editname(int i)
{
    cout<<"\n\t\tEnter The New Name----->  ";
    cin>>emp[i].name;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
}

void employee::editcode(int i)
{
    cout<<"\n\t\t\t\tEnter The New Job Code----->  ";
    cin>>emp[i].code;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
}

void employee::editdes(int i)
{
    cout<<"\n\t\t\t\tEnter The New Designation----->  ";
    cin>>emp[i].designation;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
}

void employee::editexp(int i)
{
    cout<<"\n\t\t\t\tEnter The New Experience----->  ";
    cin>>emp[i].exp;
        ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
}

void employee::editage(int i)
{
    cout<<"\n\t\t\t\tEnter The New Age----->  ";
    cin>>emp[i].age;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
}

void employee::delete_em()
{
    long int code;
    system("cls");
    cout<<"\n\n\n\t\tDelete An Entry"<<endl<<"\t\tEnter An JobCode To Delete That Entry........: ";
    cin>>code;
    for(i=0;i<num+n;i++)
        if(emp[i].code==code)
            break;
    if(i==num+n)
        {
            cout<<"\n\t\t\t\tEntered Job code is Invalid ";
            cout<<endl<<"\n\t\t\t";
            system("pause");
            menu();
        }
    for( ;i<num+n;i++)
        emp[i]=emp[i+1];
    num--;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    for(i=0;i<num+n;i++)
        file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    file.close();
    cout<<endl<<"\n\t\t\t";
    cout<<"Entry is deleted.";
    cout<<endl<<"\n\t\t\t";
    system("pause");
    menu();
}

void employee::list_em()
{
    system("cls");
    cout<<"\n\n\n\t\t\t"<<"    EMPLOYEE NAME     "<<"JOB CODE     "<<"    DESIGNATION     "<<"EXPERIENCE  "<<"AGE"<<endl;
    cout<<"\t\t\t"<<"----------------------------------------------------------------------------"<<endl;
    for(i=0;i<num+n;i++)
        cout<<"\t\t\t"<<setw(22)<<std::left<<emp[i].name<<setw(13)<<emp[i].code<<setw(20)<<std::left<<emp[i].designation<<setw(13)<<emp[i].exp<<setw(3)<<emp[i].age<<endl;
    cout<<endl<<"\n\t\t\t";
    system("pause");
    menu();
}

void employee::built_em()
{
    system("cls");
    n=num=0;
    cout<<"\n\n\n\t\tmaximum number of entries  -----  >  "<<MAX<<endl<<"\n\t\tHow many do you want........: ";
    cin>>num;
    ofstream file;
    file.open("EMPLOYMNGMENT.xls");
    if(num>MAX)
    {
        cout<<endl<<"\n\t\t\t";
        cout<<"Entered number is invalid. ";
        cout<<endl<<"\n\t\t\t";
        system("pause");
        menu();
    }
    else
    {
        for(i=n;i<num;i++)
        {
            cout<<endl<<"\t\tEnter the name of the employ.................: ";
            cin>>emp[i].name;
            do
            {
                flag=0;
                cout<<"\t\tEnter the job code of the employ.............: ";
                cin>>emp[i].code;
                    try
                    {
                        if(emp[i].code<=999)
                            throw 1;
                        if(emp[i].cheack())
                            throw 'a';
                    }
                    catch(int D)
                    {
                        cout<<"\t\tEnter job code is invalid.\n\t\t  please enter the new jobcode which has at lest 4 digit.\n";
                        flag=1;
                    }
                    catch(char D)
                    {
                        cout<<"\t\tEnter job code is Already exist.\n\t\t  please enter the new jobcode.\n";
                        flag=1;
                    }
            }while(flag);
            cout<<"\t\tEnter the designation of the employ..........: ";
            cin>>emp[i].designation;
            cout<<"\t\tHow many year's Experience of the employ.....: ";
            cin>>emp[i].exp;
            cout<<"\t\tEnter the age of the employ..................: ";
            cin>>emp[i].age;
            file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
        }
    }
    cout<<endl<<"\n\t\t\t";
    file.close();
    system("pause");
    menu();
}

void employee::insert_em()
{
    system("cls");
    ofstream file;
    file.open("EMPLOYMNGMENT.xls",ios::app);
    i=num+n;
    num++;
    cout<<endl<<"\n\n\n\n\t\tEnter the name of the employ.................: ";
    cin>>emp[i].name;
    do
    {
        flag=0;
        cout<<"\t\tEnter the job code of the employ.............: ";
        cin>>emp[i].code;
        try
        {
            if(emp[i].code<=999)
                throw 1;
            if(emp[i].cheack())
                throw 'a';
        }
        catch(int D)
        {
            cout<<"\t\tEnter job code is invalid.\n\t\t  please enter the new jobcode which has at lest 4 digit.\n";
            flag=1;
        }
        catch(char D)
        {
            cout<<"\t\tEnter job code is Already exist.\n\t\t  please enter the new jobcode.\n";
            flag=1;
        }
    }while(flag);
    cout<<"\t\tEnter the designation of the employ..........: ";
    cin>>emp[i].designation;
    cout<<"\t\tHow many year's Experience of the employ.....: ";
    cin>>emp[i].exp;
    cout<<"\t\tEnter the age of the employ..................: ";
    cin>>emp[i].age;
    cout<<endl<<"\n\t\t\t";
    file<<emp[i].name<<"\t"<<emp[i].code<<"\t"<<emp[i].designation<<"\t"<<emp[i].exp<<"\t"<<emp[i].age<<"\n";
    system("pause");
    file.close();
    menu();
}

void menu()
{
    system("cls");
    char x;
    cout<<endl<<"\n\n\t\t\t\t*****  Employees Management System 1.0.1 ***** ";
    cout<<endl<<"\n\t\t\t\t Press  b---->Built The Employee Table ";
    cout<<endl<<"\t\t\t\t Press  l---->List The Employee Table  ";
    cout<<endl<<"\t\t\t\t Press  i---->Insert New Entry        ";
    cout<<endl<<"\t\t\t\t Press  d---->Delete An Entry         ";
    cout<<endl<<"\t\t\t\t Press  e---->Edit An Entry           ";
    cout<<endl<<"\t\t\t\t Press  s---->Search A record          ";
    cout<<endl<<"\t\t\t\t Press  q---->Quit Program        ";
    cout<<endl<<endl<<"\t\t\t\t Select Your Option Please ====> ";
    cin>>x;
    if(x=='b'||x=='B')
        ex.built_em();
    else if(x=='l'||x=='L')
        ex.list_em();
    else if(x=='i'||x=='I')
        ex.insert_em();
    else if(x=='d'||x=='D')
        ex.delete_em();
    else if(x=='e'||x=='E')
        ex.edit_em();
    else if(x=='s'||x=='S')
        ex.search_em();
    else if(x=='q'||x=='Q')
        {
            system("cls");
            cout<<"\n\n\n\n\t\t\t\tThank you for visit"<<endl<<"\n\t\t\t\tMADE BY : \"KAMAL KAKADIYA(17DCE021)\""<<endl<<"\n\t\t\t\t        : \"DHARMIK ITALIYA(17DCE013)\""<<endl<<"\n\t\t\t\t        : \"TIRTHAK BHINGARADIYA(17DCE003)\""<<endl<<"\n\t\t\t\t        : \"HIRENKUMAR PARMAR(17DCE034)\""<<endl<<endl;
            exit(0);
        }
    else
        {
            system("cls");
            cout<<"\n\n\t\t\tInvalid Option ";
            cout<<endl<<"\n\t\t\t";
            system("pause");
            menu();
        }
}

void load()
{
    ifstream file;
    file.open("EMPLOYMNGMENT.xls");
        for(i=0;!file.eof();i++)
        {
            file>>name>>code>>designation>>exp>>age;
            emp[i].getdata(name,code,designation,exp,age);
            n++;
        }
    file.close();
}
