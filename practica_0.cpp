#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

// Alumno: Sergio Zapata De la Hoz 

void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(0.0,0.0,0.0); // se ponen de color negro
       glVertex3f(-5.0,0.0,0.0);
       glVertex3f(5.0,0.0,0.0);
       glColor3f(0.0,0.0,0.0);
       glVertex3f(0.0,-5.0,0.0);
       glColor3f(0.0,0.0,0.0);
       glVertex3f(0.0,5.0,0.0);   
    glEnd();
   
       
}


void Isotipo ()
{
   // logo mitsubishi

   // rombo arriba
   glColor3f(1.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(1.0,2.0,0.0);
      glVertex3f(0.0,4.0,0.0);
      glVertex3f(-1.0,2.0,0.0);
   glEnd();

   // rombo izda
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(-2.0,0.0,0.0);
      glVertex3f(-3.25,-2.0,0.0);
      glVertex3f(-1.0,-2.0,0.0);
   glEnd();

   // rombo dcha
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(2.0,0.0,0.0);
      glVertex3f(3.25,-2.0,0.0);
      glVertex3f(1.0,-2.0,0.0);
   glEnd();

}


static void Init( )
{

   glShadeModel( GL_FLAT);
}


static void Reshape( int width, int height )
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLint)width, (GLint)height);
   glOrtho (-5.0, 5.0,-5.0, 5.0, -10, 10.0);
}

static void Display( )
{

  glClearColor(1.0,1.0,1.0,0.0); // fondo blanco
  glClear( GL_COLOR_BUFFER_BIT );
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
  
   
   Ejes(1);
   Isotipo();
   
   glFlush();
}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv);
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 20, 100 );
   glutInitWindowSize(500, 500 );
   glutCreateWindow("Practica 0 IG: Logo Mitsubishi");


   Init();

   glutReshapeFunc(Reshape);
   glutDisplayFunc(Display);
   glutKeyboardFunc(Keyboard);
  
   glutMainLoop( );

   return 0;
}

