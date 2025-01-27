//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity; // Maximum capacity of the cache
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hash map to store key and iterator to its position in the list

public:
    // Constructor to initialize the cache capacity
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }
        // Move the accessed key-value pair to the end of the list (most recently used)
        cache.splice(cache.end(), cache, map[key]);
        return map[key]->second; // Return the value
    }

    // Function for storing key-value pair
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Key already exists, update the value and move to the end of the list
            cache.splice(cache.end(), cache, map[key]);
            map[key]->second = value;
        } else {
            // Key does not exist, check capacity
            if (cache.size() == capacity) {
                // Remove the least recently used item (front of the list)
                int lruKey = cache.front().first;
                cache.pop_front();
                map.erase(lruKey);
            }
            // Add the new key-value pair to the end of the list
            cache.push_back({key, value});
            map[key] = --cache.end(); // Update the map with the iterator
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends