#include<bits/stdc++.h>
#include<string.h>
using namespace std;

char a='a', b='b', c='c', e='e';
char p='p', q='q', r='r', f='f';
char NFA[4][5];

int main()
{
    int i,j;

    NFA[0][0] = '     '; NFA[0][1] = a; NFA[0][2] = b; NFA[0][3] = c; NFA[0][4] = e;
    NFA[1][0] = p; NFA[1][1] = p; NFA[1][2] = q; NFA[1][3] = r; NFA[1][4] = f;
    NFA[2][0] = q; NFA[2][1] = q; NFA[2][2] = r; NFA[2][3] = f; NFA[2][4] = p;
    NFA[3][0] = r; NFA[3][1] = r; NFA[3][2] = f; NFA[3][3] = p; NFA[3][4] = q;

    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            {
                if(j==4)
                    cout<<NFA[i][j]<<endl;
                else
                    cout<<NFA[i][j]<<ends;
            }

    cout<< "\nEpsilon Closure(p): { "<<ends;
    if(NFA[1][4] == 'f')
        cout<<"p";
    else
        cout<<"p, "<<NFA[1][4];

    cout<< " }\nEpsilon Closure(q): { "<<ends;
    if(NFA[2][4] == 'f')
        cout<<"q";
    else
        cout<<"q, "<<NFA[2][4];
    if((NFA[1][4] == 'p' || NFA[1][4] == 'r') && (NFA[1][4] == 'p' || NFA[1][4] == 'r'))
        cout<<NFA[2][4];

    cout<< " }\nEpsilon Closure(r): { "<<ends;
    if(NFA[3][4] == 'f')
        cout<<"r";
    else
        cout<<"r, "<<NFA[3][4]<<", ";
    if((NFA[2][4] == 'p' || NFA[2][4] == 'p') && (NFA[2][4] == 'p' || 'q'))
        cout<<NFA[2][4];
    cout<<" }\n";
}
