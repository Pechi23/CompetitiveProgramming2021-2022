/*
   knivel1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 20:23:51 by Pechi
   Updated: 30/01/2022 21:20:31 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("knivel1.in");
ofstream fout("knivel1.out");

struct nod{
  int info,nivel;
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

void nivelare(nod* &rad, int nivtata)
{
  if(rad){
    rad->nivel = nivtata+1;
    nivelare(rad->st,rad->nivel);
    nivelare(rad->dr,rad->nivel);
  }
}

void suma_k(nod *rad,int k, int &suma)
{
  if(rad && rad->nivel<=k)
  {
    if(rad->nivel == k)
      suma+= rad->info;
    suma_k(rad->st,k,suma);
    suma_k(rad->dr,k,suma);
  }
}

int main()
{
  int k;
  nod* radacina = NULL;
  citire(radacina);
  fin>>k;
  nivelare(radacina,-1);
  int suma = 0;
  suma_k(radacina,k,suma);
  fout<<suma;
  return 0;
}
