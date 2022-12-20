/*
   alice_xi.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 08/02/2022 20:00:03 by Pechi
   Updated: 08/02/2022 20:20:26 by Pechi
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin("alice_xi.in");
ofstream fout("alice_xi.out");

vector<vector<ll>> dp;

int main()
{
  int i=1,n;
  fin>>n;
  //triunghi dreptunghic
  dp.resize(n+1);
  for(auto &el:dp)
    el.resize(n+1);

  dp[1][1] = 1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
      if(j<i-1)
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
      else
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];

  ll sum =0;

  for(auto el:dp[n])
    sum+=el;

  fout<<sum;
  return 0;
}
