/*
   kmax.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 15:40:34 by Pechi
   Updated: 27/02/2022 15:45:10 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> numere;
int n,k;
long long suma;

void citire()
{
  cin>>n;
  numere.resize(n);
  for(int i=0;i<n;i++)
    cin>>numere[i];
  cin>>k;
}

void solve()
{
  sort(numere.begin(),numere.end());
  int i;
  for(i=0;i<k && i<n;i++)
  {
    suma -= numere[i];
  }
  for(int j=i;j<n;j++)
    suma +=numere[j];
  cout<<suma;
}

int main()
{
  citire();
  solve();
  return 0;
}
