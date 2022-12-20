#include<bits/stdc++.h>
using namespace std;
ifstream fin("bfs.in");
ofstream fout("bfs.out");

vector<vector<int>> adj;
vector<int> cost;
int n,start;

void citire()
{
  int m;
  fin>>n>>m>>start;
  adj.resize(n+1);
  cost.resize(n+1,-1);
  while(m--)
  {
    int x,y;
    fin>>x>>y;
    adj[x].push_back(y);
  }
}

void bfs()
{
  queue<int> coada;
  cost[start] = 0;
  coada.push(start);

  while(!coada.empty())
  {
    int nod = coada.front();
    coada.pop();

    for(auto vecin:adj[nod])
      if(cost[vecin]==-1)
      {
        cost[vecin] = cost[nod] + 1;
        coada.push(vecin);
      }
  }
}

int main()
{
  citire();
  bfs();

  for(int i=1;i<=n;i++)
    fout<<cost[i]<<' ';
  return 0;
}
