//TESTED

void compute(const vi& a, vi& L,vi& R) {
    //NEREYE KADAR EN BÜYÜK (EŞİTLERİ SOLA KADAR ALIYOR)
    int n = a.size()-1;
    stack<pii> st;
    for (int i=1;i<=n;i++) {
        while (!st.empty() && st.top().ff <= a[i]) st.pop();
        L[i] = st.empty()?1:st.top().ss+1;
        st.push({a[i],i});
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
        while (!st.empty() && st.top().ff < a[i]) st.pop();
        R[i] = st.empty()?n:st.top().ss-1;
        st.push({a[i],i});
    }
}