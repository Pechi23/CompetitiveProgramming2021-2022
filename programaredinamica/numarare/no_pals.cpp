/*
   no_pals.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 11:31:18 by Pechi
   Updated: 30/01/2022 11:46:34 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("no_pals.in");
ofstream fout("no_pals.out");

const int mod = 666013;

int exponentiererapida(int a,int b)
{
  int rez = 1;
  while(b>0)
  {
    if(b%2)
      rez = (1LL* rez* a)%mod;
    a=(1LL * a*a)%mod;
    b/=2;
  }
  return rez%mod;
}
int main()
{
  int n;
  fin>>n;

  //primele 2 cazuri sunt particulare
  fout<<0<<'\n';
  int nepal=90;
  int pal = 9;
  fout<<nepal-pal<<'\n';

  for(int i=3;i<=n;i++)
  {
    nepal=(nepal*10)%mod;
    pal=(pal*10)%mod;
    if(nepal-pal)
      fout<<nepal-pal;
    else
      fout<<nepal - pal + mod;
    fout<<'\n';
  }
  return 0;
}
