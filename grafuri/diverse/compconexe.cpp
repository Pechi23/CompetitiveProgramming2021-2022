#include<bits/stdc++.h>
using namespace std;
ifstream fin("dfs.in");
ofstream fout("dfs.out");

bitset<100001> vizitat;
vector<vector<int>> adj;
int n,m;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);//de la cate probleme cu grafuri orientate am rezolvat in ultimul timp doar la ele ma gandesc :)
  }
}

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
}
int main()
{
  int sol = 0;
  citire();

  for(int i=1;i<=n;i++)
    if(!vizitat[i])
    {
      sol++;
      dfs(i);
    }

  fout<<sol;
  return 0;
}
