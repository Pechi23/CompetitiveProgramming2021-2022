/*
   rf.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 09:19:53 by Pechi
   Updated: 09/02/2022 09:33:44 by Pechi
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const unsigned int inf = 0x3f3f3f3f;
int n,m;
vector<vector<pii>> adj;

void citire()
{
  cin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    cin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
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

  for(auto &el:dist)
    if(el==inf)
      el = -1;

  return dist;
}

void solve()
{
  int sol = 0;
  for(int i=1;i<=n;i++)
  {
    vector<int> drum = dijkstra(i);
    for(auto pereche:adj[i])
    {
      if(pereche.second == drum[pereche.first])
        sol++;
    }
  }
  cout<<sol/2;
}

int main()
{
  citire();
  solve();
  return 0;
}
