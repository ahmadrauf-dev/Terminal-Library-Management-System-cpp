#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void listBook();
void usrLogin();
void issueBook();
void returnBook();

void usrLogin()
{
    bool is_usr_running = true;

    while(is_usr_running)
    {
        cout<<"1. list Available Books\n2. Issue Book\n3. Return Book\n4. Go Back"<<endl;
        int usrinp;cin>>usrinp;
        switch(usrinp)
        {
            case 1: listBook();break;
            case 2: issueBook();break;
            case 3: returnBook();break;
            case 4: is_usr_running = false;break;
            default:cout<<"Please Enter a Valid Selection"<<endl;
        }
    }
}

void listBook()
{
    string line;
    int tempid;
    string tempname,tempauthor,tempissue;
    // vector<Book>lsbk;
    fstream lsfile("lib_rec.txt",ios::in);

    if(!lsfile)
    {
        cout<<"Error opening file!"<<endl;
    }
    cout<<"\n===========================================================\n";
    cout<<left
        <<setw(8)<<"ID"
        <<setw(20)<<"Name"
        <<setw(18)<<"Author"
        <<setw(12)<<"Status"<<endl;
    cout<<"\n===========================================================\n";
    while(lsfile>>tempid>>tempname>>tempauthor>>tempissue)
    {
        cout<<left
            <<setw(8)<<tempid
            <<setw(20)<<tempname
            <<setw(18)<<tempauthor
            <<setw(12)<<tempissue<<endl;
    }
    cout<<"\n===========================================================\n";
        lsfile.close();

}

void issueBook()
{
    int targetid;
    bool book_found = false;
    cout<<"Enter the ID of BOOK:"<<endl;
    cin>>targetid;

    fstream ifile("lib_rec.txt",ios::in);
    fstream ofile("temp.txt",ios::out);

    if(!ifile||!ofile)
    {
        cout<<"Error opening file"<<endl;
    }

    int tempid;
    string tempname,tempauthor,tempissue;
    while(ifile >> tempid >> tempname >> tempauthor >> tempissue)
    {
        if(tempid==targetid)
        {
            book_found = true;
            if(tempissue=="Available")
            {
                tempissue = "Issued";
            cout<<"========Book found with name "<<tempname<<" and is issued successfully!========"<<endl;
            }else{
                cout<<"========Book is already issued========"<<endl;
            }
        }
        ofile<<tempid<<" "<<tempname<<" "<<tempauthor<<" "<<tempissue<<"\n";
    }

    ifile.close();
    ofile.close();

    remove("lib_rec.txt");
    rename("temp.txt", "lib_rec.txt");

}

void returnBook()
{
    int targetid;
    bool book_found = false;
    cout<<"Enter the ID of BOOK:"<<endl;
    cin>>targetid;

    fstream ifile("lib_rec.txt",ios::in);
    fstream ofile("temp.txt",ios::out);

    if(!ifile||!ofile)
    {
        cout<<"Error opening file"<<endl;
    }

    int tempid;
    string tempname,tempauthor,tempissue;
    while(ifile >> tempid >> tempname >> tempauthor >> tempissue)
    {
        if(tempid==targetid)
        {
            book_found = true;
            if(tempissue=="Issued")
            {
                tempissue = "Available";
            cout<<"========Book found with name "<<tempname<<" and is returned successfully!========"<<endl;
            }else{
                cout<<"========Book is already Available maybe you have some other book check ID again========"<<endl;
            }
        }
        ofile<<tempid<<" "<<tempname<<" "<<tempauthor<<" "<<tempissue<<"\n";
    }

    ifile.close();
    ofile.close();

    remove("lib_rec.txt");
    rename("temp.txt", "lib_rec.txt"); 
}