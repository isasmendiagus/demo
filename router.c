#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "router.h"


/********************************************************************/ 
/*                                                                  */
/*                  SNIPPET TAKEN FROM LIBCURL                      */
/*                                                                  */
/********************************************************************/
static void custom_function(const char *filename, struct dynbuf *filebuf) {
  for(;;) {
    int c = getc(fp);
    if(c == EOF || (!pos && !ISSPACE(c))) {
      /* Strip and flush the current header. */
      while(hdrlen && ISSPACE(hdrbuf[hdrlen - 1]))
        hdrlen--;
      if(hdrlen) {
        hdrbuf[hdrlen] = '\0';
        if(slist_append(pheaders, hdrbuf)) {
          errorf(config->global, "Out of memory for field headers");
          return -1;
        }
        hdrlen = 0;
      }
    }
  }
}
/********************************************************************/ 
/*                                                                  */
/*                  SNIPPET TAKEN FROM LIBCURL                      */
/*                                                                  */
/********************************************************************/


void register_route(const char *path, RouteHandler handler) {
    if (route_count >= 10) {
        printf("Error: Too many routes registered\n");
        return;
    }
    
    strcpy(routes[route_count].path, path);
    routes[route_count].handler = handler;
    route_count++;
    
    printf("Route registered: %s\n", path);
}

