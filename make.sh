# Build with increased stack size to prevent stack overflow
# Note: The large stack array in load_file() has been converted to heap allocation
# This flag sets a larger default stack size (8MB default, increased to 32MB as safety measure)
# The -Wl,-z,stack-size flag sets the stack size for the main thread
g++ drastic.cpp -g -o drastic -fpermissive -I. -lSDL2 -Wl,-z,stack-size=33554432 
