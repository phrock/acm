template<class T>
class Point
{
public:
    Point(T _x = 0, T _y = 0, T _z = 0): x(_x), y(_y), z(_z) {}

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y && z == p.z;
    }

    T x;
    T y;
    T z;
};

template<class T>
class Vector
{
public:
    Vector(T x = 0, T y = 0, T z = 0): x(x), y(y), z(z) {}

    Vector(const Point<T> &p): x(p.x), y(p.y), z(p.z) {}

    Vector(const Point<T> &tail, const Point<T> &head):
        x(head.x - tail.x), y(head.y - tail.y), z(head.z - tail.z) {}

    bool operator==(const Vector &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    T size() { return sqrt(x * x + y * y + z * z); }

    T x;
    T y;
    T z;
};

template<class T>
Vector<T> operator+(const Vector<T> &v1,
                    const Vector<T> &v2)
{
    return Vector<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template<class T>
Vector<T> operator-(const Vector<T> &v1,
                    const Vector<T> &v2)
{
    return Vector<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<class T>
Vector<T> operator*(const T &scalar,
                    const Vector<T> &v)
{
    return Vector<T>(scalar * v.x, scalar * v.y, scalar * v.z);
}

template<class T>
Vector<T> operator*(const Vector<T> &v,
                    const T &scalar)
{
    return Vector<T>(scalar * v.x, scalar * v.y, scalar * v.z);
}

// cross product
template<class T>
Vector<T> operator*(const Vector<T> &v1,
                    const Vector<T> &v2)
{
    return Vector<T>(v1.y * v2.z - v1.z * v2.y,
                     v1.z * v2.x - v1.x * v2.z,
                     v1.x * v2.y - v1.y * v2.x);
}

// cross product
template<class T>
Vector<T> cross_product(const Vector<T> &v1,
                        const Vector<T> &v2)
{
    return Vector<T>(v1.y * v2.z - v1.z * v2.y,
                     v1.z * v2.x - v1.x * v2.z,
                     v1.x * v2.y - v1.y * v2.x);
}

// dot product
template<class T>
T operator^(const Vector<T> &v1,
            const Vector<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// dot product
template<class T>
T dot_product(const Vector<T> &v1,
              const Vector<T> &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<class T>
T triangle_area_point(const Point<T> &p1,
                      const Point<T> &p2,
                      const Point<T> &p3)
{
    Vector<T> v1(p1, p2);
    Vector<T> v2(p1, p3);
    Vector<T> v3 = v1 * v2;
    return v3.size() / 2;
}

// using Hero's formula
template<class T>
T triangle_area_edge(const T &a,
                     const T &b,
                     const T &c)
{
    T s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

template<class T>
T polygon_area(const vector< Point<T> > &points)
{
    T res = 0;
    for (int i = 0; i < (int)(points).size(); ++i) {
        int idx1 = i;
        int idx2 = i == (int)(points).size() - 1 ? 0 : i + 1;
        res += points[idx1].x * points[idx2].y - points[idx1].y * points[idx2].x;
    }
    if (res < 0) res = -res;
    return res / 2;
}

template<class T>
T distance_from_point_to_point(const Point<T> &P,
                               const Point<T> &Q)
{
    return Vector<T>(P, Q).size();
}

// point: P, line: AB
// distance: d(P,AB) = |(P - A) x (B - A)| / |B - A|
template<class T>
T distance_from_point_to_line(const Point<T> &P,
                              const Point<T> &A,
                              const Point<T> &B)
{
    return (Vector<T>(A, P) * Vector<T>(A, B)).size() / Vector<T>(A, B).size();
}

// point: P, line: ABC
// let v = (B - A) x (C - A), distance: d(P,ABC) = (P - A) · v / |v|
template<class T>
T distance_from_point_to_plane(const Point<T> &P,
                               const Point<T> &A,
                               const Point<T> &B,
                               const Point<T> &C)
{
    Vector<T> v = Vector<T>(A, B) * Vector<T>(A, C);
    T res = (Vector<T>(A, P) ^ v) / v.size();
    return res < 0 ? -res : res;
}

template<class T>
bool is_parallel(const Vector<T> &v1,
                 const Vector<T> &v2)
{
    return (v1 * v2).size() == 0;
}

template<class T>
bool is_point_on_line(const Point<T> &P,
                      const Point<T> &A,
                      const Point<T> &B)
{
    return distance_from_point_to_line(P, A, B) == 0;
}

template<class T>
bool is_point_on_segment(const Point<T> &P,
                         const Point<T> &A,
                         const Point<T> &B)
{
    return is_point_on_line(P, A, B) &&
        (distance_from_point_to_point(A, B) ==
         distance_from_point_to_point(A, P) +
         distance_from_point_to_point(B, P));
}

// point P and Q on the same side of line AB or on line AB
template<class T>
bool is_points_on_same_side_of_line_touch(const Point<T> &P,
                                          const Point<T> &Q,
                                          const Point<T> &A,
                                          const Point<T> &B)
{
    Vector<T> v1 = Vector<T>(A, B) * Vector<T>(A, P);
    Vector<T> v2 = Vector<T>(A, B) * Vector<T>(A, Q);
    return v1.z * v2.z >= 0;
}

// point P and Q on the same side of line AB, NOT on line AB
template<class T>
bool is_points_on_same_side_of_line_untouch(const Point<T> &P,
                                            const Point<T> &Q,
                                            const Point<T> &A,
                                            const Point<T> &B)
{
    Vector<T> v1 = Vector<T>(A, B) * Vector<T>(A, P);
    Vector<T> v2 = Vector<T>(A, B) * Vector<T>(A, Q);
    return v1.z * v2.z > 0;
}

// point P and Q on the opposite side of line AB or on line AB
template<class T>
bool is_points_on_opposite_side_of_line_touch(const Point<T> &P,
                                              const Point<T> &Q,
                                              const Point<T> &A,
                                              const Point<T> &B)
{
    return !is_points_on_same_side_of_line_untouch(P, Q, A, B);
}

// point P and Q on the opposite side of line AB, NOT on line AB
template<class T>
bool is_points_on_opposite_side_of_line_untouch(const Point<T> &P,
                                              const Point<T> &Q,
                                              const Point<T> &A,
                                              const Point<T> &B)
{
    return !is_points_on_same_side_of_line_touch(P, Q, A, B);
}

// check if segment AB and CD intersect
template<class T>
bool is_segments_intersect_touch(const Point<T> &A,
                                 const Point<T> &B,
                                 const Point<T> &C,
                                 const Point<T> &D)
{
    return is_points_on_opposite_side_of_line_touch(A, B, C, D) &&
        is_points_on_opposite_side_of_line_touch(C, D, A, B);
}

// check if segment AB and CD intersect
template<class T>
bool is_segments_intersect_untouch(const Point<T> &A,
                                   const Point<T> &B,
                                   const Point<T> &C,
                                   const Point<T> &D)
{
    return is_points_on_opposite_side_of_line_untouch(A, B, C, D) &&
        is_points_on_opposite_side_of_line_untouch(C, D, A, B);
}
