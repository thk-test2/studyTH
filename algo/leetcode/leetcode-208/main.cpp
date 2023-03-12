#include <iostream>

using namespace std;

struct Node {
    bool isEnd = false;
    Node* chars[26];
};

class Trie {
public:
    Trie() {
        head = new Node();
    }

    void makeTrie(Node* node, int i, string& word) {
        if (i == word.size()) {
            node->isEnd = true;
            return;
        }
        if (!node->chars[word[i] - 'a'])
            node->chars[word[i] - 'a'] = new Node();

        makeTrie(node->chars[word[i] - 'a'], i + 1, word);
    }

    void insert(string word) { makeTrie(head, 0, word); }
    bool search(string word) { return searchTrie(head, 0, word); }
    bool startsWith(string prefix) { return searchStartsWith(head, 0, prefix); }

private:
    Node* head = nullptr;

    Node* find(string key) {
        Node* node = head;
        for (int i = 0; i < key.size() && node != nullptr; ++i) {
            node = node->chars[key[i] - 'a'];
        }
        return node;
    }

    bool searchTrie(Node* node, int i, string& word) {
        if (i == word.size()) return node->isEnd;
        if (!node->chars[word[i] - 'a']) return false;

        return searchTrie(node->chars[word[i] - 'a'], i + 1, word);
    }

    bool searchStartsWith(Node* node, int i, string& word) {
        if (i == word.size()) return true;
        if (!node->chars[word[i] - 'a']) return false;

        return searchStartsWith(node->chars[word[i] - 'a'], i + 1, word);
    }
};

int main() {

    Trie* trie = new Trie();
    trie->insert("app");
    trie->insert("apple");
    cout << trie->search("apps") << "\n";
    cout << trie->search("app") << "\n";
	return 0;
}