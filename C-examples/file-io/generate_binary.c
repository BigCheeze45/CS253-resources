
/* C-examples/files/generate_binary.c */
#include <stdio.h>
#include <stdlib.h>

struct record {
    int key;
    double value1;
    double value2;
    double value3;
};

const int MAX_KEY = 1000000;

void generate_file(int n, unsigned int seed, FILE *fout) {
    int i;
    struct record *next;

    next = (struct record *) malloc(sizeof(struct record));

    srand(seed); /* set starting seed for rand num. generator */
    for (i=0; i<n; i++) {
        next->key = rand() % MAX_KEY;
        next->value1 = rand()/((double)MAX_KEY);
        next->value2 = rand()/((double)MAX_KEY);
        next->value3 = rand()/((double)MAX_KEY);
        fwrite(next, sizeof(struct record), 1, fout);
    }
    free(next);
}

int main(int argc, char **argv) {
    int n;
    unsigned int seed;
    FILE *fout;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n> [<seed>]\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    if (argc == 3) {
        seed = atoi(argv[1]);
    }


    fout = fopen("data.bin", "w");
    if (!fout) {
        perror("");
    }

    generate_file(n ,seed, fout);

    fclose(fout);
    return 0;
}
