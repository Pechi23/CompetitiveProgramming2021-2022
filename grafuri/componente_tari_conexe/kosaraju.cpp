#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");

vector<vector<int> > adj,adj_trans,adj2,vecid;
stack<int>st;
int n,m,x,y;
bitset<101> viz;
vector<int> id;
int contor=0;


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
    {
      id[i]=contor;
      dfsgt(i);
    }
}

void dfs2(int nc)
{
  viz[nc]=1;
  for(auto i:adj[nc])
    if(!viz[i])
    {
        if(id[i]!=id[nc]){
          adj2[id[nc]].push_back(id[i]);
          viz[nc]=viz[i]=1;
          //adj2[id[nc]].push_back(nc);
          //adj2[id[nc]].push_back(i);
        }
    }
}

int main()
{
  fin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  id.resize(n+1);

  for(int i=0;i<m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  viz.reset();

  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!viz[element])
    {
      id[element]=++contor;
      dfsgt(element);
    }
  }
  viz.reset();
  adj2.resize(contor+1);

  for(int i=1;i<=n;i++)
  {
    for(auto j:adj[i])
      dfs2(j);
  }

  /*cout<<contor;*/
  for(int i=1;i<=contor;i++)
  {
    for(auto j:adj2[i])
      cout<<j<<' ';
    cout<<'\n';
  }


/*
  for(int i=1;i<=n;i++)
    cout<<id[i]<<' ';
*/
  return 0;
}
