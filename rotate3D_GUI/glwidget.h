#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_1_5>
#include <QTimer>


class GLWidget : public QOpenGLWidget, public QOpenGLFunctions_1_5
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
void mousePressEvent ( QMouseEvent * event );
void mouseMoveEvent(QMouseEvent *event);
void keyPressEvent(QKeyEvent * event);
void initializeGL();
void paintGL();
void resizeGL(int w, int h);
// slots for xyz-rotation slider
void setXRotation(int angle);
void setYRotation(int angle);
void setZRotation(int angle);


GLfloat x=0,y=0,z=0;
GLfloat xold=0,yold=0,zold=0;
GLfloat mousex=0;
GLfloat mousey=1;

bool Wire = true;
bool Rotate = false;
bool xmove = false;
bool ymove = false;
bool zmove = false;

private:

int xRot;
int yRot;
int zRot;

QPoint lastPos;

QTimer timer;
};

#endif // GLWIDGET_H
