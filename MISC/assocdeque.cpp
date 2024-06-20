//TESTED

template <typename T>
T f(T a,T b) {
    return min(a,b);
}
template <typename T>
struct fdeque {

    struct fstack {
        stack<pii> st;
        int get() {
            return st.top().second;
        }
        bool empty() {return st.empty();}
        int size() {return st.size();}
        void push(T x) {
            T mn = x;
            if (!empty()) mn = f(mn, get());
            st.push({x, mn});
        }
        void pop() {st.pop();}
        int top() {return st.top().first;}
        void swap(fstack &x) {st.swap(x.st);}
    } l,r,t;
    
    void balance() {
        bool f = false;
        if (r.empty()) {f = true; l.swap(r);}
        int sz = r.size() / 2;
        while (sz--) {t.push(r.top()); r.pop();}
        while (!r.empty()) {l.push(r.top()); r.pop();}
        while (!t.empty()) {r.push(t.top()); t.pop();}
        if (f) l.swap(r);
    }
    int get() {
        if (l.empty()) return r.get();
        if (r.empty()) return l.get();
        return f(l.get(), r.get());
    }
    bool empty() {return l.empty() && r.empty();}
    int size() {return l.size() + r.size();}
    void push_front(int x) {l.push(x);}
    void push_back(int x) {r.push(x);}
    void pop_front() {if (l.empty()) balance(); l.pop();}
    void pop_back() {if (r.empty()) balance(); r.pop();}
    int front() {if (l.empty()) balance(); return l.top();}
    int back() {if (r.empty()) balance(); return r.top();}
    void swap(fdeque &x) {l.swap(x.l); r.swap(x.r);}
};