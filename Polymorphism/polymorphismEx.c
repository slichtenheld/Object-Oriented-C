#include <stdio.h>

// typedef struct {
//     int (*open)(void *self, char *fspec);
//     int (*close)(void *self);
//     int (*read)(void *self, void *buff, size_t max_sz, size_t *p_act_sz);
//     int (*write)(void *self, void *buff, size_t max_sz, size_t *p_act_sz);
//     // And data goes here.
// } tCommClass;

// The top-level class.
typedef struct _tCommClass {
    int (*open)(struct _tCommClass *self, char *fspec);
} tCommClass;

// Function for the TCP 'class'.
static int tcpOpen (tCommClass *tcp, char *fspec) {
    printf ("Opening TCP: %s\n", fspec);
    return 0;
}

static int tcpInit (tCommClass *tcp) {
    tcp->open = &tcpOpen;
    return 0;
}

// Function for the HTTP 'class'.
static int httpOpen (tCommClass *http, char *fspec) {
    printf ("Opening HTTP: %s\n", fspec);
    return 0;
}

static int httpInit (tCommClass *http) {
    http->open = &httpOpen;
    return 0;
}

// Test program.

int main (void) {
    int status;
    tCommClass commTcp, commHttp;

    // Same 'base' class but initialised to different sub-classes.

    tcpInit (&commTcp);
    httpInit (&commHttp);

    // Called in exactly the same manner.

    status = (commTcp.open)(&commTcp, "bigiron.box.com:5000");
    status = (commHttp.open)(&commHttp, "http://www.microsoft.com");

    return 0;
}
