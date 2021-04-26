#include <iostream>
#include <vector>
using namespace std;


int main(){
    int m,n;
    int i,j;
    int temp_m,temp_F=0;
    cout<<"请输入投资总金额和项目个数"<<endl;
    cin>>m>>n;
    vector<vector<int>> f(n,vector<int>(m+1));//f[i][x],0<i<n,0<=x<=m

    //F的边界条件为F[0][x] = f[0][x]
    vector<vector<int>> F(n,vector<int>(m+1));//F[i][j] 将x元投入到钱i个项目上的最大收益

    //-------------------------init-------------------------

    //在第i+1个项目上投入0元，收益为0
    for(i = 0;i<n;i++){
        f[i][0] = 0;
    }

    cout<<"请输入各个项目对应的投资的收益(从1开始)"<<endl;
    for(i = 0;i<n;i++){
        for(j = 1;j < m+1;j++){
            cin>>f[i][j];
        }
    }

    //赋予F边界条件
    for (j = 0 ;j<m+1;j++){
        F[0][j] = f[0][j];
    }

    //------------------------start---------------------------
    for (i = 1;i<n;i++){
        for (j = 0;j<m+1;j++){
            for(temp_m = 0;temp_m <= j;temp_m++){
                //递推公式
                temp_F = F[i-1][j-temp_m]+f[i][temp_m];
                //取最大值
                if (temp_F>F[i][j]){
                    F[i][j] = temp_F;
                }
            }
        }
    }
    cout<<"最大总收益为:"<<F[n-1][m]






}
