/*
   puterelogn.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/01/2022 23:21:59 by Pechi
   Updated: 27/01/2022 23:26:57 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

const unsigned int mod = 1000007;

int putere(int n,int p)
{
  long long rez=1;
  while(p)
  {
    if(p%2)
      rez = (rez * n)%mod;
    n = (n* n)%mod;
    p/=2;
  }
  return rez;
}

int main()
{
  cout<<putere(10,8543);
  return 0;
}
