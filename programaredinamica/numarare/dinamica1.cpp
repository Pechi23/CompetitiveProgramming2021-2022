/*
   dinamica1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 23/02/2022 13:42:28 by Pechi
   Updated: 23/02/2022 13:55:51 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> pare,impare;
const int mod = 30103;

int main()
{
  int n;
  cin>>n;
  pare.resize(n+1);
  impare.resize(n+1);

  pare[1] = 4;
  impare[1] = 5;

  /*
  de la 1->9(1 cifra) avem - 4 cifre pare: 2,4,6,8
   				           - 5 cifre impare: 1,3,5,7,9
  (pt 2 cifre) 1.putem adauga o cifra para la o cifra impara selectata pt o singura cifra -> 4*5
  		       2.putem adauga o cifra impara la o cifra para selectata anterior -> 5*4
  =>(pt n cifre) 1.putem adauga o cifra para la un nr ce se termina cu o cifra impara -> 4* impare[n-1]
  		       	 2.putem adauga o cifra impara la un nr ce se termina cu o cifra para -> 5* pare[n-1]
  */

  for(int i=2;i<=n;i++)
  {
    pare[i] = (4*impare[i-1])%mod;
    impare[i] = (5*pare[i-1])%mod;
  }

  cout<<(pare[n]+impare[n])%mod; //rezultaul e nr total de nr ce se termina cu cifre pare sau impare
  return 0;
}
