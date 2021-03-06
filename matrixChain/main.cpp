#include <iostream>
using namespace std;
int const M = 10;

void print(int s[][M],int i,int j) {
    if (i == j) cout << "A" << i;
    else
    {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}
int main()
{
    cout << "请输入向量P长度（小于" << M << "）：";
    int length;//问题规模（长度）
    cin >> length;
    cout << "请输入向量P：";
    int P[M] = { 0 };
    for (int i = 0; i < length; i++) {
        cin >> P[i];
    }
    int m[M][M], s[M][M];
    int t, n = length - 1;

    /*另所有m[i, j]初值为0，s[i, j]的初值为i  1≤i≤j≤n*/
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = 0;
            s[i][j] = 1;
        }
    }
    for (int r = 2; r <= n; r++) {	              //r为当前问题规模（长度）
        for (int i = 1; i <= n - r + 1; i++) {    //i的起点不断变化，各种r长
            int j = i + r - 1;                    //不同终点
            m[i][j] = m[i + 1][j] + P[i - 1] * P[i] * P[j];//划分为Ai(Ai+1...Aj),此时k=i
            s[i][j] = i;
            for (int k = i+1; k <= j - 1; k++){
                t = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                if (t < m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "当矩阵链规模为" << length << "时：" << endl;
    cout << "最小总次数为" << m[1][n] << endl;
    cout << "括号化方案为："<<endl;

    print(s, 1, n);
    cout << endl;

}
