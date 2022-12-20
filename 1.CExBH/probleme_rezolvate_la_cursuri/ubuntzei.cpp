#include<bits/stdc++.h>

using namespace std;
ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

vector<vector<pair<int,int>>> adj;
int cost[20][20];
int dp[1<<17][21]; //dp[submultime_de_orase_parcurse][ultimul oras parcurs];
int k,comb;
vector<int> porti,c;
int n,m,start,nr_porti;
const int inf = INT_MAX/2;

void citire()
{
  fin>>n>>m;
  fin>>k;
  c.resize(k+2);
  for(int i=1;i<=k;i++)
    fin>>c[i];
  c[0]=1;
  c[++k] = n;
  adj.resize(n+1);
  while(m--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
  }
}

vector<int> drum_minim(int start)
{
  set<pair<int,int>> sety; // distanta minima , nod pentru distanta minima
  vector<int> dist(n+1,inf);

  dist[start] = 0;
  sety.emplace(0,start);

  while(!sety.empty())
  {
    pair<int,int> extras = *(sety.begin());
    sety.erase(sety.begin());

    int nodcurent = extras.second;

    for(auto pereche: adj[nodcurent])
    {
      int vecin = pereche.first;
      int cost = pereche.second;

      if(dist[vecin] > dist[nodcurent] + cost)
      {
        if(dist[vecin] != inf)
          sety.erase({dist[vecin],vecin});

        dist[vecin] = dist[nodcurent] + cost;
        sety.emplace(dist[vecin],vecin);
      }
    }
  }
  return dist;
}


int main()
{
  int minim = INT_MAX,sol;
  citire();
  comb = (1<<k); //ex  k=2 -> comb =(100)2
  for(int i=0;i<=k;i++)
    for(int j=0;j<=k;j++)
      cost[i][j] = inf;

  for(int i=0;i<=comb-1;i++)
      for(int j=0;j<=k;j++)
        dp[i][j] = inf;

  for(int i=0;i<=k;i++)
  {
      vector<int> drum = drum_minim(c[i]);
      for(int j=0;j<=k;j++)
      cost[i][j] = drum[c[j]];

  }
  for(int i=0;i<=k;i++)
    dp[1<<i][i] = cost[0][i];


  for(int subm = 1;subm<=comb-1;subm++)
  {
    for(int i=0;i<=k;i++)
    {
      if(subm&(1<<i))//nodul de pe pozitia i apare in submultime
      {
        for(int j=0;j<=k;j++)
        {
          if(!(subm&(1<<j)))//nodul de pe pozitia j nu apare in submultime
          {
            dp[subm|(1<<j)][j] = min(dp[subm|(1<<j)][j],dp[subm][i]+cost[i][j]);
          }
        }
      }
    }
  }
  int minn = inf;
  for(int i=0;i<=k;i++)
  {
    minn = min(minn,dp[comb-1][i]+cost[i][k]);
    cout<<dp[comb-1][i]+cost[i][k]<<' ';
  }
  fout<<minn;

  return 0;
}
