/*
   dinamica06.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 07/02/2022 20:06:42 by Pechi
   Updated: 07/02/2022 20:13:42 by Pechi
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 123457;

ll power(ll n,ll p)
{
  ll rez = 1;
  while(p)
  {
    if(p%2)
      rez = (rez * n)%mod;
    n = (n%mod * n%mod) %mod;
    p/=2;
  }
  return rez;
}

int main()
{
  ll n;
  cin>>n;
  cout<<( power(3,n-1) * 2 )%mod;
  return 0;
}
