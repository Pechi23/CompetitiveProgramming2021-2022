#include<bits/stdc++.h>

using namespace std;
ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");

vector<vector<int>> sol;
vector<vector<pair<int,int>>> adj;
set<pair<int,int>> sety;
int n,m,x,y,z;

const int inf = 0x3f3f3f3f;

vector<int> drum_minim(int start)
{
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(make_pair(0,start));

  while(!sety.empty())
  {
    pair<int,int> extras = *sety.begin();
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto it = adj[nodcurent].begin(); it!= adj[nodcurent].end(); it++)
    {
      int vecin = (*it).first;
      int distanta = (*it).second;

      if(dist[vecin] > dist[nodcurent] + distanta)
      {
        if(dist[vecin] != inf)
          sety.erase(make_pair(dist[vecin],vecin));

        dist[vecin] = dist[nodcurent] + distanta;
        sety.emplace(make_pair(dist[vecin],vecin));
      }
    }
  }

  for(auto &el:dist)
    if(el==inf)
      el = -1;

  return dist;
}

int main()
{
  vector<int> rez;
  fin>>n>>m;
  adj.resize(n+1);
  sol.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    fin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
  }

  for(int i=1;i<=n;i++)
  {
    rez = drum_minim(i);
    for(auto it = rez.begin()+1;it!=rez.end();it++)
      cout<<*it<<' ';
    cout<<'\n';
  }
  return 0;
}
