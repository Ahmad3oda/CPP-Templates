#include <bits/stdc++.h>
using namespace std;
const int MAX_BITS = 31; // for 32-bit integers

struct Node {
    int cnt = 0;
    Node* child[2] = {nullptr, nullptr};
};

struct BinaryTrie {
    Node* root;

    BinaryTrie() {
        root = new Node();
    }

    void insert(int num) {
        Node* cur = root;
        for (int i = MAX_BITS; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    void erase(int num) {
        Node* cur = root;
        for (int i = MAX_BITS; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            cur = cur->child[bit];
            cur->cnt--;
        }
    }

    bool isExist(int num) {
        Node* cur = root;
        for (int i = MAX_BITS; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if (!cur->child[bit] || cur->child[bit]->cnt == 0)
                return false;
            cur = cur->child[bit];
        }
        return true;
    }

    // Get maximum XOR value with x from all elements in the trie
    int maxXor(int x) {
        Node* cur = root;
        int res = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            bool bit = (x >> i) & 1;
            if (cur->child[!bit] && cur->child[!bit]->cnt > 0) {
                res |= (1 << i);
                cur = cur->child[!bit];
            } else {
                cur = cur->child[bit];
            }
        }
        return res;
    }

    // Get min XOR value with x from all elements in the trie
    int minXor(int x) {
        Node* cur = root;
        int res = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            bool bit = (x >> i) & 1;
            if (cur->child[bit] && cur->child[bit]->cnt > 0) {
                cur = cur->child[bit];
            } else {
                res |= (1 << i);
                cur = cur->child[!bit];
            }
        }
        return res;
    }

    // Count how many numbers less than k when XORed with x
    int countXorLessThan(int x, int k) {
        Node* cur = root;
        int res = 0;
        for (int i = MAX_BITS; i >= 0 && cur; i--) {
            bool x_bit = (x >> i) & 1;
            bool k_bit = (k >> i) & 1;

            if (k_bit) {
                if (cur->child[x_bit]) res += cur->child[x_bit]->cnt;
                cur = cur->child[!x_bit];
            } else {
                cur = cur->child[x_bit];
            }
        }
        return res;
    }
};

