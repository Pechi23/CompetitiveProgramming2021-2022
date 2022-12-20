#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
bitset<200001> viz;
int contor=0,n;

void dfs(int nc,int start)
{
  contor++;
  viz[nc]=true;
  for(auto i:adj[nc])
    if(viz[i] && i==start)
      return;
    else
      if(!viz[i])
        dfs(i,start);
}

int main()
{
  int x;
  cin>>n;
  adj.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    adj[i].push_back(x);
  }

  for(int i=1;i<=n;i++)
  {
    contor=0;
    viz.reset();
    dfs(i,i);
    cout<<contor<<' ';
  }
  return 0;
}
