#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "book.h"


using namespace std;

void adminAccess();
void addBook();
void removeBook();

void adminAccess()
{
    bool is_admin_running = true;
    while(is_admin_running)
    {
        cout<<"1. Add Book\n2. Remove Book\n3. Go back"<<endl;
        int usrinp;
        cin>>usrinp;
        switch(usrinp)
        {
            case 1: addBook();break;
            case 2: removeBook();break;
            case 3: is_admin_running = false;break;
            default:cout<<"Please Enter a valid Selection!"<<endl;
        }

    }
}

void addBook()
{

    int tempid;string tempname;string tempauthor;
    // taking temp input will put it in the object next
    cout<<"Enter book ID:"<<endl;cin>>tempid;
    cout<<"Enter Book Name:"<<endl;cin>>tempname;
    cout<<"Enter Book Author:"<<endl;cin>>tempauthor;

    Book B1(tempid,tempname,tempauthor);
    fstream file("lib_rec.txt",ios::app);
    if(!file)
    {
        cout<<"Error reading file!"<<endl;
    }

    file<<B1.getid()<<" "
        <<B1.getname()<<" "
        <<B1.getauthor()<<" "
        <<B1.addissuetag()<<"\n";

        file.close();

}

void removeBook()
{

}

