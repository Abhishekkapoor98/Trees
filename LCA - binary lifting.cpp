#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lli long long int
#define mod 1000000007
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define vi vector<int>
#define vc vector<char>
#define vlli vector<long long int>
#define uos unordered_set<int>
#define min_heap priority_queue<int,vector<int>,greater<int>>
#define max_heap priority_queue<int>
#define pii pair<int,int>
#define F first
#define S second
#define loop(a,b) for(lli i=a;i<=b;i++)
#define endl '\n'
#define ll long long

int n,e;
vi tree[100005];
int LCA[100005][1005];
int level[100005];

void add_edge(int u,int v)
{
	tree[u].PB(v);
}

void dfs(int root,int parent,int L)
{
	level[root] = L;
	LCA[root][0] = parent;

	for(auto itr : tree[root])
		if(itr != parent)
			dfs(itr,root,L+1);
}

void init()
{	
	memset(LCA,-1,sizeof(LCA));

	dfs(1,-1,0);

	for(int j=1;j<=log2(n);j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(LCA[i][j-1] != -1)
			{
				int temp = LCA[i][j-1];
				LCA[i][j] = LCA[temp][j-1];
			}
		}
	}
}

int lca(int a,int b)
{

	if(level[a] > level[b])
	{
		int t = a;
		a = b;
		b = t;
	}

	int d = level[b] - level[a];

	while(d)
	{
		int i = log2(d);

		b = LCA[b][i];
		d -= (1 << i);
	}

	if(a == b)
		return a;
	else
	{
		for(int i = log2(n); i>=0; i--)
		{
			if(LCA[a][i] != -1 && LCA[a][i] != LCA[b][i])
			{
				a = LCA[a][i];
				b = LCA[b][i];
			}
		}
		return LCA[b][0];
	}
}

void solve()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>e;

		for(int i=0;i<e;i++)
		{
			int u,v;
			cin>>u>>v;
			add_edge(u,v);
		}

		init();

		int a,b;
		cin>>a>>b;

		cout<<"LCA is:: "<<lca(a,b);
	}
}

int main()
{
	fast_io;

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif

	solve();

	return 0;
}
