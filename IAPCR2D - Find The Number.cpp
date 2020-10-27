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
#define Max           200
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
vector<ll> ans;
bool table[Max]= {0};
ll prime[Max/2];
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

ll nod(ll n) {
    ll ans=1;
    for(ll i=0; prime[i]<=n; ++i) {
        ll m=n, cnt=1;
        while(m) {
            m/=prime[i];
            cnt+=m;
        }
        ans*=cnt;
    }
    return ans;
}

void preCalculation() {
    ans.pb(1);
    for(ll i=2; i<120; ++i) ans.pb(nod(i));
}

int main() {
    sieve();
    preCalculation();
    ll t;
    scanf("%lld", &t);
    while(t--) {
        ll n;
        scanf("%lld", &n);
        if(!binary_search(all(ans),n)) cout<<"nai\n";
        else cout<<(upper_bound(all(ans), n) - ans.begin())<<el;
    }
    return 0;
}
