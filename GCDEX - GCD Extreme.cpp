/***************************************************************
 *    Name:  KAZI NUR  ALAM MASHRY                             *
 *  School:  MAWLANA BHASHANI SCIENCE & TECHNOLOGY UNIVERSITY  *
 *           CSE (14TH BATCH)                                  *
 ***************************************************************/
#include<bits/stdc++.h>
#define INF           0x3f3f3f3f
#define el            '\n'
#define x             first
#define y             second
#define pi            acos(-1.0)
#define pb            push_back
#define mp            make_pair
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
ll n, phi[1000011]={0}, ans[1000011]={0};

void solve() {
    phi[1]=1;
    for(ll i=2; i<1000001; ++i) if(phi[i]==0){
        phi[i]=i-1;
        for(ll j=i+i; j<1000001; j+=i) {
            if(phi[j]==0) phi[j]=j;
            phi[j]/=i;
            phi[j]*=(i-1);
        }
    }
    for(ll i=1; i<1000001; ++i) {
        for(ll j=i; j<1000001; j+=i) ans[j]+=(i*phi[j/i]);
    }
    for(ll i=1; i<1000001; ++i) ans[i]+=ans[i-1]-i;
}

int main() {
    solve();
    while(scanf("%lld",&n)==1 && n) printf("%lld\n",ans[n]);
    return 0;
}
