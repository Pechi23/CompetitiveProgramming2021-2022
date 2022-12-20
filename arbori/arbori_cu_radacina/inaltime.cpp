/*
   inaltime.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 19:30:01 by Pechi
   Updated: 15/02/2022 19:37:51 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("inaltime.in");
ofstream fout("inaltime.out");

vector<vector<int>> adj;
int n,inaltime;
bitset<101> vizitat;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    adj[x].push_back(i);
  }
}

void dfs(int nodcurent,int inaltime_curenta)
{
  vizitat[nodcurent] = true;

  if(inaltime_curenta>inaltime)
    inaltime = inaltime_curenta;

  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin,inaltime_curenta+1);
}


int main()
{
  citire();
  dfs(0,0);
  fout<<inaltime;
  return 0;
}
