#include<bits/stdc++.h>
using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int n,gmax;
vector<int> w,p,linie1,linie2;

int main()
{
  //citire
  fin>>n>>gmax;
  linie1.resize(gmax+1);
  linie2.resize(gmax+1);
  w.resize(n+1);
  p.resize(n+1);

  for(int i=1;i<=n;i++)
    fin>>w[i]>>p[i];

  for(int i=1;i<=n;i++)
  {
    for(int cap=1;cap<=gmax;cap++)
      if(cap-w[i] >=0)
        linie2[cap] = max(linie1[cap],linie1[cap-w[i]] + p[i]);
      else
        linie2[cap] = linie1[cap];
    linie1 = linie2;
  }

  double ratia=0;
  int lim;
  for(int i=1;i<=n;i++)
    if((double)(p[i]/w[i]) > ratia){
      ratia = (double)(p[i]/w[i]);
      lim = w[i];
    }

  //cout<<ratia<<'\n';


  double fractie,sol = 0;
  for(int cap=1;cap<=gmax;cap++)
  {
    if(gmax-cap<=lim)
      fractie = (double)(linie1[cap]+ ratia*(gmax-cap));
    //cout<<fractie<<' ';
    sol = max(sol,fractie);
  }
  cout<<sol;

  return 0;
}
