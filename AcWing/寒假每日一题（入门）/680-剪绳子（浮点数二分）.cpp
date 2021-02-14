#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int n, m;

int check(double x) {//将a[i],最多可以分多少段长度为x的绳子
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) continue;
        ret += floor(a[i] / x);
    }
    return ret;
}

int main () {
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    double l = 1, r = 100000;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid) >= m) l = mid;
        else r = mid;
    }
    printf("%.2lf", l);
    return 0;
}