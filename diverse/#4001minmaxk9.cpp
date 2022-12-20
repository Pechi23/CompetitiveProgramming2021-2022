#include<bits/stdc++.h>

using namespace std;


int main()
{
  int x,i=0;
  int pozmax, pozmin, minn = INT_MAX, maxx = INT_MIN;

  int k;
  cin>>k;

  while((cin>>x) && (x!=0))
  {
    if(x<minn && x%10 == k)
    {
      minn = x;
      pozmin = i;
    }
    if(x>maxx && x%10 == k)
    {
      maxx = x;
      pozmax = i;
    }
    i++;
  }
  if(maxx == INT_MIN)
    cout<<"NU EXISTA";
  else
    cout<<abs(pozmin-pozmax)+1;
  return 0;
}
