#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> arr;
vector<ll> tree;
int leaf;

ll sum(int l, int r, int nnum, int nl, int nr){
    if(r < nl || l > nr) return 0;
    if(l<=nl && nr <= r) return tree[nnum];
    int mid = (nl + nr) / 2;
    return sum(l, r, nnum*2, nl, mid) + sum(l, r, nnum*2+1, mid+1, nr);
}

void update(int i, ll val){
    i = i + leaf - 1;
    tree[i] = val;
    while(i > 1){
        i /= 2;
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }
}

void construct(int arr_size){
    int tree_h = (int)ceil(log2(arr_size));
    int tree_size = (1<<(tree_h) + 1);
    tree.resize(tree_size);
    leaf = tree_size >> 1;
    for(int i = leaf, j = 0; i < tree_size; i++, j++){
        if (j < arr_size)
            tree[i] = arr[j];
        else
            tree[i] = 0;
    }
    for(int i = leaf - 1; i>0; --i){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void print_tree(){
    for(int i = 0; i<tree.size(); i++){
        printf("%lld ", tree[i]);
    }
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    arr.resize(n);
    for(int i = 0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    construct(n);
    int a, b; ll c;
    for(int i = 0; i<m+k; i++){
        scanf("%d%d%lld", &a, &b, &c);
        if(a==1){
            update(b, c);
        }
        else{ 
            printf("%lld\n", sum(b,c,1,1,leaf));
        }
    }
}