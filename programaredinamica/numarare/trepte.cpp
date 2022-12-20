#include<bits/stdc++.h>

using namespace std;

vector<int> dp;
int n;

int main()
{
  cin>>n;
  dp.resize(n+1);
  dp[1] = 1;
  dp[2] = 2;
  for(int i=3;i<=n;i++)
    dp[i] = dp[i-1]+dp[i-2];
  //solutia se afla ca utimul element din sir
  cout<<dp[n];
  return 0;
}
