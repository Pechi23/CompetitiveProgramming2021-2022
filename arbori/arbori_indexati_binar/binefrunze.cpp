//varianta fara stl
//pecherle george
#include <bits/stdc++.h>

using namespace std;
ifstream fin("binefrunze1.in");
ofstream fout("binefrunze1.out");

struct nod{
  int info;
  nod *st,*dr;
};

nod* rad_nefrunze = NULL;

void citire(nod* &rad)
{
  int x;
  fin>>x;
  if(x){
    rad = new nod;
    rad->info = x;
    rad->st = NULL;
    rad->dr = NULL;
    citire(rad->st);
    citire(rad->dr);
  }
}

void afisare_desc_nefrunze(nod* rad)
{
  if(rad)
  {
    afisare_desc_nefrunze(rad->dr);
    fout<<rad->info<<' ';
    afisare_desc_nefrunze(rad->st);
  }
}

void adaug_nefrunza(nod * &rad,int val)
{
  if(rad)
  {
    if(rad->info > val)
      adaug_nefrunza(rad->st,val);
    else
      adaug_nefrunza(rad->dr,val);
  }
  else
  {
    rad = new nod;
    rad->info = val;
    rad->st = NULL;
    rad->dr = NULL;
  }
}

void gasire_nefrunze(nod* rad)
{
  if(rad){
    if(rad->st || rad->dr) //daca e nefrunza o adaugam in arborele de nefrunze
      adaug_nefrunza(rad_nefrunze,rad->info);

    gasire_nefrunze(rad->st);
    gasire_nefrunze(rad->dr);
  }
}

int main()
{
  nod* radacina = NULL;
  citire(radacina);
  gasire_nefrunze(radacina);
  afisare_desc_nefrunze(rad_nefrunze);
  return 0;
}
