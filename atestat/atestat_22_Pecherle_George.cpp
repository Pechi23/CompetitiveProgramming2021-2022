/*
   atestat_22_Pecherle_George.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 01/02/2022 10:57:46 by Pechi
   Updated: 01/02/2022 11:09:38 by Pechi
*/
#include<iostream>
#include<fstream>

using namespace std;
ifstream fin("atestat.in");
ofstream fout("atestat.out");

int numarator[10];
int numitor[10];
int n;

int cmmdc(int a,int b) //euclid
{
  while(b)
  {
    int r = a%b;
    a = b;
    b = r;
  }
  return a;
}

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
    fin>>numarator[i]>>numitor[i];
}

void cerinta1()
{
  //afisam toate fractiile pe aceeasi linie
  for(int i=1;i<=n;i++)
    cout<<numarator[i]<<'/'<<numitor[i]<<' ';
  cout<<'\n';
}

void cerinta2()
{
  //determinam numaratorul maxim si il afisam
  int maxim = numarator[1];
  int pozmax; //al cata fractie din setul nostru de fractii are numaratorul maxim
  for(int i=2;i<=n;i++)
    if(numarator[i] > maxim){
      maxim = numarator[i];
      pozmax = i;
    }
  cout<<numarator[pozmax]<<'/'<<numitor[pozmax]<<'\n';
}

void cerinta3()
{
  //afisam in fisierul atestat.out fractiile ireductibile (cmmdc(numarator[i],numitor[i])==1)
  for(int i=1;i<=n;i++)
    if(cmmdc(numarator[i],numitor[i])==1)
      fout<<numarator[i]<<'/'<<numitor[i]<<' ';
}

int main()
{
  //citire
  citire();
  //cerinta 1
  cerinta1();
  //cerinta 2
  cerinta2();
  //cerinta 3
  cerinta3();
  return 0;
}
