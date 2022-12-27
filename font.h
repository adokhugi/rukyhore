#ifndef _FONT_H_
#define _FONT_H_

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Font
{
public:
	Font ();
	~Font ();

	void write (float xpos, float ypos, const char *string);
	bool init (int height, char *font_name);
	bool init (int height, int width, BOOL bItalic, BOOL bUnderline, char *font_name);
	void free ();

private:
	GLuint fontbase;
};

#endif