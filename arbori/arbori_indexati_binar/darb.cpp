/*
   darb.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 09/02/2022 12:35:54 by Pechi
   Updated: 09/02/2022 14:16:29 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
ifstream fin("darb.in");
ofstream fout("darb.out");


int n,ultimul,diametru;
vector<vector<int>> adj;
vector<int> tata,niv;
bitset<100001> vizitat;

void citire()
{
  int x,y;
  fin>>n;
  adj.resize(n+1);
  tata.resize(n+1);
  niv.resize(n+1);

  while(fin>>x>>y){
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void bfs(int start)
{
  queue<int> coada;
  coada.push(start);
  tata[start]= 0;

  while(!coada.empty())
  {
    int el = coada.front();
    coada.pop();

    vizitat[el] = true;
    ultimul = el;
    niv[el] = niv[tata[el]] + 1;

    if(niv[el]>diametru)
      diametru = niv[el];

    for(auto vecin:adj[el])
      if(!vizitat[vecin]){
        tata[vecin] = el;
        coada.push(vecin);
      }
  }
}

int main()
{
  citire();

  bfs(1);
  vizitat.reset();
  diametru= 0;
  bfs(ultimul);

  fout<<diametru;
  return 0;
}
