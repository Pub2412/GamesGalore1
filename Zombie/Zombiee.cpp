#include <iostream>
#include <vector>
#include <queue>

int hoursUntilInfectionSpreads(std::vector<std::vector<int>>& grid) {
    int hours = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    std::queue<std::pair<int, int>> q;

    // Enqueue all initial zombie positions
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) { // 1 represents zombies
                q.push(std::make_pair(i, j));
            }
        }
    }

    // Directions for movement (down, up, right, left)
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Perform BFS
    while (!q.empty()) {
        int size = q.size();
        bool spread = false; // To check if infection spread in this hour

        for (int i = 0; i < size; ++i) {
            std::pair<int, int> current = q.front();
            q.pop();

            for (int j = 0; j < 4; ++j) {
                int newX = current.first + directions[j][0];
                int newY = current.second + directions[j][1];

                // Check if the new position is valid, contains a human (0), and is not a wall (2)
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 0) {
                    grid[newX][newY] = 1; // Mark as infected
                    q.push(std::make_pair(newX, newY));
                    spread = true; // Infection has spread
                }
            }
        }

        // Increase hours only if infection spread during this level of BFS
        if (spread) {
            hours++;
        }
    }

    // Check if any humans remain
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) return -1; // Humans remain
        }
    }

    return hours; // Return the total hours taken for infection to spread
}

int main() {
    // Example city grid 
    std::vector<std::vector<int>> city = {
        {2, 0, 0, 0},
        {0, 1, 2, 0},
        {2, 0, 1, 0},
        {0, 2, 0, 0}
    };

    int result = hoursUntilInfectionSpreads(city);
    if (result != -1) {
        std::cout << "Total hours until no humans are left: " << result << std::endl;
    } else {
        std::cout << "Humans survived! Not all are infected." << std::endl;
    }

    return 0;
}

