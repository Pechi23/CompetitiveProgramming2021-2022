#include<bits/stdc++.h>

using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");

int n,m;
const unsigned int inf = 0x3f3f3f3f;
vector<set<pair<int,int>>> adj;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].emplace(y,z);
    adj[y].emplace(x,z);
  }
}

pair<int,vector<int>> tata_Prim(int start)
{
  set<pair<int,int>> sety;
  vector<int> dist(n+1,inf);
  vector<int> tata(n+1);
  bitset<1001> vizitat;

  tata[start] = 0;
  dist[start] = 0;
  sety.emplace(0,start);
  vizitat[start] = true;

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;
    int distanta_curenta = extras.first;

    for(auto pereche: adj[nodcurent])
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(!vizitat[vecin])
      {
        vizitat[vecin] = true;
        dist[vecin] = cost;
        tata[vecin] = nodcurent;
        sety.emplace(dist[vecin],vecin);
      }
      else if(dist[vecin] > cost && tata[nodcurent]!=vecin)
      {
        dist[vecin] = cost;
        tata[vecin] = nodcurent;
        sety.emplace(dist[vecin],vecin);
      }
    }
  }
  for(auto &el:dist)
    if(el == inf)
      el = 0;

  int dist_max = 0;
  for(auto el:dist)
    dist_max+=el;

  return {dist_max,tata};
}


int main()
{
  int start = 1;
  citire();
  pair<int,vector<int>> tati = tata_Prim(start);

  //afisare
  cout<<tati.first<<'\n';
  for(int i=1;i<=n;i++)
    cout<<tati.second[i]<<' ';
  return 0;
}
