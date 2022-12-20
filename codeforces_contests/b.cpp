/*
   b.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/01/2022 17:00:44 by Pechi
   Updated: 27/01/2022 17:05:38 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

void solve_test()
{
  map<int,int> mapa;
  vector<int> a;
  int n;
  cin>>n;
  a.resize(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    mapa[a[i]]++;
  };
  cout<<mapa.size()-1<<'\n';
}

int main()
{
  int t;
  cin>>t;
  while(t--)
    solve_test();
  return 0;
}
