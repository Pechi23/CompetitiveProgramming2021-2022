/*
   trepte22.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 11:04:50 by Pechi
   Updated: 30/01/2022 11:25:16 by Pechi
*/
#include <bits/stdc++.h>
using namespace std;

int n,k;
int dp[100001];
const int mod = 9001;

int main()
{
  cin>>n>>k;
  //dp[0] =1;
  dp[1] =1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=k && j<i;j++)
      dp[i] = (dp[i] + dp[i-j])%mod;

  cout << dp[n];
  return 0;
}
