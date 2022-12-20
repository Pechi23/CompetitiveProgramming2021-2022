/*
   inaltime1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 19:00:30 by Pechi
   Updated: 25/01/2022 19:22:24 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("inaltime1.in");
ofstream fout("inaltime1.out");

struct nod{
  int info;
  nod *st,*dr;
};

void citire(nod* &rad)
{
  int x;
  fin>>x;
  if(x)
  {
    rad = new nod;
    rad->info = x;
    rad->st = NULL;
    rad->dr = NULL;
    citire(rad->st);
    citire(rad->dr);
  }
}

void afisare(nod* rad)
{
  if(rad)
  {
    afisare(rad->st);
    cout<<rad->info<<' ';
    afisare(rad->dr);
  }
}
int inaltime = 0;

void det_inaltime(nod* rad,int nivel)
{
  if(rad)
  {
    if(nivel>inaltime)
      inaltime=nivel;
    det_inaltime(rad->st,nivel+1);
    det_inaltime(rad->dr,nivel+1);
  }
}

int main()
{
  int a=1;
  nod* radacina = NULL;
  citire(radacina);
  det_inaltime(radacina,a);
  fout<<inaltime;
  return 0;
}
