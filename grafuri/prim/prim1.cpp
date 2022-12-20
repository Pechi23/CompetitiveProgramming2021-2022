#include<bits/stdc++.h>

using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");

int n,m;
const unsigned int inf = 0x3f3f3f3f;
vector<set<pair<int,int>>> adj;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].emplace(y,z);
    adj[y].emplace(x,z);
  }
}

pair<int,vector<int>> tata_Prim(int start)
{
  set<pair<int,int>> sety; //pair < distanta curenta minima, nodul corespunzator acesteia >
  vector<int> dist(n+1,inf);//distanta pana in nodul i, initial infinita pt toate nodurile
  vector<int> tata(n+1);//vector de tati

  tata[start] = 0; //radacina nu are tata
  dist[start] = 0; //radacina nu are cost pt ca de acolo pornim
  sety.emplace(0,start);//incepem din radacina

  while(!sety.empty()) //cat timp avem distante optime de luat in considerare
  {
    pair<int,int> extras = *(sety.begin()); //extragem distanta minima
    sety.erase(sety.begin()); //si o eliminam

    int nodcurent = extras.second;

    for(auto pereche: adj[nodcurent]) // parcurgem vecinii nodului curent din lista de adiacenta
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin] > cost && tata[nodcurent]!=vecin) // daca distanta din nodcurent in vecin e mai mica
      //decat distanta vecinului pana in acest moment si nodul vecin nu e tata nodului curent
      {
        dist[vecin] = cost; //distanta vecinului va fi luata prin nodul curent
        tata[vecin] = nodcurent; //tata vecinului va fi nodul curent, logic
        sety.emplace(dist[vecin],vecin);//adaugam in set distanta prin muchia noua in set
      }
    }
  }

  int cost_arbore = 0; //costul arborelui il aflam la final cand adunam toate distantele fiecarui nod din arbore
  for(auto el:dist)
    if(el != inf) //nu se poate ajunge intr un anume nod, nu il luam in cosiderare
      cost_arbore += el;

  return {cost_arbore,tata};
}


int main()
{
  int start = 1;
  citire();
  pair<int,vector<int>> tati = tata_Prim(start);

  //afisare
  fout<<tati.first<<'\n';
  for(int i=1;i<=n;i++)
    fout<<tati.second[i]<<' ';
  return 0;
}
