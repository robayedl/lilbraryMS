
///////////////////////////////////////////////////  Library Declaration  ///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<ctime>

using namespace std;

///////////////////////////////////////////////////  Base Class  ///////////////////////////////////////////////////////////////////////////////

class Library
{
protected:

    char name[20],category[20],author[20],issue[5];
    int page,id,quantity,b_quantity;
    double price;

public:

    void setBookValue()            //The Member Function is to Add the Data of Library Class
    {
        cout<<"\n\n\t\t## Adding Book Info ##";
        cout<<endl<<"Input Category: ";
        fflush(stdin);
        cin.getline(category,19);
        cout<<endl<<"Input Name: ";
        fflush(stdin);
        cin.getline(name,19);
        cout<<endl<<"Input ID: ";
        cin>>id;
        cout<<endl<<"Input Author: ";
        fflush(stdin);
        cin.getline(author,19);
        strcpy(issue,"No");
        cout<<endl<<"Input Price: ";
        cin>>price;
        cout<<endl<<"Input Page: ";
        cin>>page;
        cout<<endl<<"Input Quantity: ";
        cin>>quantity;
        b_quantity=quantity;
    }

    int storeBookData()       //The Member Function is to Store the Data of Book Class in File
    {
        ofstream fout;
        fout.open("Library Information.txt",ios::app);
        fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
        fout.close();
    }

    void showBookData()           //The Member Function is to View the Data of Book Class
    {
        cout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t\t"<<std::left<<setw(7)<<b_quantity<<endl;
    }

    void deleteBookData(int ID)           //The Member Function is to Delete the Data of Book Class
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Library.txt",ios::out);
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                if(ID!=id)
                {
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                else
                {
                    c++;
                }
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Library Information.txt");
            rename("temp Library.txt","Library Information.txt");
        }
    }

    void editBookData(int ID)         //The Member Function is to Edit the Data of Library Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Library.txt",ios::out);
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                if(ID==id)
                {
                    c++;
                    setBookValue();
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(5)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Library Information.txt");
            rename("temp Library.txt","Library Information.txt");
        }
    }

    void searchBookData(int ID)           //The Member Function is to Search the Data of Library Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                if(ID==id)
                {
                    cout<<endl<<std::left<<setw(20)<<"Category"<<std::left<<setw(10)<<"\tName"<<std::left<<setw(5)<<"\tID"<<std::left<<setw(10)<<"\tAuthor"<<std::left<<setw(11)<<"\tIssue"<<std::left<<setw(7)<<"\tPrice"<<std::left<<setw(7)<<"\tPage"<<std::left<<setw(7)<<"\tQuantity"<<std::left<<setw(7)<<"\tTotal Quantity"<<endl<<endl;
                    c++;
                    showBookData();
                }
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllBookData()            //The Member Function is to View All the Data of Library Class Staff
    {
        ifstream fin;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Category"<<std::left<<setw(10)<<"\tName"<<std::left<<setw(5)<<"\tID"<<std::left<<setw(10)<<"\tAuthor"<<std::left<<setw(11)<<"\tIssue"<<std::left<<setw(7)<<"\tPrice"<<std::left<<setw(7)<<"\tPage"<<std::left<<setw(7)<<"\tQuantity"<<std::left<<setw(7)<<"\tTotal Quantity"<<endl<<endl;
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                showBookData();
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
        }
        fin.close();
    }

    void issueBookData(int ID)         //The Member Function is to Edit the Data of Library Class Staff
    {
        int c=0,iss=0;
        ifstream fin;
        ofstream fout;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Library.txt",ios::out);
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                if(ID==id)
                {
                    c++;
                    if(quantity!=0)
                    {
                        strcpy(issue,"Yes");
                        quantity--;
                    }
                    else
                    {
                        cout<<"\n\tAll books are issued"<<endl;
                        iss = 1;
                    }
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(5)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                if(iss!=1)
                cout<<"\n\tIssued Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Library Information.txt");
            rename("temp Library.txt","Library Information.txt");
        }
    }

    void returnBookData(int ID)         //The Member Function is to Edit the Data of Library Class Staff
    {
        int c=0,iss=0;
        ifstream fin;
        ofstream fout;
        fin.open("Library Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Library.txt",ios::out);
            fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            while(!fin.eof())
            {
                if(ID==id)
                {
                    c++;
                    if(quantity!=b_quantity)
                    {
                        quantity++;
                        if(quantity==b_quantity)
                        {
                            strcpy(issue,"No");
                        }
                    }
                    else
                    {
                        cout<<"\n\tAll copies are Available"<<endl;
                        iss = 1;
                    }
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(5)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<category<<"\t"<<std::left<<setw(10)<<name<<"\t"<<std::left<<setw(5)<<id<<"\t"<<std::left<<setw(11)<<author<<"\t"<<std::left<<setw(7)<<issue<<"\t\t"<<std::left<<setw(7)<<price<<"\t"<<std::left<<setw(7)<<page<<"\t"<<std::left<<setw(7)<<quantity<<"\t"<<std::left<<setw(7)<<b_quantity<<endl;
                }
                fin>>category>>name>>id>>author>>issue>>price>>page>>quantity>>b_quantity;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                if(iss!=1)
                cout<<"\n\tReturn Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Library Information.txt");
            rename("temp Library.txt","Library Information.txt");
        }
    }
};


///////////////////////////////////////////////////////////  Menu Function  ///////////////////////////////////////////////////////////////////////////////

int Menu()      //The Menu is to Choose the option of the Library
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tWelcome to Library Management System"<<endl<<endl<<endl;
    cout<<endl<<endl<<"\t\t\t#####\tMain Menu\t#####"<<endl<<endl;
    cout<<"\t\t[1] Add Book Info"<<endl;
    cout<<"\t\t[2] Delete Book Info"<<endl;
    cout<<"\t\t[3] Edit Book Info"<<endl;
    cout<<"\t\t[4] Search Book Info"<<endl;
    cout<<"\t\t[5] Display All Book List"<<endl;
    cout<<"\t\t[6] Issue Book Info"<<endl;
    cout<<"\t\t[7] Return Book Info"<<endl;
    cout<<"\t\t[8] Quit"<<endl<<endl;
    cout<<"\tPlease Enter Your Choice: ";
    int Choice;
    cin>>Choice;
    return Choice;
}

///////////////////////////////////////////////////  Time Function  ///////////////////////////////////////////////////////////////////////////////


void Time()
{
    time_t now;
    struct tm nowlocal;
    now=time(NULL);
    nowlocal=*localtime(&now);
    cout<<"\t\tToday's Date is: ";
    cout<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon<<"/"<<nowlocal.tm_year+1900<<endl;
    cout<<"\t\tCurrent Time is: ";
    cout<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<endl<<endl<<endl;
}

///////////////////////////////////////////////////////////  Main Menu  ///////////////////////////////////////////////////////////////////////////////

int main()
{
    Library L1;
    char e;
    int ID;
    Time();
    cout<<"\tPlease Press Any Key to Start!!!";
    getch();
    system("cls");
    while(1)
    {
        switch(Menu())
        {
           case 1:

                do
                {
                    system("cls");
                    Time();
                    L1.setBookValue();
                    L1.storeBookData();
                    cout<<"\n\tAdded Successfully!!!\n\n";
                    cout<<"\n\nAdd More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;

            case 2:

                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Deleting Book Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>ID;
                    try
                    {
                        L1.deleteBookData(ID);
                    }
                    catch(const char* msg)
                    {
                        cerr<<msg<<endl;
                    }
                    cout<<"\n\nDelete More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;

            case 3:

                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Editing Book Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>ID;
                    try
                    {
                        L1.editBookData(ID);
                    }
                    catch(const char* msg)
                    {
                        cerr<<msg<<endl;
                    }
                    cout<<"\n\nEdit More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;

            case 4:

                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Searching Book Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>ID;
                    try
                    {
                        L1.searchBookData(ID);
                    }
                    catch(const char* msg)
                    {
                        cerr<<msg<<endl;
                    }
                    cout<<"\n\n";
                    cout<<"\n\nSearch More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;

            case 5:

                system("cls");
                Time();
                try
                {
                    L1.viewAllBookData();
                }
                catch(const char* msg)
                {
                    cerr<<msg<<endl;
                }
                cout<<"\n\n\n";
                cout<<"\tPress Any Key for Main Menu!!!  ";
                getch();
                break;

            case 6:

                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Issue Book Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>ID;
                    try
                    {
                        L1.issueBookData(ID);
                    }
                    catch(const char* msg)
                    {
                        cerr<<msg<<endl;
                    }
                    cout<<"\n\n";
                    cout<<"\n\nIssue More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;
            case 7:

                do
                {
                    system("cls");
                    Time();
                    cout<<"\n\n\t\t## Return Book Info ##\n\n";
                    cout<<"\n\n\tInput ID: ";
                    cin>>ID;
                    try
                    {
                        L1.returnBookData(ID);
                    }
                    catch(const char* msg)
                    {
                        cerr<<msg<<endl;
                    }
                    cout<<"\n\n";
                    cout<<"\n\nReturn More!! (Y/N): ";
                    fflush(stdin);
                    cin>>e;
                }while(e=='y'||e=='Y');
                break;

            case 8:

                system("cls");
                Time();
                cout<<"\tPress Any Key to Close The Program!!!\n\n";
                getch();
                cout<<"\n\t\tThe Program Has Made By EWU CSE107 Section-9";
                cout<<"\n\n\t\tAll Credit Goes To >===>\n\n";
                cout<<std::left<<setw(30)<<"\t\t1. Riffat Ara Khan Tayna"<<"\t\tID:2018-1-60-183\n";
                cout<<std::left<<setw(30)<<"\t\t2. Robayed Ashraf"<<"\t\tID:2018-1-60-238\n";
                cout<<std::left<<setw(30)<<"\t\t3. Md. Tanvir Hossain Joarddar"<<"\t\tID:2018-1-60-242\n";
                cout<<std::left<<setw(30)<<"\t\t4. Nawfat Tahsin Azad"<<"\t\tID:2018-1-60-247\n";
                exit(0);

                default:

                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;

        }
    }
}
