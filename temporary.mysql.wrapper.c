#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
  const char * base_cmd = "/root/bin/temporary.mysql.main";
  char * cmd;
  char * frame_ptr; 
  int buf_required = 0;
  int i = 0; 
  char sep = ' '; 
  int base_len = 0; 
  base_len = strlen(base_cmd);
  buf_required = base_len + 1; 

  if(argc > 1) { 
    for(i = 1; i < argc; i++) {
      buf_required += strlen(argv[i]) + 1;
    }
  }
  cmd = (char *) malloc(buf_required + 1);

  memset(cmd, 0, buf_required + 1);
  memcpy(cmd, base_cmd, base_len); 
  frame_ptr = cmd + base_len; 
  *frame_ptr = ' '; 
  frame_ptr++; 
  for(i = 1; i < argc; i++) {
     base_len = strlen(argv[i]); 
     memcpy(frame_ptr, argv[i], base_len);
     frame_ptr += base_len; 
     *frame_ptr = ' ';
     frame_ptr++; 
  }
  *frame_ptr = 0;
  setuid(0); 
  system(cmd);
  return 0;
}

