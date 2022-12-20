/*
   b.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 22/02/2022 16:51:34 by Pechi
   Updated: 22/02/2022 17:06:11 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

int n,cnt;
vector<int> sol;

void afisare()
{
  for(auto el:sol)
    cout<<el<<' ';
  cout<<'\n';
  cnt++;
}

bool ok(int x)
{
  if(x>=2 && (sol[x] == sol[x-1] + sol[x-2]))
    return false;
  for(int i=0;i<x;i++)
    if(sol[i] == sol[x])
      return false;
  return true;
}

void back(int k)
{
  if(k==n)
    afisare();
  else
    for(int i=1;i<=n;i++)
    {
      sol[k] = i;
      if(ok(k) && cnt<n)
        back(k+1);
    }
}

void testcase()
{
  cnt = 0;
  sol.clear();
  cin>>n;
  sol.resize(n);
  back(0);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
    testcase();
}
