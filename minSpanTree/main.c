#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;

#define UNLIMITED 20200820
#define  MaxVertexNum 1000
#define STACKSIZE 100
FILE *fp = NULL;
FILE *fp2 = NULL;
int vNum,eNum;
int f[200095];
int  num =  0;
int count = 0;
typedef struct GNode *gNode;
typedef gNode Graph;
struct GNode{
    int nv;
    int ne;
    int G[MaxVertexNum][MaxVertexNum];
};

Graph CreateGraph(int VertexNum){
    int v,n;
    Graph graph =(Graph)malloc(sizeof(struct GNode));
    graph->nv = VertexNum;
    graph->ne = 0;
    for (int i = 0; i < graph->nv; ++i) {
        for (int j = 0; j < graph->nv; ++j) {
            graph->G[i][j] =  0;
        }
    }
    return graph;
}

typedef struct ENode *eNode;
typedef eNode Edge;
struct ENode{
    int v1,v2;
    int weight;
}a[200095];

int n,m,ans,sum,k;
void insert(Graph graph,Edge edge){
    graph->G[(edge->v1)-1][(edge->v2)-1] = edge->weight;//减一是因为要与数组下标对应起来
}

Graph BuildGraph(FILE *fp){
    Graph graph;
    Edge edge;
    int v;
    int nv,i;
    fscanf(fp,"%d",&nv);
    graph = CreateGraph(nv);
    fscanf(fp,"%d",&graph->ne);
    if (graph->ne!=0){
        edge = (Edge)malloc(sizeof(struct ENode));
        for (int i = 1; i <= 2*(graph->ne); i++) {
            fscanf(fp,"%d %d %d",&edge->v1,&edge->v2,&edge->weight);
            insert(graph,edge);
        }
    }
    return graph;
}

bool isEmpty(Graph graph){
    return graph->nv==NULL;
}

Graph initGraph(Graph graph){
    for (int i = 0; i < graph->nv; i++) {
        for (int j = 0; j < graph->nv; j++) {
            if (i==j){
                graph->G[i][j]=0;
            }
            if (graph->G[i][j]==NULL&&i!=j){
                graph->G[i][j]=UNLIMITED;
            }
        }
    }
    return graph;
}

void Prim(FILE *fp2,Graph graph){
    int lowCast[graph->nv];
    int source[graph->nv];
    lowCast[0] = 0;
    source[0] = 1;
    int k = 0;

    for (int i = 1; i <=graph->nv ; i++) {
        lowCast[i] = graph->G[0][i];
        source[i] = 1;
    }

    for (int i = 1; i < graph->nv; ++i) {
        int min = 20200821;
        int j = 0;
        while (j<graph->nv){
            if (lowCast[j]!=0&&lowCast[j]<min){
                min = lowCast[j];
                k = j;
            }
            j++;
        }
        fprintf(fp2,"%d-->%d\n",source[k],k+1);
        lowCast[k] = 0;
        //更新lowCast表
        for (int o = 0; o < graph->nv; ++o) {
            if (lowCast[o]!=0&&graph->G[k][o]<lowCast[o]){
                lowCast[o] = graph->G[k][o];
                source[o] = k+1;
            }
        }
    }
}

int find(int x)
{
    if (f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
bool merge(int t1,int t2)
{
    int r1=find(t1);
    int r2=find(t2);
    if (r1!=r2)
    {
        f[r1]=r2;
        return true;
    }
    return false;
}
bool cmp(ENode a,ENode b)
{
    return a.weight<b.weight;
}

void Kruskal(FILE *fp,FILE *fp2){
    int i,j;
    fscanf(fp,"%d%d",&n,&m);
    for (i=1;i<=m;i++)
        fscanf(fp,"%d%d%d",&a[i].v1,&a[i].v2,&a[i].weight);
    sort(a+1,a+m+1,cmp);
    for (i=1;i<=n;i++)
        f[i]=i;
    for (i=1;i<=m;i++)
    {
        if (merge(a[i].v1,a[i].v2))
        {
            sum++;
            fprintf(fp2,"%d-->%d: %d\n",a[i].v1,a[i].v2,a[i].weight);
        }
        if (sum==n-1)
            break;
    }
    for (i=1;i<=n;i++)
        if (f[i]==i)
            k++;
}

int main(){
    fp = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    if (fp==NULL||fp2==NULL){
        printf("文件打开失败");
    }
    Graph graph = BuildGraph(fp);
    graph = initGraph(graph);
    fprintf(fp2,"Prim: \n");
    Prim(fp2,graph);
    fprintf(fp2,"Kruskal: \n");
    Kruskal(fp,fp2);
}



