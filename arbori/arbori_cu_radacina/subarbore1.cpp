/*
   subarbore1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 18/02/2022 10:20:21 by Pechi
   Updated: 18/02/2022 10:26:28 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("subarbore1.in");
ofstream fout("subarbore1.out");

vector<vector<int>> adj;
bitset<101> vizitat;
int n,k;

void citire()
{
  fin>>n>>k;
  adj.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    adj[x].push_back(i);
  }
}

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
}

void solve()
{
  for(int i=1;i<=n;i++)
    if(!adj[i].size() && vizitat[i])
      fout<<i<<' ';
}

int main()
{
  citire();
  dfs(k);
  solve();
  return 0;
}
