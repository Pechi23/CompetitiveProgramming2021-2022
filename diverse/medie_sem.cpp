#include<bits/stdc++.h>
using namespace std;
ifstream fin("note_pechi.in");
ofstream fout("note.txt");

double media;
vector<pair<int,string>> note;
int nr_note = 0;

void citire()
{
  int nota;
  string materie;
  while(fin>>nota>>materie)
  {
    nr_note++;
    note.push_back(make_pair(nota,materie));
  }
}

void afisare()
{
  fout<<"notele tale pe semestrul 1:"<<'\n';
  for(auto nota : note)
    fout<<nota.first<<' '<<nota.second<<'\n';
  fout<<"media ta pe primul semestru: "<<media;
}

void calculare_medie(double &medie)
{
  medie = 0;
  for(auto nota:note)
    medie += nota.first;
  medie /= nr_note;
}

int main()
{
  citire();
  calculare_medie(media);
  afisare();
  return 0;
}
