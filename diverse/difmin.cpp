/*
   difmin.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 12/02/2022 11:34:24 by Pechi
   Updated: 12/02/2022 11:49:07 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

struct element{
  int val,dif;
};

vector<element> a;
int n;

void citire()
{
  int x;
  cin>>n;
  a.resize(n+1);
  cin>>x;
  a[1].val = x;
  for(int i=2;i<=n;i++)
  {
    cin>>x;
    a[i].val = x;
    a[i].dif = abs(a[i-1].val-a[i].val);
  }
}

void gasire_min()
{
  int minim = INT_MAX,smin = INT_MAX,primul,al_doilea;
  for(int i=2;i<=n;i++)
    if(a[i].dif < minim)
    {
      primul = a[i-1].val;
      al_doilea = a[i].val;
      minim = a[i].dif;
    }
    else
      if(a[i].dif== minim && (a[i-1].val + a[i].val <smin))
      {
        smin = a[i-1].val  + a[i].val;
        primul = a[i-1].val;
        al_doilea = a[i].val;
      }
  cout<<primul<<' '<<al_doilea;
}

int main()
{
  citire();
  gasire_min();
  return 0;
}
