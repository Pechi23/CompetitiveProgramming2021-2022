/*
   bilatime.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 25/01/2022 14:20:18 by Pechi
   Updated: 31/01/2022 12:47:32 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("bilatime.in");
ofstream fout("bilatime.out");

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

void afisare_bfs(nod* rad)
{
  queue<nod*> coada;
  coada.push(rad);
  while(!coada.empty())
  {
    //extragem urmatorul element din coada
    nod* element = coada.front();
    coada.pop();

    //afisam elementul curent
    fout<<element->info<<' ';

    //adaugam fii in coada
    if(element->st)
      coada.push(element->st);
    if(element->dr)
      coada.push(element->dr);
  }
}

int main()
{
  nod* radacina = NULL;
  citire(radacina);
  afisare_bfs(radacina);
  return 0;
}
