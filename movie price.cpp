#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream ab;
    ab.open("price.txt",ios::out);
    int mov[6];
    mov[0]=300;
    mov[1]=170;
    mov[2]=150;
    mov[3]=280;
    mov[4]=190;
    mov[5]=190;
    for(int i=0;i<6;i++)
    {
        ab<<mov[i]<<endl;
    }
    ab.close();
    fstream p;
        p.open("price.txt",ios::in);
        string a;
        int b[10];
        int k=0;
        while(getline(p,a))
        {
            b[k++]=stoi(a);
        }
        for(int i=0;i<k;i++)
        cout<<b[i]<<endl;
        p.close();
}