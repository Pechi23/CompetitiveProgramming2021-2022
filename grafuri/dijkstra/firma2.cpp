#include <bits/stdc++.h>
using namespace std;
ifstream fin("firma.in");
ofstream fout("firma.out");

vector<vector<pair<int,int> > > adj;
const unsigned int inf = 0x3f3f3f3f;
int n;

void citire()
{
  int m;
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
}

vector<int> drum_minim(int start)
{
  set<pair<int,int>> sety;
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(0,start);

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto pereche:adj[nodcurent])
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin] > dist[nodcurent] + cost)
      {
        if(dist[vecin]!= inf)
          sety.erase({dist[vecin],vecin});

        dist[vecin] = dist[nodcurent] + cost;
        sety.emplace(dist[vecin],vecin);
      }
    }
  }

  for(auto &el: dist)
    if(el == inf)
      el=0;

    return dist;
}

int solve()
{
  int suma_minima = INT_MAX, sol;
  for(int i=1;i<=n;i++)
  {
    int sum_curenta = 0;
    vector<int> drum = drum_minim(i);
    for(auto element:drum)
      sum_curenta += element;
    if(sum_curenta < suma_minima)
    {
      suma_minima = sum_curenta;
      sol = i;
    }
    /*
    else //le parcurgem in ordine lexicografica deci nu trebuie sa consideram acest caz
      if((sum_curenta == suma_minima) && i<sol)
      {
        sol = i;
      }
    */
  }
  return sol;
}

int main()
{
  citire();
  int sol = solve();
  fout<<sol;
  return 0;
}
