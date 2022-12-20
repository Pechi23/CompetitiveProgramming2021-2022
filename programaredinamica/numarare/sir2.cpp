/*
   sir2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 14:10:30 by Pechi
   Updated: 30/01/2022 14:42:24 by Pechi
*/
#include<bits/stdc++.h>
#define mod 104729
using namespace std;
ifstream fin("sir2.in");
ofstream fout("sir2.out");

int comb[301][301];

int main()
{
  int n,m;
  fin>>n>>m;

  //nr maxim din combinari
  fout<<n-(m-1)<<'\n';

  //nr de posibilitati -> combinari de n-1 luate cate m-1
  //calculam toate combinarile pana la n-1 luate cate m-1 pt a afla nr
  for(int i=0;i<=n;i++){
    comb[i][0] = 1;
    comb[i][i] = 1;
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;

  fout<<comb[n-1][m-1]%mod;
  return 0;
}
