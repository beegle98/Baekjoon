#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

int main(){
    int n,m,x;
    set<int> s;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        s.insert(x);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        if(s.find(x)!=s.end()){
            printf("1 ");
        }
        else printf("0 ");
    }
    return 0;
}