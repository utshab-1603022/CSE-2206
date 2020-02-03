#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<< "Transition Table::\n";
    cout<< "\tE\ta\tb\t\c\n";
    cout<< "p\tqr\t0\tq\tr\nq\t0\tp\tr\tpq\nr\t0\t0\t0\t0\n";
    cout<< "E-closure of p: p q r\n";
    cout<< "E-closure of q: p q r\nE-closure of r: r\n";
    /*int i;
    string a[4][5]=
    {
        {"","e","a","b","c"},
        {"p","q r","0","q","r"},
        {"q","0","p","r","p q"},
        {"r","0","0","0","0"}
    };
    cout<<"The transition table is given below:\n\n";
    for( i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
    string ans[3];
    for(i=0; i<4; i++)
    {
        if(i==0)
            continue;
        for(int j=0; j<5; j++)
        {
            ans=a[i][0]+" "+a[i][1];
        }
    }
    cout<<endl;
    for(i=0; i<3; i++)
    {
        cout<<"e-closure of state "<<a[i][0]<<": "<<ans[3]<<endl;
    }*/

}
