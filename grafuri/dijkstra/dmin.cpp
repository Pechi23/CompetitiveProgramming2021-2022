#include<bits/stdc++.h>
using namespace std;
ifstream fin("dmin.in");

int n,m;
vector<vector<int>> adj;
const int inf = 0x3f3f3f3f;


void citire()
{
  int x,y;
  fin>>n>>m;
  adj.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

int dist_bfs(int start,int destinatie)
{
  vector<int> distanta(n+1,0);
  bitset<101> vizitat;
  queue<int> coada;

  distanta[start] = 0;
  vizitat[start] = true;
  coada.push(start);

  while(!coada.empty())
  {
    int nodcurent = coada.front();
    coada.pop();

    for(auto vecin:adj[nodcurent])
      if(!vizitat[vecin]){
        coada.push(vecin);
        distanta[vecin] = distanta[nodcurent] + 1;
        vizitat[vecin]=true;
      }
  }
  return distanta[destinatie];
}

void solve_case()
{
  int start,destinatie;
  fin>>start>>destinatie;
  int distanta = dist_bfs(start,destinatie);
  cout<<distanta<<'\n';
}

int main()
{
  int cazuri;
  citire();
  fin>>cazuri;
  for(int i=1;i<=cazuri;i++)
    solve_case();
  return 0;
}
