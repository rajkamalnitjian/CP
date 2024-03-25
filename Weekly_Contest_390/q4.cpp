//
// Created by RAJKAMAL KUMAR on 25/03/24.
//

//3093. Longest Common Suffix Queries

#include <iostream>
#include<queue>
#define pi pair<ll,ll>
#define ll long long
using namespace std;

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        int shortestWordLength;
        int shortestWordIndex;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            shortestWordLength = INT_MAX;
            shortestWordIndex = INT_MAX;
        }
    };

    void insertWord(TrieNode *root, string word, int wordIndex) {
        int wordLength = word.size();
        reverse(word.begin(), word.end());

        for(int i = 0; i < wordLength; i++) {
            int charIndex = word[i] - 'a';
            if(root->children[charIndex] == nullptr) {
                TrieNode *newNode = new TrieNode();
                newNode->shortestWordLength = wordLength;
                newNode->shortestWordIndex = wordIndex;
                root->children[charIndex] = newNode;
                root = root->children[charIndex];
            } else {
                root = root->children[charIndex];
                if(wordLength < root->shortestWordLength) {
                    root->shortestWordLength = wordLength;
                    root->shortestWordIndex = wordIndex;
                }
            }
        }
    }

    int searchWord(TrieNode *root, string word) {
        reverse(word.begin(), word.end());
        int wordLength = word.size();

        for(int i = 0; i < wordLength; i++) {
            int charIndex = word[i] - 'a';
            if(root->children[charIndex] != nullptr)
                root = root->children[charIndex];
            else
                break;
        }
        return root->shortestWordIndex;
    }

    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int n = words.size();
        vector<int> indices;
        TrieNode *root = new TrieNode();

        for(int i = 0; i < n; i++) {
            if(words[i].size() < root->shortestWordLength) {
                root->shortestWordLength = words[i].size();
                root->shortestWordIndex = i;
            }
            insertWord(root, words[i], i);
        }

        int m = queries.size();
        for(int i = 0; i < m; i++) {
            int index = searchWord(root, queries[i]);
            indices.push_back(index);
        }
        return indices;
    }
};

int main(){
    vector<string> wordsContainer={"a","b"};
    vector<string> wordsQuery={"a","b"};
    Solution *pSolution =new Solution();
    vector<int>res= pSolution->stringIndices(wordsContainer,wordsQuery);

    for(auto &it:res)
        cout<<it<<" ";
     cout<<endl;

    return 0;
}

//Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

