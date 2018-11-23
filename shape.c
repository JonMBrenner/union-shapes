#include "shape.h"

#include <assert.h>
#include <math.h>
#include <stdlib.h>

const double PI = 3.141592654;

struct Circle {
  double radius;
};


struct Rectangle {
  double length;
  double width;
};


enum ShapeType { CIRCLE, RECTANGLE };

struct Shape {
};

