#include<bits/stdc++.h>
using namespace std;
ifstream fin("festivaluri.in");
ofstream fout("festivaluri.out");

const unsigned int inf = INT_MAX/2;
int n,putere,start,nrfest;
vector<int> festival;
vector< vector< pair<int,int> > > adj;
set<pair<int,int>> sety;
set<int> consum_minim;//de energie pana la un festival

void citire()
{
  int x,y,z,m;
  fin>>n>>m>>putere>>start>>nrfest;
  adj.resize(n+1);
  festival.resize(nrfest+1);

  for(int i=1;i<=m;i++)
  {
    fin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
    adj[y].push_back(make_pair(x,z));
  }
  for(int i=1;i<=nrfest;i++)
    fin>>festival[i];
}

vector<int> drum_minim(int start)
{
  vector<int> dist(n+1,inf);

  dist[start]=0;
  sety.emplace(make_pair(0,start));

  while(!sety.empty())
  {
    pair<int,int> extras = *sety.begin();//extragem cea mai mica distanta
    sety.erase(sety.begin());//stergem cea mai mica distanta

    int nodcurent= extras.second;
    for(auto it=adj[nodcurent].begin();it!=adj[nodcurent].end();it++)
    {
      int vecin = (*it).first;
      int distanta = (*it).second;

      if(dist[vecin]>dist[nodcurent] + distanta)
      {
        if(dist[vecin]!=inf)
          sety.erase(make_pair(dist[vecin],vecin));
        dist[vecin] = dist[nodcurent]+distanta;
        sety.emplace(make_pair(dist[vecin],vecin));
      }
    }

  }

  for(auto &i:dist)
    if(i==inf)
      i=-1;
  //dist.erase(dist.begin());
  return dist;
}

void rezolvare()
{
  int contor = 0;
  vector<int> distante = drum_minim(start);
  for(int i=1;i<=nrfest;i++)
    if(distante[festival[i]]!=-1)
      consum_minim.emplace(distante[festival[i]]);
  for(auto element:consum_minim)
  {
    if(putere-element>0){
      putere-=element;
      contor++;
    }
    else
      break;
  }
  fout<<contor;
}


int main()
{
  citire();
  rezolvare();
  return 0;
}
