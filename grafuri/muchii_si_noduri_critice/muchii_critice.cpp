#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

vector<vector<int>> adj;
bitset<101> vizitat;
vector<int> tata,nivel,nivel_minim;
set <int> noduri_critice;
set<pair<int,int>>muchii_critice;
int n,m;
unsigned int radacina = 1,nrfii = 0;

void citire()
{
  fin>>n>>m;
  adj.resize(n+1);
  tata.resize(n+1);
  nivel.resize(n+1);
  nivel_minim.resize(n+1);

  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void dfs(int nodcurent)
{
  vizitat[nodcurent] = true; //vizitam nodul curent
  nivel[nodcurent] = nivel[tata[nodcurent]] + 1; //nivelul fiului este nivelul tatalui + 1
  nivel_minim[nodcurent] = nivel[nodcurent]; //nivelul minim va fi initial nivelul actual
  for(auto vecin:adj[nodcurent]) //parcurgem toti vecini (potentiali fii)
  {
    if(!vizitat[vecin])//nu e vizitat
    {
      tata[vecin] = nodcurent; //retinem tatal vecinului
      if(tata[vecin] == radacina)
      {
          nrfii++;
          if(nrfii>1)
            noduri_critice.emplace(radacina);

      }
      dfs(vecin); //il vizitam
      nivel_minim[nodcurent] = min(nivel_minim[nodcurent],nivel_minim[vecin]); //daca exista o muchie de intoarcere prin intermediul fiului
      if(nivel_minim[vecin]>nivel[nodcurent])
        muchii_critice.emplace(make_pair(nodcurent,vecin));
      if(nivel_minim[vecin]>=nivel[nodcurent] && nodcurent != radacina)
        noduri_critice.emplace(nodcurent);

    }
    else
    {
      //e vizitat deja
      if(vecin != tata[nodcurent]) //daca fiul nu e tatal nodului actual
        nivel_minim[nodcurent] = min(nivel_minim[nodcurent], nivel[vecin]);//muchie de intoarcere
    }
  }
}

int main()
{

  citire();
  dfs(radacina);
  cout<<"noduri critice: ";
  for(auto nod:noduri_critice)
    cout<<nod<<' ';

  cout<<"\nmuchii critice:\n";
  for(auto it =  muchii_critice.begin();it!=muchii_critice.end();it++)
    cout<<(*it).first<<' '<<(*it).second<<'\n';

  return 0;
}
