#include<bits/stdc++.h>

using namespace std;
ifstream fin("nuclee.in");
ofstream fout("nuclee.out");

int n,contor=0;
vector<vector<int>> adj,adj_transpus;
stack<int> stiva;
bitset<201> vizitat;

void citire()
{
  int nr_vecini,vecin;
  fin>>n;
  adj.resize(n+1);
  adj_transpus.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    fin>>nr_vecini;
    while(nr_vecini--)
    {
      fin>>vecin;
      adj[i].push_back(vecin);
      adj_transpus[vecin].push_back(i);
    }
  }
}

void afisare_lista_adiacenta()
{
  for(int i=1;i<=n;i++){
    for(auto vecin:adj[i])
      cout<<vecin<<' ';
    cout<<'\n';
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

void dfsGT(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfsGT(vecin);
}

int nr_comp_tari_conexe()
{
  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      dfs(i);
  vizitat.reset();
  while(!stiva.empty())
  {
    int element = stiva.top();
    stiva.pop();

    if(!vizitat[element])
    {
      contor++;
      dfsGT(element);
    }
  }
  return contor;
}

int main()
{
  int solutie;
  citire();

  solutie = nr_comp_tari_conexe();
  fout<<solutie;
  return 0;
}
