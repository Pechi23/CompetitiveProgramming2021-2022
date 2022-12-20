#include<bits/stdc++.h>

using namespace std;
ifstream fin("cautbin.in");
ofstream fout("cautbin.out");

vector<int> v;
int n;

void solve_test()
{
  int tip,x;
  vector<int>::iterator caut;
  fin>>tip>>x;
  if(!tip)
  {
    caut = upper_bound(v.begin(),v.end(),x);
    int sol = (caut - v.begin());
    if(sol>v.size()-1) //daca nu avem x in vector
      sol = -1;
    fout<<sol<<'\n';
  }
  else
    if(tip==1)
    {
      caut = upper_bound(v.begin(),v.end(),x);
      int sol = (caut - v.begin());
      fout<<sol<<'\n';
    }
    else
    {
      caut = lower_bound(v.begin(),v.end(),x);
      int sol = (caut - v.begin());
      fout<<sol+1<<'\n';
    }
}


void citire()
{
  fin>>n;
  v.resize(n);
  for(int i=0;i<n;i++)
    fin>>v[i];
  int t;
  fin>>t;
  while(t--)
    solve_test();
}

int main()
{
  citire();
  return 0;
}
