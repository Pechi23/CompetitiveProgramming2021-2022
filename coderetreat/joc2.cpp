/*
   joc2.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 26/02/2022 11:42:59 by Pechi
   Updated: 26/02/2022 12:28:04 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("data.in");

set<pair<int,int>> celule_vii,urmatoarele_celule_vii;
int states;
int dx[] = {-1,-1,-1,0,1,1, 1, 0};
int dy[] = {-1,0,  1,1,1,0,-1,-1};

void citire()
{
  fin>>states;
  int x, y;
  while(fin>>x>>y)
  {
    celule_vii.emplace(x,y);
  }
}

int veciniAlive(int x,int y)
{
  int cnt=0;
  for(int i=0;i<8;i++)
    {
      int xVecin = x + dx[i];
      int yVecin = y + dy[i];

      if (celule_vii.find({xVecin,yVecin})!=celule_vii.end()) {
        cnt ++;
      }
    }
  return cnt;
}

void generatie()
{
  for(auto coord:celule_vii)
  {
    int x = coord.first;
    int y = coord.second;
    int vecini_vii = veciniAlive(x,y);
    if(vecini_vii==2 || vecini_vii==3)
      urmatoarele_celule_vii.emplace(x,y);
    for(int i=0;i<8;i++)
    {
      int xVecin = x + dx[i];
      int yVecin = y + dy[i];
      int vecini_vii_vecin = veciniAlive(xVecin,yVecin);
      if (vecini_vii_vecin==3)
        urmatoarele_celule_vii.emplace(xVecin,yVecin);
    }
  }
  celule_vii.clear();
  celule_vii = urmatoarele_celule_vii;
  urmatoarele_celule_vii.clear();
}

void afisare(int generatie)
{
  int xmax = INT_MIN, ymax = INT_MIN;
  int xmin = INT_MAX, ymax = INT_MAX;
  cout<<"generatia "<<generatie<<'\n';
  for(auto coord:celule_vii)
  {
    xmax = max(xmax,coord.first);
    ymax = max(ymax,coord.first);
    xmin = min(xmin,coord.first);
    ymin = min(ymin,coord.first);
  }

  for(int i=xmin;i<=xmax;i++)
    for(int j=ymin;j<=ymax;j++)
    {
      if()
    }

}

int main()
{
  citire();
  for(int i=1;i<=states;i++){
    generatie();
    afisare(i);
  }
  return 0;
}
