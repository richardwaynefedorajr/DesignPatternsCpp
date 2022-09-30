// This file belongs to DesignPatternsCpp, a project designed to test and explore various C++ design patterns
// This source code is available under the MIT License
// Description: Definitions for implementation of the flyweight design pattern, in which a factory is used to create and store instances of a rectangle class, with intrinsic dimensions and an extrinsic location to be drawn in the terminal

# include "Flyweight.h"

// Define product constructor
Rectangle::Rectangle(int height, int width) : m_height(height), m_width(width) { }

// Define functionality to return existing or new product instance depending on whether an instance exists with desired parameters or not
std::shared_ptr<Rectangle> RectangleFactory::getRectangle(int height, int width) {
   
    for (int i = 0; i < m_existing_rectangles.size(); ++i) {
        if ( m_existing_rectangles.at(i)->m_height == height && m_existing_rectangles.at(i)->m_width == width ) {
            return m_existing_rectangles.at(i);
        }
    }

    std::shared_ptr<Rectangle> rect( new Rectangle(height,width) );

    m_existing_rectangles.push_back(rect);

    return m_existing_rectangles.back();

}

// Define functionality to display product
void Rectangle::draw(int x_corner, int y_corner) {

    std::cout << m_height << "x" << m_width << " rectangle at " << x_corner << "," << y_corner << std::endl;

    for ( int j = 0; j < y_corner; ++j) {
        std::cout << std::endl;
    }

    for ( int j = 0; j < m_height; ++j) {
        for ( int i = 0; i < x_corner; ++i ) {
            std::cout << " ";
        }
        for ( int i = 0; i < m_width; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
} 

int main(int argc, char *argv[]) {
   
    std::cout << "Flyweight design pattern test:" << std::endl;

    RectangleFactory rf;
    std::shared_ptr<Rectangle> rect1 = rf.getRectangle(3,2);
    std::shared_ptr<Rectangle> rect2 = rf.getRectangle(2,2);
    rect1->draw(0,0);    
    rect2->draw(1,1);    

    std::cout << "Check pointers: rect1 - " << rect1 << " rect2 - " << rect2 << std::endl;
    
    return 0;

} 
