#include<bits/stdc++.h>
using namespace std;
ifstream fin("retea1.in");
ofstream fout("retea1.out");

int n,contor=0;
vector<vector<int>> adj,adj_transpus;
bitset<301> vizitat;
stack<int> stiva;
vector<int> id,contor_id;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  adj_transpus.resize(n+1);
  id.resize(n+1);
  contor_id.resize(n+1);
  for(int x=1;x<=n;x++)
  {
    for(int y=1;y<=n;y++)
    {
      int cifra;
      fin>>cifra;
      if(cifra){
        adj[x].push_back(y);
        adj_transpus[y].push_back(x);
      }
    }
  }
}

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin: adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  stiva.push(nodcurent);
}

void dfsGT(int nodcurent)
{
  contor_id[contor]++;
  id[nodcurent] = contor;
  vizitat[nodcurent] = true;
  for(auto vecin:adj_transpus[nodcurent])
    if(!vizitat[vecin])
      dfsGT(vecin);
}

vector<int> componente_conexe_cu_revenire_in_nodul_initial()
{
  vector<int> componente;
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
  contor_id.resize(contor+1);
  for(int i=1;i<=contor;i++)
  {
    if(contor_id[i] > 1){
      for(int j=1;j<=n;j++)
        if(id[j] == i)
          componente.push_back(j);
    }else{
      if(contor_id[i])
      {
        for(int j=1;j<=n;j++)
          if(id[j] == i && adj[j][0] == j)
            componente.push_back(j);

      }
    }

  }
  sort(componente.begin(),componente.end());
  return componente;
}

int main()
{
  citire();
  vector<int> sol = componente_conexe_cu_revenire_in_nodul_initial();
  //afisare
  fout<<'{';
  for(int i=0;i<sol.size();i++)
  {
    fout<<sol[i];
    if(i!= sol.size()-1)
      fout<<',';
  }
  fout<<'}';

}
