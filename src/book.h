#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// void listBook();
// void addBook();
// void removeBook();
// void issueBook();
// void returnBook();


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


// vector<Book> library1;




#endif