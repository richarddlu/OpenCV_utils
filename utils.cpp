/**
 * Utils for OpenCV
 *
 * @author: Lu Sun
 * 
 * Version: 0
 */

#include "utils.h"

void rectResize(const Rect& src, Rect& dst, double ratio, const Size& bound) {
	// ratio less than 0 is meaning less
	if(ratio <= 0)
		dst = Rect(0, 0, 0, 0);
	
	// calculate size change and offset
	double lengthRatio = sqrt(ratio);
	Size size(src.width*(lengthRatio-1), src.height*(lengthRatio-1));
	Point point(src.width*(lengthRatio-1)/2, src.height*(lengthRatio-1)/2);

	// copy src to dst
	dst = src;

	// perform expansion or shrink
	dst += size;
	dst -= point;

	// truncate the rectangle
	Rect boundRect(0, 0, bound.width, bound.height);
	dst = dst & boundRect;
}

void polyResize(const vector<Point>& src, vector<Point>& dst, double ratio, const Size& bound) {
	// ratio less than 0 is meaning less
	if(ratio <= 0)
		dst.resize(src.size(), Point(0,0));

    // calculate original centroid
    Point centroid(0, 0);
    for(int i = 0; i < src.size(); i++) {
        centroid += src[i];
    }
    centroid.x /= src.size();
    centroid.y /= src.size();
    
    // move centroid to origin
    for(int i = 0; i < dst.size(); i++) {
        dst[i] -= centroid;
    }

    // calculate size change and offset
	double lengthRatio = sqrt(ratio);
    
    // shrink from vertex to vertex
    for(int i = 0; i < dst.size(); i++) {
        dst[i] *= lengthRatio;
    }
    
    // move centroid to original position
    for(int i = 0; i < dst.size(); i++) {
        dst[i] += centroid;
    }
    
    // ensure polygon does not exceed image boundry
    for(int i = 0; i< dst.size(); i++) {
        if(dst[i].x < 0)
            dst[i].x = 0;
        if(dst[i].x >= bound.width)
            dst[i].x = bound.width - 1;
        if(dst[i].y < 0)
            dst[i].y = 0;
        if(dst[i].y >= bound.height)
            dst[i].y = bound.height - 1;
    }
}
