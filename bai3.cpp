#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
ll get(ll x, ll y){
    ll v = abs(x) > abs(y) ? abs(x) : abs(y);
    ll vv = (v*2+1)*(v*2+1);
    if(y == v){
        return vv - (v-x);
    }else if(-x == v){
        return vv-2*v-(v-y);
    }else if(-y == v){
        return vv-4*v-(x+v);
    }else{
        return vv-6*v-(y+v);
    
    }
}
ll vong(ll n){
    if(n == 1){
        return 0;
    }else{
        ll vong = 0;
        while(!(n>(vong*2+1)*(vong*2+1) && n<= (vong*2+3)*(vong*2+3))){
            vong++;
        }
        return vong+1;
    }
}
struct pos{
    ll x;
    ll y;
};
pos getPos(ll n){
    pos a;
    ll v = vong(n);
    ll vv = (v*2+1)*(v*2+1);
    if(n>=vv-2*v){
        a.y = v;
        a.x = n-vv+v;
    }else if(n>=vv-4*v){
        a.x = -v;
        a.y = n+3*v-vv;
    }else if(n>=vv-6*v){
        a.y = -v;
        a.x = vv-5*v -n;
    }else{
        a.x = v;
        a.y = vv-6*v-v-n;
    }
    return a;
}
int main(){
    int drr[4][2] = {{1,1},{-1,1},{-1,-1},{1,-1}};
    ll a,x,y;
    cin >> a >> x >> y;
    pos p = getPos(a);
    ll mmax = 0;
    for(int i = 0 ; i < 4;i++){
        mmax = max(mmax,get(p.x+x*drr[i][0],p.y+y*drr[i][1]));
        mmax = max(mmax,get(p.x+y*drr[i][0],p.y+x*drr[i][1]));
    }
    cout << mmax;
}
