#include <iostream>
#include <map>

using namespace std;

using node = pair<int, int>;

class MyCalendar {
    // list<node> l;
    map<int, int> events;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if (next != events.end() && next->second < end)
            return false;

        events.insert({ end, start });
        return true;
    }

    //     bool book(int start, int end) {
    //         auto it = find_if(l.begin(), l.end(), 
    //                        [&](node& a) {
    //                         return (a.first < end && a.second > start); });

    //         if (it == l.end()) {
    //             l.insert(l.end(), {start, end});
    //             return true;
    //         }
    //         return false;
    //     }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
	
	return 0;
}