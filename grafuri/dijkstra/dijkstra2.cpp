//am reluat problema pt a intelege mai bine algoritmul eficient dijkstra
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

vector<vector<pair<int,int>>> adj;
set<pair<int,int>> sety;
int n;

void citiregraf(int &start,int x,int y,int z)
{
  fin>>n>>start;
  adj.resize(n+1);
  while(fin>>x>>y>>z)
    adj[x].push_back(make_pair(y,z));
}

vector<int> drum_minim(int start)
{
  vector<int> dist(n+1,inf);

  dist[start]=0;
  sety.emplace(make_pair(0,start));

  while(!sety.empty())
  {
    pair<int,int> extras = *sety.begin();
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto it= adj[nodcurent].begin();it!=adj[nodcurent].end();it++)
    {
      int vecin = (*it).first;
      int distanta = (*it).second;

      if(dist[vecin] > dist[nodcurent] + distanta)
      {
        if(dist[vecin]!=inf)
          sety.erase(make_pair(dist[vecin],vecin));
        dist[vecin] = dist[nodcurent] + distanta;
        sety.emplace(make_pair(dist[vecin],vecin));
      }
    }
  }

  for(int i=1;i<=n;i++)
    if(dist[i] == inf)
      dist[i] = -1;

  dist.erase(dist.begin());
  return dist;
}

int main()
{
  int start,x,y,z;
  citiregraf(start,x,y,z);

  vector<int> rez= drum_minim(start);

  for(auto i:rez)
    fout<<i<<' ';
  return 0;
}
