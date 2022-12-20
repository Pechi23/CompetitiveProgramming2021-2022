#include <bits/stdc++.h>

using namespace std;
ifstream fin("arbint.in");
ofstream fout("arbint.out");

int n,m,v[400001],type,a,b,adi[400001],maxq;

void UPDATE (int cur,int st,int dr,int a,int b,int x)
{
    //cout<<cur<<' '<<st<<' '<<dr<<' '<<a<<' '<<b<<'\n';
    if (a<=st && dr<=b)
    {
        //cout<<cur<<' ';
        adi[cur]=x;
    }
    else
    {
        int mij=(st+dr)/2;
        if (a<=mij)
            UPDATE(2*cur,st,mij,a,b,x);
        if (b>mij)
        {
            UPDATE(2*cur+1,mij+1,dr,a,b,x);
        }
        adi[cur]=max(adi[2*cur],adi[2*cur+1]);
    }
}

void QUERY (int cur,int st,int dr,int a,int b)
{
    if (a<=st && dr<=b)
    {
        maxq=max(maxq,adi[cur]);
    }
    else
    {
        int mij=(st+dr)/2;
        if (a<=mij)
            QUERY(2*cur,st,mij,a,b);
        if (b>mij)
            QUERY(2*cur+1,mij+1,dr,a,b);
    }
}
int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        fin>>v[i];
        UPDATE(1,1,n,i,i,v[i]);
    }
    for (int i=1; i<=m; i++)
    {
        fin>>type>>a>>b;
        if (type==1)
        {
            UPDATE(1,1,n,a,a,b);
        }
        if (type==0)
        {
            maxq=0;
            QUERY(1,1,n,a,b);
            fout<<maxq<<'\n';
        }
        /*for (int i=1; i<=n; i++)
            cout<<v[i]<<' ';
        cout<<'\n';*/
    }
    return 0;
}
