#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        auto &arr = store[key];
        int l = 0, r = arr.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= timestamp) {
                res = arr[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl; 
    cout << timeMap.get("foo", 3) << endl; 
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl; 
    cout << timeMap.get("foo", 5) << endl; 
    return 0;
}