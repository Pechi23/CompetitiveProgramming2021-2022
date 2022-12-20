#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<pair<int,int>>> adj;
bitset<100001> grad_intern;
bitset<100001> vizitat;
stack<int> stiva;
const int inf = 0x3f3f3f3f;

void citire()
{
  cin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z=1;
    cin>>x>>y;
    adj[x].push_back(make_pair(y,z));
    grad_intern[y] = true;
  }
}
/*
void dfs(int nodcurent)
{
  vizitat[nodcurent] =true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
      dfs(vecin);
  stiva.push(nodcurent);
}
*/

vector<int> drum_minim(int start)
{
  vector<int> dist(n+1,-1);
  set<pair<int,int>> sety;
  dist[start]= 0;
  sety.emplace(0,start);

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto pereche: adj[nodcurent])
    {
      int vecin = pereche.first;
      int distanta = pereche.second;

      if(dist[vecin] < dist[nodcurent] + distanta)
      {
        if(dist[vecin] != 0)
          sety.erase({dist[vecin],vecin});

        dist[vecin] = dist[nodcurent] + distanta;
        sety.emplace(dist[vecin],vecin);
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
  int contor = n ,maxim = 0;
  for(int i=1;i<=n && contor != grad_intern.count(); i++)
  {
    if(!grad_intern[i]){
      contor--;
      vector<int> sol = drum_minim(i);
      for(auto el:sol)
        maxim = max(maxim,el);
    }
  }
  cout<<maxim;
  return 0;
}
