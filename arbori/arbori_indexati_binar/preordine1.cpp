#include<bits/stdc++.h>

using namespace std;
ifstream fin("preordine1.in");
ofstream fout("preordine1.out");

struct nod{
  int info,niv;
  nod *st,*dr;
};

void citire_arbore(nod* &rad,int nivrad)
{
  if(!rad)
  {
    int x;
    fin>>x;
    if(x){
    rad = new nod;
    rad->info = x;
    rad->niv = nivrad;
    rad->st = NULL;
    rad->dr = NULL;
    citire_arbore(rad->st,nivrad+1);
    citire_arbore(rad->dr,nivrad+1);
    }
  }
}
vector<vector<int>> arbore;
void afisare_subarbore_stang(nod * &rad)
{
  if(rad)
  {
    cout<<rad->niv<<' '<<rad->info<<'\n';
    afisare_subarbore_stang(rad->st);
    afisare_subarbore_stang(rad->dr);
  }
}

int main()
{
  nod* radacina = NULL;
  int nivrad = 1;
  citire_arbore(radacina,nivrad);
  afisare_subarbore_stang(radacina);
  return 0;
}
