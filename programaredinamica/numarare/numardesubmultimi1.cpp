/*
   numardesubmultimi1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 07/02/2022 20:43:15 by Pechi
   Updated: 07/02/2022 21:28:28 by Pechi
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 777013;

ll rez[2][2] ={ {1,0},
                {0,1} };
ll a[2][2] ={ {1,1},
              {1,0} };
ll aux[2][2];

void copiere(ll mat1[][2],ll mat2[][2])
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      mat1[i][j] = mat2[i][j];
}

void inmultire(ll rez[][2],ll mat1[][2],ll mat2[][2])
{
  rez[0][0] = ((1LL * mat1[0][0] * mat2[0][0] )%mod + (1LL * mat1[0][1] * mat2[1][0] )%mod)%mod;
  rez[0][1] = ((1LL * mat1[0][0] * mat2[0][1] )%mod + (1LL * mat1[0][1] * mat2[1][1] )%mod)%mod;
  rez[1][0] = ((1LL * mat1[1][0] * mat2[0][0] )%mod + (1LL * mat1[1][1] * mat2[1][0] )%mod)%mod;
  rez[1][1] = ((1LL * mat1[1][0] * mat2[0][1] )%mod + (1LL * mat1[1][1] * mat2[1][1] )%mod)%mod;
}

void power(ll rez[][2], ll numar)
{
  while(numar)
  {
    if(numar%2)
    {
      inmultire(aux,rez,a);
      copiere(rez,aux);
    }
    inmultire(aux,a,a);
    copiere(a,aux);
    numar/=2;
  }
}

ll fibo(ll termen)
{
  power(rez,termen);
  return rez[0][1]%mod;
}


int main()
{
  ll n;
  cin>>n;
  cout<<(fibo(n+2)-1)%mod;//fibonacci[n+2] -  1
}
