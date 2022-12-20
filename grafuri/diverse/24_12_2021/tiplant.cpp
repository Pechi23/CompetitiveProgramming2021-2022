#include<bits/stdc++.h>
using namespace std;
ifstream in("veriflant.in");
ofstream out("veriflant.out");

int n,m,k,x,y,nrelemente,el;
vector<set<int>> adj;
vector<vector<int>> lanturi;
bitset<101> neelementar;
bitset<201>apar;

int main()
{
  in>>n>>m;
  adj.resize(n+1);
  for(int i=1;i<=m;i++)
  {
    in>>x>>y;
    adj[x].emplace(y);
    adj[y].emplace(x);
  }
  in>>k;
  lanturi.resize(k+1);
  for(int i=1;i<=k;i++)
  {
    in>>nrelemente;
    apar.reset();
    for(int j=1;j<=nrelemente;j++)
    {
      in>>el;
      if(apar[el])
        neelementar[i]=true;
      lanturi[i].push_back(el);
      apar[el]=true;
    }
  }
  int ok;
  for(int i=1;i<=k;i++){
    for(int j=0;j<lanturi[i].size()-1;j++)
    {
      ok=false;
      for(auto z:adj[lanturi[i][j]])
        if(z==lanturi[i][j+1])
          ok=true;

      if(!ok){
        out<<"NU";
        break;
      }
    }
    if(ok)
      if(!neelementar[i])
        out<<"ELEMENTAR";
      else
        out<<"NEELEMENTAR";
    if(i<k)
      out<<'\n';
  }
/*
  for(int i=1;i<=n;i++){
    for(auto j:adj[i])
      cout<<j<<' ';
    cout<<'\n';
  }
*/
  /*
  for(int i=1;i<=k;i++)
    cout<<neelementar[i]<<' ';
  */
  return 0;
}
