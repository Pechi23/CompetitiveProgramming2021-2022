#include<bits/stdc++.h>
using namespace std;
ifstream fin("dijkstra2.in");
ofstream fout("dijkstra2.out");

int n,m,start,p,l,k;
vector<vector<pair<int,int> > > adj;
set<pair<int,int>> lungimi; //stocheaza distantele minime
vector<vector<int>> maxim;
const int inf = 0x3f3f3f3f;

void citire()
{
  fin>>n>>m>>k;
  adj.resize(n+1);
  maxim.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z)); //construim listele de adiacenta
    adj[y].push_back(make_pair(x,z));
  }
}

bool compara(int a,int b)
{
  return a>b;
}

vector<int> drum_minim(int start)//functia va returna vectorul distantelor minime
{
  vector<int> dist(n+1,inf); //initial distantele sunt infinite dist[i] = inf

  dist[start] = 0; //distanta nodului de start este 0
  lungimi.emplace(0,start); //adaugam nodul de start in set

  while(!lungimi.empty())//cat timp setul are elemente
  {
    pair<int,int> extras = *(lungimi.begin());//extragem primul element din set = nodul la distanta minima
    lungimi.erase(lungimi.begin());//il eliminam dupa extragere

    int nodcurent = extras.second;//retinem nodul aflat la distanta minima

    for(auto pereche : adj[nodcurent])//pentru fiecare vecin
    {
      int vecin = pereche.first;//retinem vecinul
      int distanta = pereche.second;//si distanta vecinului

      if(dist[vecin] > dist[nodcurent] + distanta)//daca gasim o distanta mai mica prin nodul curent decat prin a vecinului
      {
        if(dist[vecin] != inf){//daca avem deja perechea in set
          lungimi.erase({dist[vecin],vecin});//o eliminam
          auto it = find(maxim[vecin].begin(),maxim[vecin].end(),dist[vecin]);
          if(it!= maxim[vecin].end())
            maxim[vecin].erase(it);

        }
        dist[vecin] = dist[nodcurent] + distanta;//atualizam distanta minima
        if(dist[vecin]< inf)
          maxim[vecin].push_back(dist[vecin]);
        lungimi.emplace(dist[vecin],vecin);//adaugam perechea in set
      }
    }

  }
  for(auto &el:dist) //pentru fiecare nod
    if(el == inf) // daca nu exista drum
      el = -1;//avem distanta -1

  for(int i=1;i<=n;i++)
    sort(maxim[i].begin(),maxim[i].end(),compara);

  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    {
      dist[i] -= *(maxim[i].begin());
      maxim[i].erase(maxim[i].begin());
    }

  return dist;
}

int main()
{
  citire();
  vector<int> sol = drum_minim(1);
  sol.erase(sol.begin());
  for(auto el: sol)
    cout<<el<<' ';
  return 0;
}
