#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

vector<vector<pair<int,int> > > adj;
int n,m,start;
const int inf = 0x3f3f3f3f;

void citire()
{
  cin>>n>>start>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    cin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
    adj[y].push_back(make_pair(x,z));
  }
}

vector<int> drum_minim(int start)
{
  vector<int> dist(n+1,inf);
  set<pair<int,int>> sety;
  dist[start] = 0;
  sety.emplace(make_pair(0,start));

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;
    for(auto it = adj[nodcurent].begin();it!=adj[nodcurent].end();it++)
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
    if(el == inf)
      el = -1;
  return dist;
}


int main()
{
  citire();
  vector<int>sol = drum_minim(start);
  for(auto i:sol)
    cout<<i<<' ';
}
