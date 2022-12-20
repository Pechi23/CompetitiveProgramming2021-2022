#include<bits/stdc++.h>

using namespace std;
ifstream fin("tollroads.in");
ofstream fout("tollroads.out");

vector<vector<pair<int,int>>> adj;
vector<int> porti;
int n,start,nr_porti;
const int inf = INT_MAX/2;

void solve_test();

void citire()
{
  int m,querys;
  fin>>n>>m>>querys;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
  while(querys--)
    solve_test();
}

int cate_noduri_respecta_costul_minim(int start,int cost)
{
  int contor = 0; //solutia
  set<pair<int,int>> sety; // distanta minima , nod pentru distanta minima
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(0,start);

  while(!sety.empty() && (*(sety.begin())).first <= cost)
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
  for(auto el:dist)
    if(el<=cost)
      contor++;
  return contor-1; //nodul starrt va fi numarat dar nu trebuie luat in considerare
}

void solve_test()
{
  int start, cost_maxim;
  fin>>start>>cost_maxim;
  int sol = cate_noduri_respecta_costul_minim(start,cost_maxim);
  fout<<sol<<'\n';
}


int main()
{
  citire();
  return 0;
}
