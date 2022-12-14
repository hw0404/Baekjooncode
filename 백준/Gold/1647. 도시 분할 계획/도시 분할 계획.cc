#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 100001
typedef struct loc{
    int cur;
    int next;
    int cost;

}loc;
using namespace std;

int N,M;
int parent[MAX_N];
vector<loc> v;
vector<int> result ;

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x] = getParent(parent[x]);
}
void Union(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b)return;
    parent[a]=b;
}
bool isSame( int a, int b){
    a = getParent(a);
    b = getParent(b);
    return a == b ? true : false;
}
bool Bigger( loc a , loc b){
    return a.cost < b.cost ;
}
void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int x,y,cost;
        cin >> x >> y >> cost;
        v.push_back({x,y,cost});
    }
}

void solve(){
    int answer=0;
    sort(v.begin(),v.end(),Bigger);
    for(int i=1;i<=N;i++){
        parent[i]=i;
    }
   
    for(int i=0;i<v.size();i++){
        int cur = v[i].cur;
        int next = v[i].next;
        int cost = v[i].cost;
        if(!isSame(cur,next)){
            Union(cur, next);
            result.push_back(cost);
        }
         
    }
    for(int i=0;i<result.size()-1;i++){
        answer+=result[i];
    }
    cout<<answer;
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


