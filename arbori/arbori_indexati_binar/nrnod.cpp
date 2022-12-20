/*
   nrnod.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 12:30:49 by Pechi
   Updated: 25/01/2022 13:23:41 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("nrnod.in");
ofstream fout("nrnod.out");

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
  else
    return;
}

int sol=0;
void tati_cu_un_fiu(nod* rad)
{
  if(rad){
    if((rad->st!=NULL && rad->dr==NULL) || (rad->st==NULL && rad->dr!=NULL))
      sol++;
    tati_cu_un_fiu(rad->st);
    tati_cu_un_fiu(rad->dr);
  }
}

int main()
{
  nod *radacina = NULL;
  citire(radacina);
  tati_cu_un_fiu(radacina);
  fout<<sol;
  return 0;
}
