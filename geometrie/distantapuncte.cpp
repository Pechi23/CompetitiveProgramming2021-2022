/*
   distantapuncte.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 17:17:40 by Pechi
   Updated: 21/02/2022 17:25:08 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("distantapuncte.in");
ofstream fout("distantapuncte.out");

int power(int a,int b)
{
  if(a<0)
    a*=-1;
  int rez = 1;
  while(b)
  {
    if(b%2)
      rez*=a;
    a*=a;
    b/=2;
  }
  return rez;
}

int main()
{
  int x1,y1,x2,y2;
  fin>>x1>>y1>>x2>>y2;
  int sol = power((x2-x1),2) + power((y2-y1),2);
  fout<<sol;
  return 0;
}
