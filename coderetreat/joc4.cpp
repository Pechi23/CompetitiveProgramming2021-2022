#include<bits/stdc++.h>
using namespace std;
ifstream fin("data.in");

struct element{
  int x,y,z;
}
set<element> celule_vii,urmatoarele_celule_vii;
int dx[] = {-1,-1,-1,0,1,1, 1, 0};
int dy[] = {-1, 0, 1,1,1,0,-1,-1};
int generatii;

void citire()
{
  fin>>generatii;
  int x,y,z;
  while(fin>>x>>y>>z)
  {
    set.emplace(x,y,z);
  }
}

int determinare_nr_vecini_vii(int x,int y)
{
  int cnt_red = 0,cnt_green = 0, cnt_blue=0;
  for(int i=0;i<8;i++)
  {
    int xvecin = x+dx[i];
    int yvecin = y+dy[i];
    if(celule_vii.find({xvecin,yvecin,1})!= celule_vii.end())
    {
      cnt_red++;
    }
    if(celule_vii.find({xvecin,yvecin,2})!= celule_vii.end())
    {
      cnt_blue++;
    }
    if(celule_vii.find({xvecin,yvecin,3})!= celule_vii.end())
    {
      cnt_green++;
    }
  }
  return cnt;
}

void generatie()
{
  for(auto perechi:celule_vii)
  {
    int x = perechi.first;
    int y = perechi.second;
    int nr_vecini_vii = determinare_nr_vecini_vii(x,y);
    if(nr_vecini_vii==2 || nr_vecini_vii==3)
      urmatoarele_celule_vii.emplace(x,y);
    for(int i=0;i<8;i++)
    {
      int xvecin = x + dx[i];
      int yvecin = y + dy[i];
      int nr_vecini_vii_vecin = determinare_nr_vecini_vii(xvecin,yvecin);
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
  citire();
  for(int i=1;i<=generatii;i++){
    generatie();
    afisare(i);
  }
  return 0;
}
