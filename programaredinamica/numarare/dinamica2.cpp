/*
   dinamica2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 08/02/2022 20:45:39 by Pechi
   Updated: 09/02/2022 01:11:24 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
const unsigned int mod = 777013;

int power(int n,int p)
{
  int rez=1;
  while(p)
  {
    if(p%2)
      rez = (1LL * rez * n)%mod;
    n = (1LL * n * n)%mod;
    p/=2;
  }
  return rez%mod;
}

int main()
{
  int n;
  cin>>n;
  if(n<3)
    cout<<power(26,n);
  else
  {
    cout<<(power(26,n)%mod - power(26,n-2)%mod + mod)%mod;
  }
  return 0;
}
