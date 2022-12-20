#include<bits/stdc++.h>

using namespace std;
ifstream fin("drumdrept.in");
ofstream fout("drumdrept.out");

vector<vector<int>> adj;
bitset<100001> vizitat;
int n;

void citire()
{
  int m;
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void dfs(int nodcurent,int &lg)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin] && adj[vecin].size()<3)
    {
      lg++;
      dfs(vecin,lg);
    }
}

int solve()
{
  int lgmax = -1, lg;
  for(int i=1;i<=n;i++)
    if(adj[i].size()==1 && !vizitat[i])
    {
      lg = 1;
      dfs(i,lg);
      if(lg>lgmax)
        lgmax = lg;
    }
  return lgmax;
}

int main()
{
  citire();
  int sol = solve();
  fout<<sol;
  return 0;
}
