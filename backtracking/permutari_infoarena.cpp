#include<bits/stdc++.h>

using namespace std;
ifstream fin("permutari.in");
ofstream fout("permutari.out");

vector<int> sol;
int n;

void afisare()
{
  for(auto el:sol)
    fout<<el<<' ';
  fout<<'\n';
}

bool ok(int k)
{
  for(int i=0;i<k;i++)
    if(sol[i] == sol[k])
      return false;
  return true;
}

void back(int k)
{
  if(k==n)
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
  fin>>n;
  sol.resize(n);
  back(0);
  return 0;
}
