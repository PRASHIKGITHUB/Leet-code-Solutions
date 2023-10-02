#include <bits/stdc++.h>
using namespace std;
//T.C->(n*m);
//S.C->O(1)
// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     string ans;
//     for (int i = 0; i < arr[0].size(); i++)
//     {
//         char ch = arr[0][i];
//         bool match = true;
//         for (int j = 1; j < n; j++)
//         {
//             // not match
//             if (arr[j].size() < i || ch != arr[j][i])
//             {
//                 match = false;
//                 break;
//             }
//         }
//         if (match == false)
//         {
//             break;
//         }
//         else
//         {
//             ans.push_back(ch);
//         }
//     }
//     return ans;
// }



//T.C->(n*m)
//S.C->O(n*m)
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption word will be in caps
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) // O(length of word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // aage badhjao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // insert kardo all string  into trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}
