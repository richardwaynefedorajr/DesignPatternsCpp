// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Declarations for implementation of the flyweight design pattern, in which a factory is used to create and store instances of a rectangle class, with intrinsic dimensions and an extrinsic location to be drawn in the terminal

# include <string>
# include <iostream>
# include <vector>
# include <memory>

// Declare product class
class Rectangle {
    public:
        Rectangle(int height, int width);
        void draw(int x_corner, int y_corner);
        int m_height, m_width;
};

// Declare flyweight to manage product instances
class RectangleFactory {
    public:
        std::shared_ptr<Rectangle> getRectangle(int height, int width);
    private:
        std::vector< std::shared_ptr<Rectangle> > m_existing_rectangles;
};
