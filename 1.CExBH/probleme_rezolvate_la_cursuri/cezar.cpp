/*
   cezar.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/02/2022 15:18:14 by Pechi
   Updated: 25/02/2022 15:59:22 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("cezar1.in");
ofstream fout("cezar1.out");

vector<vector<int>> adj;
int dp[10001]; // dp[i] suma distantelor de la nodul i la nodurile subarborelui
int sz[10001]; //dp[i] nr de noduri din subarborele i
int n,k,radacina,dist_min=INT_MAX;

void citire()
{
  fin>>n>>k;
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
  dp[nod] = 0;
  sz[nod] = 1;
  for(auto vecin:adj[nod])
    if(vecin!=tata){
      dfs(vecin,nod);
      sz[nod] += sz[vecin];
      dp[nod] = dp[nod] + dp[vecin] + sz[vecin];
    }
}

void reroot(int a,int b)
{
  sz[a] = sz[a] - sz[b];
  dp[a] = dp[a] - dp[b] - sz[b];
  sz[b] = sz[b] + sz[a];
  dp[b] = dp[b] + dp[a] + sz[a];
}

void dfs2(int nod,int tata)
{
  if(dp[nod]<dist_min){
    dist_min = dp[nod];
    radacina = nod;
  }

  for(auto vecin:adj[nod])
    if(vecin!=tata)
    {
      reroot(nod,vecin);
      dfs2(vecin,nod);
      reroot(vecin,nod);
    }
}

void dfs3(int nod,int tata)
{
  sz[nod] = 1;
  for(auto vecin:adj[nod])
    if(vecin!=tata){
      dfs3(vecin,tata);
      sz[nod] += sz[vecin];
    }
}

bool cmp(int a,int b)
{
  return a>b;
}
int main()
{
  citire();
  dfs(1,0);
  dfs2(1,0);
  dfs3(radacina,0);
  sort(sz+1,sz+n+1,cmp);
  for(auto i=1;i<k;i++)
    dist_min-=sz[i];

  cout<<dist_min;
  return 0;
}
