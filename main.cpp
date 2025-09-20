#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

//given weights with positive numbers 
unordered_map<string, vector<pair<string, int>>> connectionMap = {
    {"A", {{"B", 1}, {"C", 4}}},
    {"B", {{"C", 2}, {"D", 5}, {"E", 8}}},
    {"C", {{"D", 1}, {"E", 3}}},
    {"D", {{"E", 2}}},
    {"E", {}}
};

struct RouteNode {
    string label;
    int totalWeight;
    vector<string> routeTrace;
    bool operator>(const RouteNode& rhs) const { return totalWeight > rhs.totalWeight; }
};

pair<int, vector<string>> findMinimumRoute(const string& origin, const string& destination) {
    priority_queue<RouteNode, vector<RouteNode>, greater<RouteNode>> nextRoutes;
    unordered_map<string, int> minimumReached;
    unordered_map<string, vector<string>> pathToNode;

    nextRoutes.push({origin, 0, {origin}});
    minimumReached[origin] = 0;
    pathToNode[origin] = {origin};

    while (!nextRoutes.empty()) {
        RouteNode present = nextRoutes.top(); nextRoutes.pop();
        if (present.label == destination)
            return {present.totalWeight, present.routeTrace};
        for (auto& neighbor : connectionMap[present.label]) {
            int candidateWeight = present.totalWeight + neighbor.second;
            if (!minimumReached.count(neighbor.first) || candidateWeight < minimumReached[neighbor.first]) {
                minimumReached[neighbor.first] = candidateWeight;
                vector<string> newTrace = present.routeTrace;
                newTrace.push_back(neighbor.first);
                pathToNode[neighbor.first] = newTrace;
                nextRoutes.push({neighbor.first, candidateWeight, newTrace});
            }
        }
    }
    return {numeric_limits<int>::max(), {}};
}

int main() {
    string startLabel, endLabel;
    cout << "Type the beginning label (A-E): ";
    cin >> startLabel;
    cout << "Type the target label (A-E): ";
    cin >> endLabel;

    if (!connectionMap.count(startLabel) || !connectionMap.count(endLabel)) {
        cout << "Out of range nodes!\n";
        return 1;
    }
    auto outcome = findMinimumRoute(startLabel, endLabel);
    if (outcome.first == numeric_limits<int>::max()) {
        cout << "No available path found.\n";
    } else {
        cout << "Route from " << startLabel << " to " << endLabel << " is: ";
        for (size_t pos = 0; pos < outcome.second.size(); ++pos) {
            cout << outcome.second[pos];
            if (pos + 1 < outcome.second.size()) cout << " -> ";
        }
        cout << " with total cost " << outcome.first << endl;
    }
    return 0;
}
