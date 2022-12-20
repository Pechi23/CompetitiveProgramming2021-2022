/*
   comori.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 11/02/2022 10:16:49 by Pechi
   Updated: 11/02/2022 10:25:17 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("comori.in");
ofstream fout("comori.out");
int n,m;
int a[201][201],dp[201][201];

void citire()
{
  fin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      fin>>a[i][j];
}

void solve()
{
  for(int j=1;j<=m;j++)
    dp[1][j] = a[1][j];
  for(int i=2;i<=n;i++)
    for(int j=1;j<=m;j++)
      dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j],dp[i-1][j+1])) + a[i][j];

  int maxim = 0;
  for(int j=1;j<=m;j++)
    maxim = max(maxim,dp[n][j]);

  fout<<maxim;
}

int main()
{
  citire();
  solve();
  return 0;
}
