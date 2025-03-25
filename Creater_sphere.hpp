#ifndef CREATER_SPHERE_HPP
#define CREATER_SPHERE_HPP

#endif // CREATER_SPHERE_HPP


#include <vector>
#include <cmath>

struct Vertex {
    float x, y, z; // Позиция
    float nx, ny, nz; // Нормаль
};

std::vector<Vertex> createSphere(float radius, int sectors, int stacks) {
    std::vector<Vertex> vertices;

    float sectorStep = 2 * M_PI / sectors;
    float stackStep = M_PI / stacks;

    for (int i = 0; i <= stacks; ++i) {
        float stackAngle = M_PI / 2 - i * stackStep;
        float xy = radius * cosf(stackAngle);
        float z = radius * sinf(stackAngle);

        for (int j = 0; j <= sectors; ++j) {
            float sectorAngle = j * sectorStep;

            float x = xy * cosf(sectorAngle);
            float y = xy * sinf(sectorAngle);

            // Нормаль (нормализованный вектор от центра к вершине)
            float nx = x / radius;
            float ny = y / radius;
            float nz = z / radius;

            vertices.push_back({x, y, z, nx, ny, nz});
        }
    }

    return vertices;
}
