# include <string>
# include <iostream>
# include <vector>

class Rectangle {
    public:
        Rectangle(int height, int width);
        void draw(int x_corner, int y_corner);
        int m_height, m_width;
};

class RectangleFactory {
    public:
        ~RectangleFactory();
        Rectangle *getRectangle(int height, int width);
    private:
        std::vector<Rectangle*> m_existing_rectangles;
};
