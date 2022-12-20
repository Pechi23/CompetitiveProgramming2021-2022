///centrul clepsidrei va fi un nod critic
///pentru fiecare nod critic determinam numarul de fii care nu revin deasupra lui
///sol va fi 2^(nr_fii + 1) - 2

#include <bits/stdc++.h>
#define MOD 666013

using namespace std;
ifstream in("clepsidra.in");
ofstream out("clepsidra.out");

vector<int> a[200009];
bitset<200009> viz;
int r,n,m;
int niv[200009],nmin[200009];
int nrfii[200009];///nrfii[i]=numarul fiilor care nu revin cu o muchie de intoarcere deasupra nodului critic i
int tati[200009];

void dfs(int nc)
{
    viz[nc]=1;
    niv[nc]=niv[tati[nc]]+1;
    nmin[nc]=niv[nc];
    for(int i=0;i<a[nc].size();i++){
        int nv=a[nc][i];
        if(viz[nv]==0){
            tati[nv]=nc;
            dfs(nv);
            nmin[nc]=min(nmin[nc],nmin[nv]);
            if(nc!=r && nmin[nv]>=niv[nc]){
                nrfii[nc]++;///numaram numarul de fii pentru care este nod critic
            }
        }
        else{
            if(tati[nc]!=nv){
                nmin[nc]=min(nmin[nc],niv[nv]);
            }
        }
    }
}

int power(long long x,int y)
{
    long long rez=1;
    while(y>0){
        if(y%2==1)
            rez=rez*x%MOD;
        x=x*x%MOD;
        y=y/2;
    }
    return rez%MOD;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);///formam lista de adiacenta
        a[y].push_back(x);
    }
    r=1;
    dfs(r);
    for(int i=1;i<=n;i++){///numaram fii radacinii
        if(tati[i]==r)
            nrfii[r]++;
    }
    ///for(int i=1;i<=n;i++)
        ///cout<<nrfii[i]<<" ";
    if(nrfii[r]>1){///daca radacina are mai mult de 1 fiu => radacina = nod critic
        cout<<(power(2LL,nrfii[r])+MOD-2)%MOD<<"\n";///nrfii[r] submultimi => 2^nrfii[r]-2 moduri
    }
    else
        cout<<0<<"\n";
    for(int i=2;i<=n;i++){///pentru fiecare nod
        if(nrfii[i]==0)///daca nu e nod critic => 0 moduri
            cout<<0<<"\n";
        else///daca e nod critic
            cout<<(power(2LL,nrfii[i]+1)+MOD-2)%MOD<<"\n";///nrfii[i]+1 submultimi => 2^(nrfii[i]+1)-2 moduri
    }
    return 0;
}
