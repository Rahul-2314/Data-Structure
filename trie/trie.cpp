#include <iostream>
using namespace std;

/*
    TrieNode represents a single character node in the Trie.
*/
class TrieNode {
public:
    char data;                    // Character stored in this node
    TrieNode* children[26];       // Pointers to child nodes (a-z)
    bool isTerminal;              // Marks end of a complete word

    // Constructor
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

/*
    Trie class provides insert, search, and erase functionalities.
*/
class Trie {
public:
    TrieNode* root;

    // Constructor initializes root node with null character
    Trie() {
        root = new TrieNode('\0');
    }

    /* ================= INSERTION ================= */

    // Recursive helper function for insertion
    void insertUtil(TrieNode* root, string word) {
        // Base case: end of word
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';   // Calculate index (0-25)
        TrieNode* child;

        // If character already exists
        if (root->children[index] != nullptr) {
            child = root->children[index];
        }
        else {
            // Create new node if character does not exist
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call for remaining word
        insertUtil(child, word.substr(1));
    }

    // Public insert function
    void insertWord(string word) {
        insertUtil(root, word);
    }

    /* ================= SEARCH ================= */

    // Recursive helper function for searching
    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        // If character not present
        if (root->children[index] == nullptr) {
            return false;
        }

        // Recursive search
        return searchUtil(root->children[index], word.substr(1));
    }

    // Public search function
    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    /* ================= ERASE / DELETE ================= */

    /*
        Recursive function to delete a word from Trie.
        Returns true if the node can be safely deleted.
    */
    bool eraseUtil(TrieNode* root, string word, int depth = 0) {
        // Base case: end of word
        if (depth == word.length()) {
            // Word exists, unmark terminal
            if (!root->isTerminal)
                return false;

            root->isTerminal = false;

            // Check if node has no children
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != nullptr)
                    return false;
            }
            return true; // Node can be deleted
        }

        int index = word[depth] - 'a';
        TrieNode* child = root->children[index];

        // Word not found
        if (child == nullptr)
            return false;

        // Recursive deletion
        bool shouldDeleteChild = eraseUtil(child, word, depth + 1);

        // If child node can be deleted
        if (shouldDeleteChild) {
            delete child;
            root->children[index] = nullptr;

            // Check if current node can also be deleted
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != nullptr)
                        return false;
                }
                return true;
            }
        }
        return false;
    }

    // Public erase function
    void eraseWord(string word) {
        eraseUtil(root, word);
    }
};

/* ================= MAIN FUNCTION ================= */

int main() {
    Trie* t = new Trie();

    // Insert words
    t->insertWord("abcd");
    t->insertWord("abc");

    // Search before deletion
    cout << "Searching 'abcd': " << t->searchWord("abcd") << endl;
    cout << "Searching 'abc': " << t->searchWord("abc") << endl;

    // Delete a word
    t->eraseWord("abcd");

    // Search after deletion
    cout << endl << "After deleting 'abcd'" << endl;
    cout << "Searching 'abcd': " << t->searchWord("abcd") << endl;
    cout << "Searching 'abc': " << t->searchWord("abc") << endl;

    return 0;
}
