#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <vector>

// Structure for obstacles
struct Obstacle {
    int startX, startY;
    int length;
    char direction; // 'H' for horizontal, 'V' for vertical
};

// Function to load obstacles from this file
std::vector<Obstacle> loadObstacles() {
    std::vector<Obstacle> obstacles;

    // Horizontal dashed lines
    obstacles.push_back({ 4, 3, 10, 'H' });  // Line 1: Starting at (4,3) with a length of 5
    obstacles.push_back({ 8, 5, 5, 'H' });  // Line 2: Starting at (8,5) with a length of 5
    obstacles.push_back({ 6, 7, 6, 'H' });  // Line 3: Starting at (6,7) with a length of 6

    return obstacles;
}

#endif // OBSTACLES_H
