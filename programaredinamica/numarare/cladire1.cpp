/*
   cladire1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 08/02/2022 20:23:05 by Pechi
   Updated: 08/02/2022 20:36:52 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("cladire1.in");
ofstream fout("cladire1.out");

const unsigned int mod = 9901;
int dp[1001][1001];
bool inchis[1001][1001];
int n,m,k;

void citire()
{
  fin>>n>>m;
  fin>>k;
  while(k--)
  {
    int x,y;
    fin>>x>>y;
    inchis[x][y] = true;
  }
}

void afisare_dp()
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      cout<<dp[i][j]<<' ';
    cout<<'\n';
  }
}

int main()
{
  citire();
  dp[1][1]=1;
  for(int j=1;j<=m && !inchis[1][j];j++)
    dp[1][j] = 1;

  for(int i=2;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(!inchis[i][j])
        dp[i][j] = !inchis[i-1][j] * dp[i-1][j] + !inchis[i][j-1] * dp[i][j-1];
  //afisare_dp();
  fout<<dp[n][m];
  return 0;
}
