/*
   map.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 09:43:05 by Pechi
   Updated: 10/02/2022 09:50:09 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("map.in");
ofstream fout("map.out");

map<int,int> mapa;

void citire()
{
  int x,n;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    fin>>x;
    mapa[x]++;
    cout<<mapa[x]<<' ';
  }
}

int main()
{
  citire();
  return 0;
}
