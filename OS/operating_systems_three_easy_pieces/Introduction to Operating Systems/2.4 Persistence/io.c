#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("./file", O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
    assert(fd > -1);
    const char *buf = "Hello, World.\n";
    int rc = write(fd, buf, 15);
    assert(rc == 15);
    close(fd);

    return 0;
}