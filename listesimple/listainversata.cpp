#include<bits/stdc++.h>
using namespace std;

struct node{
  int value;
  node *next;
};

void adaugare_inceput(node *&p, int x)
{
  node *nou=new node;
  nou->next = p;
  nou->value = x;
  p = nou;
}

node *invertlist(node *&p)
{
  node * ant = NULL;
  node * urm = p;
  while(p!=NULL)
  {
    urm = p->next;
    p->next=ant;
    ant = p;
    p=urm;
  }
  return ant;
}

void afisare(node * p)
{
  while(p!=NULL)
  {
    cout<<p->value<<' ';
    p = p->next;
  }
}

int main()
{
  node * first = NULL;
  adaugare_inceput(first,14);
  adaugare_inceput(first,34);
  afisare(first);
  cout<<'\n';
  first = invertlist(first);
  afisare(first);
  return 0;
}
