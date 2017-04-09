#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget> //selbst hinzugefügt

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
    //Q_WIDGET doesn't work !
private:
    int angle = 0;

public:
   MyGLWidget();
   MyGLWidget(QWidget*& parent);

   void initializeGL();
   void resizeGL(int width, int height);
   void paintGL();
   //void updateGL();

   void setAngle(int _angle);
   int getAngle();

public slots:
   void receiveRotationZ(int _angle);

};

#endif // MYGLWIDGET_H
