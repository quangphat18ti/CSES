///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1661"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
ll sum[maxn];
map <ll , int> dd;

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i] , sum[i] = sum[i - 1] + a[i];
}

void xuli()
{
    ll ans = 0;

    dd[0] = 1;
    For( i , 1 , n )
    {
        ll tam = sum[i] - k;
        ans += dd[tam];
        dd[sum[i]]++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
