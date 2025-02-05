#include "PerfTrie.h"

PerfTrie::TrieNode::TrieNode() : isEndOfWord(false), count(0) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

PerfTrie::PerfTrie() {
    root = getNewNode();
}

PerfTrie::~PerfTrie() {
    deleteTrieRecursive(root);
    root = nullptr;
}

PerfTrie::TrieNode* PerfTrie::getNewNode() {
    return new TrieNode();
}

void PerfTrie::insert(const std::string& key) {
    TrieNode* node = root;
    for (char c : key) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = getNewNode();
        }
        node = node->children[index];
        node->count++;
    }
    node->isEndOfWord = true;
}

bool PerfTrie::search(const std::string& key) {
    TrieNode* node = root;
    for (char c : key) {
        int index = c - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return (node != nullptr && node->isEndOfWord);
}

std::string PerfTrie::searchWordpPefix( std::string key) {
    TrieNode* node = root;
    std::string text = key;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index]) {
            text = "-";
            return text;
        }

        node = node->children[index];
    }
    return wordpPefixRecursive(node, text);
};

std::string PerfTrie::wordpPefixRecursive(TrieNode* root, std::string text) {
    if (!root) {
        return "";
    }
    if (root->isEndOfWord) {
        return text;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            text += char(i + 'a');
            std::string result = wordpPefixRecursive(root->children[i], text);
            if (!result.empty()) {
                return result; 
            }
            else {
                text.pop_back(); 
            }
        }
    }
    return "";
};

void PerfTrie::deleteTrieRecursive(TrieNode* node) {
    if (!node) return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        deleteTrieRecursive(node->children[i]);
    }

    delete node;
}
