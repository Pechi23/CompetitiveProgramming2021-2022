/*
   arbrush.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 21:20:31 by Pechi
   Updated: 21/02/2022 21:57:13 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("arbrush.in");
ofstream fout("arbrush.out");

int n,m,radacina;
vector<vector<int>> adj,combinari;
vector<int> dp,teste;

void citire()
{
  fin>>n>>m>>radacina;
  adj.resize(n+1);
  dp.resize(n+1,1); //fiecare subarbore are un element initial, care e chiar nodul curent
  for(int i=1;i<n;i++)
  {
    int a,b;
    fin>>a>>b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=m;i++)
  {
    int x;
    fin>>x;
    teste.push_back(x);
  }
}

void dfs(int nod)
{
  for(auto vecin:adj[nod])
  {
    dfs(vecin);
    dp[nod] += dp[vecin];//fiecarui subarbore cu radacina in nod i se adauga nr de noduri fiilor sai + 1(il numaram si pe el)
  }
}

int main()
{
  citire();
  dfs(radacina);
  for(auto el:teste)
    fout<<dp[el]*(dp[el]-1)/2<<'\n';
  return 0;
}
