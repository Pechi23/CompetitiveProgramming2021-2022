#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");

struct nod{
  int info;
  nod *urm;
};

void adaugare_inceput(int x,nod * &p)
{
  nod *nou = new nod;
  nou->info = x;
  nou->urm = p;
  p=nou;
}

void adaugare_final(int x,nod * &p)
{
  if(p==NULL)
  {
    nod *nou=new nod;
    nou->urm=NULL;
    nou->info=x;
    p=nou;
  }
  else
  {
    nod *rad=p;
    while(rad->urm!=NULL)
    {
      rad=rad->urm;
    }
    nod *nou=new nod;
    rad->urm=nou;
    nou->info=x;
    nou->urm=NULL;

  }
}

void afisare(nod * &p)
{
  while(p!=NULL){
    cout<<p->info<<' ';
    p = p->urm;
  }
}

int main()
{
  nod *p=NULL;
  int x;
  while(fin>>x)
    adaugare_final(x,p);
  afisare(p);
  return 0;
}
