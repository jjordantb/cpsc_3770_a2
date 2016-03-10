#ifndef JCANVAS_H
#define JCANVAS_H

#include <QWidget>
#include <QPen>
#include <QPainter>

#include "TimeDisk.h"

class JCanvas : public QWidget
{
  Q_OBJECT

private:
  TimeDisk* secondDisk;
  TimeDisk* minuteDisk;
  TimeDisk* hourDisk;

public:
  JCanvas(QWidget* obj=0);
  ~JCanvas();

  virtual void paintEvent(QPaintEvent*);

};

#endif // JCANVAS_H
