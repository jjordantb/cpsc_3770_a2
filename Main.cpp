#include <QApplication>
#include <QtGui>

#include "JCanvas.h"

#include <iostream>

int main(int argv, char *argc[])
{
  QApplication app(argv, argc);

  JCanvas canvas;
  canvas.show();

  return app.exec();
}
