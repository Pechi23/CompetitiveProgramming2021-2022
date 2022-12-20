#include <bits/stdc++.h>
#define mod 1999999973

using namespace std;
ifstream fin("lgput.in");
ofstream fout("lgput.out");

int power(long long n,long long p)
{
  long long rezultat = 1;
  while(p)
  {
    if(p%2)
      rezultat = (rezultat %mod * n %mod) %mod;
    n = ((n %mod)*(n %mod)) %mod;
    p/=2;
  }
  return rezultat%mod;
}

int main()
{
  long long n,p;
  fin>>n>>p;
  fout<<power(n,p);

  return 0;
}
