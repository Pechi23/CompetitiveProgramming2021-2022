/*
   graph.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 09:19:53 by Pechi
   Updated: 09/02/2022 10:20:54 by Pechi
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
ifstream fin("graph.in");
ofstream fout("graph.out");

const unsigned int inf = 0x3f3f3f3f;
int n,m;
vector<vector<pii>> adj;
int drumuri[1501][1501];
bitset<1501> vizitat;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
  }
}

vector<int> dijkstra(int start)
{
  vector<int> dist(n+1,inf);
  set<pii> sety;

  sety.emplace(0,start);
  dist[start] = 0;

  while(!sety.empty())
  {
    pii extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto pereche:adj[nodcurent])
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin] > dist[nodcurent] + cost)
      {
        if(dist[vecin]!=inf)
          sety.erase({dist[vecin],vecin});

        dist[vecin] = dist[nodcurent] + cost;
        sety.emplace(dist[vecin],vecin);
      }
    }
  }

  return dist;
}

void dijkstra_2(int start)
{
  set<pii> setyy;
  vizitat[start]= true;
  setyy.emplace(0,start);
  for(int i=1;i<=n;i++)
    drumuri[start][i] = inf;
  drumuri[start][start] = 0;

  while(!setyy.empty())
  {
    pii extras = *(setyy.begin());
    setyy.erase(setyy.begin());

    int distanta = extras.first;
    int nod = extras.second;

    cout<<nod<<' ';

    for(auto pereche:adj[nod])
    {
      int vecin = pereche.first;
      int cost = pereche.second;
      drumuri[nod][vecin] = distanta + cost;
      setyy.emplace(distanta,vecin);
      vizitat[vecin] = true;
    }

  }
  cout<<'\n';

}

void solve()
{
  for(int i=1;i<=n;i++)
    if(!vizitat[i]){
      dijkstra_2(i);
      break;
    }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      if(drumuri[i][j]==inf)
        cout<<'x'<<' ';
      else
        cout<<drumuri[i][j]<<' ';
    cout<<'\n';
  }
}

int main()
{
  citire();
  solve();
  return 0;
}
