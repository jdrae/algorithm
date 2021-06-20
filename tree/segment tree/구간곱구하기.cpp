#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define ll long long
vector<ll> tree;
vector<int> arr;
int leaf;

void construct(int n){
    int th = (int)ceil(log2(n)) + 1;
    int ts = (1<<th);
    leaf = ts >> 1;

    tree.resize(ts);
    for(int i = leaf, j = 0; i<ts; i++, j++){
        if(j<n)
            tree[i] = arr[j];
        else
            tree[i] = 0;
    }
    for(int i = leaf-1; i > 0; i--){
        tree[i] = (tree[i*2] * tree[i*2 + 1]) % MOD;
    }
}

void update(int i, ll val){
    i = i + leaf - 1;
    tree[i] = val;
    while(i>1){
        i /= 2;
        tree[i] = (tree[i*2] * tree[i*2 + 1]) % MOD;
    }
}

ll segment(int l, int r, int nnum, int nl, int nr){
    if(nl > r || nr < l) return 1;
    if(l <= nl && nr <= r) return tree[nnum];
    int mid = (nl + nr) / 2;
    return (segment(l, r, nnum*2, nl, mid) * segment(l, r, nnum* 2 +1, mid+1, nr)) % MOD;
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    arr.resize(n);
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    construct(n);

    int a, b, c;
    for(int i = 0; i<m+k; i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            update(b, c);
        }
        else{
            printf("%lld\n", segment(b,c,1,1,leaf));
        }
    }
}