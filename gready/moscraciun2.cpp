/*
   moscraciun2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 28/02/2022 08:35:07 by Pechi
   Updated: 28/02/2022 08:44:00 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > cadouri;
int n,m,p,c;
int nr_cadouri=0;

void citire()
{
  cin>>n>>m;
  while(m--)
  {
    cin>>p>>c;
    nr_cadouri+= c;
    cadouri.emplace(p,c);
  }
}

void solve()
{
  int suma_necesara = 0;
  if(nr_cadouri<n){
    cout<<"imposibil";
    return;
  }else
  {  
    nr_cadouri = 0;
    while(nr_cadouri<n)
    {
      pair<int,int> extras = *(cadouri.begin());
      cadouri.erase(cadouri.begin());

      int pret = extras.first;
      int cantitate = extras.second;

      while(cantitate && nr_cadouri<n)
      {
        cantitate --;
        nr_cadouri++;
        suma_necesara+= pret;
      }
    }
  }
  cout<<suma_necesara;
}

int main()
{
  citire();
  solve();
  return 0;
}
