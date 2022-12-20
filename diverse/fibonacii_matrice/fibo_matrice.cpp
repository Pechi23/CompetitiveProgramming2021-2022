#include<bits/stdc++.h>

using namespace std;

const unsigned int mod = 666013;

void produs(long long p[][2],long long a[][2],long long b[][2])//functie ce face produsul a doua matrice modulo
{
  p[0][0] = (1LL * a[0][0] * b[0][0] + 1LL * a[0][1] * b[1][0]) % mod;
  p[0][1] = (1LL * a[0][0] * b[0][1] + 1LL * a[0][1] * b[1][1]) % mod;
  p[1][0] = (1LL * a[1][0] * b[0][0] + 1LL * a[1][1] * b[1][0]) % mod;
  p[1][1] = (1LL * a[1][0] * b[0][1] + 1LL * a[1][1] * b[1][1]) % mod;
}

void copiere(long long a[][2], long long b[][2]) //functie ce ne ajuta sa copiem matricea b[][] in a[][]
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      a[i][j] = b[i][j];
}

int fibo(int n)
{
  long long a[2][2] = { {1 , 1},
 					    {1 , 0} }; //matricea fibonacci

    long long  p[2][2] = {{1,0}, {0,1}}; //produsul va fi el neutru initial
    long long  b[2][2];

  //exponentiere rapida, practic ridicarea la putere a matricei in timp logaritmic
  while(n>0)
  {
    if(n%2)
    {
      produs(b,a,p);
      copiere(p,b);
    }
    produs(b,a,a);
    copiere(a,b);
    n/=2;
  }
  return p[0][1];
}

int main()
{
  int n;
  cin>>n;
  int sol = fibo(n);
  cout<<sol;
  return 0;
}
