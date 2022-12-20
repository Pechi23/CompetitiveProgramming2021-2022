/*
   subarbori.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 17/02/2022 09:28:18 by Pechi
   Updated: 18/02/2022 10:18:48 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("subarbori.in");
ofstream fout("subarbori.out");

int n;
vector<vector<int> > adj;
bitset<101> vizitat;
vector<int> subnoduri;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  subnoduri.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    adj[x].push_back(i);
  }
}

void dfs(int nodcurent,int &contor)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin,++contor);
}

void cate_subnoduri_are_fiecare_nod()
{
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    vizitat.reset();
    dfs(i,cnt);
    subnoduri[i] = cnt;
  }
}

int sol = 0;
void gasire_nr_perechi()
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
      if(i!=j && adj[i].size() && adj[j].size() && subnoduri[i] == subnoduri[j])
        sol++;
}

int main()
{
  citire();
  cate_subnoduri_are_fiecare_nod();
  gasire_nr_perechi();
  fout<<sol;
  return 0;
}
