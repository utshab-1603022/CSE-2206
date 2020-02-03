#include<bits/stdc++.h>
using namespace std;
int a[100][10];

map<set<int>,bool>mp;
set<int>::iterator it1,it2,it3;

set<int> eclosure(set<int> e)
{
    set<int>ret;
    stack<int>st;
    int i,t;

    for(it2=e.begin(); it2!=e.end(); it2++)
    {
        ret.insert(*it2);
        st.push(*it2);
    }

    while(!st.empty())
    {
        t = st.top();
        st.pop();
        for( i = 0; i < 13; i++)
        {
            if(a[i][0] == t && a[i][2] == -1)
            {
                ret.insert(a[i][1]);
                st.push(a[i][1]);
            }
        }
    }
    return ret;
}


set<int> Move(set<int>tem, int tr)
{
    set<int>ret;
    for(it1= tem.begin(); it1!=tem.end(); it1++)
    {
        int tt = *it1;
        for(int i = 0; i < 13; i++)
        {
            if(a[i][0] == tt && a[i][2] == tr)
                ret.insert(a[i][1]);
        }
    }
    return ret;
}

bool check(set<int>tem,int ff)
{
    for(it1=tem.begin(); it1!=tem.end(); it1++)
    {
        if(*it1==ff)
            return true;
    }
    return false;
}


int main()
{
    freopen("input.txt","r",stdin);
    int a1, a2, a3,f,ck;
    queue <set<int> > ss;
    for(int i = 0; i < 13; i++)
    {
        scanf("%d %d %d",&a1,&a2,&a3);
        a[i][0] = a1;
        a[i][1] = a2;
        a[i][2] = a3;
    }

    set<int> flag, s,s1,s2;

    scanf("%d",&a1);
    printf("Starting node of nfa : %d\n",a1);

    flag.insert(a1);

    scanf("%d",&f);
    printf("Final node of nfa: %d\n\n",f);

    s = eclosure(flag);
    s1= eclosure(Move(s, 0));
    s2 = eclosure(Move(s, 1));
    ss.push(s1);
    ss.push(s2);
    mp[s]=true;

    printf("DFA:\n\n");
    cout <<"   states\t\t  symbol(a)\t\t symbol(b)\n\n";

    for(it1 = s.begin(); it1 != s.end(); ++it1)
        cout << *it1 << " ";
    cout << "\t\t";

    for(it1 = s1.begin(); it1 != s1.end(); ++it1)
        cout << *it1 << " ";
    cout << "\t\t";

    for(it1 = s2.begin(); it1 != s2.end(); ++it1)
        cout << *it1 << " ";

    ck=check(s,f);
    printf(ck>0? "\t\t(a final state is found)\n":"\n");

    while(!ss.empty())
    {
        set<int>tem= ss.front();
        ss.pop();
        if(mp[tem]==true)
            continue;

        s = eclosure(tem);
        s1 = eclosure(Move(s, 0));
        s2 = eclosure(Move(s, 1));

        for(it1 = s.begin(); it1 != s.end(); ++it1)
            cout << *it1 << " ";

        cout<<"\t\t";

        for(it1 = s1.begin(); it1 != s1.end(); ++it1)
            cout << *it1 << " ";

        cout<<"\t\t";

        for(it1 = s2.begin(); it1 != s2.end(); ++it1)
            cout << *it1 << " ";

        ck=check(s,f);
        printf(ck>0? "\t(a final state is found)\n":"\n");
        ss.push(s1);
        ss.push(s2);
        mp[tem]=true;
    }
    return 0;
}
