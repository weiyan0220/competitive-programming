/*
ID: nathan.18
TASK: heritage
LANG: C++11
*/

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
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
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
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

string inOrder, preOrder;
char tLeft[500], tRight[500];

char traverse(int l, int r, int idx) {
    if (l == r || l >= inOrder.length()) return 0;
    if (l == r-1) {
        return inOrder[l];
    }
    int vertex = -1;
    FOR(i, l, r) {
        if (inOrder[i] == preOrder[idx]) {
            vertex = i;
        }
    }
    tLeft[preOrder[idx]] = traverse(l, vertex, idx+1);
    tRight[preOrder[idx]] = traverse(vertex+1, r, idx+1+vertex-l);
    return inOrder[vertex];
}

void print(char c) {
    if (c == 0) return;
    print(tLeft[c]);
    print(tRight[c]);
    cout << c;
}

int main() {
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);

    cin >> inOrder >> preOrder;
    SET(tLeft, 0, 500); SET(tRight, 0, 500);

    print(traverse(0, inOrder.length(), 0));
    cout << endl;

    return 0;
}
