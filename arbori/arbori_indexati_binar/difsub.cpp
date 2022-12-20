/*
   difsub.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 15:32:29 by Pechi
   Updated: 25/01/2022 16:28:02 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("difsub.in");
ofstream fout("difsub.out");

struct nod{
  int info,st,dr;
};

int n;
bitset<1001> vizitat;
vector<nod> noduri;

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
    vizitat[y] = vizitat[z] = true;
  }
}

int determinare_rad()
{
  for(int i=1;i<=n;i++)
    if(!vizitat[i])
      return i;
}

void afisare(int rad)
{
  if(rad)
  {
    afisare(noduri[rad].st);
    cout<<noduri[rad].info<<' ';
    afisare(noduri[rad].dr);
  }
}

void suma(int rad,int &sum)
{
  if(rad)
  {
    sum+=noduri[rad].info;
    suma(noduri[rad].st,sum);
    suma(noduri[rad].dr,sum);
  }
}

int main()
{
  citire();
  int radacina = determinare_rad();
  int suma_st = 0, suma_dr = 0;
  suma(noduri[radacina].st,suma_st);
  suma(noduri[radacina].dr,suma_dr);
  fout<<abs(suma_st-suma_dr);
  return 0;
}
