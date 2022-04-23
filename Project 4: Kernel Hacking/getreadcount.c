#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int getcount(void) {

    int readcount = getcount();
    printf(1, "readcount: %d\n", readcount);
    
    exit();
}
