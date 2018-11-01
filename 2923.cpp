#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
 
const int Maxn = 80005;
struct Ac_1{int x, y; double v;}a[4*Maxn];
struct Ac_2{int to, next;double v;}w[4*Maxn];
int h[Maxn], cnt = 0, N, M;
int prt[Maxn] = {0};
double Sum = 0;
double d[Maxn] = {0};
double Minn = 1e100;
int Min;
 
inline int Getint()
{
       char c = getchar();
       while (c<'0' || c>'9') c = getchar();
       int ret = 0;
       while (c>='0' && c<='9')
       {
           ret = ret*10 + (c-'0');
           c = getchar();
       }
       return ret;
}
 
void Addedge(int x, int y, double v)
{
    cnt++;
    w[cnt].to = y;
    w[cnt].v = v;
    w[cnt].next = h[x];
    h[x] = cnt;
}
 
bool Cmp(Ac_1 aa, Ac_1 bb)
{
    return aa.v < bb.v;
}
 
void Read()
{
    N = Getint();
    M = Getint();
    for (int i = 1; i <= M; i++)
        {
            a[i].x = Getint();
            a[i].y = Getint();
            scanf("%lf", &a[i].v);
        }
    sort (a+1, a+M+1, Cmp); 
}
 
int Find_Father(int x)
{
    if (prt[x] == x)return x;
    prt[x] = Find_Father(prt[x]);
    return prt[x];
}
 
void Kruskal()
{
    int f1, f2, i, t = 0;
    for (i = 1; i <= N; i++)prt[i] = i;
    for (i = 1; i <= M; i++)
    {
        f1 = Find_Father(a[i].x);
        f2 = Find_Father(a[i].y);
        
        if (f1 != f2)
        {
            t++;
            Addedge(a[i].x, a[i].y, a[i].v);
            Addedge(a[i].y, a[i].x, a[i].v);
            Sum += a[i].v;
            prt[f1] = f2;
            if (t == N-1)break;
        }
    }
}
 
void DFS(int u)
{
    int i, j;
    for (i = h[u]; i; i = w[i].next)
        {
            int v = w[i].to;
            if(!prt[v])
            {
                prt[v] = u;
                DFS(v);
                d[u] += d[v] + w[i].v;
            }
        }
}
 
void Count(int k)
{
    int i, s = 0;
    double Ans = 0, Avg = 0;
    for (i = h[k]; i; i= w[i].next)s++;
    
    if (s <= 1)return ;
    Avg = Sum/s;
    
    for (i = h[k]; i; i= w[i].next)
        if(k == prt[w[i].to])
            Ans += (d[w[i].to]+w[i].v-Avg)*(d[w[i].to]+w[i].v-Avg);
        else Ans += (Sum-d[k]-Avg)*(Sum-d[k]-Avg);
        
        if(Ans < Minn){Minn = Ans; Min = k;}
}
    
void Solve()
{
    memset(prt, 0, sizeof(prt));
    prt[1] = 1;
    DFS(1);
    for (int i = 1; i <= N; i++)Count(i);
    cout << Min << endl;
}
int main()
{
    Read();
    Kruskal();
    Solve();
    return 0;
}