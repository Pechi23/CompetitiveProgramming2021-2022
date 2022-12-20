/*
   cartierul.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 22:11:42 by Pechi
   Updated: 21/02/2022 22:48:38 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> culoare,dp;
int n;

void citire()
{
  cin>>n;
  adj.resize(n+1);
  dp.resize(n+1);
  culoare.resize(n+1);
  for(int i=1;i<=n;i++)
    cin>>culoare[i];
  for(int i=1;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
  }
}
void dfs(int nod,set<int> &culori)
{
  bool vecini = false;
  for(auto vecin:adj[nod])
  {
    vecini = true;
    dfs(vecin,culori);
    culori.emplace(culoare[nod]);
    dp[nod] = culori.size();
  }

}

int main()
{
  citire();
  set<int> culori;
  dfs(1,culori);
  for(int i=1;i<=n;i++)
    cout<<dp[i]<<' ';

  cout<<'\n';
  for(auto el:culori)
    cout<<el<<' ';
  return 0;
}
