#include "better_string.h"
#include <stdio.h>

int main(void) {
  puts("\e[94mtesting str_init...");
  string* name = str_init();
  str_add(name, "variable that idk why is named name");
  
  puts("testing c_str... (output means test passed)\e[0m");
  puts(c_str(name));
  
  puts("\e[94mtesting c_str_to_str... (output means test passed)\e[0m");
  puts(c_str(c_str_to_str(c_str(name))));
  
  puts("\e[94mtesting str_len... (output means test passed)\e[0m");
  printf("%zu\n", str_len(name));

  puts("\e[94mtesting char_to_str... [input h] (output means test passed)\e[0m");
  puts(c_str(char_to_str('h')));
    
  str_free(name);
  return 0;
}
