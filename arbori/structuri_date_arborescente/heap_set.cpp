/*
   heap_set.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 08:28:06 by Pechi
   Updated: 10/02/2022 08:33:31 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("heap.in");
ofstream fout("heap.out");

priority_queue<int> pq;

void test()
{
  int tip;
  fin>>tip;
  if(tip==1)
  {
    int x;
    fin>>x;
    pq.push(x);
  }
  else
  {
      fout<<pq.top()<<'\n';
      pq.pop();
  }
}

void solve()
{
  int tests;
  fin>>tests;
  for(int i=1;i<=tests;i++)
    test();
}

int main()
{
  solve();
  return 0;
}
