
        #include <fenv.h>

        int main() {
            return feenableexcept(FE_OVERFLOW | FE_DIVBYZERO);
        }