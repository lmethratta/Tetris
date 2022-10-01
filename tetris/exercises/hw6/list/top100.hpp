#include <vector>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class top100 {
    private:
        vector<T> list;
    public:
        top100() {}
        void addItem(T item) {
            for(int i = 0; i < list.size(); i++) {
                if(list[i] == item) {
                    // If item already exist: Remove it
                    removeItem(list[i]);
                    // And readd it, to update it
                    list.push_back(item);
                    sort(list.begin(), list.end());
                    return;
                }
            }
            // Add item and sort vector
            list.push_back(item);
            sort(list.begin(), list.end());
        }
        void addItems(vector<T> items) {
            // Add each item in items to list
            for(int i = 0; i < items.size(); i++) {
                addItem(items[i]);
            }
        }
        int itemRanking(T item) {
            for(int i = 0; i < list.size(); i++) {
                if(list[i] == item) {
                    if(i > 99) {
                        // Return -1 if not in the top 100
                        return -1;
                    } else {
                        // Return ranking if item was found
                        return i + 1;
                    }
                }
            }
            return -1;
        }
        void removeItem(T item) {
            for(int i = 0; i < list.size(); i++) {
                if(list[i] == item) {
                    // If found: Remove item from list
                    list.erase(list.begin() + i);
                    return;
                }
            }
        }
        void removeItems(vector<T> items) {
            // Remove each item in items
            for(int i = 0; i < items.size(); i++) {
                removeItem(items[i]);
            }
        }
        int numItems() {
            if(list.size() > 100) {
                return 100;
            }
            return list.size();
        }
};