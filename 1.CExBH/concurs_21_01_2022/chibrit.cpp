//pecherle george
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> dp;
vector<int> cifra;
const unsigned int mod = 1000003;

int fix(int cat)
{
  int rezultat = 0;
  for(int i=0;i<10;i++)
  {
    if(!(cat%cifra[i]))
      rezultat++;
  }
  return rezultat;
}

void init()
{
  cifra.resize(10);
  cifra[0] = 6;
  cifra[1] = 2;
  cifra[2] = 5;
  cifra[3] = 5;
  cifra[4] = 4;
  cifra[5] = 5;
  cifra[6] = 6;
  cifra[7] = 3;
  cifra[8] = 7;
  cifra[9] = 6;
}

int main()
{
  init();
  cin>>n;
  dp.resize(n+1);
  for(int i=2;i<=n;i++)
    dp[i] = (dp[i-1] + fix(i))%mod;
  cout<<dp[n];
  return 0;
}
