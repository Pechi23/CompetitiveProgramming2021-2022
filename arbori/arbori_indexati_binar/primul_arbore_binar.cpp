#include<bits/stdc++.h>
using namespace std;

struct nod{
  int info;
  nod* st;
  nod* dr;
};

nod* insert_el(nod *&rad, int val)
{
  if(rad)
  {

    if(rad->info == val)
      return rad;
    else

    if(rad->info>val)
      rad-> st = insert_el(rad->st, val);
    else
      rad-> dr = insert_el(rad->dr, val);
    return rad;
  }
  else
  {
    nod* nou = new nod;
    nou ->info = val;
    nou ->st = NULL;
    nou ->dr = NULL;
    return nou;
  }
}

void insert_simplu(nod * &rad,int val)
{
  if(rad)
  {
    if(rad->info == val)
      return;
    else
      if(rad->info > val)
        insert_simplu(rad->st,val);
      else
        insert_simplu(rad->dr,val);
  }
  else
  {
    rad = new nod;
    rad -> info = val;
    rad -> st = NULL;
    rad -> dr = NULL;
  }
}

void deleteaux(nod* &p, nod* &rad)
{
  if(p->dr)
    deleteaux(p->dr, rad);
  else
  {
    rad->info = p->info;
    nod * aux = p;
    p = p->st;
    delete aux;
  }
}

void stergere_pechi(nod * &rad,int val)
{
  if(rad)
  {
    if(rad->info == val)
    {
      if(rad->st==NULL && rad->dr == NULL)
      {
        delete rad;
        rad = NULL;
      }
      else
        if(rad->dr == NULL)
        {
          nod *aux = rad;
          rad = rad->st;
          delete aux;
        }
        else
          if(rad->st == NULL)
          {
            nod * aux = rad;
            rad = rad->dr;
            delete aux;
          }
          else
            deleteaux(rad->st,rad);
    }
    else
      if(rad->info > val)
        stergere_pechi(rad->st,val);
      else
        stergere_pechi(rad->dr,val);
  }else
  {
    return;
  }
}

void afisare_arbore(nod * rad)
{
  if(rad){
    afisare_arbore(rad->st);
    cout<<rad->info<<' ';
    afisare_arbore(rad->dr);
  }
}

int main()
{
  nod* radacina = NULL;
  /*
  radacina = insert_el(radacina,6);
  radacina = insert_el(radacina,8);
  radacina = insert_el(radacina,8);
  radacina = insert_el(radacina,5);
  radacina = insert_el(radacina,10);
  radacina = insert_el(radacina,3);
  radacina = insert_el(radacina,2);
  */
  insert_simplu(radacina,5);
  insert_simplu(radacina,100);
  insert_simplu(radacina,43);
  insert_simplu(radacina,2);
  insert_simplu(radacina,3);
  insert_simplu(radacina,4);
  insert_simplu(radacina,1);

  stergere_pechi(radacina,5);

  afisare_arbore(radacina);
}
