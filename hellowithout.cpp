#include <unistd.h>

int main() {
    const char* message = "Hello World\n";
    write(1, message, 12);  // 1 is the file descriptor for stdout
    return 0;
}
