/*
   distanta_de_editare.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 12:58:07 by Pechi
   Updated: 21/02/2022 13:46:04 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

void resize_dp(int a,int b)
{
  dp.resize(a);
  for(int linie=0;linie<a;linie++)
    dp[linie].resize(b);
}

void afisare_dp(string a,string b)
{
  for(int i=0;i<=b.size();i++){
    for(int j=0;j<=a.size();j++)
      cout<<dp[i][j]<<' ';
    cout<<'\n';
  }
}

int edit_distance(string a,string b)
{
  for(int j=0;j<=a.size();j++)
    dp[0][j] = j;

  for(int i=1;i<=b.size();i++)
    dp[i][0] = i;


  for(int i=1;i<=b.size();i++)
    for(int j=1;j<=a.size();j++)
      if(b[i-1] == a[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;


  return dp[b.size()][a.size()];
}

int main()
{
  string a,b;
  cin>>a>>b;
  resize_dp(b.size()+1,a.size()+1);

  int sol = edit_distance(a,b);
  //afisare_dp(a,b);
  cout<<sol;
  return 0;
}
