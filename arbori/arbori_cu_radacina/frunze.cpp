/*
   frunze.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 12:53:41 by Pechi
   Updated: 15/02/2022 12:59:48 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("frunze.in");
ofstream fout("frunze.out");

int radacina;
bitset<101> nefrunze;
int n;

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    if(x==0)
      radacina = i;
    nefrunze[x] = true;
  }
}

void afisare()
{
  fout<<radacina<<'\n';
  fout<<n-nefrunze.count()+1<<'\n';
  for(int i=1;i<=n;i++)
    if(!nefrunze[i])
      fout<<i<<' ';
}

int main()
{
  citire();
  afisare();
  return 0;
}
