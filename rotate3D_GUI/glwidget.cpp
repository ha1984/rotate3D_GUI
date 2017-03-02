#include "glwidget.h"
#include <GL/glut.h>
#include <QKeyEvent>
#include <QGraphicsScene>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    setMouseTracking(true);
//    connect(&timer, SIGNAL(timeout()),this, SLOT(update()));
//    timer.start(16);
}

void GLWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}
// activate keyboard on mouse click:
void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
    printf("\nMouse in board");
    setFocus(); //activates keyboard on click
}

// convert mouse movement to rotation angles xRot, yRot, zRot:
void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
            setXRotation(xRot + dy);
            setYRotation(yRot + dx);
        } else if (event->buttons() & Qt::RightButton) {
            setXRotation(xRot + dy);
            setZRotation(zRot + dx);
        }

        lastPos = event->pos();
}

// move widget with keys W,A,S,D:
void GLWidget::keyPressEvent(QKeyEvent *event)
{
 if (event->key() == Qt::Key_A){
     x = x + 1;
     xmove=true;
     update();
 }
 else if (event->key() == Qt::Key_D){
     x = x - 1;
     xmove=true;
     update();
 }
 else if (event->key() == Qt::Key_W){
     z = z + 1;
     zmove=true;
     update();
 }
 else if (event->key() == Qt::Key_S){
     z = z - 1;
     zmove=true;
     update();
 }
}

//paint objects (triangle, teapot):

void GLWidget::paintGL(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

if (Rotate == true){
glRotatef(0.5, 1,1,1);
}

if (xmove == true){
glTranslatef(0.1*(x-xold),0,0);
xold = x;
xmove = false;
}

if (ymove == true){
glTranslatef(0,0.1*(y-yold),0);
yold=y;
ymove = false;
}

if (zmove == true){
glTranslatef(0,0,0.1*(z-zold));
zold=z;
zmove = false;
}

glColor3f(0,0,1);

 //DrawObjectOne
if (Wire == true){
glutWireTeapot(0.6);
}
else {
    glutSolidTeapot(0.6);
}
;
 //DrawObjectTwo


glBegin(GL_TRIANGLES);
glColor3f(1,0,0);
glVertex3f(-0.5,-0.5,0);
glColor3f(0,1,0);
glVertex3f(1.5,-0.5,0);
glColor3f(0,0,1);
glVertex3f(0.0,0.5,0);
glEnd();

}


void GLWidget::resizeGL(int w, int h){
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45, (float)w/h, 0.01,100.00);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0,0,5,0,0,0,0,1,0);
}

void GLWidget::setXRotation(int angle)
{
       if (angle != xRot) {
           xRot = angle;
           update();
       }
}

void GLWidget::setYRotation(int angle)
{
       if (angle != yRot) {
           yRot = angle;
           update();
       }
}

void GLWidget::setZRotation(int angle)
{
       if (angle != zRot) {
           zRot = angle;
           update();
       }
}








