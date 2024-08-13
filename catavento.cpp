#include <GL/glut.h>


int i= 1, pos = 0;


void init (void)
{
   /* selecionar cor de fundo (preto) */
   glClearColor (0.0, 0.0, 0.0, 0.0);
  
   glMatrixMode (GL_PROJECTION); //Projecao 2D
  
   gluOrtho2D (0.0, 600.0, 0.0, 400.0); //Definindo os limites da Porta de Visao (ViewPort)
  
}


void display(void)
{
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);
  
   glColor3f (1.0, 1.0, .0);
   glBegin(GL_POLYGON);
       glVertex3f (249.0f, 250.0f, -1.0f);
       glVertex3f (251.0f, 250.0f, -1.0f);
       glVertex3f (249.0f, 100.0f, -1.0f);
       glVertex3f (251.0f, 100.0f, -1.0f);
   glEnd();
  
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(250.0f, 250.0f, 0);
   glRotatef(i, 0.0f, 0.0f, 1.0f);
   glTranslatef(-250.0f, -250.0f, 0);
   glColor3f(1.0f, 1.0f, 0);


   /* Desenhar um polígono branco  */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_TRIANGLES);
       glVertex2f (250.0f, 250.0f);
       glVertex2f (230.0f, 200.0f);
       glVertex2f (270.0f, 200.0f);
   glEnd();
  
   /* Desenhar um polígono vermelho */
   glColor3f (1.0, 0.0, 0.0);
   glBegin(GL_TRIANGLES);
       glVertex2f (250.0f, 250.0f);
       glVertex2f (300.0f, 230.0f);
       glVertex2f (300.0f, 270.0f);
   glEnd();
  
   /* Desenhar um polígono verde */
   glColor3f (0.4, 0.0, 0.5);
   glBegin(GL_TRIANGLES);
       glVertex2f (250.0f, 250.0f);
       glVertex2f (230.0f, 300.0f);
       glVertex2f (270.0f, 300.0f);
   glEnd();
  
   /* Desenhar um polígono vermelho */
   glColor3f (0.0, 0.0, 1.0);
   glBegin(GL_TRIANGLES);
       glVertex2f (250.0f, 250.0f);
       glVertex2f (200.0f, 270.0f);
       glVertex2f (200.0f, 230.0f);
   glEnd();
  
   glPopMatrix();
   /* Não esperar! */
   glFlush ();
}


void keyboard(int key, int x, int y){
   switch(key){
       case GLUT_KEY_F1:
           pos=1;
           break;
       case GLUT_KEY_F2:
           pos=-1;
           break;
   }
}


void rotation(){
   i += 1 * pos;
   glutPostRedisplay();
}


int main(int argc, char** argv) {
  
    glutInit(&argc, argv);
  
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Flor de Abril");
  
    init ();
  
    glutDisplayFunc(display);
   glutSpecialFunc(keyboard);
   glutIdleFunc(rotation);
    glutMainLoop();
  
    /* C ANSI requer que main retorne um inteiro */
    return 0;
  
}



