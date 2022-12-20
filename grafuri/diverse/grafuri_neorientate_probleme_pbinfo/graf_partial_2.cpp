/*
   graf_partial_2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 05/02/2022 09:37:01 by Pechi
   Updated: 05/02/2022 12:27:23 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

vector<set<int>> adj;
vector<int> size_init;
int n;

void citire()
{
  int x,y;
  fin>>n;
  adj.resize(n+1);
  size_init.resize(n+1);
  while(fin>>x>>y)
  {
    adj[x].emplace(y);
    adj[y].emplace(x);
    size_init[y]++;
    size_init[x]++;
  }
}

void afisare_lista()
{
  for(int i=1;i<=n;i++){
    for(auto el:adj[i])
      cout<<el<<' ';
    cout<<'\n';
  }
}

void afisare_mat_transformata_din_lista()
{
  int zerouri; //trebuie sa afisam 0 cand nu exista muchie spre acel nod
  for(int i=1;i<=n;i++){
    zerouri = 1;
    for(auto el:adj[i]){
      while(zerouri++<el)
        fout<<'0'<<' ';
      fout<<1<<' ';//afisam 1 in loc de element pentru ca elementul e nodul, noi afisam 1 la locul nodului respectiv
    }
    while(zerouri++<=n)
      fout<<'0'<<' ';

    fout<<'\n';
  }
}

void solve()
{
  int nr_muchii_eliminate=0;
  //gasim nodul cu cei mai multi vecini (nodmax) (grad maxim)
  int maxx = 0;
  for(int i=1;i<=n;i++)
  {
    if(adj[i].size()>maxx)
      maxx = adj[i].size();
  }
  //parcurgem lista de adiacenta si daca ajungem la vecinii nodului ce trebuie eliminat ii stergem pe toti
  //iar in rest pt fiecare nod ii stergem ca vecin nodul respectiv
  for(int i=1;i<=n;i++)
    if(adj[i].size()==maxx){
      while(!adj[i].empty()){
        if(size_init[*(adj[i].begin())]!=maxx)
          nr_muchii_eliminate++;
        adj[i].erase(adj[i].begin());
      }
    }
    else
      for(auto it= adj[i].begin();it!=adj[i].end();it++)
        if(size_init[*(it)]==maxx)
          adj[i].erase(it);

  //afisare_lista();
  fout<<nr_muchii_eliminate<<'\n';
  afisare_mat_transformata_din_lista();
}

int main()
{
  citire();
  solve();
  return 0;
}
