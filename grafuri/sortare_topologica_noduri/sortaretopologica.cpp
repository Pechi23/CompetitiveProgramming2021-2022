#include<bits/stdc++.h>

using namespace std;
ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

vector<set<int>> adj;
bitset<50001> vizitat;
stack <int> stiva;
int n,m;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].emplace(y);
  }
}

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  stiva.push(nodcurent);
}
void afisare()
{
  while(!stiva.empty())
  {
    fout<<stiva.top()<<' ';
    stiva.pop();
  }
}


int main()
{
  citire();
  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      dfs(i);
  afisare();
  return 0;
}
