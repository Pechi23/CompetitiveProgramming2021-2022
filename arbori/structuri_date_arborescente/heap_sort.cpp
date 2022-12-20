/*
   heap_sort.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 10/02/2022 08:35:07 by Pechi
   Updated: 10/02/2022 08:50:00 by Pechi
*/
#include<bits/stdc++.h>

using namespace std;
ifstream fin("heap_sort.in");
ofstream fout("heap_sort.out");

vector<int> date;
int n;


void citire()
{
  int x,n;
  fin>>n;
  for(int i=1;i<=n;i++)
  {
    fin>>x;
    date.push_back(x);
  }
}

void afisare()
{
  sort(date.begin(),date.end());
  for(auto el:date)
    fout<<el<<' ';
}

int main()
{
  citire();
  afisare();
  return 0;
}
