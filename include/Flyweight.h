# include <string>
# include <iostream>
# include <vector>
# include <memory>

class Rectangle {
    public:
        Rectangle(int height, int width);
        void draw(int x_corner, int y_corner);
        int m_height, m_width;
};

class RectangleFactory {
    public:
        std::shared_ptr<Rectangle> getRectangle(int height, int width);
    private:
        std::vector< std::shared_ptr<Rectangle> > m_existing_rectangles;
};
