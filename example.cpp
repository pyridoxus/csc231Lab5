#include <iostream>
using namespace std;
#include <GL/glut.h>
#include <stdlib.h>

void myInit();
void myDraw();
void keyboard(unsigned char, int, int);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
   glutInitWindowSize( 400, 300 );
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
   gluPerspective( 45.0, 1.333, 0.01, 10000.0 );
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
   // Material properties
   GLfloat mat_diffuse1[] = { 0.8, 0.6, 0.7, 1.0 };
   GLfloat mat_specular1[] = { 0.87, 0.85, 0.8, 1.0 };
   GLfloat mat_shininess1[] = { 40.0 };
   GLfloat mat_diffuse2[] = { 0.3, 0.7, 0.8, 1.0 };
   GLfloat mat_specular2[] = { 0.87, 0.85, 0.8, 1.0 };
   GLfloat mat_shininess2[] = { 120.0 };
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glPushMatrix();
   glTranslatef( -1, 0, 0 );
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
   glutSolidSphere( 1.0, 40, 40 );
   glPopMatrix();
   glPushMatrix();
   glTranslatef( 1, 0, 0 );
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
   glutSolidSphere( 1.0, 40, 40 );
   glPopMatrix();
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
