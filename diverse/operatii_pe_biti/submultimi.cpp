/*
   submultimi.cpp
   By: Pecherle George Daniel (Pechi)
   Created: 19/02/2022 12:52:30 by Pechi
   Updated: 19/02/2022 13:03:30 by Pechi
*/
#include<bits/stdc++.h>
using namespace std;
ifstream fin("submultimi.in");
ofstream fout("submultimi.out");
int n;
/*
pt n = 3
j        1  2  3
j-1      0  1  2
1<<j-1   1  2  4
         1 10 100
pentru (i=1;i<=7;i++)
  if(i&1) scriem 1
  if(i&2) scriem 2
  if(i&4) scriem 3
  ex: i=7 -> scriem 1 2 3
*/
int main()
{
  fin>>n;
  long long subm = ((1<<n)-1); //nr de submultimi
  for(int i=1;i<=subm;i++){
    for(int j=1;j<=n;j++)
      if(i&(1<<(j-1)))
        fout<<j<<' ';
    fout<<'\n';
  }
  return 0;
}
