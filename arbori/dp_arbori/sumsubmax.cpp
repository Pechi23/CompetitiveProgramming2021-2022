/*
   sumsubmax.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 18:57:21 by Pechi
   Updated: 21/02/2022 19:22:26 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("sumsubmax.in");
ofstream fout("sumsubmax.out");

int n;
vector<int> tata,valoare,dp,sol;
vector<vector<int> > adj;
int sum_max=INT_MIN;


void citire()
{
  fin>>n;
  adj.resize(n+1);
  tata.resize(n+1);
  valoare.resize(n+1);
  dp.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    tata[i] = x;
    adj[x].push_back(i);
  }
  for(int i=1;i<=n;i++){
    fin>>valoare[i];
    dp[i] = valoare[i];
  }
}

void dfs(int nod)
{
  bool vecini = false;
  for(auto vecin:adj[nod])
  {
    vecini = true;
    dfs(vecin);
    dp[nod] += dp[vecin];
  }
}

void determinare_sol()
{
  for(int i=1;i<=n;i++)
  {
    if(dp[i]>sum_max)
    {
      sum_max = dp[i];
      sol.clear();
      sol.push_back(i);
    }
    else
      if(dp[i]==sum_max)
        sol.push_back(i);
  }
}

int main()
{
  citire();
  dfs(0);
  determinare_sol();
  for(auto el:sol)
    fout<<el<<' ';
  return 0;
}
