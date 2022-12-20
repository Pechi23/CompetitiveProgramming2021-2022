/*
   niceset.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 16:16:37 by Pechi
   Updated: 27/02/2022 16:27:58 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("niceset.in");
ofstream fout("niceset.out");

vector<int> niceset, valori;
int n;
long long suma;

void citire()
{
  fin>>n>>suma;
  for(int i=0;i<n;i++)
  {
    int x;
    fin>>x;
    valori.emplace_back(x);
  }
}

long long suma_absoluta(int x)
{
  long long suma = 0;
  for(auto el:niceset)
  {
    suma = suma+ abs(x - el);
  }
  return suma;
}

void solve()
{
  sort(valori.begin(),valori.end());
  long long s_partiala=0;
  int cnt =0;
  for(int i=0;i<n && s_partiala<=suma;i++)
  {
    long long suma_noua = suma_absoluta(valori[i]);
    if(s_partiala + suma_noua<= suma)
    {
      cnt++;
      s_partiala += suma_noua;
      niceset.emplace_back(valori[i]);
    }
  }
  fout<<cnt;
}

int main()
{
  citire();
  solve();
  return 0;
}
