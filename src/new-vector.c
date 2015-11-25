#include "new-vector.h"
#include <assert.h>

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
static void vectorref_free(VectorRef* pself) {
  safe_free(*pself);
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
static size_t vector_get_size(VectorRef self) {
  return self->finish_ - self->start_;
}
static size_t vector_get_capacity(VectorRef self) {
  return self->end_ - self->start_;
}
static Type* vector_get_begin(VectorRef self) {
  return self->start_;
}
static Type* vector_get_end(VectorRef self) {
  return self->finish_;
}
static void vector_set_size(VectorRef self, size_t size) {
  self->finish_ = self->start_ + size;
}
static void vector_fill(Type* dst, Type fill, size_t count) {
  size_t i = 0;
  for (i = 0; i < count; ++i) {
    dst[i] = fill;
  }
}


VectorRef make_vector(const Type* src, size_t count) {
  const VectorRef self = vector_ctor();
  vector_assign(self, src, count);
  return self;
}
VectorRef vector_ctor(void) {
  return vectorref_alloc();
}
void vector_dtor(VectorRef* pself) {
  assert(pself);
  if (*pself) {
    vector_free(*pself);
    vectorref_free(pself);
  }
}
void vector_copy(VectorRef self, VectorRef src) {
  assert(self && src);
  vector_assign(self, vector_data(src), vector_size(src));
}
void vector_assign(VectorRef self, const Type* src, size_t count) {
  assert(self);
  assert(count == 0 || src);
  if (vector_capacity(self) < count) {
    vector_free(self);
    vector_alloc(self, count);
  }
  VECTOR_MEMORY_COPY(vector_data(self), src, count);
  vector_set_size(self, count);
}
Type vector_at(VectorRef self, size_t index) {
  assert(self);
  return vector_data(self)[index];
}
Type vector_front(VectorRef self) {
  assert(self);
  return vector_begin(self)[0];
}
Type vector_back(VectorRef self) {
  assert(self);
  return vector_end(self)[-1];
}
Type* vector_data(VectorRef self) {
  assert(self);
  return vector_get_begin(self);
}
Type* vector_begin(VectorRef self) {
  assert(self);
  return vector_get_begin(self);
}
Type* vector_end(VectorRef self) {
  assert(self);
  return vector_get_end(self);
}
bool vector_empty(VectorRef self) {
  assert(self);
  return vector_begin(self) == vector_end(self);
}
size_t vector_size(VectorRef self) {
  assert(self);
  return vector_get_size(self);
}
void vector_reserve(VectorRef self, size_t size) {
  assert(self);
  if (vector_capacity(self) < size) {
    struct Vector original = *self;
    vector_alloc(self, size);
    vector_copy(self, &original);
    vector_free(&original);
  }
}
size_t vector_capacity(VectorRef self) {
  assert(self);
  return vector_get_capacity(self);
}
void vector_shrink_to_fit(VectorRef self) {
  assert(self);
  {
    const size_t size = vector_size(self);
    if (size < vector_capacity(self)) {
      struct Vector original = *self;
      vector_alloc(self, size);
      vector_copy(self, &original);
      vector_free(&original);
    }
  }
}
void vector_clear(VectorRef self) {
  assert(self);
  vector_set_size(self, 0);
}
void vector_insert(VectorRef self, size_t index,
                   const Type* data, size_t count) {
  assert(self);
  assert(count == 0 || data);
  if (0 < count) {
    const size_t size = vector_size(self);
    vector_reserve(self, size + count);
    {
      Type* const head = vector_begin(self) + index;
      Type* const tail = head + count;
      VECTOR_MEMORY_MOVE(tail, head, size - index);
      VECTOR_MEMORY_COPY(head, data, count);
      vector_set_size(self, size + count);
    }
  }
}
void vector_erase(VectorRef self, size_t index, size_t count) {
  assert(self);
  {
    const size_t size = vector_size(self);
    if (size < index + count) {
      count = size - index;
    }
    {
      const size_t new_size = size - count;
      Type* const head = vector_begin(self) + index;
      Type* const tail = head + count;
      VECTOR_MEMORY_MOVE(head, tail, new_size - index);
      vector_set_size(self, new_size);
    }
  }
}
void vector_push_back(VectorRef self, Type data) {
  assert(self);
  {
    const size_t new_size = vector_size(self) + 1;
    vector_reserve(self, new_size);
    *vector_end(self) = data;
    vector_set_size(self, new_size);
  }
}
void vector_pop_back(VectorRef self) {
  assert(self);
  vector_set_size(self, vector_size(self) - 1);
}
void vector_resize(VectorRef self, size_t size, Type fill) {
  assert(self);
  if (vector_size(self) < size) {
    vector_reserve(self, size);
    vector_fill(vector_end(self), fill, size - vector_size(self));
  }
  vector_set_size(self, size);
}
void vector_swap(VectorRef self, VectorRef other) {
  assert(self);
  {
    struct Vector tmp = *self;
    *self = *other;
    *other = tmp;
  }
}
