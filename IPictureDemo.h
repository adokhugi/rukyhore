#ifndef _IPICTUREDEMO_H_
#define _IPICTUREDEMO_H_

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "math.h"

#include "NeHeGL.h"
#include "NeHe_Window.h"

#include "wcpt2d.h"
#include "font.h"

class IPictureDemo
{
public:
	bool Initialize (GL_Window *window, Keys *keys, float tickCount);
	void Deinitialize ();
	void Update (float tickCount, float lastTickCount);
	void Draw (float tickCount);

private:
	static const int SIZE = 15;
	void InitializeEffect (int num, float tickCount);
	GL_Window *g_window;
	Keys *g_keys;
	float startTickCount;
	wcPt3D sphereCenter;
	float sphereRotAngleX;
	float sphereRotAngleY;
	float sphereRotAngleZ;
	float sphereMov;
	float sphereMovDif;
	wcPt3D spherePoint[SIZE][SIZE];
	float sphereRadius;
	float midPointOffset[SIZE];
	float partialSphereRadius[SIZE];
	Font font;
};

#endif