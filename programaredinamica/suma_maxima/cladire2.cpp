#include<bits/stdc++.h>

using namespace std;
ifstream fin("cladire2.in");
ofstream fout("cladire2.out");

int n,m;
vector<vector<int>> a,dp;

void citire()
{
  fin>>n>>m;
  a.resize(n+1);
  for(int i=0;i<a.size();i++)
    a[i].resize(m+1);
  dp = a;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      fin>>a[i][j];
}

void afisare_mat(vector<vector<int>> x)
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      cout<<x[i][j]<<' ';
    cout<<'\n';
  }
}

void solve()
{
  dp[1][1] = a[1][1];
  for(int j=2;j<=m;j++)
    dp[1][j] = dp[1][j-1] + a[1][j];
  for(int i=2;i<=n;i++)
    dp[i][1] = dp[i-1][1] + a[i][1];

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];

  fout<<dp[n][m]<<'\n';
  fout<<1<<' '<<1<<'\n';
}

void drum(int i,int j) //pornim din solutie catre dp[1][1]
{
  if(i != 1 || j != 1)
  {
    if(dp[i-1][j]>dp[i][j-1])
      drum(i-1,j);
    else
      drum(i,j-1);

    fout<<i<<' '<<j<<'\n';  //recursia drumului
  }
}

int main()
{
  citire();
  solve();
  drum(n,m);
  //afisare_mat(dp);
  return 0;
}
