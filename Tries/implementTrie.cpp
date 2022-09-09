#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class trie{
private:
    trie *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    trie* root;
    void put(char ch, trie* node){
        links[ch - 'a'] = node;
    }
    trie* get(char ch){
        return links[ch - 'a'];
    }
    bool setEnd(){
        flag = false;
    }
    bool isEnd(){
        return flag;
    }
public:
    trie(){
        root = new trie();
    }
    // insert a word into the trie
    void insert(string word){
        trie* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i], new trie());
            }
            node->get(word[i]); //moves to reference trie
        }
        node->setEnd();
    }
    bool search(string word){
        trie *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        trie *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
    
};
int main()
{
   return 0;
}