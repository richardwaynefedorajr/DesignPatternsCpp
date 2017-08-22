# include "Flyweight.h"

Rectangle::Rectangle(int height, int width) : m_height(height), m_width(width) { }

RectangleFactory::~RectangleFactory() {
    for ( int i = 0; i < m_existing_rectangles.size(); ++i) { delete m_existing_rectangles.at(i); }
}

Rectangle* RectangleFactory::getRectangle(int height, int width) {
   
    for (int i = 0; i < m_existing_rectangles.size(); ++i) {
        if ( m_existing_rectangles.at(i)->m_height == height && m_existing_rectangles.at(i)->m_width == width ) {
            return m_existing_rectangles.at(i);
        }
    }

    Rectangle *rect = new Rectangle(height,width);

    m_existing_rectangles.push_back(rect);

    return m_existing_rectangles.back();

}

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
