/*
   masini.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 27/02/2022 15:07:16 by Pechi
   Updated: 27/02/2022 15:24:00 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("masini.in");
ofstream fout("masini.out");

priority_queue<int,vector<int>,greater<int> > pq;
int timp,n;

void citire()
{
  fin>>n>>timp;
  for(int i=0;i<n;i++)
  {
    int x;
    fin>>x;
    pq.push(x);
  }
}

void solve()
{
  int cnt =0,suma=0;
  while(suma + pq.top() <= timp)
  {
    suma += pq.top();
    pq.pop();
    cnt++;
  }
  fout<<cnt;
}
int main()
{
  citire();
  solve();
}
