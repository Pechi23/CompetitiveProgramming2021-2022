/*
   atestat9_pecherle_george.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 03/02/2022 09:20:57 by Pechi
   Updated: 03/02/2022 09:41:48 by Pechi
*/
#include<iostream>
#include<fstream>
#include<map>

using namespace std;
ifstream fin("atestat.in");
ofstream fout("atestat.out");

int mat[20][20],n;

void afisare(int x[][20])
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cout<<x[i][j]<<' ';
    cout<<'\n';
  }
}

void citire()
{
  fin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      fin>>mat[i][j];
}

void cerinta1()
{
  afisare(mat);
}

void cerinta2()
{
  int k;
  cin>>k;
  for(int i=1;i<=n;i++)
      mat[i][n-i+1] = k;
  afisare(mat);
}

bool prim(int x)
{
  if(x<2)
    return false;
  if(!(x%2) && x!=2)
    return false;
  for(int d=3;d*d<=x;d+=2)
    if(!(x%d))
      return false;
  return true;
}

void cerinta3()
{
  map<int,int> frecv; //o alternativa este set<int>, care retine nr prime diferite, dar nu si frecventa lor
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(prim(mat[i][j]))//daca elemetul e prim
        frecv[mat[i][j]]++;//frecventa acestui nr prim creste(daca apare prima data il adaugam in mapa)

  if(frecv.empty())//daca nu avem elemente in mapa nu am gasit nici un nr prim
    fout<<"NU";
  else
    for(auto el:frecv) //afisez fiecare nr prim o singura data
      fout<<el.first<<' ';
}

int main()
{
  citire();
  cerinta1();
  cerinta2();
  cerinta3();
  return 0;
}
