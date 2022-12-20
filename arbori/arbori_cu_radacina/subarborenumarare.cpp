/*
   subarborenumarare.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 17/02/2022 09:19:57 by Pechi
   Updated: 17/02/2022 09:27:43 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");

int n,k;
vector<vector<int>> adj;
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
int sol;
void dfs(int nodcurent)
{
  sol++;
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
}


int main()
{
  citire();
  dfs(k);
  cout<<sol;
  return 0;
}
