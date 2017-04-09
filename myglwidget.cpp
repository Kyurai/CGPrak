#include "myglwidget.h"
#include <iostream>

MyGLWidget::MyGLWidget(){

}

MyGLWidget::MyGLWidget(QWidget*& parent): QGLWidget(parent){
    this->setVisible(true);
}

/*void MyGLWidget::updateGL(){
    std::cout << "test !!!!!!!!!!!!!!!!!!!!";
    QGLWidget::glDraw();
}*/

void MyGLWidget::setAngle(int _angle){
    this->angle = _angle;
}

int MyGLWidget::getAngle(){
    return this->angle;
}

void MyGLWidget::receiveRotationZ(int _angle){
    this->setAngle(_angle);
}

void MyGLWidget::initializeGL(){
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE); //--disable to make Objects always visible
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_FLAT);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glClearDepth(1.0f);
    //--change clear color to alter background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyGLWidget::resizeGL(int width, int height){
    // Compute aspect ratio
    height = (height == 0) ? 1 : height;
    //GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set viewport to cover the whole window
    glViewport(0, 0, width, height);

    // Set projection matrix to a perspective projection
    glMatrixMode(GL_PROJECTION); //Projection
    glLoadIdentity();

    glFrustum(-0.05,0.05,-0.05,0.05,0.1,100.0);
    //glDraw();
}

void MyGLWidget::paintGL(){
    // Clear buffer to set color and alpha
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apply model view transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //--Change values here to move the object
    glTranslatef(0.0f, 0.0f, -7.0f);

    //--1.5 rotate Function
    glRotatef(45 + this->angle*1,0.0f,0.0f,1.0f); //1 = angle, 2 = rotate x, 3 = rotate y, 4 =  rotate z

    //--1.6 rotate y
    //glRotatef(180,0.0f,1.0f,0.0f);
    //--Backside not visible with culling turned on !
    //--Culling -> if object is not visible, dont draw it

    // Set color for drawing
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);

    // Draw shape
    //--first Triangle
    glBegin(GL_TRIANGLES);
        //bottom right
        glColor3f(1.0f,0.0f,0.0f); //1= red, 2= green, 3= blue
        glVertex3f( 1.0f, -1.0f,  0.0f);
        //top right
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f( 1.0f,  1.0f,  0.0f);
        //top left
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0f,  1.0f,  0.0f);
    glEnd();

    //--second Triangle
    glBegin(GL_TRIANGLES);
        //top left
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0, 1.0f, 0.0f);
        //bottom left
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        //bottom right
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    //needed for gradient
    glShadeModel(GL_SMOOTH);

    // Execute all issued GL commands
    //glFlush(); // replace with glutSwapBuffers() for double buffered mode

    // Increment angle for rotation
    this->angle++;
    this->update(); //to update the widget constantly
}
