/*
   subarbore.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 09:21:24 by Pechi
   Updated: 16/02/2022 09:26:25 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("subarbore.in");
ofstream fout("subarbore.out");

int n,k;
vector<vector<int>> adj;
set<int> sol;
bitset<101> vizitat;

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

void formare_subarbore(int nodcurent)
{
  vizitat[nodcurent] = true;
  sol.emplace(nodcurent);
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      formare_subarbore(vecin);
}

int main()
{
  citire();
  formare_subarbore(k);
  for(auto el:sol)
    fout<<el<<' ';
  return 0;
}
