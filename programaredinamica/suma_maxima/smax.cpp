/*
   smax.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 11/02/2022 10:51:39 by Pechi
   Updated: 11/02/2022 16:35:49 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("smax.in");
ofstream fout("smax.out");

vector<long long> dp;
int n;

void citire()
{
  fin>>n;
  dp.resize(n+1);
}

void solve()
{
  for(int i=1;i<=n;i++)
  {
    fin>>x;
    dp[i] = max(dp[i-1],dp[i-2]+x);
  }
  fout<<dp[n];
}

int main()
{
  citire();
  solve();
  return 0;
}
