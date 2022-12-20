#include<bits/stdc++.h>
#define INF 1000000000

using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int n,start,x,y,z;

vector<vector<pair<int,int>>> adj;
vector<int> dist;
bitset<101> incoada;

struct compara{
  bool operator()(int a,int b)
  {
    return dist[a]>dist[b];
  }
};

priority_queue < int, vector< int >, compara> coada;

void dijkstra(int nodstart)
{
  for(int i=1;i<=n;i++)
    dist[i]=INF;
  dist[nodstart]=0;
  coada.push(nodstart);
  incoada[nodstart]=true;

  while(!coada.empty())
  {
    int nodcurent=coada.top();
    coada.pop();
    incoada[nodcurent]=false;
    for(int i=0;i<adj[nodcurent].size();i++)
    {
      int vecin= adj[nodcurent][i].first;
      int cost = adj[nodcurent][i].second;
      dist[vecin]=dist[nodcurent]+cost;
      if(!incoada[vecin])
      {
        coada.push(vecin);
        incoada[vecin]=true;
      }
    }
  }
}

int main()
{
  in>>n>>start;
  adj.resize(n+1);
  dist.resize(n+1);
  while(in>>x>>y>>z)
    adj[x].push_back(make_pair(y,z));
/*
  for(int i=1;i<=n;i++){
    for(int j=0;j<adj[i].size();j++)
      cout<<adj[i][j].first<<' '<<adj[i][j].second<<'\n';
      cout<<'\n';
    }
*/



  dijkstra(start);
  for(int i=1;i<=n;i++)
    if(dist[i]!=INF)
      out<<dist[i]<<' ';
    else
      out<<-1;
  return 0;
}
