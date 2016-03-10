#include "JCanvas.h"

JCanvas::JCanvas(QWidget* obj)
{
  this->resize(600, 600);
  this->setWindowTitle("Super Epic and Pretty Clock");
  secondDisk = new TimeDisk(DiskType::sec, 60, 5, 460, this->width(), this->height(), 8, 50);
  minuteDisk = new TimeDisk(DiskType::min, 60, 5, 350, this->width(), this->height(), 8, 50);
  hourDisk = new TimeDisk(DiskType::hour, 12, 1, 230, this->width(), this->height(), 8, 50);
}

JCanvas::~JCanvas()
{
  delete secondDisk;
  delete minuteDisk;
  delete hourDisk;
}

void JCanvas::paintEvent(QPaintEvent* event)
{
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);

  QPoint center(this->width() / 2, this->height() / 2);
  p.setBrush(Qt::black);
  p.drawEllipse(center, 75, 75);

  p.setPen(QPen(Qt::white, 10));
  QFont font = p.font();
  font.setPointSize(50);
  p.setFont(font);

  p.drawText(center.x() - 50, center.y() + 25, QTime::currentTime().hour() >= 12 ? "PM" : "AM");

  secondDisk->render(&p);
  minuteDisk->render(&p);
  hourDisk->render(&p);


  QPainter p2(this);
  p2.setPen(QPen(Qt::NoPen));
  p2.setBrush(Qt::white);
  p2.setOpacity(0.7);
  p2.drawRect(0, 0, 600, 265);
  p2.drawRect(0, 265, 245, 75);
  p2.drawRect(0, 340, 600, 600);

  this->update();
}
