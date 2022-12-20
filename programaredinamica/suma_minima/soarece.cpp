#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mat;
int n,m,istart,jstart,idest,jdest;
queue <pair<int,int>> coada;
vector<vector<int>> vizitat;

int di[4] = {0,1, 0,-1};
int dj[4] = {1,0,-1, 0};

void citire()
{
  cin>>n>>m;
  mat.resize(n+2);
  for(int i=0;i<=n+1;i++)
    mat[i].resize(m+2);
  vizitat = mat;
  //bordam marginile matricei
  for(int j=0;j<=m+1;j++)
    mat[0][j] = mat[n+1][j] = -1;
  for(int i=0;i<=n+1;i++)
    mat[i][0] = mat[i][m+1] = -1;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
      if(mat[i][j]==1)
        mat[i][j] = -1;
    }
  cin>>istart>>jstart;
  cin>>idest>>jdest;
}

void afisare_matrice()
{
  for(int i=0;i<=n+1;i++){
    for(int j=0;j<=m+1;j++)
      cout<<mat[i][j]<<' ';
    cout<<'\n';
  }
}

int suma_vecini(int i,int j)
{
  int sum = 0;
  for(int e=0;e<4;e++)
  {
    int ivecin = i + di[i];
    int jvecin = j + dj[i];
    if(mat[ivecin][jvecin]>0)
      sum += mat[ivecin][jvecin];
  }
  return sum;
}

bool in_matrice(int i,int j)
{
  if(i>0 && i<=n && j>0 && j<=m && mat[i][j]!= -1)
    return true;
  return false;
}

void formare_matrice()
{
  mat[istart][jstart] = 1;
  coada.push(make_pair(istart,jstart));

  while(!coada.empty())
  {
    pair<int,int> element = coada.front();
    coada.pop();
    vizitat[element.first][element.second] = 1;

    mat[element.first][element.second] = suma_vecini(element.first,element.second);
    cout<<element.first<<' '<<element.second<<'\n';
    for(int i=0;i<4;i++)
    {
      int ivecin = element.first  + di[i];
      int jvecin = element.second + dj[i];

      if(in_matrice(ivecin,jvecin) && !vizitat[ivecin][jvecin]);
        coada.push({ivecin,jvecin});
    }
  }

}



int main()
{
  citire();
  formare_matrice();
  afisare_matrice();
  return 0;
}
