#include<bits/stdc++.h>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,m,x,y;
bitset <100001> viz;
vector<vector<int> >adj;

vector<int> sol;
void dfs(int nc)
{
  viz[nc]=1;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  sol.push_back(nc);
}

int main()
{
  fin>>n>>m;
  adj.resize(n+1);
  for(int i=0;i<m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
  }
  for(int i=1;i<=n;i++)
  {
    if(!viz[i])
      dfs(i);
  }

  for(int i=sol.size()-1;i>=0;i--)
    cout<<sol[i]<<' ';
  return 0;
}
