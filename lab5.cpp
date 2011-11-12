#include <iostream>
using namespace std;
#include "Sphere.h"

void myInit();
void myDraw();
void keyboard(unsigned char, int, int);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
   glutInitWindowSize( 1280, 256 );
   glutCreateWindow( argv[0] );
   myInit();
   glutDisplayFunc( myDraw );
   glutKeyboardFunc( keyboard );
   glutMainLoop();
   return 0;
}

void myInit()
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   gluPerspective( 45.0, 1280.0 / 256.0, 0.01, 10000.0 );
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0, 0, -5 );
   glClearColor( 0.0, 0.0, 0.0, 0.0 );
   glEnable( GL_DEPTH_TEST );

   // Select shading model
   glShadeModel(GL_SMOOTH);

   // Define light source
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   // Enable lighting model
   glEnable(GL_LIGHTING);

   // Enable light 0
   glEnable(GL_LIGHT0);
}

void myDraw()
{
	Sphere *sphere;
	int j;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   // Material properties
	float data[][4] = {// First sphere
										 // Diffuse                 Specular
										 { 0.9, 0.6, 0.9, 1.0 },  { 0.9, 0.9, 0.9, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 40.0, 0.0, 0.0, 0.0 }, { -1.0, 0.0, 0.0, 0.0 },
										 // Second sphere
										 // Diffuse                 Specular
										 { 0.3, 0.7, 0.8, 1.0 },  { 0.87, 0.85, 0.8, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 120.0, 0.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0, 0.0 }
										};

  for(int i = 0; i < 2; i++)
  {
  	j = i * 4;
  	sphere = new Sphere(data[j], data[j + 1], data[j + 2], data[j + 3]);
  	sphere->draw();
  	delete sphere; // This object is only temporary
  }

   glutSwapBuffers();
}

// Keyboard callback
void keyboard( unsigned char key, int x, int y )
{
  // Process entries
  switch( key )
    {
    case 'q': // Quit
      exit(1);
      break;
    }

  // Redraw the scene
  glutPostRedisplay();
}

