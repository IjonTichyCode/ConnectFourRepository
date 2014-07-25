#include "OpenGLGameSceneWidget.h"

OpenGLGameSceneWidget::OpenGLGameSceneWidget(const QGLFormat& format, QWidget* parent) :
    QGLWidget( format, parent )
{
}

void OpenGLGameSceneWidget::initializeGL() {
    QGLFormat glFormat = QGLWidget::format();

    if ( !glFormat.sampleBuffers() )
            qWarning() << "Could not enable sample buffers";

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glClearColor(1, 0, 0, 1);

    if ( !prepareShaderProgram( "vertex.glsl", "fragment.glsl" ) ) {
       return;
    }

    if ( !shader.bind() )    {
        qWarning() << "Could not bind shader program to context";
        return;
    }

    shader.setAttributeBuffer( "in_Position", GL_FLOAT, 0, 2);
    shader.enableAttributeArray( "in_Position" );
    glFuncs = QGLFunctions(QGLContext::currentContext());
    GLuint vertexLoc = shader.attributeLocation("in_Position");
    glFuncs.glEnableVertexAttribArray(vertexLoc);

    // Achtung hier werden die Vertexdaten mit dem Hauptspeicher verknuepft, das heisst bei jedem Rendern
    // wird aus dem Hauptspeicher, nicht aus dem Grafikspeicher gelesen
    //glFuncs.glVertexAttribPointer(vertexLoc, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)vertices);
    //verticesTotal = 4;
    qWarning() << vertexLoc;

    //videoFile.read((char*)frameData, frameSize*sizeof(uchar));

//    glFuncs.glActiveTexture(GL_TEXTURE0);
//    glGenTextures(3, textures);

//    int w =704;
//    int h = 288;
//    qint32 offsets[] = {yOff, uOff, vOff};
//    for (int i=0; i<3; ++i) {
//        glFuncs.glActiveTexture(GL_TEXTURE0+i);
//        glBindTexture(GL_TEXTURE_2D, textures[i]);

//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//        glTexImage2D(GL_TEXTURE_2D, // target
//                     0,  // level, 0 = base, no minimap,
//                     GL_LUMINANCE, // internalformat
//                     w,  // width
//                     h,  // height
//                     0,  // border, always 0 in OpenGL ES
//                     GL_RED,  // format
//                     GL_UNSIGNED_BYTE, // type
//                     (GLvoid*) frameData+offsets[i]);

//        w = 352;
//        h=144;
//        //glFuncs.glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    for (int i=0; i<3;++i) {
//        glFuncs.glActiveTexture(GL_TEXTURE0+i);
//        glBindTexture(GL_TEXTURE_2D, textures[i]);
//    }
//    int location = glFuncs.glGetUniformLocation(shader.programId(), "yTexture");
//    glFuncs.glUniform1i(location, 0);
//    location = glFuncs.glGetUniformLocation(shader.programId(), "uTexture");
//    glFuncs.glUniform1i(location, 1);
//    location = glFuncs.glGetUniformLocation(shader.programId(), "vTexture");
//    glFuncs.glUniform1i(location, 2);

    glFuncs.glActiveTexture(GL_TEXTURE0);

  // glBindTexture(GL_TEXTURE_2D, textures[0]);
//   (new LoopTimer(this))->start();
}

void OpenGLGameSceneWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    int w =704;
    int h = 288;
//    qint32 offsets[] = {yOff, uOff, vOff};

//    for (int i=0; i<3; ++i) {
//        glFuncs.glActiveTexture(GL_TEXTURE0+i);
//        glBindTexture(GL_TEXTURE_2D, textures[i]);
//        glTexSubImage2D(GL_TEXTURE_2D,
//                             0,
//                             0,
//                             0,
//                             w,
//                             h,
//                             GL_RED,
//                             GL_UNSIGNED_BYTE,
//                             (GLvoid*) (videoPreBuffer->nextChunkToRender()+offsets[i]));
//        w = 352;
//        h=144;
//    }
//    glFuncs.glActiveTexture(GL_TEXTURE0);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, verticesTotal);
}

bool OpenGLGameSceneWidget::prepareShaderProgram( const QString& vertexShaderPath,
                                     const QString& fragmentShaderPath )
{
    // First we load and compile the vertex shader...
    bool result = shader.addShaderFromSourceFile( QGLShader::Vertex, vertexShaderPath );
    if ( !result )
        qWarning() << shader.log();

    // ...now the fragment shader...
    result = shader.addShaderFromSourceFile( QGLShader::Fragment, fragmentShaderPath );
    if ( !result )
        qWarning() << shader.log();

    // ...and finally we link them to resolve any references.
    result = shader.link();
    if ( !result )
        qWarning() << "Could not link shader program:" << shader.log();

    return result;
}

void OpenGLGameSceneWidget::resizeGL(int w, int h) {
    glViewport(40, 40, w-40, h-40);
}
