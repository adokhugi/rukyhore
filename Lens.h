#ifndef _LENS_H_
#define _LENS_H_

#include <math.h>
#include "wcpt2d.h"

class Lens
{
public:
	void Precalc (int newSize, double factor = 0);
	wcPt2D *GetCoords ();
	int GetSize ();

private:
	wcPt2D *coords;
	int size;
};

#endif