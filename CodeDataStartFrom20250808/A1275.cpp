#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Test
const int N = 2e5 + 10;

typedef long long ll;

struct Segment_Tree {
    int l, r;
    ll v;
} tr[N * 4];
void build(int u, int l, int r);
void modify(int u, int x, int v);
int query(int u, int l, int r);
void pushup(int u);
int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int m, p, last = 0, r_bound = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m);
    char op[2];
    ll x;
    while (m --)
    {
        scanf("%s%lld", op, &x);
        if(*op == 'Q') {
            last = query(1, r_bound - x + 1, r_bound);
            printf("%d\n", last);
        }
        else {
            modify(1, r_bound + 1, (x + last) % p);
            ++ r_bound;
        }
    }
    return 0;
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
    if(tr[u].l >= l && tr[u].r <= r) {
        return tr[u].v;
    }
    int ans = 0;
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(l <= mid) {
        ans = query(u << 1, l, r);
    }
    if(r > mid) {
        ans = max(ans, query(u << 1 | 1, l, r));
    }
    return ans;
}

void modify(int u, int x, int v) {
    if(tr[u].l == x && tr[u].r == x) {
        tr[u].v = v;
        return ;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid) {
        modify(u << 1, x, v);
    }
    else {
        modify(u << 1 | 1, x, v);
    }
    pushup(u);
}

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}