
        #include <string.h>
        int main() {
        const char *s = "abc";
          return memrchr((const void *)s, 0, 3) != NULL;
        }