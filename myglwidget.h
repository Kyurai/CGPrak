#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QGLWidget> //selbst hinzugefügt

class MyGLWidget : public QGLWidget
{
public:
   MyGLWidget();

   MyGLWidget(QWidget*&);
};

#endif // MYGLWIDGET_H
