#include<bits/stdc++.h>
using namespace std;

int n,m,k,contor=0,solutie=0;
vector<vector<int>> adj,adj_trans;
stack<int> st;
vector<int>id;
bitset<101> viz;

void dfs(int nc)
{
  viz[nc]=true;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);
}

void dfsgt(int nc)
{
  id[nc]=contor;
  viz[nc]=true;
  for(auto i:adj_trans[nc])
    if(!viz[i])
      dfsgt(i);
}

int main()
{
  int x,y;
  cin>>n>>m>>k;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  id.resize(n+1);

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

  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!viz[element])
    {
      contor++;
      dfsgt(element);
    }
  }
  //id[i] reprezinta nr componentei conexe in care se afla varful i
  //cautat  reprezinta nr componentei conexe ale caror nr de varfuri trebuie sa
  //le aflam
  int cautat = id[k];


  for(int i=1;i<=n;i++)
    if(id[i]==cautat)
      solutie++;

  cout<<solutie;
  return 0;
}
