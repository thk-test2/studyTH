#include <iostream>

enum Color       { red = 1, blue };
enum class Shape { rect = 1, circle };

int main() {
    int n1 = red;
    int n2 = Color::red;
    Color c1 = red;
    Color c2 = Color::red;
    // int n3 = rect;
    // int n4 = Shape::rect;
    // Shape s1 = rect;
    Shape s2 = Shape::rect; 
}