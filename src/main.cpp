#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "book.h"

using namespace std;

int main()
{

    int usrinp;
    bool menu_running = true;
    

    cout<<"=========Welcome To Library Management System========="<<endl;
    // cout<<"1. Add Book\n2. Remove Book\n3. Issue Book\n4. Return Book\n5. Exit"<<endl;
    // cin>>usrinp; 

    while(menu_running)
    {    
        cout<<"1. List Availabe Books\n2. Add Book\n3. Remove Book\n4. Issue Book\n5. Return Book\n6. Exit"<<endl;
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
            case 1: listBook();break;
            case 2: addBook();break;
            case 3: removeBook();break;
            case 4: issueBook();break;
            case 5: returnBook();break;
            case 6: menu_running = false;break;
            default : cout<<"Please Enter a Valid Selection!"<<endl;break;
        }
    }

}