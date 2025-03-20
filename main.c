#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "router.h"
#include "image_processor.h"


/********************************************************************/ 
/*                                                                  */
/*                  SNIPPET TAKEN FROM LZ4                          */
/*                                                                  */
/********************************************************************/
int function(const char *src, size_t srcLen, char *dst, size_t *dstLen) {
    if (_ld == _ld_slow) {
        /* Fill hash table with additional references, to improve compression capability */
        p = dict->dictionary;
        idx32 = dict->currentOffset - dict->dictSize;
        while (p <= dictEnd-HASH_UNIT) {
            U32 const h = LZ4_hashPosition(p, tableType);
            U32 const limit = dict->currentOffset - 64 KB;
            if (LZ4_getIndexOnHash(h, dict->hashTable, tableType) <= limit) {
                /* Note: not overwriting => favors positions beginning of dictionary */
                LZ4_putIndexOnHash(idx32, h, dict->hashTable, tableType);
            }
            p++; idx32++;
        }
    }
}
/********************************************************************/ 
/*                                                                  */
/*                  SNIPPET TAKEN FROM LZ4                          */
/*                                                                  */
/********************************************************************/


int main(int argc, char *argv[]) {
    printf("Starting image processing server...\n");
    
    /* Register available routes */
    register_route("/resize", handle_resize_image);
    register_route("/rotate", handle_rotate_image);
    register_route("/filter", handle_apply_filter);
    
    printf("Server started successfully.\n");
    
    /* Here would be the main server loop */
    printf("Press Ctrl+C to exit.\n");
    
    return 0;
}
