//TESTED

struct Node {

};

Node merge(Node a,Node b) {

}

Node id;

struct ST {
    vector<Node> t;

    void build(int node,int l,int r) {
        if (l == r) {
            t[node] = id; //CHANGE TO BUILD
            return;
        }
        int m = (l+r) >> 1;
        build(2*node,l,m),build(2*node+1,m+1,r);
        t[node] = merge(t[2*node],t[2*node+1]);
    }

    ST(int nn) {
        t.resize(4*nn+1);
        build(1,1,nn);
    }

    Node query(int node,int l,int r,const int& L,const int& R) {
        if (l > R || r < L) return id;
        if (l >= L && r <= R) return t[node];
        int m = (l+r) >> 1;
        return merge(query(2*node,l,m,L,R),query(2*node+1,m+1,r,L,R));
    }

    void update(int node,int l,int r,const int& p,const Node& v) {
        if (l == r) {
            t[node] = v;
            return;
        }
        int m = (l+r) >> 1;
        if (p <= m) update(2*node,l,m,p,v);
        else update(2*node+1,m+1,r,p,v);
        t[node] = merge(t[2*node],t[2*node+1]);
    }
};
