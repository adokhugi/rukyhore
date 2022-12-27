#include "font.h"

Font::Font ()
{
}

Font::~Font ()
{
	free ();
}

void Font::write (float xpos, float ypos, const char *string)
{
	glRasterPos2f (xpos, ypos);
	glListBase (fontbase - 32);
	glCallLists ((GLsizei) strlen (string), GL_UNSIGNED_BYTE, string);
}

bool Font::init (int height, char *font_name)
{
	return init (height, 0, FALSE, FALSE, font_name);
}

bool Font::init (int height, int width, BOOL bItalic, BOOL bUnderline, char *font_name)
{
	HFONT font;
	HDC	myHDC;

	fontbase = glGenLists (96);

	font = CreateFontA (height, width, 0, 0, 100, bItalic, bUnderline, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE|DEFAULT_PITCH, font_name);

	myHDC = CreateCompatibleDC (GetDC (0));
	if (!myHDC)
		return false;

	SelectObject (myHDC, font);
	wglUseFontBitmapsA (myHDC, 32, 96, fontbase);

	return true;
}

void Font::free ()
{
	glDeleteLists (fontbase, 96);
}
