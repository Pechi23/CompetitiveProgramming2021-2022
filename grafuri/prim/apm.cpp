//nu mi judecati sursa, am modificat alta problema pentru ca nu am avut rabdare sa o iau de la inceput
#include<bits/stdc++.h>

using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

int n,m;
const unsigned int inf = 0x3f3f3f3f;
vector<vector<pair<int,int>>> adj;
set<pair<int,int>> muchii;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].emplace_back(y,z);
    adj[y].emplace_back(x,z);
  }
}

struct {
  int from,to;
  int pret;
  int tata;
  bool vizitat;
}dist[200001];

int Prim(int start)
{
  set<pair<int,int>> sety; //pair < distanta curenta minima, nodul corespunzator acesteia >
  for(int i=0;i<=n;i++)
    dist[i].pret = inf;//distanta pana in nodul i, initial infinita pt toate nodurile

  dist[start].tata = 0; //radacina nu are tata
  dist[start].pret = 0; //radacina nu are cost pt ca de acolo pornim
  dist[start].vizitat =true;
  sety.emplace(0,start);//incepem din radacina

  while(!sety.empty()) //cat timp avem distante optime de luat in considerare
  {
    pair<int,int> extras = *(sety.begin()); //extragem distanta minima
    sety.erase(sety.begin()); //si o eliminam

    int nodcurent = extras.second;
    dist[nodcurent].vizitat =true;

    for(auto pereche: adj[nodcurent]) // parcurgem vecinii nodului curent din lista de adiacenta
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin].pret > cost && dist[nodcurent].tata!=vecin && !dist[vecin].vizitat) // daca distanta din nodcurent in vecin e mai mica
      //decat distanta vecinului pana in acest moment si nodul vecin nu e tata nodului curent
      {
        if(dist[vecin].pret != inf)
          muchii.erase({dist[vecin].from,dist[vecin].to});
        dist[vecin].pret = cost; //distanta vecinului va fi luata prin nodul curent
        dist[vecin].tata = nodcurent; //tata vecinului va fi nodul curent, logic
        dist[vecin].from = nodcurent;
        dist[vecin].to = vecin;
        muchii.emplace(dist[vecin].from,dist[vecin].to);
        sety.emplace(dist[vecin].pret,vecin);//adaugam in set distanta prin muchia noua in set
      }
    }
  }

  int cost_arbore = 0; //costul arborelui il aflam la final cand adunam toate distantele fiecarui nod din arbore
  for(int i=1;i<=n;i++)
    cost_arbore = cost_arbore + dist[i].pret;



  return cost_arbore;
}


int main()
{
  int start = 1;
  citire();
  int sol = Prim(start);

  //afisare
  fout<<sol<<'\n';
  fout<<muchii.size()<<'\n';
  for(auto pereche:muchii)
    fout<<pereche.first<<' '<<pereche.second<<'\n';

  return 0;
}
