#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int N = 1001000; 
int n,m,k; 

vll tree, arr,lazy;

ll init(int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    }
    return tree[node] = init(node*2, start, (start+end)/2)
        + init(node*2+1,(start+end)/2+1, end);
}
void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){ 
        tree[node] += (end-start+1) * lazy[node]; 
        if(start != end){ 
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node, start, end);

    if(left>end || right<start){ 
        return;
    }
    if(left<=start && end<=right){ 
        tree[node] += (end-start+1) * diff;
        if(start!=end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll sum(int node, int start, int end, int left, int right){
    update_lazy(node,start,end);
    if(left > end || right < start) return 0;
    if(left <= start && right >= end){
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right)
        + sum(node*2+1, (start+end)/2+1, end, left, right);
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m >> k ;

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));

    arr = vll(n+10);
    tree = vll(tree_size+10);
    lazy = vll(tree_size+10);
    
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    init(1,1,n);
    for(int i=0;i<m+k;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1){// add
            ll d; cin >> d;
            update_range(1,1,n,b,c,d);
        }
        else{// sum
            cout << sum(1,1,n,b,c) <<'\n';
        }
    }
    
    return 0;
}