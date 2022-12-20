/*
   eureni.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 28/02/2022 08:17:11 by Pechi
   Updated: 28/02/2022 08:30:17 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("eureni.in");
ofstream fout("eureni.out");
int s,n,e;
vector<pair<int,int>> sol;
//e^n

int power(int n,int p)
{
  int rez = 1;
  while(p)
  {
    if(p%2)
      rez *= n;
    n*=n;
    p/=2;
  }
  return rez;
}

void solve()
{
  fin>>s>>n>>e;
  int putere = n;
  int cnt_bancnote=0;
  while(s>0)
  {
    int bancnota = power(e,putere);
    if(s/bancnota){
      sol.emplace_back(bancnota, s/bancnota);
      cnt_bancnote+= s/bancnota;
      s%= bancnota;
    }
    putere--;
  }

  for(auto pereche:sol)
    fout<<pereche.first<<' '<<pereche.second<<'\n';
  fout<<cnt_bancnote;
}
int main()
{
  solve();
  return 0;
}
