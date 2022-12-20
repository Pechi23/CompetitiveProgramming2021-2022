/*
   cmlsc.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 19/02/2022 13:30:26 by Pechi
   Updated: 19/02/2022 13:39:34 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector<int> a,b,sol;
int n,m;

void citire()
{
  fin>>n>>m;
  for(int i=1;i<=n;i++){
    int x;
    fin>>x;
    a.push_back(x);
  }
  for(int i=1;i<=m;i++){
    int x;
    fin>>x;
    b.push_back(x);
  }
}

int main()
{
  citire();
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(auto el:a)
  {
    if(binary_search(b.begin(),b.end(),el))
      sol.push_back(el);
  }

  //afisare
  fout<<sol.size()<<'\n';
  for(auto el:sol)
    fout<<el<<' ';
  return 0;
}
