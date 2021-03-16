#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAXLENGTH 20200820
typedef struct GNode* gNode;
typedef gNode Graph;
struct GNode{
    int nv;
    int ne;
    int G[MAXSIZE][MAXSIZE];
};

typedef struct ENode* eNode;
typedef eNode Edge;
struct ENode{
    int v1,v2;
    int weight;
};

Graph CreateGraph(int VertexNum);
Graph BuildGraph();
void insert(Graph graph,Edge edge);
Graph initGraph(Graph graph);
void Floyd(Graph graph);
void Dijkstra(Graph graph2);

int main(){
    Graph  graph = BuildGraph();
    initGraph(graph);
    printf("Floyd:\n");
    Floyd(graph);
    Graph graph2 = BuildGraph();
    initGraph(graph2);
    printf("Dijkstra:\n");
    Dijkstra(graph2);
    return 0;
}

Graph CreateGraph(int VertexNum){
    Graph graph = (Graph)malloc(sizeof(struct GNode));
    graph->nv = VertexNum;
    graph->ne = 0;
    for (int i = 0; i < graph->nv; ++i) {
        for (int j = 0; j < graph->nv; ++j) {
            graph->G[i][j] = 0;
        }
    }
    return graph;
}

Graph BuildGraph(){
    Graph graph;
    Edge edge;
    int vertexNum;
    scanf("%d",&vertexNum);
    graph = CreateGraph(vertexNum);
    scanf("%d",&graph->ne);
    if (graph->ne!=0){
        edge = (Edge)malloc(sizeof(struct ENode));
        for (int i = 0; i < graph->ne; ++i) {
            scanf("%d %d %d",&edge->v1,&edge->v2,&edge->weight);
            insert(graph,edge);
        }
    }
    return graph;
}

void insert(Graph graph,Edge edge){
    graph->G[(edge->v1)-1][(edge->v2)-1] = edge->weight;
}

Graph initGraph(Graph graph){
    for (int i = 0; i < graph->nv; ++i) {
        for (int j = 0; j < graph->nv; ++j) {
            if (i==j){
                graph->G[i][j] = 0;
            }
            if (graph->G[i][j]==NULL&&i!=j){
                graph->G[i][j] = MAXLENGTH;
            }
        }
    }
    return graph;
}

void Floyd(Graph graph){
    int T[graph->nv][graph->nv];
    //拷贝一份graph->G
    for (int i = 0; i < graph->nv; ++i) {
        for (int j = 0; j < graph->nv; ++j) {
            T[i][j] = graph->G[i][j];
        }
    }
    for (int k = 0; k < graph->nv; ++k) {
        for (int i = 0; i < graph->nv; ++i) {
            for (int j = 0; j < graph->nv; ++j) {
                if (T[i][j]>(T[i][k]+T[k][j])){
                    T[i][j] = T[i][k]+T[k][j];
                }
            }
        }
    }
    for (int i = 0; i < graph->nv; ++i) {
        for (int j = 0; j < graph->nv; ++j) {
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
}

void Dijkstra(Graph graph2){
    int start,k;
    int min;
    int minLength[graph2->nv]={0};
    int temp[graph2->nv];
    scanf("%d",&start);
    int origin;
    origin = start-1;
    minLength[origin] = 1;
    //初始化temp
    for (int i = 0; i < graph2->nv; ++i) {
            temp[i]  = graph2->G[origin][i];
    }
    temp[origin] = 0;



    for (int i = 1; i < graph2->nv; ++i) {
        min = MAXLENGTH;
        for (int o = 0; o < graph2->nv; ++o) {
            if (!minLength[o]&&temp[o]<min){
                min = temp[o];
                k = o;
            }
        }
        minLength[k] = 1;
        for (int j = 0; j < graph2->nv; ++j) {
            if (!minLength[j]){
                if (min+graph2->G[k][j]<temp[j]){
                    temp[j] = min+graph2->G[k][j];
                }
            }
        }
    }
    for (int i = 0; i < graph2->nv; ++i) {
        printf("从点%d到点%d最短距离为 : %d\n",origin+1,i+1,temp[i]);
    }


}








