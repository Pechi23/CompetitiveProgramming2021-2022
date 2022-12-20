/*
   biarbore1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 31/01/2022 13:11:36 by Pechi
   Updated: 31/01/2022 14:02:10 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("biarbore1.in");
ofstream fout("biarbore1.out");

void citire_rad_si_fii(int &rad, int &st,int &dr)
{
  int cnt=2,aux;
  fin>>rad>>st;
  if(st==0){
    fin>>dr;
    return;
  }else
  {
    while(cnt){
      fin>>aux;
      if(aux)
        cnt++;
      else
        cnt--;
    }
  }
  fin>>dr;
}

int main()
{
  int rad,st,dr;
  citire_rad_si_fii(rad,st,dr);

  //afisare
  fout<<st<<' '<<dr;
  return 0;
}
