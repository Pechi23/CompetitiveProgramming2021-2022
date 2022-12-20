//algoritmul lui kosaraju
#include<bits/stdc++.h>

using namespace std;
ifstream fin("date.in");

vector<vector<int> > adj;
vector<vector<int> > adj_trans;
stack<int> st;
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
  fin>>n>>m;
  adj.resize(n+1);
  adj_trans.resize(n+1);

  for(int i=1;i<=m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
    adj_trans[y].push_back(x);
  }

  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  viz.reset();

  int c=0;
  while(!st.empty())
  {
    int element = st.top();
    st.pop();
    if(!viz[element]){
      c++;
      dfsgt(element);
    }
  }
  cout<<c;

  return 0;
}
