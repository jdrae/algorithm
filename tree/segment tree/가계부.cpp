#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> tree;
int leaf;

void construct(int arr_size){
    int tree_h = (int)ceil(log2(arr_size));
    int tree_size = (1<<(tree_h) + 1);
    leaf = tree_size >> 1;
    tree.resize(tree_size);
}

ll segment(int l, int r, int nnum, int nl, int nr){
    if(r < nl || l > nr) return 0;
    if(l<=nl && nr <= r) return tree[nnum];
    int mid = (nl + nr) / 2;
    return segment(l, r, nnum*2, nl, mid) + segment(l, r, nnum*2+1, mid+1, nr);
}

void update(int i, ll val){
    i = i + leaf - 1;
    tree[i] += val;
    while(i > 1){
        i /= 2;
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    construct(n);
    int a, b; ll c;
    for(int i = 0; i<q; i++){
        scanf("%d%d%lld", &a, &b, &c);
        if(a==1){
            update(b, c);
        }
        else{ 
            printf("%lld\n", segment(b,c,1,1,leaf));
        }
    }
}