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