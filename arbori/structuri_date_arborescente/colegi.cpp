#include<bits/stdc++.h>
using namespace std;

map<string,int> mapa;

int main()
{
  //citire
  int n;
  string nume;
  cin>>n;
  while(n--)
  {
    cin>>nume;
    mapa[nume]++;
  }

  //aflarea frecventei maxime si formarea solutiei
  int max_aparitii = 0;
  string sol_nume;
  for(auto pereche:mapa)
   if(pereche.second> max_aparitii)
   {
     max_aparitii = pereche.second;
     sol_nume = pereche.first;
   }

   //afisare
   cout<<sol_nume<<' '<<max_aparitii;
   return 0;
}
