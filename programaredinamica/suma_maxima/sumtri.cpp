/*
   sumtri.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 19:07:19 by Pechi
   Updated: 10/02/2022 19:20:25 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("sumtri.in");
ofstream fout("sumtri.out");

long long dp[101][101];
int n,a[101][101];

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      fin>>a[i][j];
}

void solve()
{
  dp[1][1] = a[1][1];
  for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
      dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];

  long long maxim = 0;
  for(int j=1;j<=n;j++)
    maxim = max(maxim,dp[n][j]);

  fout<<maxim;
}

int main()
{
  citire();
  solve();
  return 0;
}
