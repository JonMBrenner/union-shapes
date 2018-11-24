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
    return PI * shape->circle.radius * shape->circle.radius;
  } else {
    return shape->rectangle.length * shape->rectangle.width;
  }
}

double perimeter(const struct Shape* shape) {
  if (shape->type == CIRCLE) {
    return 2 * PI * shape->circle.radius;
  } else {
    return 2 * shape->rectangle.length + 2 * shape->rectangle.width;
  }
}

int x_pos(const struct Shape* shape) {
  return shape->x;
}

int y_pos(const struct Shape* shape) {
  return shape->y;
}

void set_rectangle(struct Shape* shape, double length, double width) {
  shape->type = RECTANGLE;
  shape->rectangle.length = length;
  shape->rectangle.width = width;
}

void set_circle(struct Shape* shape, double radius) {
  shape->type = CIRCLE;
  shape->circle.radius = radius;
}

int area_cmp(const struct Shape* lhs, const struct Shape* rhs) {
  return area(lhs) - area(rhs);
}

struct Shape* new_rectangle(int x, int y, double length, double width) {
  struct Shape* rect = malloc(sizeof *rect);
  rect->x = x;
  rect->y = y;
  rect->rectangle.length = length;
  rect->rectangle.width = width;
  rect->type = RECTANGLE;
  return rect;
}

struct Shape* new_circle(int x, int y, double radius) {
  struct Shape* cir = malloc(sizeof *cir);
  cir->x = x;
  cir->y = y;
  cir->circle.radius = radius;
  cir->type = CIRCLE;
  return cir;
}

void free_shape(struct Shape* shape) {
  free(shape);
}
