void print_num(int);
void print(const char *);

void put_num(int n) {
  print_num(n);
  print(" ");
}

int collatz() {
  int n = 27;
  
  while (n != 1) {
    put_num(n);
    
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    
    if (n > 1000) {
      print("\n");
      return n;
    }
  }
  print("\n");
  return -1;
}

void return_nothing() {
  print(":)\n");
  return;
  print("X(\n");
  return;
}

int main(void) {
  int i, j, count;

  i = 0;
  for (;;) {
    put_num(i++);
    if (i > 5) { break; }
  }
  print("\n");

  i = collatz();
  print_num(i);
  print(" > 1000\n");

  for (i = 0; i < 10; ++i) {
    if (i & 1) { continue; }
    put_num(i);
  }
  print("\n");

  i = 1;
loop_head:
  put_num(i);
  i = i * 2;
  if (i > 1000) goto loop_tail;
  goto loop_head;
loop_tail:
  print("\n");

  j = 1;
  goto first_time;
  for (;j < 100;) {
    if (count > 30) {
      print("\n");
      j += 1;
first_time:
      i = j, count = 1;
      print("j = "); print_num(j); print(": ");
      continue;
    }

    i = (i + j) % 121;
    count++;
    print_num(i); print(",");
    if (i == 0 && count == j) {
      print("\nsqrt of 121 = "); print_num(j); print("\n");
      break;
    }
  }

  for (i = 1; i < 100; ++i)
    for (j = 1; j < 100; ++j)
      for (count = 1; count < 100; ++count)
        if (i * i + j * j == count * count) do {
          put_num(i);
          put_num(j);
          put_num(count);
          print("\n");
          goto end_of_3_nested_for;
        } while (0);
end_of_3_nested_for:

  return_nothing();

  goto NULL;
  print("\"goto NULL;\" failed\n");
NULL:
  goto define;
  print("\"goto define;\" failed\n");
define:
  goto include;
  print("\"goto include;\" failed\n");
include:
  
  return 0;
}
