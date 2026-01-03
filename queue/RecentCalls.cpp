// 933. Number of Recent Calls
#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
   private:
    queue<int> reqQueue;

   public:
    RecentCounter() {}

    int ping(int t) {
        reqQueue.push(t);
        // remove all requests older than (t - 3000)ms
        while (reqQueue.front() < t - 3000) reqQueue.pop();
        return reqQueue.size();
    }
};

int main() {
    RecentCounter counter;
    cout << counter.ping(642) << endl;  // 1
    cout << counter.ping(1849) << endl;
    cout << counter.ping(4921) << endl;
    cout << counter.ping(5936) << endl;
    cout << counter.ping(5957) << endl;

    return 0;
}
