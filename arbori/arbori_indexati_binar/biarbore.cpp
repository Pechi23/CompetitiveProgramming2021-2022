/*
   biarbore.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 26/01/2022 12:49:16 by Pechi
   Updated: 26/01/2022 13:02:48 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("biarbore1.in");
ofstream fout("biarbore1.out");

struct nod{
  int info;
  nod *st,*dr;
};

void citire(nod * &rad)
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

void afisare_fii_radacina(nod * rad)
{
  if(rad->st)
    fout<<rad->st->info<<' ';
  else
    fout<<0<<' ';
  if(rad->dr)
    fout<<rad->dr->info;
  else
    fout<<0;

}

int main()
{
  nod *radacina = NULL;
  citire(radacina);
  afisare_fii_radacina(radacina);
  return 0;
}
