/*
   bst.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 21:24:28 by Pechi
   Updated: 30/01/2022 21:46:54 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("bst.in");
ofstream fout("bst.out");

struct nod{
  int info;
  nod *st,*dr;
};

nod* radacina = NULL;

void insert(nod* &rad,int x)
{
  if(rad)
  {
    if(rad->info > x)
      insert(rad->st,x);
    else
      insert(rad->dr,x);
  }
  else
  {
    rad = new nod;
    rad->info = x;
    rad->st = NULL;
    rad->dr = NULL;
  }
}

void afisare(nod * rad)
{
  if(rad)
  {
    afisare(rad->st);
    fout<<rad->info<<' ';
    afisare(rad->dr);
  }
}

void citire()
{
  int n;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    insert(radacina,x);
  }
}

int main()
{
  citire();
  afisare(radacina);
  return 0;
}
