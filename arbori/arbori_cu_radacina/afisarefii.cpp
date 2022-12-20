/*
   afisarefii.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 12:45:36 by Pechi
   Updated: 15/02/2022 12:51:54 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");

vector<vector<int>> listafii;
int n;

void testcase(int rad)
{
  fout<<listafii[rad].size()<<' ';
  for(auto el:listafii[rad])
    fout<<el<<' ';
  fout<<'\n';
}

void citire()
{
  fin>>n;
  listafii.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    fin>>x;
    listafii[x].push_back(i);
  }
  int tests;
  fin>>tests;
  for(int i=1;i<=tests;i++)
  {
    int radacina;
    fin>>radacina;
    testcase(radacina);
  }

}
int main()
{
  citire();
  return 0;
}
