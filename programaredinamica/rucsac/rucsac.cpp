#include<bits/stdc++.h>

using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int n,gmax;
vector<int> linie1,linie2;

int main()
{
  //citire
  fin>>n>>gmax;
  linie1.resize(gmax+1);
  linie2.resize(gmax+1);

  for(int i=1;i<=n;i++)
  {
    int pret,greutate;
    fin>>greutate>>pret;
    for(int cap=1;cap<=gmax; cap++)
    {
      linie2[cap] = linie1[cap];

      if(cap - greutate >= 0)
        linie2[cap] = max(linie2[cap], linie1[cap-greutate] + pret);

    }
    linie1 = linie2; //trecem pe linia urmatoare asa ca linia curenta se transforma in anterioara
  }

  //determinarea maximului de pe ultima linie (solutia)
  int sol = 0;
  for(auto el:linie1)
    sol = max(sol,el);

  fout<<sol;
  return 0;
}
