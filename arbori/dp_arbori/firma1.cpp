/*
   firma1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 21/02/2022 19:38:35 by Pechi
   Updated: 21/02/2022 20:02:41 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("firma1.in");
ofstream fout("firma1.out");

vector<vector<int>> adj;
vector<int> salariu,dp;
bitset<101> vizitat;
int n;

void citire()
{
  fin>>n;
  adj.resize(n+1);
  salariu.resize(n+1);
  dp.resize(n+1);
  for(int i=1;i<=n;i++)
  {
    int tata;
    fin>>tata;
    adj[tata].push_back(i);
  }
  for(int i=1;i<=n;i++)
    fin>>salariu[i];
}

void dfs(int nod)
{
  int vecini_vizitati = 0;
  for(auto vecin:adj[nod])
  {
    vecini_vizitati++;
    dfs(vecin);
    dp[nod] += dp[vecin];
    if(vecini_vizitati == adj[nod].size())//daca avem suma tuturor fiilor
      dp[nod] = ceil( 1.0 * dp[nod] / vecini_vizitati) + salariu[nod]; // impartim suma la nr de fii si adunam salariul,
      // ceil() = aproximare prin adaos
  }
  if(!vecini_vizitati) //daca e frunza salariul nu are bonusuri
    dp[nod] = salariu[nod];
}

int main()
{
  citire();
  dfs(0);
  fout<<dp[0];//radacina 0 are aceeasi valoare cu dp[directorgenral]/1 ,
  //adica putem afisa direct dp[0], fara a retine radacina
  return 0;
}
