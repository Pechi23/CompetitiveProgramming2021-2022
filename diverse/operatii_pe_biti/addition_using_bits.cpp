#include<bits/stdc++.h>
using namespace std;

void toBase2(int x)
{
  if(x)
  {
    toBase2(x/2);
    cout<<x%2;
  }
}

void afis(int x)
{
  cout<<'\n';
  toBase2(x);
  cout<<'\n';
}

int main()
{
  int a,b;
  cin>>a>>b;
  int carry;
  do{
    carry = ((a&b)<<1);
    a = a^b;
    b= carry;
  }while(b);
  cout<<a;
  return 0;
}
