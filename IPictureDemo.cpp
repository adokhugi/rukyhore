#include "IPictureDemo.h"
#include <mmsystem.h>

bool IPictureDemo::Initialize (GL_Window* window, Keys* keys, float tickCount)	
{
	GLuint black [3]	= { 0, 0, 0 };
	GLuint white [3]	= { 255, 255, 255 };

	g_window			= window;
	g_keys				= keys;

	font.init(60, "Verdana");

	InitializeEffect (0, tickCount);

	PlaySound("traymuss-tr7b-intro-8k.wav", NULL, SND_FILENAME|SND_ASYNC);

	startTickCount = tickCount;

	return true;
}

void IPictureDemo::InitializeEffect (int num, float tickCount)
{
	glClearColor (0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth (1.0f);
	glDepthFunc (GL_LEQUAL);
	glEnable (GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glAlphaFunc (GL_GREATER, 0.1f);
	glEnable (GL_ALPHA_TEST);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE);

	glDisable (GL_TEXTURE_2D);
	sphereCenter.x = 0.5;
	sphereCenter.y = 0.1;
	sphereCenter.z = 0.5;
	sphereRotAngleX = 0;
	sphereRotAngleY = 0;
	sphereRotAngleZ = 0;
	sphereMov = -0.0001;
	sphereRadius = 1.4;

	for (int i = 0; i < SIZE - 1; i++)
	{
		midPointOffset[i] = sphereRadius * sin(3.141592 / (SIZE - 1) * (i - 4));
		partialSphereRadius[i] = sphereRadius * cos(3.141592 / (SIZE - 1) * (i - 4));
	}
	midPointOffset[SIZE - 1] = sphereRadius;
	partialSphereRadius[SIZE - 1] = 0;
}

void IPictureDemo::Deinitialize ()
{
}

void IPictureDemo::Update (float tickCount, float lastTickCount)
{
	if (g_keys->keyDown [VK_ESCAPE] || tickCount - startTickCount > 60000)
		TerminateApplication (g_window);

	if (g_keys->keyDown [VK_F1])
		ToggleFullscreen (g_window);

	glClearColor (0.2f + sin(sphereRotAngleY) / 10, 0.05f, 0.2f + sin(sphereRotAngleY) / 10, 0.5f);

	sphereCenter.y += sphereMov;
	if(sphereCenter.y < -0.5)
		sphereMov = 0.1;
	if(sphereCenter.y < -1.0)
	{
		sphereMov = 0.8;
		sphereMovDif = 0;
	}
	if(sphereCenter.y < -0.2)
		sphereMov = 0.2;
	if(sphereCenter.y > 1.5)
		sphereMov = -0.4;
	sphereMov -= sphereMovDif;
	sphereMovDif += 0.0001;

	// remove these lines to get a real sphere, but it looks cooler this way ;)
	//sphereRotAngleX += 0.2;
	sphereRotAngleY += 0.1;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			spherePoint[i][j].x = sphereCenter.x + midPointOffset[i];
			spherePoint[i][j].y = sphereCenter.y + partialSphereRadius[i] * sin(3.141592 / (SIZE - 1) * (GLfloat)(4 - j));
			spherePoint[i][j].z = sphereCenter.z + partialSphereRadius[i] * cos(3.141592 / (SIZE - 1) * (GLfloat)(4 - j));
		}
	}
}

void IPictureDemo::Draw (float tickCount)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity ();

	glDisable (GL_BLEND);

	glTranslatef (0.0f, 0.0f, -5.0f);

	if (tickCount - startTickCount < 7500)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(-2.5, 0, "  ruky hore, gate dole!");
	}

	if (tickCount - startTickCount < 7000) return;

	if (tickCount - startTickCount > 35000 && tickCount - startTickCount < 40000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(-2.2, 1.5, "music:");
	}

	if (tickCount - startTickCount > 37500 && tickCount - startTickCount < 42500)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0.5, 1.5, "traymuss");
	}

	if (tickCount - startTickCount > 42500 && tickCount - startTickCount < 47500)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(-2.2, 1.5, "code:");
	}

	if (tickCount - startTickCount > 45000 && tickCount - startTickCount < 50000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(1.3, 1.5, "adok");
	}

	if (tickCount - startTickCount > 50000 && tickCount - startTickCount < 51000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "10");
	}

	if (tickCount - startTickCount > 51000 && tickCount - startTickCount < 52000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "9");
	}

	if (tickCount - startTickCount > 52000 && tickCount - startTickCount < 53000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "8");
	}

	if (tickCount - startTickCount > 53000 && tickCount - startTickCount < 54000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "7");
	}

	if (tickCount - startTickCount > 54000 && tickCount - startTickCount < 55000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "6");
	}

	if (tickCount - startTickCount > 55000 && tickCount - startTickCount < 56000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "5");
	}

	if (tickCount - startTickCount > 56000 && tickCount - startTickCount < 57000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "4");
	}

	if (tickCount - startTickCount > 57000 && tickCount - startTickCount < 58000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "3");
	}

	if (tickCount - startTickCount > 58000 && tickCount - startTickCount < 59000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "2");
	}

	if (tickCount - startTickCount > 59000 && tickCount - startTickCount < 60000)
	{
		glColor3f ((float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f, (float)((int)tickCount % 1000) / 2000.0f);
		font.write(0, 1.5, "1");
	}

	for (int i = 0; i < SIZE; i++)		
	{
		for (int j = 0; j < SIZE; j++)
		{
			int i_next = i + 1 > (SIZE - 1) ? 0 : i + 1;
			int j_next = j + 1 > (SIZE - 1) ? 0 : j + 1;

			glRotatef (sphereRotAngleX, 1.0f, 0.0f, 0.0f);
			glRotatef (sphereRotAngleY, 0.0f, 1.0f, 0.0f);
			glRotatef (sphereRotAngleZ, 0.0f, 0.0f, 1.0f);

			glBegin (GL_QUADS);
			glColor3f (partialSphereRadius[i] / sphereRadius + (float)((int)tickCount % 1000) / 2000.0f, 0.0f, partialSphereRadius[i_next] / sphereRadius * 2);
			glVertex3f (spherePoint[i][j].x, spherePoint[i][j].y, spherePoint[i][j].z);
			glVertex3f (spherePoint[i_next][j].x, spherePoint[i_next][j].y, spherePoint[i_next][j].z);
			glVertex3f (spherePoint[i_next][j_next].x, spherePoint[i_next][j_next].y, spherePoint[i_next][j_next].z);
			glVertex3f (spherePoint[i][j_next].x, spherePoint[i][j_next].y, spherePoint[i][j_next].z);
			glEnd ();

			GLfloat x_mid = (spherePoint[i][j].x + spherePoint[i_next][j].x + spherePoint[i_next][j_next].x + spherePoint[i][j_next].x) / 4;
			GLfloat y_mid = (spherePoint[i][j].y + spherePoint[i_next][j].y + spherePoint[i_next][j_next].y + spherePoint[i][j_next].y) / 4;
			GLfloat z_mid = (spherePoint[i][j].z + spherePoint[i_next][j].z + spherePoint[i_next][j_next].z + spherePoint[i][j_next].z) / 4;
		}
	}
}
