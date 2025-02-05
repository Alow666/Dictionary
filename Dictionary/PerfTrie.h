#pragma once
#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

class PerfTrie{

private:
    
    struct TrieNode {
        TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord;
        int count;
        
        TrieNode();
    };

    TrieNode* root;
    std::string wordpPefixRecursive(TrieNode* root, std::string prefix);
    

public:
    TrieNode* getNewNode();

    PerfTrie();
    ~PerfTrie();

    void insert(const std::string& key);//Добавление слова
    bool search(const std::string& key);//Поиск слова

    std::string searchWordpPefix(std::string key);
    void deleteTrieRecursive(TrieNode* node);

};