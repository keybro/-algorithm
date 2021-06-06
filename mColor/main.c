#include<stdio.h>
#include<string.h>
const int max=120;

int n,m,match;//顶点数，颜色数，边数
int c[max][max];//图的链接矩阵
int b[max];//当前的解
int sum=0;//方案数

bool A(int a)
{
    for (int i=1;i<=n;++i)
    {
        if(c[a][i]==1 && b[i]==b[a])
        {
            return false;
        }
    }
    return true;
}

void Backtrack(int a)
{
    if (a>n)
    {
        sum++;
        for (int i=1;i<=n;++i)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i=1;i<=m;++i)
        {
            b[a] = i;
            if (A(a))
            {
                Backtrack(a+1);
            }
            b[a]=0;
        }
    }
}

int main()
{
    scanf("%d",&m);
    scanf("%d %d",&n,&match);
    for (int i=1;i<=match;++i)
    {
        int x, y;
        scanf("%d %d",&x,&y);
        c[x][y]=c[y][x]=1;
    }
    Backtrack(1);
    if (sum==0)
    {
        printf("NO\n");
    }
    else
    {
        printf("%d\n", sum);
    }
    return 0;
}

