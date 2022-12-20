#include<bits/stdc++.h>
using namespace std;
ifstream fin("autostrada.in");
ofstream fout("autostrada.out");

vector<pair<int,int>> muchii;
set<pair<int,int>> muchii_critice;
vector<set<int>> adj;
vector<int> nivel, nivel_minim, tata, noduri_critice;
bitset<101> vizitat;
int n,m;

void citire()
{
  int x,y;
  fin>>n>>m;
  adj.resize(n+1);
  nivel.resize(n+1);
  nivel_minim.resize(n+1);
  tata.resize(n+1);

  for(int i=1;i<=m;i++)
  {
    fin>>x>>y;
    adj[x].emplace(y);
    adj[y].emplace(x);
    if(x<=y)
      muchii.push_back(make_pair(x,y));
    else
      muchii.push_back(make_pair(y,x));
  }
}


void dfs(int nodcurent)
{
  vizitat[nodcurent] = true;
  nivel[nodcurent] = nivel[tata[nodcurent]]+1;
  nivel_minim[nodcurent] = nivel[nodcurent];
  for(auto vecin:adj[nodcurent])
  {
    if(!vizitat[vecin])
    {
      tata[vecin] = nodcurent;
      dfs(vecin);
      nivel_minim[nodcurent] = min(nivel_minim[nodcurent],nivel_minim[vecin]);
      if(nivel_minim[vecin] > nivel[nodcurent])
        //cout<<nodcurent<<' '<<vecin<<'\n';
        muchii_critice.emplace(make_pair(nodcurent,vecin));
    } else {
        if(vecin != tata[nodcurent])
          nivel_minim[nodcurent] = min(nivel_minim[nodcurent],nivel[vecin]);
    }
  }
}

int main()
{
  citire();
  const unsigned int radacina = 1;
  dfs(radacina);
  //afisare
  fout<<muchii_critice.size()<<'\n';
  for(auto it = muchii_critice.begin(); it!=muchii_critice.end();it++)
    if((*it).first<=(*it).second)
      fout<<(*it).first<<' '<<(*it).second<<'\n';
    else
      fout<<(*it).second<<' '<<(*it).first<<'\n';

  return 0;
}
