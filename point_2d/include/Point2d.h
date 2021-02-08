
#ifndef POINT_2D
#define POINT_2D 

class Point2d{ 
private:
    double m_x{0};
    double m_y{0};
public:
    Point2d(double x=0.0, double y=0.0): m_x{x}, m_y{y}{

    }

    double getX ()const{
        return m_x;
    }
    double getY ( )const{
        return m_y;
    }

    void print () const; 
    double distanceTo (Point2d p) const;
};


#endif /* ifndef POINT_2D */
