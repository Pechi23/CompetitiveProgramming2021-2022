#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
  int rezultat = 1;
  while(b>0)
  {
    if(b%2)
      rezultat *= a;
    a *= a;
    b /= 2;
  }
  return rezultat;
}

int main()
{
  int sol = power(10,3);
  cout<<sol;
  return 0;
}
