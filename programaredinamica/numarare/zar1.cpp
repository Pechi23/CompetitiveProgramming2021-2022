/*
   zar1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 19/02/2022 10:39:15 by Pechi
   Updated: 19/02/2022 11:04:59 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

long long z[10];
int main()
{
  int n;
  cin>>n;
  z[0]=1; //putem da 1 cu un singur zar intr-un singur mod
  z[1]=2; // 1 1 sau 2
  for(int i=2;i<6;i++)
    z[i] = z[i-1] + z[i-2];

  for(int i=6;i<10;i++)
    for(int j=1;j<=5;j++)
      z[i] = z[i] + z[i-j];
  cout<<z[3];
}
