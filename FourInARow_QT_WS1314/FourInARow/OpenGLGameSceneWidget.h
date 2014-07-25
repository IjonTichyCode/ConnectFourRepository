#ifndef OPENGLGAMESCENEWIDGET_H
#define OPENGLGAMESCENEWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLFunctions>

class OpenGLGameSceneWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLGameSceneWidget( const QGLFormat& format, QWidget* parent = 0 );

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
   QGLShaderProgram shader;
   QGLFunctions glFuncs;

   bool prepareShaderProgram( const QString& vertexShaderPath,
                                  const QString& fragmentShaderPath );

};

#endif // OPENGLGAMESCENEWIDGET_H
