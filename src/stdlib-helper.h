#ifndef INC_3D_VIEWER_STDLIB_HELPER_H
#define INC_3D_VIEWER_STDLIB_HELPER_H

#define malloc(size) malloc(size); mallocCount++
#define free(pointer) free(pointer); mallocCount--

extern unsigned long mallocCount;

#endif //INC_3D_VIEWER_STDLIB_HELPER_H
