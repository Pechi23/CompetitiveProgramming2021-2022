#include<bits/stdc++.h>
using namespace std;

struct tuplee{
  int first,second,third;
};

vector<tuplee> distante = {{3,4,3},{5,3,7},{64,6,6}};

int main()
{
  for(auto el:distante)
    cout<<el.first<<' '<<el.second<<' '<<el.third<<'\n';
  return 0;
}
