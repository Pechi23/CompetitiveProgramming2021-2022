/*
   rerooting.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/02/2022 14:37:47 by Pechi
   Updated: 25/02/2022 14:56:15 by Pechi
*/
#include<bits/stdc++.h>;
using namespace std;
ifstream fin("rerooting.in");
int n;

vector<vector<int>> adj;
int dp[100001];//suma distantelor cu rad in i pana in celelalte
int sz[100001]; //nr de noduri din subarborele i
int suma[100001];

void citire()
{
  fin>>n;
  adj.resize(n+1);
  int a,b;
  while(fin>>a>>b)
  {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void dfs(int nod,int tata)
{
  sz[nod] = 1;
  dp[nod] = 0;
  for(auto vecin:adj[nod])
  {
    if(vecin!=tata)
    {
      dfs(vecin,nod);
      sz[nod] += sz[vecin];
      dp[nod] = dp[nod] + dp[vecin] + sz[vecin];
    }
  }
}

void dfs2(int nod,int tata)
{
  suma[nod] = dp[nod];
  for(auto vecin:adj[nod])
  {
    if(vecin!=tata)
      sz[nod] = sz[nod] - sz[vecin];
      dp[nod] = dp[nod] - dp[vecin] - sz[vecin];
      sz[vecin] = sz[vecin] + sz[nod];
      dp[vecin] = dp[vecin] + dp[nod] + sz[nod];
      dfs2(vecin,nod);
      sz[vecin] = sz[nod] - sz[nod];
      dp[vecin] = dp[vecin] - dp[nod] - sz[nod];
      sz[nod] = sz[nod] + sz[vecin];
      dp[nod] = dp[nod] + dp[vecin] + sz[vecin];
  }
}
void solve()
{
  dfs(1,0);
  dfs2(1,0);
  for(int i=1;i<=n;i++)
    cout<<suma[i]<<' ';
}
int main()
{
  citire();
  solve();
  return 0;
}
