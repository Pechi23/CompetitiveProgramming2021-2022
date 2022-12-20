/*
   e.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/01/2022 17:17:16 by Pechi
   Updated: 27/01/2022 17:41:50 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

bitset<200001> colorat;

void solve_test()
{
  vector<int> a;
  int n;
  cin>>n;
  a.resize(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      for(int k=j+1;k<i;k++)
        if(a[i]==a[j] && i>k && j<k)
          colorat[k]=true;
  /*
    for(int i=0;i<n;i++)
      cout<<colorat[i]<<' ';
  */
  cout<<colorat.count()-1;
}

int main()
{
  solve_test();
  return 0;
}
