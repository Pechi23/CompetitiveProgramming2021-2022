/*
   kruskal_union.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 18:23:20 by Pechi
   Updated: 09/02/2022 19:00:13 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

struct muchie{
  int from,to,cost;
};

long long cost_arbore=0;
vector<muchie> muchii,sol;
vector<int> tata,dim;
int n,m;

void citire()
{
  fin>>n>>m;
  tata.resize(n+1);
  dim.resize(n+1);
  muchii.resize(m+1);
  for(int i=1;i<=m;i++)
  {
    int x,y,c;
    fin>>x>>y>>c;
    muchii[i].from = x;
    muchii[i].to = y;
    muchii[i].cost = c;
  }
}

bool cmp(muchie a,muchie b)
{
  return a.cost<b.cost;
}

int find_root(int a)
{
  while(a!=tata[a])
  {
    tata[a] = tata[tata[a]]; //comprimam calea
    a = tata[a];
  }
  return a;
}

void unire(int root_a,int root_b)
{
  if(dim[root_a]>dim[root_b])
  {
    dim[root_a]+=dim[root_b];
    tata[root_b] = root_a;
  }
  else
  {
    dim[root_b]+=dim[root_a];
    tata[root_a] = root_b;
  }
}

void kruskal()
{
  iota(tata.begin(),tata.end(),0);

  int contor = 0;
  sort(muchii.begin()+1,muchii.end(),cmp);
  for(int i=1;i<=m && contor<n;i++)
  {
    int root_a = find_root(muchii[i].from);
    int root_b = find_root(muchii[i].to);
    if(root_a!=root_b)
    {
      cost_arbore += muchii[i].cost;
      sol.push_back(muchii[i]);
      unire(root_a,root_b);
      contor++;
    }
  }
}

int main()
{
  citire();
  kruskal();

  fout<<cost_arbore<<'\n';
  fout<<sol.size()<<'\n';
  for(auto pereche:sol)
    fout<<pereche.from<<' '<<pereche.to<<'\n';

}
