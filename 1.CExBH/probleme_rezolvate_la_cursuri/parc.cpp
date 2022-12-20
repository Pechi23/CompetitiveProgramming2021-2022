#include<bits/stdc++.h>

using namespace std;
ifstream fin("parc.in");
ofstream fout("parc.out");

vector<vector<pair<int,int>>> adj;
vector<int> porti;
int n,m,start,nr_porti;
const int inf = INT_MAX/2;

void citire()
{
  fin>>n>>m>>start;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
  fin>>nr_porti;
  for(int i=0;i<nr_porti;i++)
  {
    int x;
    fin>>x;
    porti.push_back(x);
  }
}

vector<int> drum_minim(int start)
{
  set<pair<int,int>> sety; // distanta minima , nod pentru distanta minima
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(0,start);

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto pereche: adj[nodcurent])
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin] > dist[nodcurent] + cost)
      {
        if(dist[vecin] != inf)
          sety.erase({dist[vecin],vecin});

        dist[vecin] = dist[nodcurent] + cost;
        sety.emplace(dist[vecin],vecin);
      }
    }
  }
  return dist;
}


int main()
{
  int minim = INT_MAX,sol;
  citire();
  vector<int> drum = drum_minim(start);
  for(int i=0;i<porti.size();i++)
  {
    if(drum[porti[i]] < minim)
    {
      minim = drum[porti[i]];
      sol = porti[i];
    }
    else
      if(drum[porti[i]] == minim)
        if(porti[i] < sol)
          sol = porti[i];
  }
  fout<<sol;
  return 0;
}
