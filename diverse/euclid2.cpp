#include<bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
  while(b)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}


void solve_test()
{
  int a,b;
  fin>>a>>b;
  fout<<cmmdc(a,b)<<'\n';
}

int main()
{
  int t;
  fin>>t;
  while(t--)
    solve_test();
  return 0;
}
