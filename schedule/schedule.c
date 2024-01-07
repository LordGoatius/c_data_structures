#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "schedule.h"

typedef struct {
    Vector* vec;
    int value;
} thread_args;

void *thread_push(void *args) {
    // wait for all threads to be created
    sleep(1);
    thread_args *actual_args = args;

    vec_push(actual_args->vec, actual_args->value);

    free(actual_args);
    return 0;
}

void schedule_sort(Vector *vec) {
    int size = vec_size(vec);
    pthread_t* thread_id = (pthread_t*) malloc(size * sizeof(pthread_t));

    for (int i = 0; i < size; ++i) {
        int vec_val = vec_pop(vec);
        thread_args *args = malloc(sizeof(thread_args));
        args->vec = vec;
        args->value = vec_val;
        if (pthread_create(&thread_id[i], NULL, thread_push, (void*)args)) {
            // free if not created
            free(args);
        }
        switch (pthread_setschedprio(thread_id[i], vec_val)) {
            case EINVAL: 
                puts("Invalid proiority");
                break;
            case ENOTSUP:
                puts("Unsupported value");
                break;
            case EPERM:
                puts("No permissions to set scheduling policy OR");
                puts("implementation doesn't allow priority modifying");
                break;
            case ESRCH:
                puts("Does not refer to existing thread");
                break;
            default:
                puts("Unknown");
        }
    }

    free(thread_id);

    for (int i = 0; i < size; ++i) {
        pthread_join(thread_id[i], NULL);
    }
}
