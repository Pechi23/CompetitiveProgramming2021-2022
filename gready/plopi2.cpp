/*
   plopi2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 28/02/2022 17:23:40 by Pechi
   Updated: 28/02/2022 17:31:52 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("plopi2.in");
ofstream fout("plopi2.out");

vector<int> plopi;
int n;

int main()
{
  int cnt_modif = 0, val_tot_modif=0;
  fin>>n;
  plopi.resize(n+1);
  for(int i=1;i<=n;i++)
    fin>>plopi[i];

  for(int i=2;i<=n;i++)
  {
    if(plopi[i]>plopi[i-1]){
      cnt_modif ++;
      val_tot_modif += plopi[i] - plopi[i-1];
      plopi[i] = plopi[i-1];
    }
  }
  fout<<cnt_modif<<' '<<val_tot_modif;
  return 0;
}
