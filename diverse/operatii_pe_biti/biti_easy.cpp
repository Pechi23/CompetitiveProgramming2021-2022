#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isOk(ll n)
{
  ll i = 1, j;
  while(i<n)
  {
    j = i<<1;
    if(n&i && n&j)
      return false;
    i=i<<1;
  }
  return true;
}

void baza2(ll x, int &nr)
{
  if(x)
  {
    baza2(x/2, nr);
    cout<<x%2;
    nr ++;
  }
}

int main()
{
  ll n;
  cin>>n;
  int nr = 0;
  baza2(2e39-1, nr);
  cout<<endl<<nr;
  return 0;
}
