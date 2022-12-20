//am reluat problema pt a intelege mai bine algoritmul eficient dijkstra
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
ifstream fin("parc.in");
ofstream fout("parc.out");

vector<vector<pair<int,int>>> adj;
vector<int> porti,sol;
set<pair<int,int>> sety;
int n,p;

void citiregraf(int &start)
{
  int x,y,z,m;
  fin>>n>>m>>start;
  adj.resize(n+1);
  while(m--){
    fin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
    adj[y].push_back(make_pair(x,z));
  }
  fin>>p;
  for(int i=1;i<=p;i++)
  {
    fin>>x;
    porti.push_back(x);
  }
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
      dist[i] = 0;

  return dist;
}

int main()
{
  int start,minim=INT_MAX,rez;
  citiregraf(start);
  vector<int> distante = drum_minim(start);

  for(int i=0;i<p;i++)
  {
    if(distante[porti[i]]==minim)
      sol.push_back(porti[i]);
    else
      if(distante[porti[i]]<minim){
        sol.clear();
        sol.push_back(porti[i]);
        minim = distante[porti[i]];
      }
  }
  fout<<*sol.begin();
  return 0;
}
