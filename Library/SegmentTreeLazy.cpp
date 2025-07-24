//
// Created by STW on 07-May-25.
//

// template<typename T>
// struct Node {
//     T val;
//     int lazy;
//     bool is_lazy;
//
//     Node(T x = -1e18) {
//         val = x;
//         lazy = 0;
//         is_lazy = false;
//     }
//     void change(T x, int lx = 0, int rx = 0) {
//         val += x;
//         lazy += x;
//         is_lazy = true;
//     }
//     static Node merge(const Node& a, const Node& b) {
//         Node res;
//         res.val = max(a.val, b.val);
//         return res;
//     }
// };
//
// template<typename T>
// class SegTree {
//
// #define L (2 * ni + 1)
// #define R (2 * ni + 2)
// #define mid (lx + rx >> 1)
//
//     using NodeT = Node<T>;
//     int treeSize;
//     vector<NodeT> segTree;
//
//     void build(const vector<T> &arr, int ni, int lx, int rx) {
//         if (rx - lx == 1) {
//             if (lx < (int)arr.size())
//                 segTree[ni] = NodeT(arr[lx]);
//             return;
//         }
//         build(arr, L, lx, mid);
//         build(arr, R, mid, rx);
//         segTree[ni] = NodeT::merge(segTree[L], segTree[R]);
//     }
//
//     void propagate(int ni, int lx, int rx) {
//         if(rx - lx == 1 || !segTree[ni].is_lazy) return;
//
//         segTree[L].change(segTree[ni].lazy, lx, mid);
//         segTree[R].change(segTree[ni].lazy, mid, rx);
//
//         segTree[ni].lazy = 0;
//         segTree[ni].is_lazy = false;
//     }
//
//     NodeT get(int l, int r, int ni, int lx, int rx) {
//         propagate(ni, lx, rx);
//         if (lx >= l && rx <= r) return segTree[ni];
//         if (rx <= l || lx >= r) return NodeT();
//
//         auto left = get(l, r, L, lx, mid);
//         auto right = get(l, r, R, mid, rx);
//         return NodeT::merge(left, right);
//     }
//
//     void set(int l, int r, T val, int ni, int lx, int rx) {
//         propagate(ni, lx, rx);
//
//         if (rx <= l || lx >= r) return;
//
//         if (lx >= l && rx <= r) {
//             segTree[ni].change(val, lx, rx);
//             return;
//         }
//
//         set(l, r, val, L, lx, mid);
//         set(l, r, val, R, mid, rx);
//         segTree[ni] = NodeT::merge(segTree[L], segTree[R]);
//     }
//
//
// public:
//     SegTree(const vector<T>& arr) {
//         treeSize = 1;
//         while (treeSize < (int)arr.size()) treeSize *= 2;
//         segTree.assign(2 * treeSize, NodeT());
//         build(arr, 0, 0, treeSize);
//     }
//     T get(int l, int r) { // 0-based
//         return get(l, r, 0, 0, treeSize).val;
//     }
//
//     void set(int l, int r, T val) { // 0-based
//         set(l, r, val, 0, 0, treeSize);
//     }
// };
