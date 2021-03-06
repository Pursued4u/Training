#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}

ll f[2000+7][2000+7],A[2000+7][2000+7];
void init(){
    memset(f,0,sizeof(f));
    f[1][1] = 1;
    for(int i = 2;i < 2000+7;++i){
        for(int j = 1;j <= i;++j){
            f[i][j] = (f[i-1][j]*j%mod + f[i-1][j-1])%mod;
            //cout << f[i][j] << " ";
        }
        //cout << endl;
    }
    for(int i = 1;i < 2000+7;++i){
        A[i][1] = i;
        for(int j = 2;j <= i;j++)
            A[i][j] = A[i][j-1]*(i-j+1ll)%mod;
    }
}
void solve(){
    int n,m;scanf("%d%d",&n,&m);
    ll ans = 0;
    for(int i = 2;i < m+1;++i){
        for(int j = 1;j < i;++j){
            ans += f[n][j]*f[n][i-j]%mod*A[m][i]%mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int main(){
    int T;scanf("%d",&T);init();
    while(T--) solve();
    return 0;
}
