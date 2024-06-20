//TESTED

struct Upd {

};

Upd id;

Upd merge(Upd a,Upd b) {

}


struct ST {
    vector<Upd> t;

    ST(int nn) {
        t.assign(4*nn+1,id);
    }

    Upd query(int node,int l,int r,const int& p) {
        if (l == r) return t[node];
        int m = (l+r) >> 1;
        if (p <= m) return merge(t[node],query(2*node,l,m,p));
        else return merge(t[node],query(2*node+1,m+1,r,p));
    }

    void update(int node,int l,int r,const int& L,const int& R,const Upd& v) {
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            t[node] = merge(t[node],v);
            return;
        }
        int m = (l+r) >> 1;
        update(2*node,l,m,L,R,v);
        update(2*node+1,m+1,r,L,R,v);
    }
};