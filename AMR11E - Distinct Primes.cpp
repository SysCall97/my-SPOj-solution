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
#define Max           900000
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

bool table[Max]= {0};
ll prime[Max/10];
vector<ll> ans;

void sieve() {
    ll i,j,k=4,n=Max;
    for(i=5; i*i<=n; i+=k) {
        for(j=2*i; j<=n; j+=i) {
            table[j]=1;
        }
        k=(k==2)?4:2;
    }
    k=4;
    for(i=5,j=2; i<=n; i+=k) {
        if(table[i]==0) {
            prime[j]=i;
            j++;
        }
        k=(k==2)?4:2;
    }
    prime[0]=2,prime[1]=3;
}

ll func(ll n) {
    ll s=0;
    for(ll i=0; prime[i]<=n; ++i) if(n%prime[i]==0) ++s;
    return s;
}

void solve() {
    ll sz=0;
    ans.pb(-1);
    for(ll i=6; ; ++i) if(func(i)>2) {
        ans.pb(i), ++sz;
        if(sz==1010) break;
    }
    sort(all(ans));
}

int main() {
    sieve();
    solve();

//    for(ll i=1; i<1001; ++i) printf("%lld\n", ans[i]);
    ll q, n;
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld", &n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}
