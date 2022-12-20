//varianta fara stl
//pecherle george
#include <bits/stdc++.h>

using namespace std;
ifstream fin("bifrunze1.in");
ofstream fout("bifrunze1.out");

struct nod{
  int info;
  nod *st,*dr;
};

nod* rad_frunze = NULL;

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

void afisare_inordine_frunze(nod* rad)
{
  if(rad)
  {
    afisare_inordine_frunze(rad->st);
    fout<<rad->info<<' ';
    afisare_inordine_frunze(rad->dr);
  }
}

void adaug_frunza(nod * &rad,int val)
{
  if(rad)
  {
    if(rad->info > val)
      adaug_frunza(rad->st,val);
    else
      adaug_frunza(rad->dr,val);
  }
  else
  {
    rad = new nod;
    rad->info = val;
    rad->st = NULL;
    rad->dr = NULL;
  }
}

void gasire_frunze(nod* rad)
{
  if(rad->st)
    gasire_frunze(rad->st);
  if(rad->dr)
    gasire_frunze(rad->dr);
  if(rad->st == NULL && rad->dr == NULL) //daca e frunza o adaugam in set
    adaug_frunza(rad_frunze,rad->info);
}

int main()
{
  nod* radacina = NULL;
  citire(radacina);
  gasire_frunze(radacina);
  afisare_inordine_frunze(rad_frunze);
  return 0;
}
