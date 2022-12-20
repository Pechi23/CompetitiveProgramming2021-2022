/*
   a.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 22/02/2022 16:37:34 by Pechi
   Updated: 22/02/2022 16:46:12 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;

bitset<256> litera;

void testcase()
{
  litera.reset();
  string sir;
  cin>>sir;
  for(int i=0;i<sir.size();i++)
  {
    if(sir[i]=='r' || sir[i]=='g' || sir[i]=='b' )
      litera[(int)sir[i]] = true;
    else
      if(sir[i]=='R' || sir[i]=='G' || sir[i]=='B' )
        if(!litera[tolower(sir[i])])
        {
          cout<<"NO"<<'\n';
          return;
        }
  }
  cout<<"YES"<<'\n';
}
int main()
{
  int n;
  cin>>n;
  while(n--)
    testcase();
}
