#include <cstdio>

class Square {
private:
    float length;

public:
    float setLength(float l) {
        if (l <= 0) {
            printf("Length must be positive.\n");
            return 0;
        }
        length = l;
        return length;
    }

    float calculateArea() {
        return length * length;
    }
};

class Cube {
private:
    float length;

public:
    float setLength(float l) {
        if (l <= 0) {
            printf("Length must be positive.\n");
            return 0;
        }
        length = l;
        return length;
    }

    float calculateArea() {
        return 6 * length * length;
    }
};

class Rectangle {
private:
    float length, width;

public:
    float setDimensions(float l, float w) {
        if (l <= 0 || w <= 0) {
            printf("Length and Width must be positive.\n");
            return 0;
        }
        length = l;
        width = w;
        return length * width;
    }

    float calculateArea() {
        return length * width;
    }
};

class Cuboid {
private:
    float length, width, height;

public:
    float setDimensions(float l, float w, float h) {
        if (l <= 0 || w <= 0 || h <= 0) {
            printf("Length, Width, and Height must be positive.\n");
            return 0;
        }
        length = l;
        width = w;
        height = h;
        return 2 * (length * width + width * height + height * length);
    }

    float calculateArea() {
        return 2 * (length * width + width * height + height * length);
    }
};

int main() {
    int choice;

    do {
        printf("\nMenu:\n 1. Square\n 2. Cube\n 3. Rectangle\n 4. Cuboid\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Square square;
                float side, area;
                printf("Enter the side length of the square: ");
                scanf("%f", &side);
                if (square.setLength(side)) {
                    area = square.calculateArea();
                    printf("Area of Square: %.2f\n", area);
                }
                break;
            }
            case 2: {
                Cube cube;
                float side, area;
                printf("Enter the side length of the cube: ");
                scanf("%f", &side);
                if (cube.setLength(side)) {
                    area = cube.calculateArea();
                    printf("Surface Area of Cube: %.2f\n", area);
                }
                break;
            }
            case 3: {
                Rectangle rectangle;
                float l, w, area;
                printf("Enter the length of the rectangle: ");
                scanf("%f", &l);
                printf("Enter the width of the rectangle: ");
                scanf("%f", &w);
                if (rectangle.setDimensions(l, w)) {
                    area = rectangle.calculateArea();
                    printf("Area of Rectangle: %.2f\n", area);
                }
                break;
            }
            case 4: {
                Cuboid cuboid;
                float l, w, h, area;
                printf("Enter the length of the cuboid: ");
                scanf("%f", &l);
                printf("Enter the width of the cuboid: ");
                scanf("%f", &w);
                printf("Enter the height of the cuboid: ");
                scanf("%f", &h);
                if (cuboid.setDimensions(l, w, h)) {
                    area = cuboid.calculateArea();
                    printf("Surface Area of Cuboid: %.2f\n", area);
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
