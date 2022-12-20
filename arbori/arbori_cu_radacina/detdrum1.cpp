/*
   detdrum1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 09:36:07 by Pechi
   Updated: 16/02/2022 09:44:48 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("detdrum1.in");
ofstream fout("detdrum1.out");

vector<vector<int>> adj_transpus;
int n,k,radacina;
bitset<101> vizitat;

void citire()
{
  fin>>n>>k;
  adj_transpus.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    if(!x)
      radacina = i;
    adj_transpus[i].emplace_back(x);
  }
}

void dfs_invers(int nodcurent)
{
  vizitat[nodcurent] =true;
  if(nodcurent==radacina)
    return;
  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfs_invers(vecin);
  fout<<nodcurent<<' ';
}


int main()
{
  citire();
  fout<<radacina<<' ';
  dfs_invers(k);
  return 0;
}
