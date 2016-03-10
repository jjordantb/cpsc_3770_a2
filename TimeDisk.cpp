#include "TimeDisk.h"
#include <QPainter>

TimeDisk::TimeDisk(DiskType::Type type, const int maxValue, const int numberSpacing, const int diameter, const int containerWidth, const int containerHeight, const int fontInset, const int diskWidth)
    : maxValue(maxValue), numberSpacing(numberSpacing), diameter(diameter), containerWidth(containerWidth), containerHeight(containerHeight), fontInset(fontInset), diskWidth(diskWidth), type(type)
{
  image = new QImage(diameter + diskWidth, diameter + diskWidth, QImage::Format_ARGB4444_Premultiplied);
  QPainter painter(image);
  painter.setRenderHint(QPainter::Antialiasing);
  QFont font = painter.font();
  font.setPointSize(fontInset * 2);
  painter.setFont(font);


  QPoint center((diameter + diskWidth) / 2, (diameter + diskWidth) / 2);
  QPoint origin(0, 0);
  painter.translate(center);
  painter.setPen(QPen(Qt::black, diskWidth));
  painter.drawEllipse(origin, diameter / 2, diameter / 2);

  painter.setPen(QPen(Qt::white, 1));

  for (int i = 1; i <= maxValue; i++) {
    painter.save();
    painter.rotate(i * (360 / maxValue));
    if (numberSpacing == 1) {
      painter.drawText((diameter / 2) - fontInset, 0, QString::number(i));
    } else {
      if (i % numberSpacing == 0) {
        if (i == 60) {
          painter.drawText((diameter / 2) - fontInset, 0, QString::number(0));
        } else {
          painter.drawText((diameter / 2) - fontInset, 0, QString::number(i));
        }
      } else {
        painter.drawLine(diameter / 2, -7, diameter / 2 + fontInset, -7);
      }
    }
    painter.restore();
  }
  painter.end();
}

TimeDisk::~TimeDisk()
{
  delete image;
}

void TimeDisk::render(QPainter* g)
{
  QPainter p(g->device());
  p.translate(containerWidth / 2, containerHeight / 2);

  QTime time = QTime::currentTime();

  switch (type) {
    case DiskType::hour:
      p.rotate(-((time.hour() % 12) * 30));
    break;
    case DiskType::min:
      p.rotate(-((time.minute() * 6) + (time.second() * 0.1) + ((time.msec() / 1000) * 0.1)));
    break;
    case DiskType::sec:
      p.rotate(-((time.second() * 1000 + time.msec()) * 0.006));
    break;
  }

  QPoint point(-(image->width() / 2), -(image->height() / 2));
  p.drawImage(point, *image);
}
