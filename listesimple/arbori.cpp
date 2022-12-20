#include<bits/stdc++.h>
using namespace std;

struct nod{
  int info;
  nod *st,*dr;
};


void adaugare(nod * &root,int x)
{
  if(root!=NULL)
  {
    if(root->info==x)
      return ;
    else
      if(x<root->info){
        adaugare(root->st,x);
      }
      else{
        adaugare(root->dr,x);
      }
  }
  else
  {
    root = new nod;
    root->info = x;
    root->st = NULL;
    root->dr = NULL;
  }
}

void afisare(nod *root) //preordine
{
  if(root!=NULL){
    cout<<root->info<<' ';
    afisare(root->st);
    afisare(root->dr);
  }
}

int main()
{
  nod *r=new nod;
  //r->info=3;
  //r->st=r->dr=NULL;
  r=NULL;

  adaugare(r,5);
  adaugare(r,3);
  adaugare(r,4);
  adaugare(r,6);
  adaugare(r,8);
  adaugare(r,2);
  afisare(r);
  return 0;
}
