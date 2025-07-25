#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T val;

    Node(T x = 0) {
        val = x;
    }
    void change(T x) {
        val += x;
    }
    static Node merge(const Node& a, const Node& b) {
        Node res;
        res.val = a.val + b.val;
        return res;
    }
};

template<typename T>
class SegTree {

#define L (2 * ni + 1)
#define R (2 * ni + 2)
#define mid (lx + rx >> 1)

    using NodeT = Node<T>;
    int treeSize;
    vector<NodeT> segTree;

    void build(const vector<T> &arr, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)arr.size())
                segTree[ni] = NodeT(arr[lx]);
            return;
        }
        build(arr, L, lx, mid);
        build(arr, R, mid, rx);
        segTree[ni] = NodeT::merge(segTree[L], segTree[R]);
    }

    NodeT get(int l, int r, int ni, int lx, int rx) {
        if (lx >= l && rx <= r) return segTree[ni];
        if (rx <= l || lx >= r) return NodeT();

        auto left = get(l, r, L, lx, mid);
        auto right = get(l, r, R, mid, rx);
        return NodeT::merge(left, right);
    }

    void set(int idx, T val, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            segTree[ni].change(val);
            return;
        }
        if (idx < mid) set(idx, val, L, lx, mid);
        else set(idx, val, R, mid, rx);
        segTree[ni] = NodeT::merge(segTree[L], segTree[R]);
    }

public:
    SegTree(const vector<T>& arr) {
        treeSize = 1;
        while (treeSize < (int)arr.size()) treeSize *= 2;
        segTree.assign(2 * treeSize, NodeT());
        build(arr, 0, 0, treeSize);
    }
    T get(int l, int r) { // 0-based
        return get(l, r + 1, 0, 0, treeSize).val;
    }

    void set(int idx, T val) { // 0-based
        set(idx, val, 0, 0, treeSize);
    }
};
