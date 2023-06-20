#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    fstream seats;
    seats.open("seats.txt");
    //int r,c;
    /*cout<<"enter no of rows and columns in hall\n";
    cin>>r>>c;
    string seatname[r][c];
    cout<<"Enter the name of seat row-wise\n";
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    getline(cin>>ws,seatname[i][j]);
    if(!seats)
    {
    cout<<"File cannot be opened\n";
    exit(1);
    }
    
    for(int i=0;i<r;i++)
    {
    for(int j=0;j<c;j++)
    seats<<seatname[i][j]<<" ";
    seats<<endl;
    }*/
    if(seats.is_open())
        {
            string mn;
            for(int j=0;j<10;j++)
            {
            getline(seats,mn);
            cout<<mn<<endl;
            }
        }
    seats.close();
    return 0;
}