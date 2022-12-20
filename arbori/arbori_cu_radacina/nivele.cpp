/*
   nivele.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 18:49:11 by Pechi
   Updated: 15/02/2022 19:01:59 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("nivele.in");
ofstream fout("nivele.out");

vector<vector<int>> adj;
vector<int> nivel;
int n;
bitset<101> vizitat;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  nivel.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    adj[x].push_back(i);
  }
}

void nivelare_dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
    {
      nivel[vecin] = nivel[nodcurent] + 1;
      nivelare_dfs(vecin);
    }
}

void query()
{
  int x;
  fin>>x;
  fout<<nivel[x]<<'\n';
}

int main()
{
  citire();
  nivelare_dfs(0);

  int queries;
  fin>>queries;
  for(int i=1;i<=queries;i++)
    query();
  return 0;
}
