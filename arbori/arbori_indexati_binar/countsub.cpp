/*
   countsub.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 19:36:53 by Pechi
   Updated: 25/01/2022 19:50:41 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("countsub.in");
ofstream fout("countsub.out");

struct nod{
  int info,st,dr;
};

int n;
vector<nod> noduri;

void numara_noduri(int rad,int &suma)
{
  if(rad)
  {
    suma++;
    numara_noduri(noduri[rad].st,suma);
    numara_noduri(noduri[rad].dr,suma);
  }
}

void solve()
{
  int rad,nr_noduri=0;
  fin>>rad;
  numara_noduri(rad,nr_noduri);
  fout<<nr_noduri<<'\n';
}

void citire()
{
  fin>>n;
  noduri.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    noduri[i].info = x;
    noduri[i].st = y;
    noduri[i].dr = z;
  }
  int tests;
  fin>>tests;
  while(tests--)
    solve();
}

int main()
{
  citire();
  return 0;
}
