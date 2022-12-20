/*
   partitieAB.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 14:57:09 by Pechi
   Updated: 27/02/2022 14:59:51 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,n;
  int cnt_a=0,cnt_b=0;
  cin>>n>>a>>b;
  while(n%a)
  {
    n-=b;
    cnt_b++;
  }
  cnt_a = n/a;
  while(cnt_a--)
  {
    cout<<a<<' ';
  }
  while(cnt_b--)
  {
    cout<<b<<' ';
  }
  return 0;
}
