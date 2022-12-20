/*
   bifrunze.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 24/01/2022 19:13:09 by Pechi
   Updated: 25/01/2022 12:26:17 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");

void citire()
{
  int n;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    if(y==0 && z==0)
      fout<<i<<' ';
    }
}

int main()
{
  citire();
}
