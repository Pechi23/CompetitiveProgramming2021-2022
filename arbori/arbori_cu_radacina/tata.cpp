/*
   tata.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 15/02/2022 19:04:55 by Pechi
   Updated: 15/02/2022 19:27:23 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tata,tata_test;
bitset<100001> vizitat;
int n;
bool okk=true;

void citire()
{
  cin>>n;
  adj.resize(n+1);
  tata.resize(n+1);
  tata_test.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int x;
    cin>>x;
    tata_test[i]=x;
    adj[x].push_back(i);
  }
}
void nivelare(int nodcurent)
{
  vizitat[nodcurent] = true;
  for(auto vecin:adj[nodcurent])
    if(!vizitat[vecin])
    {
      tata[vecin] = nodcurent;
      nivelare(vecin);
    }
    else{
      okk = false;
      return;
    }
}

bool ok()
{
  for(int i=1;i<=n;i++)
    if(tata_test[i]!=tata[i])
      return false;
  return true;
}

int main()
{
  citire();
  nivelare(0);
  if(ok() && okk && (vizitat.count()==n+1))
    cout<<"DA";
  else
    cout<<"NU";
  return 0;
}
