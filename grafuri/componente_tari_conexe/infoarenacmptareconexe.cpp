#include<bits/stdc++.h>

using namespace std;
ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector<vector<int>> sol; //componentele
vector<vector<int> > adj,adj_trans;
stack<int> stiva;
bitset<100001> vizitat;
int n;

void citire()
{
  int m;
  fin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
  }
}

void dfs(int nodcurent)//parcurgem graful
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  stiva.push(nodcurent);
}

void dfsGT(int nodcurent,int componenta) //parcurgem graful transpus
{
  sol[componenta].push_back(nodcurent);
  vizitat[nodcurent] = true;
  for(auto vecin:adj_trans[nodcurent])
    if(!vizitat[vecin])
      dfsGT(vecin,componenta);
}

void comp_tari_conexe()
{
  int nr_componente=-1;

  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      dfs(i);
  vizitat.reset(); // vizitat se reseteaza pt a parcurge graful transpus

  while(!stiva.empty())
  {
    int element = stiva.top();
    stiva.pop();

    if(!vizitat[element])
    {
      nr_componente++;
      sol.resize(nr_componente+1);
      dfsGT(element,nr_componente);
    }
  }

}

int main()
{
  citire();

  comp_tari_conexe();

  //afisare
  fout<<sol.size()<<'\n';
  for(int i = 0;i< sol.size(); i++){
    for(auto element: sol[i])
      fout<<element<<' ';
    fout<<'\n';
  }
  return 0;
}
