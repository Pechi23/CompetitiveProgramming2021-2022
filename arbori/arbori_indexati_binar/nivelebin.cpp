/*
   nivelebin.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 16:33:19 by Pechi
   Updated: 30/01/2022 22:21:31 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");
int n;
map<int,int> mapa; //pair<nivel,noduri_pe_nivelul_respectiv>
bitset<1001> vizitat;

struct nod{
  int st,dr;
};

nod noduri[1001];

void nivelare(int rad,int niv_rad)
{
  if(rad)
  {
    ++niv_rad;
    mapa[niv_rad]++; //avem inca un nod pe nivelul curent
    nivelare(noduri[rad].st,niv_rad);
    nivelare(noduri[rad].dr,niv_rad);
  }
}

void citire2()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    noduri[i].st = y;
    noduri[i].dr = z;
    vizitat[y] = vizitat[z] = 1;
  }
}

void afla_rad(int &rad)
{
  for(int i=1;i<=n;i++)
    if(!vizitat[i]){
      rad = i;
      return;
    }
}

int main()
{
  int radacina;
  citire2();
  afla_rad(radacina);
  nivelare(radacina,0);

  fout<<mapa.size()<<'\n';
  for(auto pereche:mapa)
  {
    fout<<pereche.second<<' ';
  }
  return 0;
}
