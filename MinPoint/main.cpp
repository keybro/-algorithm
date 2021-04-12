#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
//当只有一个点的时候认为距离为无穷大
#define MAX 0x3f3f3f3f
#define M 99999

struct Point{
    double x,y;
}point[M];

//保存排序的索引
int a[M];

//根据x值进行升序排序
int cmpByX(const Point &a,const Point &b){
    return a.x<b.x;
}

//根据y值进行升序排序
int comByY(const int &a,const int &b){
    return point[a].y<point[b].y;
}

//取最小数
inline double min(double a,double b){
    return a<b?a:b;
}

//计算两点之间距离
inline double dist(const Point &a,const Point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closeset(int low,int high){
    if (low==high){
        return MAX;
    }
    //只有两个点的时候返回两点之间距离
    if(low+1 == high){
        return dist(point[low],point[high]);
    }
//    int mid = (low+high)/2;
// 采用右移的方式比/快，且不易溢出
    int mid = (low+high)>>1;
    double ans = min(closeset(low,mid),closeset(mid+1,high));
    int tool = 0;
    for (int k = low; k <=high; ++k) {
        if (point[mid].x - ans <= point[k].x&&point[k].x<=point[mid].x+ans){
            a[tool++] = k;
        }
    }
    sort(a,a+tool,comByY);
    for (int i = 0; i < tool; ++i) {
        int k = i+7> tool? tool:i+7;
        for (int j = i+1 ; j < k; ++j) {
            if (point[a[j]].y - point[a[i]].y >ans){
                break;
            }
            ans = min(dist(point[a[i]],point[a[j]]),ans);
        }
    }
    return ans;
}

int main(){
    int n;
    double minDistance;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>point[i].x>>point[i].y;
    }
    sort(point,point+n,cmpByX);
    minDistance = closeset(0,n-1);
    cout<<"最近的距离是："<<minDistance<<endl;
    return 0;

}




