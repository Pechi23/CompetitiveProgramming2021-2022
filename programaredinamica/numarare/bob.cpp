/*
   bob.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 20/02/2022 13:09:19 by Pechi
   Updated: 20/02/2022 13:41:40 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("bob.in");
ofstream fout("bob.out");

const int mod = 1e9 + 7;
int p,t,n,k;
vector<vector<bool>> mat;

void cerinta1()
{
  bitset<21> tipuri;
  tipuri.reset();
  int contor=0;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)
      if(mat[i][j])
        tipuri[j]=true;

    if(tipuri.count()==k-1)
    {
      tipuri.reset();
      contor++;
    }
  }

  cout<<contor<<'\n';

  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++)
      cout<<mat[i][j]<<' ';
    cout<<'\n';
  }
}

void cerinta2()
{
  //soon
  cout<<"sada";
}

void testcase()
{
  fin>>n>>k;
  //for(int i=0;i<=n;i++)
  //  mat[i].clear();
  //pregatim dimensiunile matricei pentru testul curent
  mat.resize(n+1);
  for(int i=0;i<=mat.size();i++)
    mat[i].resize(k+1);

  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    {
      int x;
      fin>>x;
      if(x==1)
        mat[i][j] = true;
    }

  if(p==1)
    cerinta1();
  else
    cerinta2();
}

void citire()
{
  fin>>p>>t;
  while(t--)
    testcase();
}

int main()
{
  citire();
  return 0;
}
