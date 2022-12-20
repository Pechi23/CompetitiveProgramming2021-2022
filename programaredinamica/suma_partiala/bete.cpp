#include<bits/stdc++.h>
using namespace std;
ifstream fin("bete.in");
ofstream fout("bete.out");

int n;
vector<int> suma,v,vizitat;
set<int> sol;

int main()
{
  int s;
  fin>>n>>s;
  v.resize(n+1);
  suma.resize(s+1);
  vizitat.resize(s+1);
  for(int i=1;i<=n;i++)
    fin>>v[i];
  int smax = 0;
  for(int i=1;i<=n;i++)
  {
    for(int j=smax;j>=1;j--)
    {
      if(vizitat[j])
        if(j+v[i]<= s){
            vizitat[j+v[i]] = i;
            smax = max(smax,j+v[i]);
        }
      if(v[i] <= s){
        vizitat[v[i]]  =i;
        smax = max(smax,v[i]);

      }
      smax = min(smax,s);
    }
  }
  if(vizitat[s])
    fout<<"DA"<<'\n';
  else
    fout<<"NU"<<'\n';

  //reconstituirea drumului

  if(vizitat[s]){
    while(s>0)
    {
      sol.emplace(vizitat[s]);
      s -= v[vizitat[s]];
    }

    fout<<sol.size()<<'\n';
    for(auto el:sol)
      fout<<el<<' ';
  }
  return 0;
}
