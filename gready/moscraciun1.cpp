/*
   moscraciun1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 15:29:16 by Pechi
   Updated: 27/02/2022 15:35:27 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> pret;
int bani,n;

void citire()
{
  cin>>n>>bani;
  pret.resize(n);
  for(int i=0;i<n;i++)
    cin>>pret[i];
}

solve()
{
  int cnt = 0,suma = 0;
  sort(pret.begin(),pret.end());
  for(int i=0;i<n;i++)
  {
    if(suma + pret[i] <=bani)
    {
      suma += pret[i];
      cnt++;
    }
    else{
      suma+= pret[i];
      break;
    }
  }
  cout<<cnt<<' '<<suma-bani;
}

int main()
{
  citire();
  solve();
}
