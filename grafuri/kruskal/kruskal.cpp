/*
arbore de cost minim (Kruskal)
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

int n;
vector<vector<pair<int,int> > > adj;
set<pair<int,int>> sety;
vector<pair<int,int>> sol;


struct muchie{
  int from,to;
  int cost;
};

muchie muchii[400001];

void citire()
{
  int m;
  fin>>n>>m;
  adj.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
    muchii[i].from = x; //retinem pt fiecare muchie nodurile pe care le uneste si costul
    muchii[i].to = y;
    muchii[i].cost = z;
    sety.emplace(z,i); //costul muchiei, i pt localizarea muchiei in vectorul de muchii
  }
}

int kruskal()
{
  int cost_total = 0;
  int nr_muchii = 0;
  vector<int> comp(n+1); // componenta din care face parte, inital vor face parte toate nodurile din comp diferite
  iota(comp.begin(),comp.end(),0); //incepe de la 1 si creste cu unu la fiecare pas

  while(nr_muchii < n-1)
  {
    pair<int,int> extras = *(sety.begin()); //extragem muchia de cost minim
    sety.erase(sety.begin());

    int muchie_curenta = extras.second;
    int comp_a = comp[ muchii[muchie_curenta].from ];
    int comp_b = comp[ muchii[muchie_curenta].to ];

    if(comp_a != comp_b) //daca nu se afla in aceeasi componenta
    {
      nr_muchii++;
      cost_total += muchii[muchie_curenta].cost; //la cost i se adauga muchia minima
      sol.push_back({muchii[muchie_curenta].from,muchii[muchie_curenta].to}); //adaugam muchia in solutie

      //reuniunea celor doua componente
      for(int i=1;i<=n;i++)
        if(comp[i] == comp_b)
          comp[i] = comp_a;

    }
  }
  return cost_total;
}

int main()
{
  citire();

  int cost_total = kruskal();

  fout<<cost_total<<'\n';
  //fout<<sol.size()<<'\n'; //nr de muchii
  for(auto pereche:sol)
    fout<<pereche.first<<' '<<pereche.second<<'\n';
  return 0;
}
