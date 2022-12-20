/*
   partitieAB1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 15:02:51 by Pechi
   Updated: 27/02/2022 15:05:35 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,n;
  cin>>n>>a>>b;
  int cnt_a=0,cnt_b=0;
  while(n%b)
  {
    n-=a;
    cnt_a++;
  }
  cnt_b = n/b;
  while(cnt_a--)
    cout<<a<<' ';
  while(cnt_b--)
    cout<<b<<' ';
  return 0;
}
