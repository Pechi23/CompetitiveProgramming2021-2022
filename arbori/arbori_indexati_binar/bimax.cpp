/*
   bimax.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 13:25:52 by Pechi
   Updated: 25/01/2022 13:42:06 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("bimax.in");
ofstream fout("bimax.out");

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

void maxim(nod* rad,int &max)
{
  if(rad)
  {
    if(rad->info >max)
      max = rad->info;
    maxim(rad->st,max);
    maxim(rad->dr,max);
  }
  else
    return;
}


int main()
{
  int maxim_st = INT_MIN;
  int maxim_dr = INT_MIN;
  nod * radacina =NULL;

  citire(radacina);

  maxim(radacina->st,maxim_st);
  maxim(radacina->dr,maxim_dr);

  fout<<maxim_st<<' '<<maxim_dr;
  return 0;
}
