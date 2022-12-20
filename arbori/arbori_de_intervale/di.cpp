/*
   di.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 24/02/2022 17:17:40 by Pechi
   Updated: 24/02/2022 17:29:09 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("di.in");
ofstream fout("di.out");

int n,queries;
vector<int> sol;

void query(int node,int left,int right,int a,int b)
{
  if(a<=left && right<=b)
  {
    if(a==left)
      sol.push_back(left);
    sol.push_back(right);
  }
  else
  {
    int mid = left + (right-left)/2;
    if(a<=mid)
      query(2*node,left,mid,a,b);
    if(mid<b)
      query(2*node+1,mid+1,right,a,b);
  }
}
int main()
{
  fin>>n>>queries;
  while(queries--)
  {
    int a,b;
    fin>>a>>b;
    query(1,1,n,a,b);
    fout<<sol.size()-1<<' ';
    for(auto el:sol)
      fout<<el<<' ';
    fout<<'\n';
    sol.clear();
  }
  return 0;
}
