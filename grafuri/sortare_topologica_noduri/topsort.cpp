#include<bits/stdc++.h>
using namespace std;
ifstream fin("topsort.in");
ofstream fout("topsort.out");


vector <vector<int> > adj;
stack<int>st;
bitset <100001> viz;

void dfs(int nc)
{
  viz[nc]=true;
  for(auto i:adj[nc])
    if(!viz[i])
      dfs(i);
  st.push(nc);
}

int main()
{
  int n,m,x,y;
  fin>>n>>m;


  adj.resize(n+1);
  for(int i=0;i<m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
  }

  for(int i=1;i<=n;i++)
    if(!viz[i])
      dfs(i);

  while(!st.empty())
  {
    fout<<st.top()<<' ';
    st.pop();
  }

  return 0;
}
