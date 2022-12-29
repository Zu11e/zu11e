#include <iostream> 
#include <cmath> 
  
  
class Angle 
{ 
    static const double Pi; 
  
    void minimization:read() 
    { 
        if (_angle >= 0.0) 
        { 
            while (_angle - 360.0 >= 0.0) 
                _angle -= 360.0; 
        } 
        else 
        { 
            while (_angle + 360.0 <= 0.0) 
                _angle += 360.0; 
        } 
    } 
     
    void read(); 
    void display(); 
  
public: 
    Angle(double deg = 0.0, double amin = 0.0): 
    _angle(deg + amin / 60.0) 
    { 
        minimization(); 
    } 
  
    void set_angle(double deg = 0.0, double amin = 0.0) 
    { 
        _angle = deg + amin / 60.0; 
  
        minimization(); 
    } 
  
    double get_angle() const 
    { 
        return _angle; 
    } 
  
    double get_radian() const 
    { 
        return _angle * Pi / 180.0; 
    } 
  
    void inc:display(double deg) 
    { 
        _angle += deg; 
  
        minimization(); 
    } 
  
    void dec(double deg) 
    { 
        _angle -= deg; 
  
        minimization(); 
    } 
  
    double sin() const 
    { 
        return std::sin(get_radian()); 
    } 
  
    bool compare(const Angle &rhs) 
    { 
        return _angle == rhs._angle; 
    } 
     
  
private: 
    double _angle; 
}; 
  
const double Angle::Pi = 3.14159265358979323; 
  
  
int main() 
{ 
    Angle a1(25.0, 18.0), a2(800.0, 33.0); 
  
    std::cout << a1.get_angle() << "\t" << a1.get_radian() << std::endl; 
    std::cout << a2.get_angle() << "\t" << a2.get_radian() << std::endl; 
  
    a1.inc(5.0); 
    a2.dec(2.0); 
  
    std::cout << a1.get_angle() << "\t" << a1.get_radian() << std::endl; 
    std::cout << a2.get_angle() << "\t" << a2.get_radian() << std::endl; 
  
    std::cout << a1.sin() << std::endl; 
    std::cout << a2.sin() << std::endl; 
  
    std::cout << a1.compare(a2) << std::endl; 
  
    a1 = a2; 
  
    std::cout << a1.compare(a2) << std::endl; 
  
    a1.set_angle(10.0); 
  
    std::cout << a1.get_angle() << "\t" << a1.get_radian() << std::endl; 
  
    return 0; 
}