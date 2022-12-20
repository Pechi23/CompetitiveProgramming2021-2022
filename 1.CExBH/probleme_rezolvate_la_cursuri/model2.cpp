#include<bits/stdc++.h>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,m,x,y;
bitset <100001> viz;
vector<vector<int> >adj;
vector<int> gI;
set<int> M;

int main()
{
  fin>>n>>m;
  adj.resize(n+1);
  gI.resize(n+1);
  for(int i=0;i<m;i++)
  {
    fin>>x>>y;
    adj[x].push_back(y);
    gI[y]++;
  }

  while(M.size()!=0)
  {
    int p = *M.begin();
    M.erase(M.begin());
    cout<<p;
    for(auto i:adj[p]){
      gI[i]--;
      if(gI[i]==0)
        M.insert(i);
    }
  }

  return 0;
}
