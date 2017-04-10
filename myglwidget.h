#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

//#include <QWidget>
#include <QOpenGLWidget>

class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
private:
    int angle = 0;
    double coord_x = 0.0;
    double coord_y = 0.0;
    //double coord_z = ;

public:
   MyGLWidget();
   MyGLWidget(QWidget*& parent);

   void initializeGL();
   void resizeGL(int width, int height);
   void paintGL();
   //void updateGL();
   void keyPressEvent(QKeyEvent *event);

   //Getter & Setter for Attributes
   void setAngle(int _angle);
   int getAngle();
   double getCoord_x() const;
   void setCoord_x(double value);
   double getCoord_y() const;
   void setCoord_y(double value);

public slots:
   void receiveRotationZ(int _angle);

};

#endif // MYGLWIDGET_H
