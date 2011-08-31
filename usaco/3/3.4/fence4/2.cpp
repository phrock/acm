/*
  ID:   aphrodi1
  LANG: C++
  PROG: fence4
*/

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
#endif

ifstream fin("fence4.in");
ofstream fout("fence4.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

template<class T>
class Point
{
public:
    Point(T _x = 0, T _y = 0, T _z = 0): x(_x), y(_y), z(_z) {}

    bool operator==(const Point &p) { return x == p.x && y == p.y && z == p.z; }

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

    bool operator==(const Vector &v) { return x == v.x && y == v.y && z == v.z; }

    T size() { return sqrt(x * x + y * y + z * z); }

    T x;
    T y;
    T z;
};

template<class T>
Vector<T> operator*(const Vector<T> &v1,
                    const Vector<T> &v2)
{
    return Vector<T>(v1.y * v2.z - v1.z * v2.y,
                     v1.z * v2.x - v1.x * v2.z,
                     v1.x * v2.y - v1.y * v2.x);
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

template<class T>
bool is_point_on_line(const Point<T> &P,
                      const Point<T> &A,
                      const Point<T> &B)
{
    return distance_from_point_to_line(P, A, B) == 0;
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

bool check_valid(const vector<pair<Point<double>, Point<double> > > &lines)
{
    for (int i = 0; i < (int)(lines).size(); ++i)
        for (int j = 0; j < (int)(lines).size(); ++j)
            if (is_segments_intersect_untouch(lines[i].first, lines[i].second,
                                              lines[j].first, lines[j].second))
                return false;
    return true;
}            

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.second;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    Point<double> p;
    cin >> p.x >> p.y;
    vector< Point<double> > points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    vector<pair<Point<double>, Point<double> > > lines;
    for (int i = 0; i < n; ++i) {
        int j = i == n - 1 ? 0 : i + 1;
        lines.push_back(make_pair(points[i], points[j]));
        for (int k = 0; k < n; ++k)
            if (k != i && k != j && is_point_on_segment(points[k], points[i], points[j])) {
                cout << "NOFENCE" << endl;
                return 0;
            }
    }

    if (!check_valid(lines)) {
        cout << "NOFENCE" << endl;
        return 0;
    }
    vector<pair<int, int> > res;
    for (int i = 0; i < n; ++i) {
        Point<double> p1 = lines[i].first, p2 = lines[i].second;
        // cout << p1.x << " **  " << p1.y << " " << p2.x << " " << p2.y << endl;
        // if (i == 10) {
        //     cout <<"asdfsdfsf"<<endl;
        // }
        if (is_point_on_line(p, p1, p2))
            continue;
        bool ok1 = true, ok2 = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            Point<double> p3 = lines[j].first, p4 = lines[j].second;
            // if ((is_segments_intersect_touch(p, p1, p3, p4) &&
            //      is_points_on_opposite_side_of_line_untouch(p, p2, p3, p4)) ||
            //     (is_segments_intersect_untouch(p, p1, p3, p4)))
            //     ok1 = false;
            // if ((is_segments_intersect_touch(p, p2, p3, p4) &&
            //      is_points_on_opposite_side_of_line_untouch(p, p1, p3, p4)) ||
            //     (is_segments_intersect_untouch(p, p2, p3, p4)))
            //     ok2 = false;

            if (is_segments_intersect_touch(p, p1, p3, p4)) {
                if (p1 == p3  || p1 == p4) {
                    // if (is_points_on_opposite_side_of_line_untouch(p, p2, p3, p4))
                    if (is_segments_intersect_touch(p, p2, p3, p4))
                        ok1 = false;
                } else {
                    ok1 = false;
                }
            }

            if (is_segments_intersect_touch(p, p2, p3, p4)) {
                if (p2 == p3  || p2 == p4) {
                    // if (is_points_on_opposite_side_of_line_untouch(p, p1, p3, p4))
                    if (is_segments_intersect_touch(p, p1, p3, p4))
                        ok2 = false;
                } else {
                    ok2 = false;
                }
            }
            // if (i == 10) {
            //     if (!ok1) cout << "11: "<<j<<endl;
            //     if (!ok2) cout << "22: "<<j<<endl;
            // }
            
        }
        if (ok1 || ok2) {
            if (i != n - 1)
                res.push_back(make_pair(i, i + 1));
            else
                res.push_back(make_pair(0, i));
        }
    }
    // if (is_segments_intersect_touch(p, points[11], points[11], points[12])) {
    //     cout <<"xxx"<<endl;
    // }
    cout << (int)(res).size() << endl;
    sort((res).begin(), (res).end(), cmp);
    for (int i = 0; i < (int)(res).size(); ++i) {
        int p = res[i].first, q = res[i].second;
        cout << points[p].x << " " << points[p].y << " "
             << points[q].x << " " << points[q].y << endl;
    }
}
