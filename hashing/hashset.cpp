#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    static const int BUCKETS = 1000;
    vector<vector<int>> table;

    int hash(int key) {
        return key % BUCKETS; 
    }

public:
    MyHashSet() : table(BUCKETS) {}

    void add(int key) {
        int bucket = hash(key);
        for (int val : table[bucket]) {
            if (val == key) return; 
        }
        table[bucket].push_back(key);
    }

    void remove(int key) {
        int bucket = hash(key);
        for (auto it = table[bucket].begin(); it != table[bucket].end(); ++it) {
            if (*it == key) {
                table[bucket].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int bucket = hash(key);
        for (int val : table[bucket]) {
            if (val == key) return true;
        }
        return false;
    }
};



int main(){
    MyHashSet* obj = new MyHashSet();
    
    // Example operations
    obj->add(1);
    obj->add(2);
    cout << "Contains 1: " << (obj->contains(1) ? "Yes" : "No") << endl; // Expected: Yes
    cout << "Contains 3: " << (obj->contains(3) ? "Yes" : "No") << endl; // Expected: No
    obj->add(3);
    cout << "Contains 3 after adding: " << (obj->contains(3) ? "Yes" : "No") << endl; // Expected: Yes
    obj->remove(2);
    cout << "Contains 2 after removing: " << (obj->contains(2) ? "Yes" : "No") << endl; // Expected: No
    
    // Clean up
    delete obj;
    return 0;
}