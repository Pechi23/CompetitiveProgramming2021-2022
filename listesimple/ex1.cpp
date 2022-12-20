#include<bits/stdc++.h>
using namespace std;
ifstream fin("sortare.in");
ofstream fout("sortare.out");

set<long long ,greater<long long>> heap;
int fr[101];
long long x,y;
int main()
{
  fin>>y;
  while(fin>>x)
  {
    fr[x]++;
    heap.emplace(x);
  }
  for(auto i:heap)
    for(int j=1;j<=fr[i];j++)
      cout<<i<<' ';


}
