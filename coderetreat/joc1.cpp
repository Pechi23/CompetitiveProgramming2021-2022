/*
   joc1.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 26/02/2022 10:46:12 by Pechi
   Updated: 26/02/2022 11:26:19 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("data.in");

set<pair<int,int>> alive_cells;

int dx = {-1,-1,-1,0,1,1,1};
int dy = {-1, 0, 1,1,1,0,-1};

int verif_vecini(int x,int y)
{
  int cnt = 0;
  for(int i=0;i<8;i++)
  {
    int x_vecin = pairs.first + dx[i];
    int y_vecin = pairs.second + dy[i];
    if(alive_cells.find(x_vecin,y_vecin)!= alive_cells.end());
      cnt++;
  }
  return cnt;
}

int main()
{
  while(fin>>x>>y)
    alive_cells.emplace(x,y);

  for(auto pairs:alive_cells)
  {
    int x = pairs.first;
    int y = pairs.second;
    int counter = verif_vecini(x,y);
    if(counter ==2 || counter==3)
      next_alive_cells.emplace(x,y);
    for(int i=0;i<8;i++)
    {
      int x_vecin = x+ dx[i];
      int y_vecin = y+ dy[i];
      int counter_vecin = verif_vecini(x_vecin,y_vecin);
      if(coun)
    }

  }
}
