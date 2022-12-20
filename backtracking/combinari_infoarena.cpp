#include<bits/stdc++.h>
using namespace std;
ifstream fin("combinari.in");
ofstream fout("combinari.out");

int n,m;
vector<int> sol;

bool ok(int k)
{
  for(int i=0;i<k;i++)
    if(sol[i] >= sol[k])
      return false;
  return true;
}

void afisare()
{
  for(auto el:sol)
    fout<<el<<' ';
  fout<<'\n';
}

void back(int k)
{
  if(k==m)
    afisare();
  else
    for(int i=1;i<=n;i++)
    {
      sol[k] = i;
      if(ok(k))
        back(k+1);
    }
}

int main()
{
  fin>>n>>m;
  sol.resize(m);
  back(0);

  return 0;
}
