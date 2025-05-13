#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\\n", prog_name);
}

void xor_encrypt_decrypt(const char *input_path, const char *output_path, const char *key) {
    FILE *fin = fopen(input_path, "rb");
    if (!fin) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(output_path, "wb");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    size_t key_len = strlen(key);
    int ch;
    size_t i = 0;

    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key[i % key_len], fout);
        i++;
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key = argv[4];

    if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strlen(key) == 0) {
        fprintf(stderr, "Error: Key cannot be empty.\\n");
        return EXIT_FAILURE;
    }

    xor_encrypt_decrypt(input_file, output_file, key);

    printf("%sion completed successfully. Output file: %s\\n", mode, output_file);

    return EXIT_SUCCESS;
}
