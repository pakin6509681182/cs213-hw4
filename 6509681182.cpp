//6509681182 Pakin Pratkittikul
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
//store all 4 possible directions
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N, K, P, Xs, Ys, Hs;
    do {
        std::cin >> N >> K >> P >> Xs >> Ys >> Hs;
    } while (N < 4 || N > 10000 || K < 1 || K > 1000 || P < 0 || P > N*N);

    std::vector<Destination> destinations(K);
    // 1 <= i <= K
    //recieve destinations from user
    for (int i = 0; i < K; ++i) {
        std::cin >> destinations[i].Xi >> destinations[i].Yi >> destinations[i].Hi;
    }

    std::vector<KnownHeight> knownHeights(P);
    // 1 <= j <= P
    //recieve known heights from user
    for (int i = 0; i < P; ++i) {
        std::cin >> knownHeights[i].Xj >> knownHeights[i].Yj >> knownHeights[i].Hj;
    }

    std::vector<std::vector<int>> heights(N, std::vector<int>(N, -1));
    std::vector<std::vector<int>> times(N, std::vector<int>(N, INT_MAX));
    for (const KnownHeight& knownHeight : knownHeights) {
        heights[knownHeight.Xj - 1][knownHeight.Yj -1] = knownHeight.Hj; //assign known heights
    }
    heights[Xs-1][Ys-1] = Hs; //assign start height

    std::priority_queue<Node, std::vector<Node>, CompareNode> pq;
    //push and set time = 0 for starting node
    pq.push({Xs-1, Ys-1, 0});
    times[Xs-1][Ys-1] = 0;

    while (!pq.empty()) {
        Node u = pq.top();
        //Node u are the nodes with the shortest time
        pq.pop();
        //check all 4 directions with loop
        for (int i = 0; i < 4; ++i) {
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < N && heights[x][y] != -1) {
                int time = u.time + abs(heights[u.x][u.y] - heights[x][y]) + 1;
                //when found a shorter path to a node, update the time and push it to the queue
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
        //printf("time: %d\n", time);
        //if it is unreachable, increment unreachable
        if (time == INT_MAX) {
            unreachable++;
        } else {
            //printf("maxTime: %d\n", maxTime);
            if (time > maxTime) {
                maxTime = time;
                //printf("maxTime: %d\n", maxTime);
            }
            if (time < minTime) {
                minTime = time;
                //printf("minTime: %d\n", minTime);
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