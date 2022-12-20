/*
   prodmax1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 30/01/2022 15:33:58 by Pechi
   Updated: 30/01/2022 16:31:55 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int minn1=inf,minn2=inf;
int max1=-inf,max2=-inf;


int main()
{
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    if(x>minn2 && x<max2)
      continue;

    if(x<minn1){
      minn2 = minn1;
      minn1 = x;
    }
    else
      if(x<minn2)
        minn2 = x;

    if(x>max1){
      max2 = max1;
      max1 = x;
    }
    else
      if(x>max2)
        max2 = x;
  }

  if(1LL*max1*max2 > 1LL*minn1*minn2)
    cout<<1LL*max1*max2;
  else
    cout<<1LL*minn1*minn2;
  return 0;
}
