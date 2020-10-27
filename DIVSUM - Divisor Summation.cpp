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
#define Max           600000
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
ll ans[500010];

void solve() {
    for(ll i=1; i<=500009; ++i) {
        for(ll j=i+i; j<=500009; j+=i) {
            ans[j]+=i;
        }
    }
    ans[1]=0;
}

int main() {
    solve();
    ll q, n;
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld", &n);
        printf("%lld\n",ans[n]);
    }
    return 0;
}

