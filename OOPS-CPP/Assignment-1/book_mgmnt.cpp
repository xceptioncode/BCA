//Author: Shubham Raj (@xceptioncode)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

//Cross Platform - Using it this way represent security risk, It has been designed just for compatibility.
//Security risk has not been considered for this program.
#ifdef __linux__
    #define pause "read"
    #define clear "clear"
#elif _WIN32
    #define pause "pause"
    #define clear "cls"
#endif

using namespace std;
int global_id, book_count=1, author_count=1;

class book
{
    int id;
    char book_name[50];
    int quantity;
    float price;
    char author_name[50];
public:
    void info() const;
    int retid() const;
    void add_book();
    void list_author() const;
    void list_book() const;
    void list_info() const;
    void modify(int book_id);
};
void getid();
void updateid();
void book::list_author() const
{
    cout<<author_count<<". ";
    cout<<author_name<<endl;
}
void book::list_book() const
{
    cout<<book_count<<". ";
    cout<<book_name<<endl;

}
int book::retid() const
{
    return id;
}
void book::modify(int book_id)
{
    id = book_id;
    cout<<"\nEnter new details to update database:-"<<endl;
    cout<<"  Book name : ";
    cin.ignore();
	cin.getline(book_name, 50);
	cout<<"  Book price : ";
	cin>>price;
	cout<<"  Quantity : ";
	cin>>quantity;
	cout<<"  Author name : ";
	cin.ignore();
	cin.getline(author_name, 50);
	cout<<"\nDatabase updated for book - ID:"<<id<<"\n\n";
}
void book::add_book()
{
    getid();
    id = global_id;
    cout<<"\nEnter book name : ";
    cin.ignore();
	cin.getline(book_name, 50);
	cout<<"Enter book price : ";
	cin>>price;
	cout<<"Enter quantity : ";
	cin>>quantity;
	cout<<"Enter author name : ";
	cin.ignore();
	cin.getline(author_name, 50);
	cout<<"\nBook added - ID:"<<id<<"\n\n";
	updateid();

}
void add()
{
    book b1;
    ofstream outfile;
    outfile.open("data.dat", ios::binary|ios::app);
    if(!outfile)
    {
        cout<<"Unable to create data file. Make sure you have permission to create new files here.\n"<<endl;
        return;
    }
    b1.add_book();
    outfile.write((char *)(&b1), sizeof(book));
	outfile.close();
    system(pause);
    cout<<"\n\n";
}

void getid()
{
    int id;
    ifstream readfile;
    readfile.open("book_id.txt", ios::in);
    if(!readfile)
    {
        //cout<<"I am here";
        ofstream outfile;
        outfile.open("book_id.txt", ios::out);
        outfile << 10000;
        global_id = 10000;
        outfile.close();
        return;
    }
    readfile >> id;
    global_id = id+1;
    readfile.close();

}
void updateid()
{
    ofstream outfile;
    outfile.open("book_id.txt");
    outfile << global_id;
    outfile.close();
}

void book::info() const
{
	cout<<"Book Id             Name             Price      Quantity          Author\n";
	cout<<"=============================================================================\n";
    //cout<<id<<setw(10)<<" "<<book_name<<setw(10)<<" "<<price<<setw(10)<<" "<<quantity<<setw(10)<<" "<<author_name<<endl;
    cout<<id<<setw(25)<<book_name<<setw(12)<<price<<setw(10)<<quantity<<setw(25)<<author_name<<endl;
    cout<<"\n\n";
}

void book::list_info() const
{
    //cout<<id<<setw(10)<<" "<<book_name<<setw(10)<<" "<<price<<setw(10)<<" "<<quantity<<setw(10)<<" "<<author_name<<endl;
    cout<<id<<setw(25)<<book_name<<setw(12)<<price<<setw(10)<<quantity<<setw(25)<<author_name<<endl;
}
void book_find(int book_id)
{
    book b1;
    ifstream readfile;
    bool flag=false;
    readfile.open("data.dat", ios::binary|ios::in);
    if(!readfile)
    {
        cout<<"Data file is not readable or not found.\n"<<endl;
        return;
    }
    while(readfile.read((char *) (&b1), sizeof(book)))
    {
        if(b1.retid() == book_id)
        {
            cout<<"\n";
            b1.info();
            flag = true;
        }

    }
    readfile.close();
    if (flag==false)
    {
        cout<<"Book ID not found in database\n"<<endl;
        return;

    }
    cin.ignore();
    system(pause);
    cout<<"\n\n";
}

void list_auth()
{
    book b1;
    ifstream readfile;
    readfile.open("data.dat", ios::binary|ios::in);
    if(!readfile)
    {
        cout<<"Data file is not readable or not found\n"<<endl;
        return;
    }
    cout<<"\nAUTHORS : "<<endl;
    cout<<"\n";
    while(readfile.read((char *)(&b1), sizeof(book)))
    {
       b1.list_author();
       author_count+=1;
    }
    cout<<"\n";
    cout<<"Total no. of record : "<<author_count-1<<"\n"<<endl;
    author_count=1;
    cin.ignore();
    system(pause);
    cout<<"\n\n";
}

void list_bk()
{
    book b1;
    ifstream readfile;
    readfile.open("data.dat", ios::binary|ios::in);
    if(!readfile)
    {
        cout<<"Data file is not readable or not found\n"<<endl;
        return;
    }
    cout<<"\nBOOKS : "<<endl;
    cout<<"\n";
    while(readfile.read((char *) (&b1), sizeof(book)))
    {
       b1.list_book();
       book_count+=1;
    }
    cout<<"\n";
    cout<<"Total no. of record : "<<book_count-1<<"\n"<<endl;
    book_count=1;
    cin.ignore();
    system(pause);
    cout<<"\n\n";
}

void list_info()
{
    int count=0;
    book b1;
    ifstream readfile;
    readfile.open("data.dat", ios::binary|ios::in);
    if(!readfile)
    {
        cout<<"Data file is not readable or not found\n"<<endl;
        return;
    }
    /*
    cout<<"\n==========================================================================\n";
	cout<<"Book Id          Name          Price          Quantity          Author\n";
	cout<<"==========================================================================\n";
	*/
	cout<<"\n=============================================================================\n";
	cout<<"Book Id             Name             Price      Quantity          Author\n";
	cout<<"=============================================================================\n";
    while(readfile.read((char *) (&b1), sizeof(book)))
    {
            b1.list_info();
            count+=1;
    }
    cout<<"\n";
    readfile.close();
    cout<<"Total no. of record : "<<count<<"\n"<<endl;
    cin.ignore();
    system(pause);
    cout<<"\n\n";
}

void modify(int book_id)
{
    book b1;
    fstream iofile;
    bool flag=false;
    iofile.open("data.dat", ios::binary|ios::in|ios::out);
    if(!iofile)
    {
        cout<<"Data file is not readable or not found.\n"<<endl;
        return;
    }
    while(iofile.read((char *) (&b1), sizeof(book)))
    {
        if(b1.retid() == book_id)
        {
            cout<<"\nCurrent Detail for this book Id:\n"<<endl;
            cout<<"Book Id             Name             Price      Quantity          Author\n";
            cout<<"=============================================================================\n";
            b1.list_info();
            b1.modify(book_id);
            int pos=(-1)*static_cast<int>(sizeof(book));
			iofile.seekp(pos,ios::cur);
			iofile.write((char *)(&b1), sizeof(book));
            flag = true;
        }

    }
    iofile.close();
    if (flag==false)
    {
        cout<<"Book ID not found in database\n"<<endl;
        return;

    }
    system(pause);
    cout<<"\n\n";
}

void delt(int book_id)
{
    book b1;
    char c;
    ifstream infile;
    bool flag=false;
    infile.open("data.dat", ios::binary);
    if(!infile)
    {
        cout<<"Data file is not readable or not found.\n"<<endl;
        return;
    }
    ofstream outfile;
    outfile.open("tmp6dgdj3tu3.dat", ios::binary); //Random character - SO that it does not interfere with any other temp file.
    if(!outfile)
    {
        cout<<"Unable to write data. This function needs writing permission to work properly.\nMake sure you have permission to create file.\n"<<endl;
        return;
    }
    while(infile.read((char *) (&b1), sizeof(book)))
    {
        if(b1.retid() == book_id)
        {
            cout<<"\nCurrent Detail for this book Id:\n"<<endl;
            cout<<"Book Id             Name             Price      Quantity          Author\n";
            cout<<"=============================================================================\n";
            b1.list_info();
            cout<<"\n\nAre you sure you want to delete this record? [y/n] : ";
            cin.ignore();
            cin.get(c);
            if (c=='y' || c == 'Y')
            {
                flag = true;
                continue;
            }
            else
                outfile.write((char *) (&b1), sizeof(book));
        }
        else
            outfile.write((char *) (&b1), sizeof(book));

    }
    infile.close();
    outfile.close();
    remove("data.dat");
	rename("tmp6dgdj3tu3.dat","data.dat");
    if (flag==false)
    {
        cout<<"Book ID not found in database\n"<<endl;
        return;

    }
    else
        cout<<"\nRecord Deleted .."<<endl;
    system(pause);
    cout<<"\n\n";
}

void welcome()
{

cout<<"\n\t _____         _      _____                                   _   ";
cout<<"\n\t| __  |___ ___| |_   |     |___ ___ ___ ___ ___ _____ ___ ___| |_ ";
cout<<"\n\t| __ -| . | . | '_|  | | | | .'|   | .'| . | -_|     | -_|   |  _|";
cout<<"\n\t|_____|___|___|_,_|  |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|  ";
cout<<"\n\t                                       |___|                      ";
cout<<"\n                                                                         ";
cout<<"\n\t                      _____         _             ";
cout<<"\n\t                     |   __|_ _ ___| |_ ___ _____ ";
cout<<"\n\t                     |__   | | |_ -|  _| -_|     |";
cout<<"\n\t                     |_____|_  |___|_| |___|_|_|_|";
cout<<"\n\t                           |___|                  ";
cout<<"\n\t                                                       ";
cout<<"\n\t                                               - Shubham Raj";
cout<<"\n\n\n\n\n";
system(pause);

}

int main()
{
    welcome();
    system(clear);
    int option, book_id;
    for(;;){
    cout<<"                        X World - Shubham Raj"<<endl;
    //cout<<"***********************************************************************"<<endl;
    cout<<"##########################################################################"<<endl;
    cout<<"1. Check Availability \n2. Add Book \n3. Modify Book Details \n4. Delete Book Record \n5. Book Lists With Details \n6. List Author \n7. List Book \n8. Exit"<<endl;
    //cout<<"***********************************************************************"<<endl;
    cout<<"\n\nEnter Option (1-8) : ";
    cin>>option;
    switch (option)
    {
    case 1:
        cout<<"Enter book id : ";
        cin>>book_id;
        book_find(book_id);
        break;
    case 2:
        add();
        break;
    case 3:
        cout<<"Enter book id : ";
        cin>>book_id;
        modify(book_id);
        break;
    case 4:
        cout<<"Enter book id : ";
        cin>>book_id;
        delt(book_id);
        break;
    case 5:
        list_info();
        break;
    case 6:
        list_auth();
        break;
    case 7:
        list_bk();
        break;
    case 8:
        cout<<"\nThanks for using book management system - Shubham Raj"<<endl;
        return 0;
    default:
        cout<<"\nWrong option"<<endl;

    }
    }
}
