#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
char s[400];
int poz=1,n,m,ls[400],rs[400],nr=1,dp[400],sol_c=1;

struct el
{
    int tip,k;
} v[400];

void create (int nod)
{
    if (s[poz]=='V')
        v[nod].tip=2;
    else   if (s[poz]=='H')
        v[nod].tip=1;
    else    v[nod].tip=3;
    poz++;
    if (s[poz-1]!='*')
    {
        while (s[poz]>='0' && s[poz]<='9')
        {
            v[nod].k=v[nod].k*10+s[poz]-'0';
            poz++;
        }
        ls[nod]=++nr;
        create (nr);
        rs[nod]=++nr;
        create(nr);
    }
}

void solve (int nod,int valh,int valv)
{
    if (nod!=0)
    {
        solve(ls[nod],valh,valv);
        if (v[nod].tip==1)
        {
            n=max(n,v[nod].k+valh);
            valh+=v[nod].k;
        }
        else    if (v[nod].tip==2)
        {
            m=max(m,v[nod].k+valv);
            valv+=v[nod].k;
        }
        solve(rs[nod],valh,valv);
    }
}

int dfs (int nod)
{
    if (v[nod].tip!=3)
    {
        int cant=1;
        if (v[ls[nod]].tip == v[nod].tip)
            cant+=dfs (ls[nod]);
        else    sol_c=sol_c*dp[dfs (ls[nod])]%mod;
        if (v[rs[nod]].tip == v[nod].tip)
            cant+=dfs (rs[nod]);
        else    sol_c=sol_c*dp[dfs (rs[nod])]%mod;
        return cant;
    }
    return 0;
}

void afis (int nod)
{
    if (nod!=0)
    {
        if (v[nod].tip==1)
            cout<<'H'<<v[nod].k;
        else    if (v[nod].tip==2)
            cout<<'V'<<v[nod].k;
        else    cout<<'*';
        afis(ls[nod]);
        afis(rs[nod]);
    }
}

void schimba (int nod, int tata=0,bool side=0)//0-stanga 1-dr
{
    if (nod==0)
        return;
    schimba(ls[nod],nod,0);
    if (v[nod].tip == v[ls[nod]].tip)
    {
        v[nod].k-=v[ls[nod]].k;
        int aux=rs[ls[nod]],newdad=ls[nod];
        if (side==0)
            ls[tata]=ls[nod];
        else    rs[tata]=ls[nod];
        rs[ls[nod]]=nod;
        ls[nod]=aux;
        schimba(ls[newdad],newdad,0);
        schimba(rs[newdad],newdad,1);
    }
    else    schimba(rs[nod],nod,1);
}

int32_t main()
{
    int t;
    cin>>t;
    cin.get();
    cin.getline(s+1,358);
    int lg=strlen(s+1),i,j,res_a=0;
    if (t==1)
    {
        for (i=1; i<=lg; i++)
            if (s[i]=='*')
                res_a++;
        cout<<res_a<<'\n';
        return 0;
    }
    create(1);
    if (t==2)
    {
        solve (1,0,0);
        cout<<n+1<<' '<<m+1<<'\n';
        return 0;
    }
    dp[0]=1,dp[1]=1,dp[2]=2;
    for (i=3;i<=350;i++)
        for (j=0;j<i;j++)
        dp[i]=(dp[i]+dp[j]*dp[i-1-j])%mod;
    if (t==3)
    {
        sol_c=sol_c*dp[dfs(1)];
        cout<<sol_c<<'\n';
        return 0;
    }
    schimba(1);
    if (ls[0]!=0)
    afis(ls[0]);
    else    afis(1);
    return 0;
}
