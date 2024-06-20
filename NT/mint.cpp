//TESTED

int add(int x,int y) {
    return ((x+y) >= MOD ? x+y-MOD : x+y);
}
int sub(int x,int y) {
    assert(y <= MOD);
    return add(x,MOD-y);
}
int mult(int x,int y) {
    if (x >= MOD) x%=MOD;
    if (y >= MOD) y%=MOD;
    return (x*y)%MOD;
}
int expo(int x,int y) {
    if (!y) return 1;
    int e = expo(x,y/2);
    e = mult(e,e);
    if (y&1) e = mult(e,x);
    return e;
}
int divide(int x,int y) {
    return mult(x,expo(y,MOD-2));
}

vi f,ff;
void fact(int n) {
    f.resize(n+1),ff.resize(n+1);
    f[0] = 1;
    for (int i=1;i<=n;i++) f[i] = mult(f[i-1],i);
    for (int i=0;i<=n;i++) ff[i] = divide(1,f[i]);
}

int nck(int n,int k) {
    if (n < k) return 0;
    if (ff.size()-1 >= k) return mult(f[n],mult(ff[n-k],ff[k]));
    else return divide(f[n],mult(f[n-k],f[k]));
}