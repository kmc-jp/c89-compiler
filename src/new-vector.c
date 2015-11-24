#include "new-vector.h"

/* vector of Type */
struct Vector {
  Type* start_;  /* first data */
  Type* finish_;  /* last data */
  Type* end_;  /* end of storage */
};

static VectorRef vectorref_alloc(void) {
  const VectorRef self = safe_malloc(struct Vector);
  self->start_ = self->finish_ = self->end_ = NULL;
  return self;
}
static void vectorref_free(VectorRef self) {
  safe_free(self);
}
static void vector_alloc(VectorRef self, size_t size) {
  const size_t capacity = enough_capacity(size);
  self->start_ = safe_array_malloc(Type, capacity);
  self->finish_ = self->start_;
  self->end_ = self->start_ + capacity;
}
static void vector_free(VectorRef self) {
  safe_free(self->start_);
  self->finish_ = self->end_ = NULL;
}