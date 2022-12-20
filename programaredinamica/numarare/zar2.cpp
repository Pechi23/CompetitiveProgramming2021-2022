/*
   zar2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 19/02/2022 10:18:01 by Pechi
   Updated: 19/02/2022 10:35:14 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

float dp[101][601];
int n,a,b;

float find_probability(int n,int a,int b)
{
  float probabilitate = 0.0;
  //cazul in care avem doar un zar cu probabilitate 1/6
  for(int j=1;j<=6;j++)
    dp[1][j] = 1.0/6;

  for(int i=1;i<=n;i++)//nr de zaruri
  {
    for(int j=i;j<=6*i;j++)//suma valorilor date cu n zaruri
    {
      for(int k=1;k<=6 && k<j;k++)// probabilitatea actuala e suma celor cu un zar in minus la care se aduna valoarea de pe zarul curent[1,6]
      {
        dp[i][j] = dp[i][j] + dp[i-1][j-k]/6;
      }
    }
  }
  //adunam probabilitatile din intervalul care ne convine
  for(int i=a;i<=b;i++)
    probabilitate += dp[n][i];
  return probabilitate;
}

int main()
{
  cin>>n>>a>>b;
  if(a>b)
    swap(a,b);
  float probabilitate = find_probability(n,a,b);
  cout<<fixed<<setprecision(6)<<probabilitate;
  return 0;
}
