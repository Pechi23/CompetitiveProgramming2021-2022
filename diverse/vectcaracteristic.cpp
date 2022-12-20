#include<bits/stdc++.h>
using namespace std;

int vizitat[1000001];
int maxim = INT_MIN,x,poz1,poz2,n;

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(vizitat[x])
    {
      int diferenta = i - vizitat[x];
      if(diferenta>maxim)
      {
        maxim = diferenta;
        poz1 =  vizitat[x];
        poz2 = i;
      }
    }
    else
      vizitat[x]=i;
  }
  cout<<poz1<<' '<<poz2;
  return 0;
}
