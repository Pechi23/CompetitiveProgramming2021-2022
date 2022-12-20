#include<bits/stdc++.h>

using namespace std;

int a,b,n;
vector<int> sol;

void afisare()
{
  for(auto el:sol)
    cout<<el<<' ';
  cout<<'\n';
}

bool ok(int k)
{
  for(int i=0;i<k;i++)
    if(sol[i] == sol[k])
      return false;
  return true;
}

bool solutie(int k)
{
  if(k == n-1)
    return true;
  return false;
}

void back(int k)
{
  for(int i=a;i<=b;i++)
  {
    sol[k] = i;
    if(ok(k))
    {
      if(solutie(k))
        afisare();
      else
        back(k+1);
    }
  }
}

int main()
{
  cin>>a>>b>>n;
  sol.resize(n);
  back(0);
  return 0;
}
