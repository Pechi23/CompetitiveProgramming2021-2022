/*
   nrfii.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 19:42:32 by Pechi
   Updated: 15/02/2022 19:51:02 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("nrfii.in");
ofstream fout("nrfii.out");

int n;
map<int,int> frecv;

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    frecv[x]++;
  }
}

void solve()
{
  int maxim = 0;
  set<int> sol;
  for(auto pereche:frecv)
    if(pereche.second>maxim)
    {
      maxim = pereche.second;
      sol.clear();
      sol.emplace(pereche.first);
    }
    else
      if(pereche.second==maxim)
        sol.emplace(pereche.first);

  for(auto el:sol)
    fout<<el<<' ';
}

int main()
{
  citire();
  solve();
  return 0;
}
