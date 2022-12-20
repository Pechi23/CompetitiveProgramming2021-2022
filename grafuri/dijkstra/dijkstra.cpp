//cu set si functie care returneaza vectorul distanta
#include<bits/stdc++.h>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

vector<vector<pair<int,int>>> adj;
int n;
const int inf = INT_MAX/2;

vector<int> drum_minim(int start)
{
  set<pair<int,int>> sety;

  //vectorul distanta cu val infinite initial
  vector<int> dist(n+1,inf);

  //initializam cu nodul de start
  sety.emplace(make_pair(0,start));
  dist[start]=0;

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());//extragem primul element din set
    sety.erase(sety.begin());//scoatem elementul din set

    int nodcurent = extras.second;//nodul curent extras din set

    for(auto it=adj[nodcurent].begin();it!=adj[nodcurent].end();it++)//parcurgem nodurile in care se poate ajunge din nc
    {
      int distanta = (*it).second;
      int vecin = (*it).first;

      if(dist[vecin] > dist[nodcurent] + distanta)//daca gasim o distanta mai mica spre nc printr-un vecin de al lui
      {
        if(dist[vecin]!=inf)
          sety.erase(make_pair(dist[vecin],vecin));

        dist[vecin] = dist[nodcurent] + distanta;
        sety.emplace(make_pair(dist[vecin],vecin));
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(dist[i]==inf)
      dist[i] = -1;
    return dist;
}

int main()
{
  int x,y,z,m,start;
  fin>>n>>m>>start;
  adj.resize(n+1);
  for(int i=1;i<=m;i++){
    fin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
    adj[y].push_back(make_pair(x,z));
  }

  vector<int> rez = drum_minim(start);

  for(int i=1;i<=n;i++)
    fout<<rez[i]<<' ';
  return 0;
}
