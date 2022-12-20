/*
   trepte2.2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 23/02/2022 13:05:15 by Pechi
   Updated: 23/02/2022 13:14:34 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
vector<short>dp;
const unsigned int mod = 9001;

int main()
{
  int n,k;
  cin>>n>>k;
  dp.resize(n+1);
  dp[1] = dp[2] = 1;
  for(int i=3;i<=k;i++)
    dp[i] = (2*dp[i-1])%mod;
  for(int i=k+1;i<=n;i++)
    dp[i] = (2*dp[i-1] - dp[i-k-1])%mod;
  cout<<dp[n];
}
