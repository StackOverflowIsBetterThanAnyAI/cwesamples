/*
 * CWE-121: Stack-based Buffer Overflow
 * https://cwe.mitre.org/data/definitions/121.html
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

static void
validate_addr_form(char *v) {
  // naive, simplistic validation
  if (strspn(v, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-0123456789.") < strlen(v)) {
    fprintf(stderr, "hostname contains invalid characters");
    exit(1);
  }
}

void
host_lookup(char *user_supplied_addr) {
  struct hostent *hp;
  in_addr_t *addr;
  char hostname[10];
  in_addr_t inet_addr(const char *cp);

  // routine that ensures user_supplied_addr is in the right format for conversion
  
  validate_addr_form(user_supplied_addr);
  addr = inet_addr(user_supplied_addr);
  hp = gethostbyaddr( addr, sizeof(struct in_addr), AF_INET);
  strcpy(hostname, hp->h_name);
}

int main() {
  host_lookup("his_is_a_string_longer_than_ten_chars");
}
