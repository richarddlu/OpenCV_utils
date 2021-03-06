/**
 * Utils for OpenCV
 *
 * @author: Lu Sun
 * 
 * Version: 0
 */

#ifndef __OPENCV_UTILS_H__
#define __OPENCV_UTILS_H__

#include <opencv2/opencv.hpp>
#include <cmath>

using namespace std;
using namespace cv;

/**
 * Resize a rectangle while keeping the center unchanged
 *
 * @param const Rect& src
 * @param Rect& dst
 * @param double ratio equal to dst.area() / src.area(). If larger than 1, the rectangle is expanded, if less than 1, it is shrinked
 * @param const Size& bound boundary of the rectangle. The portion out of bound will be truncated.
 */
void rectResize(const Rect& src, Rect& dst, double ratio, const Size& bound);

/**
 * Resize a polygon while keeping the center unchanged
 *
 * @param const vector<Point>& src
 * @param vector<Point>& dst
 * @param double ratio equal to dst.area() / src.area(). If larger than 1, the polygon is expanded, if less than 1, it is shrinked
 * @param const Size& bound boundary of the polygon. The vertices outside of bound is shrinked back to the bound
 */
void polyResize(const vector<Point>& src, vector<Point>& dst, double ratio, const Size& bound);

#endif
