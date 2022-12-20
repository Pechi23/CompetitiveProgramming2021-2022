#include<bits/stdc++.h>
using namespace std;

ifstream fin("lacusta.in");
ofstream fout("lacusta.out");
int n,m;
vector<vector<int>> mat,suma;
const int inf = 0x3f3f3f3f;

void citire_mat()
{
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      fin>>mat[i][j];
}

void afisare_mat(vector<vector<int>> x)
{
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      cout<<x[i][j]<<' ';
    cout<<'\n';
  }
}

void solve()
{
  //prima linie
  for(int j=2;j<=m;j++)
    suma[1][j] = mat[1][1] + mat[1][j];
  //linia a doua
  for(int j=2;j<=m;j++)
    suma[2][j] = suma[1][j] + mat[2][j];
  suma[2][1] = inf;
  //restul liniilor pana la ultima
  for(int i=3;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      int minn = inf;
      for(int k=1;k<=m;k++)
      {
        if(k!=j && suma[i-1][k]<minn)
        {
          minn = suma[i-1][k];
        }
        else
          continue;
      }
      suma[i][j] = minn + mat[i-1][j] + mat[i][j];
    }
  }
  //ultima linie (rezultatul e minimul de pe ultima linie + ultimul element de pe ultima linie)
  int minn = inf;
  for(int j=1;j<m;j++)
    minn = min(suma[n][j],minn);

  suma[n][m] = minn+mat[n][m];

  fout<<suma[n][m];
}

int main()
{
  fin>>n>>m;
  mat.resize(n+1);
  for(auto &i:mat)
    i.resize(m+1);
  suma = mat;

  citire_mat();
  solve();
  //afisare_mat(suma);
  return 0;
}
