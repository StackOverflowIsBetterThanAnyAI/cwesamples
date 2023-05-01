/*
 * CWE-121: Stack-based Buffer Overflow
*/

#include <string.h>

#define BUFSIZE 10

int main(int argc, char **argv) {
  char buf[BUFSIZE];

  // segmentation fault if no value on argv[1]
  
  // The buffer overflow if the string in argv[1] exceed this size and cause an overflow.
  // example : ./sample.o this_is_a_string_longer_than_ten_chars
  strcpy(buf, argv[1]);
}
