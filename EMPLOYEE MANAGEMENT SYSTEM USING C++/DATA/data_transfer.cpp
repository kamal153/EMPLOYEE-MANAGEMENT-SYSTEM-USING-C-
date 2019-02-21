#include<iostream>
#include<stdlib.h>
#include<fstream>
#define MAX 50
int num=0,n=-1,i,exp,age;
char name[20],designation[20];
long int code;
using namespace std;

main()
{
    ofstream file;
    ifstream ag,ex,de,na,co;
    file.open("EMPLOYMNGMENT.xls");
    ag.open("AGE.txt");
    ex.open("EXPERIENCE.txt");
    de.open("DESIGNATION.txt");
    na.open("NAME.TXT");
    co.open("CODE.txt");
    system("PAUSE");
        for(i=0;i<15;i++)
        {
            na>>name;
            co>>code;
            de>>designation;
            ex>>exp;
            ag>>age;
            file<<name<<"\t"<<code<<"\t"<<designation<<"\t"<<exp<<"\t"<<age<<"\n";
        }
    file.close();
    na.close();
    co.close();
    de.close();
    ex.close();
    ag.close();
}
