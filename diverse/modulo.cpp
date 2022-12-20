#include<bits/stdc++.h>
using namespace std;
long long a,b;
//int float double
unsigned long long mod = 10;

int main()
{
  cin>>a>>b;
  //adunare a + b
  int rez1 = (a % mod + b % mod)%mod;
  cout<<"adunare:"<<rez1<<' ';
  //scadere
  int rez2 = (a%mod - b%mod + mod) % mod;
  cout<<rez2<<' ';
  //inmultire
  int rez3 = (a%mod * b%mod) % mod;
  cout<<rez3<<' ';
  //impartire
  //...
//  inv[i]= −(mod / i) * inv(mod % i) % mod;
//  cout<<mod<<' ';


  return 0;
}
