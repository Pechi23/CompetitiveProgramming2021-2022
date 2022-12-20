#include<bits/stdc++.h>

using namespace std;
ifstream fin("cladire.in");
ofstream fout("cladire.out");

int n,m;
vector<vector<int>> mat;
const unsigned int mod = 9901;

void afisare()
{
  for(int i=0;i<n;i++){
    for(auto j:mat[i])
      cout<<j<<' ';
    cout<<'\n';
  }
}

void formare_matrice()
{
  mat.resize(n);
  for(int i=0;i<n;i++)
    mat[i].resize(m);

  for(int i=0;i<n;i++)
    mat[i][0] = 1;
  for(int j=0;j<m;j++)
    mat[0][j] = 1;
  for(int i=1;i<n;i++)
    for(int j=1;j<m;j++)
     mat[i][j] = (mat[i-1][j]%mod + mat[i][j-1]%mod ) % mod;
}

int main()
{
  //citire
  fin>>n>>m;
  formare_matrice();
  //afisare
  //rezultatul este elementul de pe linia n-1 coloana m-1 (elementul din dreapta jos a matricei)
  fout<<mat[n-1][m-1];
  //afisare();
  return 0;
}
