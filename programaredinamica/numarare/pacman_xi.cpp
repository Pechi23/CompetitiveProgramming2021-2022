/*
   pacman_xi.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 08/02/2022 19:27:37 by Pechi
   Updated: 08/02/2022 19:44:02 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("pacman_xi.in");
ofstream fout("pacman_xi.out");

long long dp[41][41];

int main()
{
  int n,m;
  fin>>n>>m;
  //prima linie 1
  for(int j=1;j<=m;j++)
    dp[1][j] = 1;
  //diagonala din dp[1][1] are toate elementele 1
  for(int i=1;i<=n;i++)
    dp[i][i] = 1;

  for(int i=2;i<=n;i++)
    for(int j=i;j<=m;j++)
      dp[i][j] = dp[i-1][j-1] + dp[i][j-1];

  fout<<dp[n][m];

  return 0;
}
