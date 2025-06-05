#include <vector> #include <list> #include <deque> #include <queue> #include <stack> #include <set> #include <map> #include <unordered_set>
#include <unordered_map>#include <algorithm>#include <numeric>#include <functional>#include <iterator>
#include <iostream>#include <iomanip>
#include <ios>#include <iosfwd>#include <istream>#include <ostream>#include <fstream>#include <sstream>#include <streambuf>
#include <string>
#include <cstring>
#include <utility>#include <limits>#include <memory>#include <typeinfo>#include <new>#include <exception>#include <stdexcept>
#include <tuple>#include <bitset>#include <cmath>#include <cstdlib>#include <ctime>#include <valarray>#include <complex>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    int arr[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            arr[i][j]--;
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        int v[n];
        memset(v,0,sizeof(v));
        v[i]=1;
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                if(arr[j][k]==i){
                    if(k>0 && k<n-1){
                        v[arr[j][k-1]]=1;
                        v[arr[j][k+1]]=1;
                    }
                    else if(k<n-1){
                        v[arr[j][k+1]]=1;
                    }
                    else if(k>0){
                        v[arr[j][k-1]]=1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(v[i]==0){
                cnt++;
            }
        }
        

    }
    cout<<cnt/2<<endl;
}