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
#define Max           2000
#define all(v)        v.begin(), v.end()
#define allr(v)       v.rbegin(), v.rend()
#define mem(x,y)      memset(x , y , sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;

bool table[Max]= {0};
ll n, prime[Max/10], ans[1000011];

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

ll eulerPhi(ll n) {
    ll ans=n;
    for(ll i=0; prime[i]*prime[i]<=n; ++i) if(n%prime[i]==0) {
            while(n%prime[i]==0) n/=prime[i];
            ans/=prime[i];
            ans*=(prime[i]-1);
        }
    if(n>1) {
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}

ll gcdSum(ll n) {
    ll ans=0;
    vector<ll> div;
    for(ll i=1; i*i<n; ++i) if(n%i==0) {
        ans+=(i*eulerPhi(i));
        if(i*i!=n) ans+=((n/i)*eulerPhi(n/i));
    }
    return ans;
}

void func() {
    ans[0]=ans[1]=0;
    for(ll i=2; i<=1000001; ++i) ans[i]=ans[i-1]+gcdSum(i)-i;
}

int main() {
    sieve();
    func();
    while(scanf("%lld",&n)==1 && n) printf("%lld\n",ans[n]);
    return 0;
}


