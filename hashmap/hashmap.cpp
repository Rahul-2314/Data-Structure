#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

// unordered map
// - uses hashtable internally
// - not follow any order - stored in an arbitrary order.
// - search, insertion, deletion -> O(1)  worst case - O(n)

// map
// - uses self balancing BST (red-black tree) internally
// - follow a specific order (stored in sorted order by key)
// - search, insertion, deletion -> O(log n)  worst case - O(log n)

int main(){
    // creation
    unordered_map<string, int> mp;

    // insertion

    // 1
    pair<string, int> p = make_pair("apple", 1);
    mp.insert(p);

    // 2
    pair<string, int> p2("ball", 2);
    mp.insert(p2);

    // 3
    mp["cat"] = 3;

    // search
    cout<< "value of apple :" << mp["apple"] <<endl;
    cout<< "value of ball :" << mp.at("ball") <<endl;

    // search condition - unknown key
    cout<< "value of any unknown key :";
    //cout<< mp.at("uknownKey") <<endl;   //error - key not found
    cout<< mp["uknownKey"] <<endl;  //create key and value with 0

    // size
    cout<< "size :" << mp.size() <<endl;

    // check presence (present - 1, not present - 0)
    cout<< "check presence (cat):"<< mp.count("cat") <<endl;

    // erase
    cout<< "erasing ball" <<endl;
    mp.erase("ball");
    cout<< "size (updated):" << mp.size() <<endl;

    // accessing elements of unordered map

    // normal traversal
    cout<< endl << "accessing elements - (normal) :" <<endl;
    for(auto &i : mp){
        cout<< i.first <<" -> " <<i.second <<endl;
    }

    // iterator
    cout<< endl << "accessing elements - (iterator) :" <<endl;
    unordered_map<string, int> :: iterator it = mp.begin();

    while(it != mp.end()){
        cout<< it->first <<" -> " <<it->second <<endl;
        it++;
    }

    return 0;
}

// what is hash table ? ==========================================

// A hash table is a fast data structure that stores data as key-value pairs,
// using a hash function to convert a key into an array index (a "bucket") for quick storage and retrieval,
// enabling near-constant time lookups, insertions, and deletions,
// much like a digital phonebook mapping names (keys) to numbers (values).

// How it Works : ==================================================================

// Key-Value Pairs : Data is stored as a pair, 
// like{"name" : "Alice", "phone" : "123-4567"} where "name" and "Alice" are the key and value.

// Hash Function : A mathematical function takes the key(e.g., "name") and produces a unique integer(the "hash code").
// Array / Buckets : This hash code is then used(often with the modulo operator%) to determine the specific index(bucket)
// in an underlying array where the value is stored.

// Fast Access: When you need to find a value, you hash its key, get the index, and go directly to that bucket,
// avoiding slow searches through entire lists. 

// Key Benefits : ======================================================================

// Speed: Offers extremely fast average performance for finding, adding, and removing data, even with large datasets.
// Efficiency: Ideal for scenarios needing quick lookups, like username/password checks or database indexing. 

// Challenges (Collisions) : ===================================================

// Collisions: When two different keys produce the same hash code, a "collision" occurs.
// Resolution: Techniques like chaining (using linked lists within buckets) or open addressing handle collisions to maintain performance.

// ======================================================================================================
// ============================================================
//              COLLISION RESOLUTION TECHNIQUES
// ============================================================
//
// There are mainly two methods to handle collisions in hashing:
//
// ------------------------------------------------------------
// 1) OPEN HASHING (SEPARATE CHAINING) : ==================================================
// ------------------------------------------------------------
// - Each index of the hash table contains a linked list.
// - All keys that hash to the same index are stored in that list.
// - Collision is resolved by chaining elements together.
//
// Example:
//   index i  ->  key1 -> key2 -> key3
//
// Advantages:
// - Easy to implement
// - Hash table never becomes completely full
//
// Disadvantages:
// - Extra memory required for pointers
// - Performance decreases if chains grow long
//
//
// ------------------------------------------------------------
// 2) OPEN ADDRESSING : ===============================================================
// ------------------------------------------------------------
// - All elements are stored directly inside the hash table.
// - On collision, we probe for another empty slot.
//
// Types of Open Addressing:
//
// ------------------------------------------------------------
// a) LINEAR PROBING
// ------------------------------------------------------------
// - If collision occurs at index h, check:
//   (h + 1), (h + 2), (h + 3) ... until an empty slot is found
//
// Formula:
//   h(i) = (h(key) + i) % table_size
//
// Drawback:
// - Causes primary clustering
//
//
// ------------------------------------------------------------
// b) QUADRATIC PROBING
// ------------------------------------------------------------
// - Uses quadratic increments to find next index
//
// Formula:
//   h(i) = (h(key) + i*i) % table_size
//
// Advantage:
// - Reduces primary clustering
//
// Drawback:
// - Causes secondary clustering
//
//
// ------------------------------------------------------------
// c) DOUBLE HASHING
// ------------------------------------------------------------
// - Double hashing uses two hash functions: h1(key) and h2(key)
// - h1(key) gives the initial index
// - h2(key) gives the step size for probing
//
// Formula:
//   h(i) = (h1(key) + i * h2(key)) % table_size
//
// Advantage:
// - Best collision resolution among open addressing methods
// - Minimizes clustering
//
// Disadvantage:
// - More complex to implement
//
// ============================================================
