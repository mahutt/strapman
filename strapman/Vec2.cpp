// FOR TESTING - redundant Vec2:: is currently omitted
#include <iostream>
#include <cmath>

class Vec2
{
public:
    float x = 0;
    float y = 0;
    
	Vec2() {}

	Vec2(float xin, float yin) : x(xin), y(yin)
    {
    }

	bool operator == (const Vec2& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

	bool operator != (const Vec2& rhs) const 
    {
        return (x != rhs.x || y != rhs.y);
    }

	Vec2 operator + (const Vec2& rhs) const 
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }
	Vec2 operator - (const Vec2& rhs) const 
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }
	Vec2 operator / (const float val) const
    {
        return Vec2(x/val, y/val);
    }
	Vec2 operator * (const float val) const
    {
        return Vec2(x*val, y*val);
    }

	void operator += (const Vec2& rhs) 
    {
        x += rhs.x;
        y += rhs.y;
    }
	void operator -= (const Vec2& rhs) 
    {
        x -= rhs.x;
        y -= rhs.y;
    }
	void operator /= (const float val) 
    {
        x /= val;
        y /= val;
    }
	void operator *= (const float val) 
    {
        x *= val;
        y *= val;
    }

	float dist(const Vec2& rhs) const
    {
        return sqrtf((rhs.x - x)*(rhs.x - x) + (rhs.y - y)*(rhs.y - y));
    }

	float length() const
    {
        return sqrtf((x*x) + (y*y));
    }

    void normalize() 
    {
        float length = this->length();
        x /= length;
        y /= length;
    }

    // FOR TESTING
    void print() const {
        float length = this->length();
        std::cout << x << " " << y << " - " << length <<  "\n";
    }


};

// FOR TESTING
// int main() {
//     Vec2 a(12, -40);
//     Vec2 b(2.9, -2);
//     Vec2 c(100, 0);

//     a.normalize();
//     b.normalize();
//     c.normalize();

//     a.print();
//     b.print();
//     c.print();
// }
