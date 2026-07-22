
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void listBook();
void addBook();
void removeBook();
void issueBook();
void returnBook();


class Book
{
    private:
    int id;
    string name;
    string author;
    string issuetag;

    // initial values 
    public:
    Book() : id(0) , name(" ") , author(""), issuetag(""){}
    // 
    public:
    Book(int bid,string bname,string bauthor)
    {
        id = bid;
        name = bname;
        author = bauthor;
        issuetag = "Available";


    }

    //getters
    public:
    int getid()const{return id;}
    string getname()const{return name;}
    string getauthor()const{return author;}
    string addissuetag()const{return issuetag;}

// i dont think i will ned this but just in case
    void showrecdisplay()
    {
        cout<<"Book ID:"<<id<<endl;
        cout<<"Name:   "<<name<<endl;
        cout<<"Author: "<<author<<endl;
    }



};

void listBook()
{
    string line;
    int tempid;
    string tempname,tempauthor,tempissue;
    vector<Book>lsbk;
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
// vector<Book> library1;
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