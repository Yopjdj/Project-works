#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class movie
{
    public:
    string name;
    string phoneNo;
    int amount;
    string seatNo;

    movie()
    {
        amount=0;
        seatNo="";
        phoneNo="";
    }

    void input()
    {
    cout<<"\n\t\t\t\t\tEnter your details :\n";
    cout<<"\t\t\t\t\tName : ";
    getline(cin>>ws,name);
    cout<<"\t\t\t\t\tPhone number : ";
    getline(cin>>ws,phoneNo);
    cout<<"\n";
    }

    int book(int i)
    {
        fstream p;
        p.open("price.txt",ios::in);
        string a;
        int b[10];
        int k=0;
        while(getline(p,a))
        {
            b[k++]=stoi(a);
        }
        p.close();
        return b[i-1];
    }   

    void book(string s)
    {
        fstream m1,m2;
        string line,newline="";
        m1.open("newFile.txt",ios::out);
        m2.open("seats.txt",ios::in);
        int k=int(s.at(0))-48;
        int i=int(s.at(1))-65;
        while(i>0)
        {
            getline(m2,line);
            m1<<line<<endl;
            i--;
        }
        getline(m2,line);
        line.replace(3*(k-1),2,"X ");
        m1<<line<<endl;
        while(getline(m2,line))
        m1<<line<<endl;
        m1.close();
        m2.close();
        remove("seats.txt");
        rename("newFile.txt","seats.txt");        
    }

    void book()
    {
        fstream movie;
        int choice;
        cout<<"Choose the movie you want to see from the menu below\n";
        movie.open("movies.txt",ios::in);
        if(movie.is_open())
        {
            string s;
            while(getline(movie,s))
            cout<<s<<endl;
        }
        cout<<"Enter choice number : ";
        cin>>choice;
        amount=book(choice);
        movie.close();       
        cout<<"Enter the seat you want from the available choices shown below\n\n";
        movie.open("seats.txt",ios::in);
        if(movie.is_open())
        {
            string mn;
            for(int j=0;j<10;j++)
            {
            getline(movie,mn);
            cout<<mn<<endl;
            }
        }
        cout<<"\n\n\t\tBooked seats are marked with X\n";
        cout<<"\t\tEnter your choice ----->   ";
        getline(cin>>ws,seatNo);
        if(seatNo=="X")
        {
            cout<<"WRONG CHOICE!! ENTER AGAIN\n";
            book();
        }
        book(seatNo);
        movie.close();
        cout<<"\n\t\t\t------> Your payable amount is : Rs "<<amount<<" <------"<<endl;
        //payment();
    }
};


class details:public movie
{
    public:
    void add()
    {
        fstream d1;
        d1.open("details.txt",ios::app);
        d1<<"Name : "<<name<<endl;
        d1<<"Phone number : "<<phoneNo<<endl;
        d1<<"Seat number : "<<seatNo<<endl;
        d1<<"Amount paid : "<<amount<<endl;
        d1.close();
    }
    void display()
    {
        cout<<"\n\t\t\t\t||  YOUR DETAILS ARE SHOWN BELOW  ||\n\n";
        cout<<"\t\t\t\t\tNAME         :  "<<name<<endl;
        cout<<"\t\t\t\t\tPHONE NUMBER :  "<<phoneNo<<endl;
        cout<<"\t\t\t\t\tSEAT NUMBER  :  "<<seatNo<<endl;
        cout<<"\t\t\t\t\tAMOUNT PAID  :  "<<amount<<endl;
    }
};
int main()
{
    int k=0;
    details d;
    cout << "    \t\t\t************************************" << endl;
    cout << "    \t\t\t* WELCOME TO MOVIE TICKET BOOKING SYSTEM *" << endl;
    cout << "    \t\t\t************************************\n\n"<<endl;
    do
    {
        cout<<"\n\t\t\t\t------> Enter 1 for booking.\n";
        cout<<"\t\t\t\t------> Enter 2 for displaying details.\n";
        cout<<"\t\t\t\t------> Enter 3 to end.\n\n";
        cout<<"\t\t\t\tEnter your choice :    ";
        cin>>k;
        if(k==1)
        {
            d.input();
            d.book();
            d.add();
        }
        else if(k==2)
            d.display();
        else if(k==3)
        {
            cout<<"\n\t\t\t\t<<------!!!!  Exiting movie ticket booking section   !!!!------>>\n";
            break;
        }
        else
        cout<<"\t\t!! Wrong input  !!  Enter again.\n\n";
    }while(k!=3);
    return 0;
}