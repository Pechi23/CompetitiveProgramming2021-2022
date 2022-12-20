/*
   cuvinte8.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 13:54:42 by Pechi
   Updated: 21/02/2022 14:15:42 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("cuvinte8.in");
ofstream fout("cuvinte8.out");

int n,k;
vector<vector<int>> dp;
string model;
int lungime_model;

void resize_dp(int a,int b)
{
  dp.resize(a+1);
  for(int i=0;i<=a;i++)
    dp[i].resize(b+1);
}

void afisare_dp()
{
  for(int i=0;i<dp.size();i++){
    for(auto el:dp[i])
      cout<<el<<' ';
    cout<<'\n';
  }
  cout<<'\n';
}

void testcase()
{
  dp.clear();
  string sir;
  int lungime_sir;
  fin>>lungime_sir>>sir;
  if(abs(lungime_model-lungime_sir)>k)
  {
    cout<<0<<'\n';
    return;
  }
  resize_dp(lungime_model,lungime_sir);

  for(int i=0;i<=lungime_model;i++)
    dp[i][0] = i;
  for(int j=1;j<=lungime_sir;j++)
    dp[0][j] = j;

  for(int i=1;i<=lungime_model;i++)
    for(int j=1;j<=lungime_sir;j++)
      if(model[i-1] == sir[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;

  if(dp[lungime_model][lungime_sir]<=k)
    fout<<'1'<<'\n';
  else
    fout<<'0'<<'\n';
  //afisare_dp();
  free(dp[1][1]);
}

void citire()
{
  fin>>n>>k;
  fin>>lungime_model>>model;
  while(n--)
    testcase();
}
int main()
{
  citire();
  return 0;
}
