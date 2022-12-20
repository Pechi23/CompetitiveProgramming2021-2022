#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<vector<int>> adj;
vector<vector<int>> adj_trans;
int n,m,x,y;
bitset <101> viz;

void dfs(int nc)
{
  viz[nc]=1;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);
}

void dfsgt(int nc)
{
  viz[nc]=1;
  for(auto i:adj_trans[nc])
    if(!viz[i])
      dfsgt(i);
}

int main()
{
  cin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  int x,y;
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
  }

  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  viz.reset();
  int contor=0;
  while(!st.empty())
  {
    int element=st.top();
    st.pop();
    if(!viz[element])
    {
      contor++;
      dfsgt(element);
    }
  }

  cout<<contor;
  return 0;
}
