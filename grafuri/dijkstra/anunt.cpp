#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> grad_intern,predecesor;
bitset<101> viz;
set<int> sety,ramas;

int main()
{
  int m,x,y;
  //citire
  cin>>n>>m;
  adj.resize(n+1);
  grad_intern.resize(n+1);
  predecesor.resize(n+1);

  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    grad_intern[y]++;
    predecesor[y]=x;
    ramas.emplace(i);
  }

  while(sum){
  for(int i=1;i<=n;i++){
    if(grad_intern[i]==1){
      sety.emplace(predecesor[i]);
      grad_intern[predecesor[i]]=0;
      grad_intern[i]=0;
    }
    sum+=grad_intern[i];
  }
}

  for(auto i:sety)
    cout<<i<<' ';
  return 0;
}
