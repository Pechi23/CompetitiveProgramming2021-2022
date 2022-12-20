#include<bits/stdc++.h>

using namespace std;
ifstream fin("drumdrept.in");
ofstream fout("drumdrept.out");

vector<vector<int>> adj;
bitset<100001> vizitat;
bitset<100001> noduri_critice;
vector<int> tata,nmin,niv;
set<pair<int,int>> muchii_critice;
int radacina = 1,nrfii =0;
int n;

/*
struct muchie{
  bool critica;
  int from,to;
};

muchie muchii[120001];
*/
void citire()
{
  int m;
  fin>>n>>m;
  adj.resize(n+1);
  tata.resize(n+1);
  nmin.resize(n+1);
  niv.resize(n+1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void afisare_lista()
{
  for(int i=1;i<=n;i++){
    for(auto el: adj[i])
      cout<<el<<' ';
    cout<<'\n';
  }
}

dfs_critic(int nodcurent)
{
  vizitat[nodcurent] =true;
  niv[nodcurent] = niv[tata[nodcurent]] + 1;
  nmin[nodcurent] = niv[nodcurent];

  for(auto vecin: adj[nodcurent])
  {
    if(!vizitat[vecin])
    {
      tata[vecin] = nodcurent;
      if(tata[vecin]==radacina)
        nrfii++;

      dfs_critic(vecin);
      nmin[nodcurent] = min(nmin[nodcurent],nmin[vecin]);
      if(nmin[vecin] > niv[nodcurent] && nodcurent!= radacina)
        noduri_critice[nodcurent] = true;
      if(nmin[vecin] > niv[nodcurent])
        muchii_critice.emplace(nodcurent,vecin);
    }
    else
    {
      if(tata[nodcurent]!=vecin)
        nmin[nodcurent] = min(nmin[nodcurent],niv[vecin]);
    }
  }
}
void critice()
{
  dfs_critic(radacina);
  if(nrfii>1)
    noduri_critice[radacina] = true;
}

void dfs(int nodcurent,int &lg)
{
  cout<<nodcurent<<' ';
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
    {
      lg++;
      dfs(vecin,lg);
    }
}

int solve()
{
  int lgmax = -1, lg;
  critice();
  vizitat.reset();
  for(int i=1;i<=n;i++)
    if(adj[i].size()==1 && !vizitat[i])
    {
      lg = 0;
      dfs(i,lg);
      cout<<'\n';
      if(lg>lgmax)
        lgmax = lg;
    }
  return lgmax;
}

int main()
{
  citire();
  int sol = solve();
  cout<<sol;
  /*
  for(auto el:noduri_critice)
    cout<<el<<' ';
  */
  //afisare_lista();
  return 0;
}
