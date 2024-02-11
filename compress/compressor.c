#include <stdlib.h>
#include <stdio.h>
#include "../lib/headers/compress.h"

int
main(void) {
    FILE *input;
    FILE *output;
    input = fopen("inputt.txt", "r");
    output = fopen("output.txt", "w");
    int n = 0;
    char *data, cur;
    while (1) {
        cur = fgetc(input);
        if (cur == EOF) {
            break;
        }
        ++n;
    }
    data = calloc(n, sizeof(*data));
    fseek(input, 0, 0);
    for (int i = 0; i < n; ++i) {
        cur = fgetc(input);
        data[i] = cur;
    }
    CompressedData out_data;
    CompressType mode = RLE_COMPRESS;
    out_data = compress(mode, n, data);
    out_data = rle_decompress(out_data);
    char *out = out_data.data;
    printf("%s\n", out);
    free(out);
    fclose(input);
    fclose(output);
    return 0;
}
