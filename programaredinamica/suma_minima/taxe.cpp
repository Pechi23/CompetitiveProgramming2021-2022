/*
   taxe.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 11/02/2022 10:29:03 by Pechi
   Updated: 11/02/2022 10:44:28 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("taxe.in");
ofstream fout("taxe.out");

int a[202][201],dp[202][201];
int n,m;
const int inf = 0x3f3f3f3f;

void citire()
{
  fin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      fin>>a[i][j];
}

void bordare_mat()
{
  for(int j=0;j<=m;j++)
    dp[0][j] = dp[n+1][j] = inf;
}

void solve()
{
  bordare_mat();
  for(int i=1;i<=n;i++)
    dp[i][m] = a[i][m];
  for(int j=m-1;j>=1;j--)
    for(int i=1;i<=n;i++)
      dp[i][j] = min(dp[i-1][j+1], min(dp[i][j+1],dp[i+1][j+1])) + a[i][j];
  int minim = dp[1][1];
  for(int i=2;i<=n;i++)
    minim = min(minim, dp[i][1]);

  fout<<minim;
}

int main()
{
  citire();
  solve();
  return 0;
}
