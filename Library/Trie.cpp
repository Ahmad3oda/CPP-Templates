#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int count;      // how many words go through or end here (pass count)
    int endCount;   // how many words end exactly here
    TrieNode* next[26];

    TrieNode() : count(0), endCount(0) {
        fill(next, next + 26, nullptr);
    }
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& s) {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->next[idx])
                node->next[idx] = new TrieNode();
            node = node->next[idx];
            node->count++;
        }
        node->endCount++;
    }

    bool erase(const string& s) {
        if (!exists(s)) return false;

        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            TrieNode* nextNode = node->next[idx];
            nextNode->count--;
            node = nextNode;
        }
        node->endCount--;
        return true;
    }

    bool exists(const string& s) {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->next[idx]) return false;
            node = node->next[idx];
        }
        return node->endCount > 0;
    }

    int countPrefix(const string& s) {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->next[idx]) return 0;
            node = node->next[idx];
        }
        return node->count;
    }

    int countExact(const string& s) {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->next[idx]) return 0;
            node = node->next[idx];
        }
        return node->endCount;
    }
};
