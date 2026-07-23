#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "book.h"
#include "admin.h"
#include "user.h"

using namespace std;
void adminLogin();
int main()
{

    int usrinp;
    bool menu_running = true;
    

    cout<<"=========Welcome To Library Management System========="<<endl;
    // cout<<"1. Add Book\n2. Remove Book\n3. Issue Book\n4. Return Book\n5. Exit"<<endl;
    // cin>>usrinp; 

    while(menu_running)
    {    
        cout<<"1. User Login\n2. Admin Login\n3. Exit"<<endl;
        cin>>usrinp; 
        while(cin.fail())
        { 
        cin.clear();
        cin.ignore();
        cout<<"Invalid choice please enter again!"<<endl;
        cin>>usrinp;
        }
        switch(usrinp)
        {
            case 1: usrLogin();break;
            case 2: adminLogin();break;
            case 3: menu_running = false;break;
            default : cout<<"Please Enter a Valid Selection!"<<endl;break;
        }
    }

}

void adminLogin()
{

    
    // 17447165830677979488
    // hashing the password so it can be a bit secure
    hash <string> hasher;
    // #TODO make it more secure
    const string stored_pwd = "library345"; 
    string pwd;
    cout<<"Username : Admin"<<endl;
    cout<<"Password : ";
    cin>>pwd;

    // i am removing the hash system as it is producing inconsistent result will 
    // put in a SHA-256 later

    // size_t enteredHash = hasher(pwd);
    // const unsigned long long storedHash = 17447165830677979488ULL;

    // if(enteredHash==storedHash)
    // {
    //     cout<<"==========Access Granted=========="<<endl;
    //     adminAccess();
    // }else{
    //     cout<<"========Wrong password! Access Denied========"<<endl;
    // }

    if(pwd==stored_pwd)
    {
        cout<<"========Access Granted========"<<endl;
        adminAccess();
    }else{
        cout<<"========Wrong pasword! Access Denied========"<<endl;
    }


    

}