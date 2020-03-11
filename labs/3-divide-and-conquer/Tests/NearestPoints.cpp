/*
 * NearestPoints.cpp
 */

#include <limits>
#include <thread>
#include <algorithm>
#include <cmath>
#include "NearestPoints.h"
#include "Point.h"

const double MAX_DOUBLE = std::numeric_limits<double>::max();

Result::Result(double dmin, Point p1, Point p2) {
    this->dmin = dmin;
    this->p1 = p1;
    this->p2 = p2;
}

Result::Result() {
    this->dmin = MAX_DOUBLE;
    this->p1 = Point(0, 0);
    this->p2 = Point(0, 0);
}

/**
 * Auxiliary functions to sort vector of points by X or Y axis.
 */
static void sortByX(vector<Point> &v, int left, int right) {
    std::sort(v.begin() + left, v.begin() + right + 1,
              [](Point p, Point q) { return p.x < q.x || (p.x == q.x && p.y < q.y); });
}

static void sortByY(vector<Point> &v, int left, int right) {
    std::sort(v.begin() + left, v.begin() + right + 1,
              [](Point p, Point q) { return p.y < q.y || (p.y == q.y && p.x < q.x); });
}

/**
 * Brute force algorithm O(N^2).
 */
Result nearestPoints_BF(vector<Point> &vp) {
    Result res;
    res.dmin = MAX_DOUBLE;
    double aux;
    for (auto x = vp.begin(); x != vp.end(); ++x)
        for (auto y = x + 1; y != vp.end(); ++y) {
            aux = x->distance(*y);
            if (aux < res.dmin) {
                res.dmin = aux;
                res.p1 = *x;
                res.p2 = *y;
            }
        }
    return res;
}

/**
 * Improved brute force algorithm, that first sorts points by X axis.
 */
Result nearestPoints_BF_SortByX(vector<Point> &vp) {
    Result res;
    sortByX(vp, 0, vp.size() - 1);
    res.dmin = MAX_DOUBLE;
    double aux;
    for (auto x = vp.begin(); x != vp.end(); ++x)
        for (auto y = x + 1; y != vp.end(); ++y) {
            if(y->x - x->x >= res.dmin)
                break;
            aux = x->distance(*y);
            if (aux < res.dmin) {
                res.dmin = aux;
                res.p1 = *x;
                res.p2 = *y;
            }
        }
    return res;
}


/**
 * Auxiliary function to find nearest points in strip, as indicated
 * in the assignment, with points sorted by Y coordinate.
 * The strip is the part of vp between indices left and right (inclusive).
 * "res" contains initially the best solution found so far.
 */
static void npByY(vector<Point> &vp, int left, int right, Result &res) {
    auto begin = vp.begin() + left;
    auto end = vp.begin() + right + 1;
    double aux;
    for (auto x = begin; x != end; ++x) {
        for (auto y = x + 1; y != end; ++y) {
            if (y->y - x->y >= res.dmin)
                break;
            aux = x->distance(*y);
            if (aux < res.dmin) {
                res.dmin = aux;
                res.p1 = *x;
                res.p2 = *y;
            }
        }
    }
}

/**
 * Recursive divide and conquer algorithm.
 * Finds the nearest points in "vp" between indices left and right (inclusive),
 * using at most numThreads.
 */
static Result np_DC(vector<Point> &vp, int left, int right, int numThreads) {
    Result result;

    // Base case of a single point: no solution, so distance is MAX_DOUBLE
    if (right - left == 0)
        return result;

    // Base case of two points
    if (right - left == 1) {
        result.dmin = vp[left].distance(vp[right]);
        result.p1 = vp[left];
        result.p2 = vp[right];
        return result;
    }

    // Divide in halves (left and right) and solve them recursively,
    // possibly in parallel (in case numThreads > 1)
    int mid = (left + right) / 2;
    Result leftSolution;
    Result rightSolution;

    if (numThreads > 1) {
        thread t([&]() {
            leftSolution = np_DC(vp, left, mid, numThreads / 2);
        });
        rightSolution = np_DC(vp, mid + 1, right, numThreads / 2);
        t.join();
    } else {
        leftSolution = np_DC(vp, left, mid, numThreads);
        rightSolution = np_DC(vp, mid + 1, right, numThreads);
    }

    // Select the best solution from left and right
    result = (leftSolution.dmin < rightSolution.dmin) ? leftSolution : rightSolution;

    // Determine the strip area around middle point
    double midStrip = (vp[mid].x + vp[mid + 1].x) / 2;
    int leftStrip = mid;
    int rightStrip = mid + 1;
    while (leftStrip > left && midStrip - vp[leftStrip - 1].x < result.dmin)
        leftStrip--;
    while (rightStrip < right && vp[rightStrip + 1].x - midStrip < result.dmin)
        rightStrip++;

    // Order points in strip area by Y coordinate
    sortByY(vp, leftStrip, rightStrip);

    // Calculate nearest points in strip area (using npByY function)
    npByY(vp, leftStrip, rightStrip, result);

    // Reorder points in strip area back by X coordinate
    sortByX(vp, leftStrip, rightStrip);

    return result;
}


/**
 * Defines the number of threads to be used.
 */
static int numThreads = 1;

void setNumThreads(int num) {
    numThreads = num;
}

/*
 * Divide and conquer approach, single-threaded version.
 */
Result nearestPoints_DC(vector<Point> &vp) {
    sortByX(vp, 0, vp.size() - 1);
    return np_DC(vp, 0, vp.size() - 1, 1);
}


/*
 * Multi-threaded version, using the number of threads specified
 * by setNumThreads().
 */
Result nearestPoints_DC_MT(vector<Point> &vp) {
    sortByX(vp, 0, vp.size() - 1);
    return np_DC(vp, 0, vp.size() - 1, numThreads);
}
