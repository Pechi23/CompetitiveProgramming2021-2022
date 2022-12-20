/*
   royfloyd_dijkstra.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 11:49:01 by Pechi
   Updated: 16/02/2022 12:02:02 by Pechi
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

vector<vector<pii>> adj;
int n;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      int z;
      fin>>z;
      if(z)
        adj[i].push_back({j,z});
    }
}

vector<int> dijkstra(int start)
{
  set<pii> sety;
  const int inf = 0x3f3f3f3f;
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(0,start);

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

  for(auto &el:dist)
    if(el == inf)
      el = 0;

  return dist;
}

int main()
{
  citire();
  for(int i=1;i<=n;i++)
  {
    vector<int> sol = dijkstra(i); //fac dijkstra pentru fiecare nod
    for(int i=1;i<=n;i++)
      fout<<sol[i]<<' ';
    fout<<'\n';
  }
  return 0;
}
