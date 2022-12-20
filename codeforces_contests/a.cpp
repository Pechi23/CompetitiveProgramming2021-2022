/*
   a.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/01/2022 16:44:32 by Pechi
   Updated: 27/01/2022 16:53:35 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

void solve_test()
{
  vector<int> a,b;
  int n;
  cin>>n;
  a.resize(n);
  b.resize(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  int maxa = INT_MIN, maxb = INT_MIN;
  for(int i=0;i<n;i++)
  {
    if(b[i]>a[i])
      swap(b[i],a[i]);
    maxa = max(maxa,a[i]);
    maxb = max(maxb,b[i]);
  }
  int sol = maxa*maxb;
  cout<<sol<<'\n';
}

int main()
{
  int t;
  cin>>t;
  while(t--)
    solve_test();
}
