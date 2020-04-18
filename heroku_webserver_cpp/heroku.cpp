#include "heroku.h"

#include <cstdlib>
#include <cstring>

#include <cstdio>
#include <pthread.h>

#include "webserver.h"

void *thread_main(void *arg);

void heroku_start_webserver_thread()
{
    pthread_t thread;
    int err = pthread_create(&thread, NULL, &thread_main, NULL);
    if (err != 0)
        printf("# Can't create thread :[%s]", strerror(err));
    else
        printf("# Thread created successfully\n");
}

void *thread_main(void *arg)
{
    printf("# New thread started \n");
    //
    const char *portEnv = getenv("PORT");
    if (portEnv == NULL)
        portEnv = "3000";
    int portno = atoi(portEnv);
    (void)webserver_run(portno);
    //
    return NULL;
}