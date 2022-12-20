/// prof. Ionel-Vasile Pit-Rada
/// Colegiul National Traian Drobeta Turnu Severin

///O(n*n*log(n))
#include <fstream>
using namespace std;
ifstream  fin("recyclebin.in");
ofstream fout("recyclebin.out");
int n,v,i,j,k,dp[1002][1024],vmax;
///dp[i][j]=cea mai mare suma a unei secvente cu capatul din dreapta egal cu i si din care
///s-au eliminat secvente de lungimi puteri de 2, distincte, care insumate dau valoarea j
int main(){
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>v;
        
        for(k=0;k<=i-1;k++){
            dp[i][k]=max(dp[i][k],v+dp[i-1][k]);
            vmax=max(vmax,dp[i][k]);
        }

        for(j=1;j<=i-1;j=j*2){
            for(k=0;k<=i-j;k++){
                if((j&k)==0){
                    dp[i][(k|j)]=max(dp[i][(k|j)],dp[i-j][k]);
                    vmax=max(vmax,dp[i][(k|j)]);
                }
            }
        }

    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++)
        fout<<dp[i][j]<<' ';
      fout<<'\n';
    }
    //fout<<vmax; fout.close(); fin.close(); return 0;
}
