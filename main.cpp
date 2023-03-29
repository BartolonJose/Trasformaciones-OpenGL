#include <GL/glut.h>
#include <cmath>

double Rotacion = 0.0;
double TraslacionX = 0.0; 
double TraslacionY = 0.0; 
double EscalamientoX = 1.0; 
double EscalamientoY = 1.0;

void IniciarConfiguracion() {
	glClearColor(1, 1, 1, 0);
	glLineWidth(3.0);
    glOrtho(0, 800, 0, 600, 1, -1); 
}

void DibujarPoligono() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f( 0.0, 0.5, 0 ); 
	glColor3f(1.0,1.0,0.0);

 	glVertex3f( -0.2, 0.1, 0 );  	
	glVertex3f( -0.5, 0, 0 );
 	glVertex3f( -0.2, -0.1, 0 );
	glVertex3f( -0.1, -0.2, 0 );
	glVertex3f( 0.0, -0.1, 0 );
	glVertex3f( 0.1, -0.2, 0 );
	glVertex3f( 0.2, -0.1, 0 );
	glVertex3f( 0.5, 0.0, 0 );
	glVertex3f( 0.2, 0.1, 0 );
	glEnd();
  	glFlush();
}
void keyboard(unsigned char key, int x, int y) {
  switch(key) {
  	 case 'z':  
      Rotacion -= 5.0;
      break;
    case 'x': 
      Rotacion += 5.0;
      break;
      case '+': 
      EscalamientoX *= 1.1;
      EscalamientoY *= 1.1;
      break;
    case '-': 
      EscalamientoX /= 1.1;
      EscalamientoY /= 1.1;
      break;
    case 'w': 
      TraslacionY += 0.1;
      break;
    case 's': 
      TraslacionY -= 0.1;
      break;
    case 'a': 
      TraslacionX -= 0.1;
      break;
    case 'd' :
      TraslacionX += 0.1;
      break;
   
  }
  glutPostRedisplay();
}


void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(TraslacionX, TraslacionY, 0.0);
  glRotatef(Rotacion, 0.0, 0.0, 1.0);
  glScalef(EscalamientoX, EscalamientoY, 1.0);
  DibujarPoligono();
  glutSwapBuffers();
}


int main(int argc, char** args) {
  glutInit(&argc, args);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Transformaciones");
  glutDisplayFunc(display);
  IniciarConfiguracion();
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
