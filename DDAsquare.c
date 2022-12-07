#include<GL/glut.h>
#include <math.h>
#include <stdio.h>

void init() {
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,400.0,0.0,300.0);
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    glBegin(GL_POINTS);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        glVertex2i(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void drawRect() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    int x, y, w, h;
    printf("Enter x, y, w, h: ");
    scanf("%d %d %d %d", &x, &y, &w, &h);

    glColor3f(1.0,0.0,0.0);
    drawLineDDA(x, y, x + w, y);
    drawLineDDA(x + w, y, x + w, y + h);
    drawLineDDA(x + w, y + h, x, y + h);
    drawLineDDA(x, y + h, x, y);
    glFlush();
    scanf("%d", &x);
}

int main(int argc,char **argv) {
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,300);
    glutCreateWindow("DDA");
    init();
    drawRect();
    return 0;
}

