#include "shape.h"

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(A) (sizeof A / sizeof A[0])

static int shape_ptr_cmp(const void* lhs, const void* rhs) {
  const struct Shape*const* lhs_shape = lhs;
  const struct Shape*const* rhs_shape = rhs;
  return area_cmp(*lhs_shape, *rhs_shape);
}

int main(void) {
  struct Shape* c = new_circle(1, 3, 10);
  struct Shape* r = new_rectangle(5, 4, 3, 6);
  printf("(%d, %d), a=%lf p=%lf\n", x_pos(c), y_pos(c), area(c), perimeter(c));
  printf("(%d, %d), a=%lf p=%lf\n", x_pos(r), y_pos(r), area(r), perimeter(r));

  set_circle(r, 3);
  printf("(%d, %d), a=%lf p=%lf\n", x_pos(r), y_pos(r), area(r), perimeter(r));

  free_shape(r);
  free_shape(c);

  struct Shape* shapes[] = {
    new_circle(0, 0, 13),
    new_rectangle(0, 0, 4, 6),
    new_rectangle(0, 0, 5, 10),
    new_circle(0, 0, 4),
    new_circle(0, 0, 10),
    new_rectangle(0, 0, 7, 3),
    new_circle(0, 0, 2),
  };

  qsort(shapes, ARRAY_SIZE(shapes), sizeof shapes[0], shape_ptr_cmp);

  puts("shapes sorted by area:");
  for (size_t i = 0; i < ARRAY_SIZE(shapes); ++i) {
    printf("area = %lf\n", area(shapes[i]));
  }

  for (size_t i = 0; i < ARRAY_SIZE(shapes); ++i) {
    free_shape(shapes[i]);
  }
}
