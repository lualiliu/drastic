#!/bin/bash
# Wrapper script to run drastic with increased stack size
# This is necessary because the main thread's stack is allocated at process start
# and setrlimit() may not affect it on some systems

# Set stack size to 32MB (32768 KB)
ulimit -s 327680

# Check if it worked
STACK_SIZE=$(ulimit -s)
echo "Stack size set to: ${STACK_SIZE} KB" >&2

# Run drastic with all arguments passed through
exec ./drastic "$@"




