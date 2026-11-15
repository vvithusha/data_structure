class Shape {
    public:
        virtual float area() = 0;          // pure virtual: Shape is abstract
    };
    
    class Circle : public Shape {
        float r;
    public:
        Circle(float r) : r(r) {}
        float area() override { return 3.14 * r * r; }
    };
    
    class Rectangle : public Shape {
        float w, h;
    public:
        Rectangle(float w, float h) : w(w), h(h) {}
        float area() override { return w * h; }
    };
    int main()
    {
        return 0;
    }