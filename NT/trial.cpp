

vi divs(int x,bool sorted = 0) {
    for (int i=1;i*i<=x;i++) {
        if (x%i) continue;
        v.push_back(i);
        if (x/i != i) v.push_back(x/i);
    }
    if (sorted) sort(v.begin(),v.end());
    return v;
}