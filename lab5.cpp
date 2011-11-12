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
   gluPerspective( 10.0, 1280.0 / 256.0, 0.01, 10000.0 );
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0, 0, -25 );
   glClearColor( 1.0, 1.0, 0.0, 0.0 );
   glEnable( GL_DEPTH_TEST );

   // Select shading model
   glShadeModel(GL_SMOOTH);
   // Define light source
   GLfloat light_position0[] = { 0.0, 1.0, 1.0, 0.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

   // Define light source
   GLfloat light_position1[] = { -1.0, -1.0, 1.0, 1.0 };
   GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
   glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

   // Enable lighting model
   glEnable(GL_LIGHTING);

   // Enable light 0
   glEnable(GL_LIGHT0);

   // Enable light 1
   glEnable(GL_LIGHT1);
}

void myDraw()
{
	Sphere *sphere;
	int i, j;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   // Material properties
	float data[][4] = {// First sphere
										 // Diffuse                 Specular
										 { 0.0, 0.0, 0.0, 1.0 },  { 1.0, 1.0, 1.0, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 512.0, 0.0, 0.0, 0.0 }, { -9.5, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.05, 0.05, 0.05, 0.0},
										 // Second sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.1, 1.0 },  { 0.93, 0.93, 0.95, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 256.0, 0.0, 0.0, 0.0 }, { -7.4, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Third sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.2, 1.0 },  { 0.85, 0.85, 0.9, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 128.0, 0.0, 0.0, 0.0 }, { -5.3, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Fourth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.3, 1.0 },  { 0.75, 0.75, 0.85, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 64, 0.0, 0.0, 0.0 }, { -3.2, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Fifth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.4, 1.0 },  { 0.6, 0.6, 0.8, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 32.0, 0.0, 0.0, 0.0 }, { -1.1, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Sixth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.5, 1.0 },  { 0.5, 0.5, 0.75, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 26.0, 0.0, 0.0, 0.0 }, { 1.1, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Seventh sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.6, 1.0 },  { 0.4, 0.4, 0.70, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 20.0, 0.0, 0.0, 0.0 }, { 3.2, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Eighth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.7, 1.0 },  { 0.3, 0.3, 0.65, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 16.0, 0.0, 0.0, 0.0 }, { 5.3, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Ninth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.8, 1.0 },  { 0.2, 0.2, 0.6, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 12.0, 0.0, 0.0, 0.0 }, { 7.4, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										 // Tenth sphere
										 // Diffuse                 Specular
			 	 	 	 	 	 	 	 { 0.0, 0.0, 0.9, 1.0 },  { 0.1, 0.1, 0.5, 1.0 },
										 // Shininess               Translation
			 	 	 	 	 	 	 	 { 8.0, 0.0, 0.0, 0.0 }, { 9.5, 0.0, 0.0, 0.0 },
			 	 	 	 	 	 	 	 // Ambient
			 	 	 	 	 	 	 	 { 0.1, 0.1, 0.1, 0.0},
										};

  for(i = 0; i < 10; i++)
  {
  	j = i * 5;
  	sphere = new Sphere(data[j], data[j + 1], data[j + 2],
  										  data[j + 3], data[j + 4]);
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

