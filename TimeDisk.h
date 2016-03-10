#include <QString>
#include <math.h>
#include <QTime>
#include <QImage>

struct DiskType {
  enum Type {hour, min, sec};
};

#ifndef TIMEDISK_H
#define TIMEDISK_H

class TimeDisk
{

private:
  const int maxValue;
  const int numberSpacing;
  const int diameter;
  const int containerWidth;
  const int containerHeight;
  const int fontInset;
  const int diskWidth;

  QImage* image;
  DiskType::Type type;

public:
  TimeDisk(DiskType::Type type, const int maxValue, const int numberSpacing, const int diameter,
    const int containerWidth, const int containerHeight, const int fontInset, const int diskWidth);
  ~TimeDisk();

  void render(QPainter* g);

};

#endif // TIMEDISK_H
