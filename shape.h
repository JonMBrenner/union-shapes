#ifndef SHAPE_H_
#define SHAPE_H_

struct Shape;

double area(const struct Shape* shape);
double perimeter(const struct Shape* shape);
int x_pos(const struct Shape* shape);
int y_pos(const struct Shape* shape);

// set existing Shape, possibly to another shape type
void set_rectangle(struct Shape* shape, double length, double width);
void set_circle(struct Shape* shape, double radius);

int area_cmp(const struct Shape* lhs, const struct Shape* rhs);

struct Shape* new_rectangle(int x, int y, double length, double width);
struct Shape* new_circle(int x, int y, double radius);

void free_shape(struct Shape* shape);

#endif
