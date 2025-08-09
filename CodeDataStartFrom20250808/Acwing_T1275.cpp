#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define Test

typedef long long ll;

const int N = 2e5 + 10;

struct Segment_Tree {
    int l, r;
    int v;
} tr[N * 4];

void pushup(int u);
void build(int u, int l, int r);
int query(int u, int l, int r);
void modify(int u, int x, int v);

int main() {
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    int m, p, last = 0, n = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m);
    char op[2];
    int x;
    while (m --)
    {
        scanf("%s%d", op, &x);
        if(*op == 'Q') {
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        }
        else {
            int target = ((((ll)last + (ll)x)) % p);
            modify(1, n + 1, target);
            // cout << "test :" << target << endl;
            ++ n;
        }
    }
    
    return 0;
}

void pushup(int u) {
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
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
    int v = 0;
    int mid = (tr[u].l + tr[u].r) / 2;
    if(l <= mid) {
        v = query(u << 1, l, r);
    }
    if(r > mid) {
        v = max(v, query(u << 1 | 1, l, r));
    }
    return v;
}

void modify(int u, int x, int v) {
    if(tr[u].l == x && tr[u].r == x) {
        tr[u].v = v;
        
    }
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(x <= mid) {
            modify(u << 1, x, v);
        }
        else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u); // remember to update the information of root !
    }
}