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
  int x;
  int y;
  union {
    struct Circle circle;
    struct Rectangle rectangle;
  };
  enum ShapeType type;
};

double area(const struct Shape* shape) {
  if (shape->type == CIRCLE) {
    return PI * shape->radius * shape->radius;
  else {
    return shape->length * shape->width;
  }
}

double perimeter(const struct Shape* shape) {
  if (shape->type == CIRCLE) {
    return 2 * PI * shape->radius;
  } else {
    return 2 * shape->length + 2 * shape->width;
  }
}
