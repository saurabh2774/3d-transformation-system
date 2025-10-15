#include "vector3d.h"
#include "matrix4x4.h"
#include <iostream>

int main() {
    std::cout << "=== 3D Transformation Demo ===\n\n";

    
    float x, y, z;
    std::cout << "Enter vector (x y z): ";
    std::cin >> x >> y >> z;
    Vector3D v(x, y, z);


    int choice;
    Matrix4x4 transform = Matrix4x4::identity();

    do {
        std::cout << "\nChoose Transformation:\n";
        std::cout << "1. Translate\n";
        std::cout << "2. Scale\n";
        std::cout << "3. Rotate X\n";
        std::cout << "4. Rotate Y\n";
        std::cout << "5. Rotate Z\n";
        std::cout << "6. Apply and Show Result\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            float tx, ty, tz;
            std::cout << "Enter translation (tx ty tz): ";
            std::cin >> tx >> ty >> tz;
            transform = transform * Matrix4x4::createTranslation(Vector3D(tx, ty, tz));
        } 
        else if (choice == 2) {
            float sx, sy, sz;
            std::cout << "Enter scale (sx sy sz): ";
            std::cin >> sx >> sy >> sz;
            transform = transform * Matrix4x4::createScale(Vector3D(sx, sy, sz));
        } 
        else if (choice == 3) {
            float angle;
            std::cout << "Enter rotation angle (degrees around X): ";
            std::cin >> angle;
            transform = transform * Matrix4x4::createRotationX(angle);
        } 
        else if (choice == 4) {
            float angle;
            std::cout << "Enter rotation angle (degrees around Y): ";
            std::cin >> angle;
            transform = transform * Matrix4x4::createRotationY(angle);
        } 
        else if (choice == 5) {
            float angle;
            std::cout << "Enter rotation angle (degrees around Z): ";
            std::cin >> angle;
            transform = transform * Matrix4x4::createRotationZ(angle);
        } 
        else if (choice == 6) {
            Vector3D result = transform * v;
            std::cout << "\nOriginal Vector: " << v << std::endl;
            std::cout << "Transformed Vector: " << result << std::endl;
            break;
        } 
        else {
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (true);

    return 0;
}
