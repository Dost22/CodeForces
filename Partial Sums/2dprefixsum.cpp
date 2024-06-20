

struct PSUM {
    vector<vi> p;
    int n,m;
    PSUM(const vector<vi>& a) {
        n = a.size()-1;
        m = a[0].size()-1;
        p.assign(n+1,vi(m+1,0));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
            }
        }
    }
    int get(int x1,int y1,int x2,int y2) {
        assert(x2 >= x1 && y2 >= y1);
        return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
    }
    
};