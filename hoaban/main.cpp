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

#define vi vector<int>
#define ii(a, b) pair<a , b>
#define fi first
#define se second
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


#define i1 i << 1
#define i2 i << 1 | 1
using namespace std;
const int INF = (int) 1e9 + 9;
const long long LIF = (long long) 1e18 + 9;
const int MOD = (int) 1e9 + 7;
const int maxn = (int) 1e6 + 6;
const int maxm = (int) 1e5 + 5;
// const int maxt = (int) e + 5;
template< typename X, typename Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; }
template< typename X, typename Y> bool minimize(X &a, const Y &b) { return a > b ? a = b,  1 : 0; }
template< typename T > void add( T &a, const T &b) { a += b; if (a >= MOD) a -= MOD; }
template< typename T > void sub( T &a, const T &b) { a -= b; if (a < 0) a += MOD; }
template< typename T> T abs(T &a) { return a < 0 ? -a : a; }



struct lazy
{
    long long sum, val;
} tree[4 * maxm];
int n, q, b, r, p;
void down(int i, int l, int m, int r)
{
    if (!tree[i].val) return;
    long long &tmp = tree[i].val;
    tree[i1].val = tmp;
    tree[i2].val = tmp;
    tree[i1].sum = tmp * (m - l + 1);
    tree[i2].sum = tmp * (r - m);
    tmp = 0;
}
void update(int i, int L, int R, int u, int v, long long val)
{
    if (v < L || u > R) return;
    if (u <= L && R <= v)
    {
        tree[i].val = val;
        tree[i].sum = val * (R - L + 1);
        return;
    }
    int m = (L + R) >> 1;
    down(i, L, m, R);
    update(i1, L, m, u, v, val);
    update(i2, m + 1, R, u, v, val);
    tree[i].sum = tree[i1].sum + tree[i2].sum;
}
long long getSum(int i, int l, int r, int u, int v)
{
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return tree[i].sum;
    int m = (l + r) >> 1;
    down(i, l, m, r);
    long long res = getSum(i1, l, m, u, v) + getSum(i2, m + 1, r, u, v);
    tree[i].sum = tree[i1].sum + tree[i2].sum;
    return res;
}
void O()
{
    For (i, 1, n)
    {
        cout << getSum(1, 1, n, i, i) << " ";
    }
}

bool check(int L, int R)
{
    long long SUM = getSum(1, 1, n, L, R) + p;
    long long val_1 = L - 1 == 0 ? LIF : getSum(1, 1, n, L - 1, L - 1);
    long long val_2 = SUM / (R - L + 1) + (SUM % (R - L + 1) != 0);
    return val_1 >= val_2;
}
int solve(int r)
{
    int L = 1, R = r;
    while(L <= R)
    {
        if (L == R) return L;
        if (R - L == 1) return check(R, r) ? R : L;
        int M = (L + R) >> 1;
        if (check(M, r)) L = M; else R = M - 1;
    }
}
int main()
{
    #define IOI ""
    freopen(IOI".inp","r",stdin);
    //freopen(IOI".out","w",stdout);
    faster

    cin >> n >> q >> b;
    update(1, 1, n, 1, n, b);
    while(q--)
    {
        cin >> r >> p;
        int l = solve(r);
//        see(l);
        int du = (p + getSum(1, 1, n, l, r)) % (r - l + 1);
        long long nguyen = (p + getSum(1, 1, n, l, r)) / (r - l + 1);
//        see(nguyen);
        update(1, 1, n, l, r, nguyen);
        if (du)
        {
            update(1, 1, n, l, l + du - 1, nguyen + 1);
        }
//        see(getSum(1, 1, n, l, r));
    }

    O();

    /*
    auto time = clock();
    #define Time cerr<<"[It took "<<fixed<<setprecision(3)<<double(clock()-time)/CLOCKS_PER_SEC<<"s]"<<"\n"
    Time;
    */
}
//NOTE: khoer :)
