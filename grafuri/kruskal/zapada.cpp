/*
   zapada.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 19:15:20 by Pechi
   Updated: 09/02/2022 19:42:31 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("zapada.in");
ofstream fout("zapada.out");

struct muchie{
  int from,to,cost;
};

long long cost_arbore=0;
vector<muchie> muchii,sol;
vector<int> tata,dim,obligatorii;
int n,m,k;

void citire()
{
  fin>>n>>m;
  tata.resize(n+1);
  dim.resize(n+1);
  muchii.resize(m+1);
  for(int i=0;i<m;i++)
  {
    int x,y,c;
    fin>>x>>y>>c;
    muchii[i].from = x;
    muchii[i].to = y;
    muchii[i].cost = c;
  }
  fin>>k;
  for(int i=1;i<=k;i++)
  {
    int x;
    fin>>x;
    obligatorii.push_back(x-1);
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

void prelucrare_obligatorii()
{
  iota(tata.begin(),tata.end(),0);
  for(auto el:obligatorii)
  {
    cost_arbore += muchii[el].cost;
    unire(find_root(muchii[el].from),find_root(muchii[el].to));
  }
}

void kruskal()
{
  sort(muchii.begin(),muchii.end(),cmp);

  for(int i=0;i<m;i++)
  {
    int root_a = find_root(muchii[i].from);
    int root_b = find_root(muchii[i].to);
    if(root_a!=root_b)
    {
      cost_arbore += muchii[i].cost;
      unire(root_a,root_b);
    }
  }
}

int main()
{
  citire();
  prelucrare_obligatorii();
  kruskal();

  fout<<cost_arbore;
}
