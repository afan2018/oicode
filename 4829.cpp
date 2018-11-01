#include<iostream>
#include<set>
#include<map>
using namespace std;
map<string,int>Map;
set<string>Set;
int n,m,p,q,rec[505]={0},suc=0;
string Reverse(string str)
{
    string ret;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='Y') ret+='N';
        else ret+='Y';
    }
    return ret;
}
void DFS(int dep)
{
    if(suc) return;
    if(dep>m)
    {
        string ans;
        for(int i=1;i<=m;i++)
        {
            if(rec[i]==1) ans+='Y';
            else ans+='N';
        }
        if(!Map.count(ans)&&!Map.count(Reverse(ans)))
        {
            suc=1;
            cout<<ans;
        }
        return;
    }
    for(int i=0;i<=1;i++)
    {
        rec[dep]=i;
        DFS(dep+1);
    }
}
int main()
{
    cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++)
    {
        char buffer[505];
        scanf("%s",buffer);
        string str=buffer;
        Set.insert(str);
        if(!Map.count(str)) Map[str]=0;
        Map[str]++;
    }
    if(p!=0)
    {
        for(set<string>::iterator i=Set.begin();i!=Set.end();i++)
        {
            string cor=*i;
            string wor=Reverse(cor);
            if(Map[wor]==q&&Map[cor]==p) {cout<<cor;return 0;}
        }
        cout<<-1;
        return 0;
    }
    if(q>0&&p==0)
    {
        set<string>ans;
        for(set<string>::iterator i=Set.begin();i!=Set.end();i++)
            ans.insert(Reverse(*i));
        for(set<string>::iterator i=ans.begin();i!=ans.end();i++)
        {
            string cor=*i;
            string wor=Reverse(cor);
            if(Map[cor]==p&&Map[wor]==q) {cout<<cor;return 0;}
        }
        cout<<-1;
        return 0;
    }
    DFS(1);
    return 0;
}
/*
1.插入集合
2.建立映射（如果计数为0则映射为0）
3.有满分：挨个检验
4.有零分且没有满分：设新集合，插入每一个答案，依次检验
5.搜索：若搜完则依照搜索记录记下答案，同时检查映射计数中不存在答案，记下成功标记，输出；
搜索：0，1枚举，记下枚举值，下一层搜索
*/
