/*
   knivel.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 09:10:31 by Pechi
   Updated: 16/02/2022 09:17:58 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("knivel.in");
ofstream fout("knivel.out");

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

set<int> sol;

void nivelare(int nodcurent,int nivelcurent)
{
  vizitat[nodcurent] = true;

  if(nivelcurent==k)
    sol.emplace(nodcurent);

  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      nivelare(vecin,nivelcurent+1);
}

void afisare()
{
  for(auto el:sol)
    fout<<el<<' ';
}

int main()
{
  citire();
  nivelare(0,0);
  afisare();
  return 0;
}
