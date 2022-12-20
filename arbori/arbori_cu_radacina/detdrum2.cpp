/*
   detdrum2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 19:17:15 by Pechi
   Updated: 16/02/2022 19:45:10 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");

vector<vector<int>> adj,adj_transpus;
vector<int> tata;
bitset<101> vizitat;
int n,a,b;

void citire()
{
  fin>>n>>a>>b;
  adj.resize(n+1);
  adj_transpus.resize(n+1);
  tata.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    tata[i] = x;
    adj[x].push_back(i);
    adj_transpus[i].push_back(x);
  }
}
int rad_comuna;

void dfs_gt(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfs_gt(vecin);
    else
    {
      rad_comuna = vecin;
      return;
    }
}

vector<int> sol;

void dfs_gt_retine_drumul(int nodcurent)
{
  vizitat[nodcurent] = true;

  if(rad_comuna==nodcurent)
    return;

  sol.push_back(nodcurent);

  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfs_gt_retine_drumul(vecin);
}

void gasire_radacina_comuna()
{
  dfs_gt(a);
  dfs_gt(b);
  vizitat.reset();
  dfs_gt_retine_drumul(a);
}

void retine_drumul_de_la_rad_la_b(int nod)
{
  if(nod!=rad_comuna)
    retine_drumul_de_la_rad_la_b(tata[nod]);
  fout<<nod<<' ';
}

int main()
{
  citire();
  gasire_radacina_comuna();
  for(auto el:sol)
    fout<<el<<' ';
  retine_drumul_de_la_rad_la_b(b);
  return 0;
}
