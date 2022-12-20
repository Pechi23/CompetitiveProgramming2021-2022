/*
   biminprim.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 13:44:26 by Pechi
   Updated: 25/01/2022 13:57:05 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("biminprim.in");
ofstream fout("biminprim.out");

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

bool prim(int x) //returneaza true daca x e prim
{
  if(x<2)
    return false;
  if(!(x%2) && x!=2)
    return false;
  for(int d=3;d*d<=x;d++)
    if(!(x%d))
      return false;
  return true;
}

void minprim(nod* rad,int &min)
{
  if(rad)
  {
    if(prim(rad->info) && rad->info<min)
      min = rad->info;

    minprim(rad->st,min);
    minprim(rad->dr,min);
  }
}

int main()
{
  nod* radacina = NULL;
  int minprim_st = INT_MAX,minprim_dr = INT_MAX;
  citire(radacina);

  minprim(radacina->st,minprim_st);
  minprim(radacina->dr,minprim_dr);

  //daca nu sunt nr prime in subarborele respectiv
  if(minprim_st==INT_MAX)
    minprim_st = -1;
  if(minprim_dr==INT_MAX)
    minprim_dr = -1;

  fout<<minprim_st<<' '<<minprim_dr;
  return 0;
}
