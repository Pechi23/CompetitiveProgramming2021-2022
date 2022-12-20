#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> a;
bitset<100009> viz;
int dp1[100009];///dp1[i] = suma max a nodurilor din subarborele cu rad in i daca includem si nodul i
int dp2[100009];///dp2[i] =  -----||---- daca nu il includem
int cost[100009];

/**

8
1 4
1 5
1 2
2 3
5 6
5 7
5 8
9 4 1 7 10 1 6 5


*/

void dfs(int nodC)
{
    viz[nodC]=1;
    int s1=cost[nodC],s2=0;
    ///s1 = suma max daca includem nodC
    ///s2 = suma max daca nu includem nodC
    for(int i=0;i<a[nodC].size();i++){///parcurgem vecinii nodului
        int nodV=a[nodC][i];
        if(viz[nodV]==0){///daca nu l-am vizitat
            dfs(nodV);///continuam parcurgerea
            s1=s1+dp2[nodV];///adaugam la s1 suma subarborilor cu radacina in nodV, daca nu il includem pe nodV
            s2=s2+max(dp1[nodV],dp2[nodV]);///adaugam maximul dintre sumele subarborilor cu radacina in nodV
        }
    }
    dp1[nodC]=s1;
    dp2[nodC]=s2;
}

int main()
{
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n-1;i++){///citim muchiile
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){///citim costurile
        cin>>cost[i];
    }
    dfs(1);///incepem parcurgerea cu radacina 1
    cout<<max(dp1[1],dp2[1]);///afisam maximul sumelor din radacina
    return 0;
}
