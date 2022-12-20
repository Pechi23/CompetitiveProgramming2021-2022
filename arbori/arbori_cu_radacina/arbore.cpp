/*
   arbore.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 12:13:59 by Pechi
   Updated: 15/02/2022 12:27:06 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("arbore.in");
ofstream fout("arbore.out");

bitset<101> vizitat;
vector<vector<int>> adj;
vector<int> tata;
int n,radacina;

void citire()
{
  fin>>n>>radacina;
  adj.resize(n+1);
  tata.resize(n+1);
  int x,y;
  while(fin>>x>>y)
  {
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void nivelare_dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin]){
      tata[vecin] = nodcurent;
      nivelare_dfs(vecin);
    }
}

void afisare()
{
  for(int i=1;i<=n;i++)
    fout<<tata[i]<<' ';
}

int main()
{
  citire();
  nivelare_dfs(radacina);
  afisare();
  return 0;
}
