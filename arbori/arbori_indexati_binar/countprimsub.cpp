/*
   countprimsub.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 31/01/2022 12:56:14 by Pechi
   Updated: 31/01/2022 13:09:26 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("countprimsub.in");
ofstream fout("countprimsub.out");

struct nod{
  int info,st,dr;
};
nod noduri[1001];
int n;

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x,y,z;
    fin>>x>>y>>z;
    noduri[i].info = x;
    noduri[i].st = y;
    noduri[i].dr = z;
  }
}

bool prim(int x)
{
  if(x<2)
    return false;
  if(!(x%2) && x!=2 )
    return false;
  for(int d=3;d*d<=x;d+=2)
    if(!(x%d))
      return false;
  return true;
}

void countprim(int rad,int &prime)
{
  if(rad)
  {
    if(prim(noduri[rad].info))
      prime++;
    countprim(noduri[rad].st,prime);
    countprim(noduri[rad].dr,prime);
  }
}

void testcase()
{
  int radacina,prime = 0;
  fin>>radacina;
  countprim(radacina,prime);
  fout<<prime<<'\n';
}

int main()
{
  citire();
  int k;
  fin>>k;
  while(k--)
    testcase();
  return 0;
}
