#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
 
void drawCircle() {
    glBegin(GL_POLYGON);
    for (float i = 0; i < 6.29; i += 0.001)
    {
        float x = cos(i);
        float y = sin(i);
        glColor3f(x+0.2*y, y+0.2*x, 1);
        glVertex2f(x, y);
    }
    glEnd();
    glLoadIdentity();
}

void drawTriangle(float a, float b) {
    glBegin(GL_TRIANGLES);
        glColor3f( 1, 0, 0 ); // red
        glVertex2f( a*-0.8, b*-0.8 );

        glColor3f( 0, 1, 0 ); // green
        glVertex2f( a*0.8, b*-0.8 );

        glColor3f( 0, 0, 1 ); // blue
        glVertex2f( a*0, b*0.9 );
    glEnd();
}

void drawRect(float a, float b) {
    glBegin(GL_QUADS);
        glColor3f( a, 0, 0 ); // red
        glVertex2f( a*-0.8, b*-0.8 );

        glColor3f( 0, a, 0 ); // green
        glVertex2f( a*0.8, b*-0.8 );

        glColor3f( 0, 0, a ); // blue
        glVertex2f( a*0.8, b*0.8 );

        glColor3f( 0, a, b ); // blue
        glVertex2f( a*-0.8, b*0.8 );
    glEnd();
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
}
 
// Função para desenhar na tela
// Contém a lógica das animações
void display (void)
{   
    glScalef(1.5,1.5,1.0);
    
    float dir = 1; // Variável de controle do sentido da animação

    for (float j = 0;;j+=0.05*dir) {
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Controla o sentido da animação
        if (j >= 60) { j = 60; dir = -1; } 
        else if (j <= 0) { j = 0; dir = 1; }

        // -- Círculo
        // Redimensionamento

        // Redimensiona o círculo
        glScalef(j,j,1.0);
        // Desenha um círculo de raio j
        drawCircle();
        // Limpa as tranformações
        glLoadIdentity();


        // -- Triângulo
        // Translação
        
        // Translada o triângulo
        glTranslatef(-200, 30-2*-j, 0);
        // Desenha o triângulo
        drawTriangle(40, 40);
        // Limpa as tranformações
        glLoadIdentity();


        // -- Quadrado
        // Rotação

        // Translada o quadrado
        glTranslatef(200, 0, 0);
        // Rotaciona o quadrado
        glRotatef(j*2*3.14159, 0,0,1);
        // Desenha o quadrado
        drawRect(40, 40);
        // Limpa as transformações
        glLoadIdentity();

        glFlush();
    }
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1360*0.5, 768*0.5);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Animacao");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}