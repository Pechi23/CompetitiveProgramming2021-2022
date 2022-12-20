/*
   subarbore2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 18/02/2022 10:28:41 by Pechi
   Updated: 18/02/2022 10:41:10 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("subarbore2.in");
ofstream fout("subarbore2.out");

struct nod{
  int tata,val;
}noduri[101];

vector<vector<pair<int,int> > > adj;
bitset<101> vizitat;
int n,k;

void citire()
{
  int x;
  fin>>n>>k;
  adj.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    fin>>x;
    noduri[i].tata = x;
  }
  for(int i=1;i<=n;i++)
  {
    fin>>x;
    noduri[i].val = x;
  }
  for(int i=1;i<=n;i++)
    adj[noduri[i].tata].push_back({i,noduri[i].val});
}

void dfs_suma(int nodcurent,int valcurenta,int &suma)
{
  suma += valcurenta;
  vizitat[nodcurent] = true;
  for(auto pereche:adj[nodcurent])
    if(!vizitat[pereche.first])
      dfs_suma(pereche.first,pereche.second,suma);
}

int main()
{
  int sol_suma=0;
  citire();
  dfs_suma(k,noduri[k].val,sol_suma);
  fout<<sol_suma;
  return 0;
}
