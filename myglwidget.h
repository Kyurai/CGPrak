#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget> //selbst hinzugefügt

class MyGLWidget : public QGLWidget
{
    Q_OBJECT //used for Qt signals & slots

public:
   MyGLWidget();
   MyGLWidget(QWidget*& parent);

   void initializeGL();
   void resizeGL(int width, int height);
   void paintGL();
   void updateGL();

signals:

};

#endif // MYGLWIDGET_H
