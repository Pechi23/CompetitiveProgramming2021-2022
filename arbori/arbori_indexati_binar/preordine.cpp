/*
   preordine.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 24/01/2022 23:17:33 by Pechi
   Updated: 24/01/2022 23:17:36 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("inordine.in");
ofstream fout("inordine.out");

bitset<1001>vizitat;
int n;

struct nod{
  int info,st,dr;
}noduri[1001];

int det_radacina()
{
  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      return i;
}

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    noduri[i].info = x;
    noduri[i].st = y;
    noduri[i].dr = z;
    vizitat[y] = vizitat[z] = true;
  }
}

void afisare_preordine(int rad)
{
  if(rad)
  {
    fout<<noduri[rad].info<<' ';
    afisare_preordine(noduri[rad].st);
    afisare_preordine(noduri[rad].dr);
  }
}

void afisare_inordine(int rad)
{
  if(rad)
  {
    afisare_inordine(noduri[rad].st);
    fout<<noduri[rad].info<<' ';
    afisare_inordine(noduri[rad].dr);
  }
}

void afisare_postordine(int rad)
{
  if(rad)
  {
    afisare_postordine(noduri[rad].st);
    afisare_postordine(noduri[rad].dr);
    fout<<noduri[rad].info<<' ';
  }
}

int main()
{
  citire();
  int radacina = det_radacina();
  afisare_inordine(radacina);
  return 0;
}
