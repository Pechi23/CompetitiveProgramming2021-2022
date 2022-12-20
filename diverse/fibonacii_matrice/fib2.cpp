#include<bits/stdc++.h>

using namespace std;
ifstream fin("kfib.in");
ofstream fout("kfib.out");

const int mod = 666013;

void produs(int p[][2], int a[][2], int b[][2]) //produsul matricelor a[][] si b[][] retinut in p[][]
{
  p[0][0] = ((1LL * a[0][0] * b[0][0])%mod + (1LL * a[0][1] * b[1][0])%mod ) %mod;
  p[0][1] = ((1LL * a[0][0] * b[0][1])%mod + (1LL * a[0][1] * b[1][1])%mod ) %mod;
  p[1][0] = ((1LL * a[1][0] * b[0][0])%mod + (1LL * a[1][1] * b[1][0])%mod ) %mod;
  p[1][1] = ((1LL * a[1][0] * b[0][1])%mod + (1LL * a[1][1] * b[1][1])%mod ) %mod;
}

void copiere(int a[][2],int b[][2]) //copiaza matricea b[][] in a[][]
{
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      a[i][j] = b[i][j];
}

int fibo(int n)
{
  int a[2][2] = { {1, 1},
                  {1, 0} }; //matricea lui fibonacci (geniala)
  int p[2][2] = { {1, 0},
                  {0, 1} }; //produsul este neutru initial pentru a nu influenta termenii fibo pt termeni mici
  int b[2][2];

  //functie ce se foloseste de ridicarea la putere exponentiala O(log n)
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
  return p[0][1]; //al n-ulea termen fibonacci
}

int main()
{
  int n;
  fin>>n;
  fout<< fibo(n);
  return 0;
}
