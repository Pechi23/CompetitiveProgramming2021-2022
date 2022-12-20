#include<bits/stdc++.h>
using namespace std;
ifstream fin("data.in");

set<pair<int,int>> celule_vii, urmatoarele_celule_vii;

int dx[] = {-1,-1,-1,0,1,1, 1,0};
int dy[] = {-1, 0, 1,1,1,0,-1,-1};

void citire()
{
  int x,y;
  while(fin>>x>>y)
    celule_vii.emplace(x,y);
}

int det_nr_vecini_vii(int x,int y)
{
  int cnt = 0;
  for(int i=0;i<8;i++)
  {
    int xvecin = x + dx[i];
    int yvecin = y + dy[i];
    if(celule_vii.find({xvecin,yvecin})!=celule_vii.end())
      cnt++;
  }
  return cnt;
}
/*
1 3
2 3
3 3
3 2
2 1
*/

void generatie()
{
  for(auto pereche:celule_vii)
  {
    int x = pereche.first;
    int y = pereche.second;
    int nr_vecini_vii = det_nr_vecini_vii(x,y);
    if(nr_vecini_vii==2 || nr_vecini_vii==3)
      urmatoarele_celule_vii.emplace(x,y);
    for(int i=0;i<8;i++)
    {
      int xvecin = x + dx[i];
      int yvecin = y + dy[i];
      int nr_vecini_vii_vecin = det_nr_vecini_vii(xvecin,yvecin);
      if(nr_vecini_vii_vecin==3)
        urmatoarele_celule_vii.emplace(xvecin,yvecin);
    }
  }
  celule_vii.clear();
  celule_vii = urmatoarele_celule_vii;
  urmatoarele_celule_vii.clear();
}


void afisare(int i)
{
  int xmin = INT_MAX, ymin = INT_MAX;
  int xmax = INT_MIN, ymax = INT_MIN;
  cout<<"generatia "<<i<<'\n';
  for(auto perechi:celule_vii)
  {
    xmin = min(xmin, perechi.first);
    ymin = min(ymin, perechi.second);
    xmax = max(xmax, perechi.first);
    ymax = max(ymax, perechi.second);
  }
  for(int i=xmin;i<=xmax;i++){
    for(int j=ymin;j<=ymax;j++){
      if(celule_vii.find({i,j})!= celule_vii.end())
        cout<<'*'<<' ';
      else
        cout<<'-'<<' ';
      }
    cout<<'\n';
  }
  cout<<'\n';
}

int main()
{
  int i=1;
  citire();
  while(i++){
    generatie();
    afisare(i);
  }
  return 0;
}
