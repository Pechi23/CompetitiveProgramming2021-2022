/*
   the_most_wanted_prime.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/01/2022 20:26:27 by Pechi
   Updated: 27/01/2022 20:36:23 by Pechi
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool prim(int x)
{
  if(x<2)
    return false;
  if(!(x%2)&& x!=2)
    return false;
  for(int d=3;d*d<=x;d+=2)
    if(!(x%d))
      return false;
  return true;
}


int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i+=2)
  {
    ll numar = 1;
    int putere = 10;
    for(int j=1;j<=i;j++)
    {
      if(j/putere)
        putere*=10;
      numar = numar * putere + j;
    }
    for(int j=i;j>=1;j--)
    {
      numar = numar*10 + j;
    }
    cout<<numar;
  }
  return 0;
}
