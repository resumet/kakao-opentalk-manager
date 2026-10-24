/* Minimal compiler helper for MSVC /NODEFAULTLIB builds. */
typedef unsigned __int64 CRT_SIZE_T;

#pragma function(memset)

void *__cdecl memset(void *destination, int value, CRT_SIZE_T count)
{
    volatile unsigned char *output = (volatile unsigned char *)destination;
    unsigned char byte_value = (unsigned char)value;

    while (count != 0) {
        *output = byte_value;
        ++output;
        --count;
    }

    return destination;
}
