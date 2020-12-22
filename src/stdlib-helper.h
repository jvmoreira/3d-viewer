#ifndef INC_3D_VIEWER_STDLIB_HELPER_H
#define INC_3D_VIEWER_STDLIB_HELPER_H

#include <stdlib.h>

#define malloc(size) malloc(size); mallocCount++
#define free(size) free(size); mallocCount--

int mallocCount;

#endif //INC_3D_VIEWER_STDLIB_HELPER_H
