//TESTED

int si[LIM]; // MAKE SURE LIM IS DEFINED! [0..LIM)

void init_sieve() {
    for (int i=2;i<LIM;i++) {
        if (si[i]) continue;
        si[i] = i;
        for (int j=i*i;j<LIM;j+=i) {
            si[j] = i;
        }
    } 
} 

vi pf(int x) {
    vi ps;
    while (x > 1) {
        assert(x < LIM);
        int y = si[x];
        ps.push_back(y);
        while (x%y == 0) x/=y;
    }
    return ps;
}

vector<pii> pfc(int x) {
    vector<pii> ps;
    while (x > 1) {
        assert(x < LIM);
        int y = si[x];
        int c = 0;
        while (x%y == 0 && ++c) x/=y;
        ps.push_back({y,c}); 
    }
    return ps;
}