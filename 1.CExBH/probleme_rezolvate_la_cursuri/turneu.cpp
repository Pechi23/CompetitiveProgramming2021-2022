#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
bitset <101> viz;
vector<int>sol;
int n;

void dfs(int nc)
{
  sol.push_back(nc);
  viz[nc]=true;
  for(auto i:adj[nc])
    if(!viz[i])
        dfs(i);
}
/*
void dfssol(int nc)
{
  cout<<nc<<' ';
  viz[nc]=true;
  for(auto i:adj[nc])
    if(!viz[i])
        dfssol(i);
}*/

int main()
{
  int x,y;
  cin>>n;
  adj.resize(n+1);
  for(int i=0;i<(n*(n-1))/2;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
  }

  bool ok=false;
  int nodsol=0;
  for(int i=1;i<=n && !ok;i++)
  {
    dfs(i);
    ok=true;
    for(int i=1;i<=n && ok;i++)
      if(!viz[i])
      {
        ok=false;
        viz.reset();
        sol.clear();
      }
      else{
        nodsol=i;
        break;
      }
      if(nodsol && sol.size()==n)
        break;
  }
  //viz.reset();
  //dfssol(nodsol);
  for(auto i:sol)
    cout<<i<<' ';
  return 0;
}
