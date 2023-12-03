#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
struct Destination {
    int Xi;
    int Yi;
    int Hi;
};

struct KnownHeight {
    int Xj;
    int Yj;
    int Hj;
};

struct Node {
    int x, y, time;
};
struct CompareNode {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.time > n2.time;
    }
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N, K, P, Xs, Ys, Hs;
    do {
        std::cin >> N >> K >> P >> Xs >> Ys >> Hs;
    } while (N < 4 || N > 10000 || K < 1 || K > 1000 || P < 0 || P > N*N);

    std::vector<Destination> destinations(K);
    // 1 <= i <= K
    //recieve destinations
    for (int i = 0; i < K; ++i) {
        std::cin >> destinations[i].Xi >> destinations[i].Yi >> destinations[i].Hi;
    }

    std::vector<KnownHeight> knownHeights(P);
    // 1 <= j <= P
    //recieve known heights
    for (int i = 0; i < P; ++i) {
        std::cin >> knownHeights[i].Xj >> knownHeights[i].Yj >> knownHeights[i].Hj;
    }

    std::vector<std::vector<int>> heights(N, std::vector<int>(N, -1));
    std::vector<std::vector<int>> times(N, std::vector<int>(N, INT_MAX));
    for (const KnownHeight& knownHeight : knownHeights) {
        heights[knownHeight.Xj - 1][knownHeight.Yj -1] = knownHeight.Hj;
    }
    heights[Xs-1][Ys-1] = Hs;

    std::priority_queue<Node, std::vector<Node>, CompareNode> pq;
    pq.push({Xs-1, Ys-1, 0});
    times[Xs-1][Ys-1] = 0;

    while (!pq.empty()) {
        Node u = pq.top();
        pq.pop();
        for (int i = 0; i < 4; ++i) {
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < N && heights[x][y] != -1) {
                int time = u.time + abs(heights[u.x][u.y] - heights[x][y]) + 1;
                if (time < times[x][y]) {
                    times[x][y] = time;
                    pq.push({x, y, time});
                }
            }
        }
    }

        int maxTime = INT_MIN;
        int minTime = INT_MAX;
        int unreachable = 0;

        for (const Destination& destination : destinations) {
            int time = times[destination.Xi - 1][destination.Yi - 1];
            if (time == INT_MAX) {
                unreachable++;
            } else {
                if (time > maxTime) {
                    maxTime = time;
                }
                if (time < minTime) {
                    minTime = time;
                }
            }
        }

        if (unreachable > 0) {
            std::cout << unreachable << "\n";
        } else {
            std::cout << maxTime << "\n";
            std::cout << minTime << "\n";
        }

        return 0;
    }