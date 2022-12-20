/*
   aplusb.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 16:06:57 by Pechi
   Updated: 27/02/2022 16:09:14 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("aplusb.in");
ofstream fout("aplusb.out");
int a,b,suma;

void citire()
{
  fin>>a>>b;
}

void solve()
{
  suma = a+b;
}

void afisare()
{
  fout<<suma;
}

int main()
{
  citire();
  solve();
  afisare();
}
