/*
   niceset2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 19:48:51 by Pechi
   Updated: 27/02/2022 20:33:32 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("niceset.in");
ofstream fout("niceset.out");

bool ok=true;
long long n,suma,cate_1,cate_2;

void citire()
{
  fin>>n>>suma;
  for(int i=0;i<n;i++)
  {
    int x;
    fin>>x;
    if(x!=1 && x!=2)
      return;
    if(x==1)
      cate_1 ++;
    else
      cate_2++;
  }
}


int main()
{
  //citire();
  return 0;
}
