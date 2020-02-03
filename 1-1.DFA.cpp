#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(1)
    {
        cout<<"Enter String:";
        cin>>s;
        long long length=s.length();
        string state="start";

        for(long long i=0; i<length; i++)
        {
            if(state=="start")
            {
                if(s[i]=='0')
                    state="state1";
                else
                    state="start";
            }
            else if(state=="state1")
            {
                if(s[i]=='0')
                    state="state1";
                else
                    state="state2";
            }
            else if(state=="state2")
            {
                if(s[i]=='0')
                    state="state1";
                else
                    state="accept";
            }
            else
                state="accept";
        }
        if(state=="accept")
            cout<<"\tAccepted"<<endl;
        else
            cout<<"\tRejected"<<endl;
        cout<<"\n\tTransition Table\n\t\n\t0\t1\n*->q0\tq1\tq0\nq1\tq1\tq2\nq2\tq1\tq3\nq3\tq3\tq3\n\n";

        if(s=="0")
            break;
    }
}
