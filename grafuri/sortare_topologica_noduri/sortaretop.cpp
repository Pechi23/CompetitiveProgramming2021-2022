#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >adj;
vector<vector<int> >adj_trans;
bitset <101> viz;
stack<int>st;

int n,m,x,y;

void dfs(int nc)
{
  viz[nc]=1;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);//adaugam nodurile in fct de timpul de vizitare
}

void sorttop()
{
  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);
}

void dfs2(int nc)
{
  viz[nc]=1;
  for(auto i:adj_trans[nc])
    if(!viz[i])
      dfs2(i);
}

int main()
{
  cin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);
  int nrcomptariconexe=0;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  sorttop();
  for(int i=0;i<=100;i++)
    viz[i]=0;
  while(!st.empty())
  {
    int nod = st.top();
    st.pop();
    if(!viz[nod])
      {
        nrcomptariconexe++;
        dfs2(nod);
      }
  }
  cout<<nrcomptariconexe;
  return 0;
}
