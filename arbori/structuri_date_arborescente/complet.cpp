/*
   complet.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 08:16:12 by Pechi
   Updated: 10/02/2022 08:34:53 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;

struct nod{
  int info;
  nod *st,*dr,*tata;
};

nod * radacina = NULL;

void citeste_rad(nod* &rad,nod* parinte)
{
  int x;
  fin>>x;
  if(x)
  {
    rad = new nod;
    rad->st = NULL;
    rad->dr = NULL;
    rad->info = x;
    rad->tata = parinte;
    citeste_rad(rad->st);
    citeste_rad(rad->dr);
  }
}

void test()
{
  int tip,x;
  fin>>tip>>x;
  if(tip==1)
    cout<<
}

void citire()
{
  fin>>n;
  citeste_rad(radacina,NULL);
  fin>>tests;
  for(int i=1;i<=tests;i++)
    test();
}

int main()
{
  citire();
  return 0;
}
