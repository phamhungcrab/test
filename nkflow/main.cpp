#include <bits/stdc++.h>

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")





#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, a, b) for (__typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for (__typeof(b) i = (a); i >= (b); i--)
#define Rep(i, n) for (int i = 0; i < (n); i++)
#define TR(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define offBIT(x, k) ( (x) & ~( 1 << (k) )
#define onBIT(x, k) ( (x) | ( 1 << (k) )

#define ii(a, b) pair<a , b>
#define fi first
#define se second
#define vi vector<int>
#define all(v) v.begin(), v.end()

#define reset(a,b) memset(a,b,sizeof a)
#define el cout << "\n";
#define sp cerr << " ";
#define pb push_back
#define pf push_front
#define mp make_pair


#define __builtin_popcount __builtin_popcountll
#define sz(x) printf("%d", int( sizeof(x) ));
#define see(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define see1(a, b, c) For (i, b, c) cerr << a[i] << " ";
#define see2(a, u, m, v, n) For (i, u, m) { For (j, v, n) cerr << a[i][j] << " "; el }

#define ll long long
#define ull unsigned long long
#define LOG

using namespace std;
const long long LIF = (long long) 1e18 + 9;
const int MOD = (int) 1e9 + 7, INF = (int) 1e9 + 9, maxn = (int) 1e3 + 6, maxm = (int) 1e5 + 5;

template< typename X, typename Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template< typename X, typename Y> bool minimize(X &a, const Y &b) { return a > b ? a = b,  1 : 0; }
template< typename T > void add( T &a, const T &b) { a += b; if (a >= MOD) a -= MOD; }
template< typename T > void sub( T &a, const T &b) { a -= b; if (a < 0) a += MOD; }
template< typename T> T abs(T &a) { return a < 0 ? -a : a; }


int n, m, s, t, vis[maxn], par[maxn], matrixAdj[maxn][maxn], ans;
vector<int> adj[maxn];
void I()
{
    cin >> n >> m >> s >> t;
    Rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        matrixAdj[u][v] += w;
    }
}
bool augFlow()
{
    reset(vis, 0);
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) if (matrixAdj[u][v] && !vis[v])
        {
            vis[v] = 1;
            par[v] = u;
            q.push(v);
            if (v == t) return 1;
        }
    }
    return 0;
}
void O()
{
    while(augFlow())
    {
        int min_flow = INF;
        for(int tmp = t; tmp != s; tmp = par[tmp])
            minimize(min_flow, matrixAdj[par[tmp]][tmp]);
        ans += min_flow;
        for (int tmp = t; tmp != s; tmp = par[tmp])
        {
            matrixAdj[par[tmp]][tmp] -= min_flow;
            matrixAdj[tmp][par[tmp]] += min_flow;
        }
    }
    cout << ans;
}
int main()
{
    #define IOI ""
    freopen(IOI".inp","r",stdin);
    //freopen(IOI".out","w",stdout);
    faster

    I();

    O();

    /*
    auto time = clock();
    #define Time cerr<<"[It took "<<fixed<<setprecision(3)<<double(clock()-time)/CLOCKS_PER_SEC<<"s]"<<"\n"
    Time;
    */
}
//NOTE:
