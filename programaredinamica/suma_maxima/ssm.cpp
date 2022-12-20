/*
   ssm.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 19/02/2022 15:02:29 by Pechi
   Updated: 19/02/2022 15:17:46 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("ssm.in");
ofstream fout("ssm.out");


int main()
{
  int n,suma=0,bestsum=INT_MIN,inceput,sfarsit,beg;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    if(suma<0){
      suma = x;
      inceput = i;
    }else
      suma += x;

    if(bestsum<suma)
    {
      bestsum = suma;
      sfarsit = i;
      beg = inceput;
    }
  }
  fout<<bestsum<<' '<<beg<<' '<<sfarsit;
  return 0;
}
