/*
   sumtri1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 19:24:22 by Pechi
   Updated: 10/02/2022 19:49:03 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("sumtri1.in");
ofstream fout("sumtri1.out");

int a[105][105],dp[105][105];
const int inf = 0x3f3f3f3f;
int n;

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      fin>>a[i][j];
}

void reconstituire(int i,int j)
{
  if(!i || !j)
    return;
  if(dp[i-1][j]<dp[i-1][j-1])
    reconstituire(i-1,j);
  else
    reconstituire(i-1,j-1);
  fout<<a[i][j]<<' ';
}

void bordare_mat()
{
  for(int i=0;i<=n;i++)
    a[i][0] = dp[i][0] = inf;
  for(int i=0;i<=n;i++)
    a[i][i+1] = dp[i][i+1] = inf;
}

void solve()
{
  //construirea solutiei
  dp[1][1] = a[1][1];
  bordare_mat();
  for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
        dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + a[i][j];

  //minimul de pe ultima linie si pe ce pozitie se afla
  int minim = dp[n][1],imin=n,jmin=1;
  for(int j=2;j<=n;j++)
    if(dp[n][j]<minim)
    {
      minim = dp[n][j];
      jmin = j;
    }

  //afisare
  fout<<minim<<'\n';
  reconstituire(imin,jmin);
}

int main()
{
  citire();
  solve();
  return 0;
}
