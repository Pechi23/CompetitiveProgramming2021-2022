#include<bits/stdc++.h>
using namespace std;
ifstream fin("data.in");
int generatii;
set<pair<int,int>> celule_vii,urmatoarele_celule_vii;

int dx[] ={-1,-1,-1,0,1,1,1, 0};
int dy[] ={-1, 0, 1,1,1,0,-1, 1};

void citire()
{
  fin>>generatii;
  int x,y;
  while(fin>>x>>y)
    celule_vii.emplace(x,y);
}

bool viu(int x,int y)
{
  if(celule_vii.find({x,y})!= celule_vii.end())
    return true;
  return false;
}

int nr_vecini_vii(int x,int y)
{
  int cnt = 0;
  for(int i=0;i<8;i++){
    int xvecin = x + dx[i];
    int yvecin = y + dy[i];
    cnt = cnt + viu(xvecin,yvecin); }
  return cnt;
}

void viu_sau_nu(int x,int y,int nrvecini)
{
  if(nrvecini ==2 || nrvecini==3)
    urmatoarele_celule_vii.emplace(x,y);
}

void viu_sau_nu_2(int x,int y, int nrvecini)
{
  if(nrvecini==3)
    urmatoarele_celule_vii.emplace(x,y);
}

void parcurgere_celule_vii()
{
  for(auto coord:celule_vii){
    int nrvecini = nr_vecini_vii(coord.first,coord.second);
    cout<<nrvecini<<'\n';
    viu_sau_nu(coord.first,coord.second,nrvecini);
  }
}

void stare_vecini_celula_vie(int x,int y)
{
  for(int i=0;i<8;i++){
    int contor_nr_vecini = nr_vecini_vii(x+dx[i],y+dy[i]);
    viu_sau_nu_2(x+dx[i],y+dy[i],contor_nr_vecini);
  }
}

void parcurgere_celule_moarte()
{
  for(auto coord:celule_vii)
    stare_vecini_celula_vie(coord.first,coord.second);
}

int main()
{
  citire();
  parcurgere_celule_vii();
  parcurgere_celule_moarte();
  //for(auto perechi:urmatoarele_celule_vii)
  //  cout<<perechi.first<<' '<<perechi.second<<'\n';
  return 0;
}
