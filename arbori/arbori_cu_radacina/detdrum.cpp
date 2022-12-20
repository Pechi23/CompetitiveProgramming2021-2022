/*
   detdrum.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 16/02/2022 09:28:36 by Pechi
   Updated: 16/02/2022 09:34:27 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

ifstream fin("detdrum.in");
ofstream fout("detdrum.out");

int n,k;
vector<int> tata;

void citire()
{
  fin>>n>>k;
  tata.resize(n+1);
  for(int i=1;i<=n;i++)
    fin>>tata[i];
}

void reconstituire_drum(int nodcurent)
{
  fout<<nodcurent<<' ';
  if(tata[nodcurent])
    reconstituire_drum(tata[nodcurent]);
}

int main()
{
  citire();
  reconstituire_drum(k);
  return 0;
}
