#include<bits/stdc++.h>

using namespace std;

const unsigned int mod = 9901;
int n,k;
vector<int> dp;

int main()
{
  cin>>n>>k;
  dp.resize(n+1);
  dp[1] = dp[2] = 1;
  for(int i=3;i<=k;i++)
    dp[i] = (dp[i-1] * 2)% mod;
  for(int i=k+1;i<=n;i++)
    dp[i] = (dp[i-1]* 2 - dp[i-k-1]+ mod)%mod;
  cout<<dp[n];
  return 0;
}
