#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000010
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
#define SET3D(arr, val, dim1, dim2, dim3) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) arr[i][j][k] = val;
#define SET4D(arr, val, dim1, dim2, dim3, dim4) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) F0R(l, dim4) arr[i][j][k][l] = val;
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;

void setupIO(const string &PROB) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream infile(PROB + ".in");
    if (infile.good()) {
        freopen((PROB + ".in").c_str(), "r", stdin);
        freopen((PROB + ".out").c_str(), "w", stdout);
    }
}

/* ============================ */

bool ask(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    char c; cin >> c;
    return c == 'y';
}

void guess(ll x) {
    cout << "! " << x << endl;
}

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s != "start") break;

        ll a = 1, b = 2;
        while (true) {
            bool c = ask(a, b);
            if (a == 1 && b == 2 && !c) {
                // special case, number is either 1 or 2
                if (ask(10, 1)) {
                    // number is 2
                    guess(2);
                } else {
                    // number is 1
                    guess(1);
                }
                break;
            }
            if (!c) {
                // number is between (a, b]
                ll hi = b, lo = a, mid;
                while (lo < hi) {
                    mid = (lo + hi + 1)/2;
                    bool res = ask(lo, mid);
                    if (res) {
                        if (hi - lo == 1) {
                            break;
                        }
                        lo = mid;
                    } else {
                        if (hi - lo == 1) {
                            lo = hi;
                            break;
                        }
                        hi = mid;
                    }
                }
                guess(lo);
                break;
            }
            a = b, b = b+b;
        }
    }

    return 0;
}
