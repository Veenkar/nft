#include <stdio.h>
#include "nft.h"
#include "math.h"

#define N_ELEMS(x)  ( sizeof(x) / sizeof(x[0]) )

void printarr(char * str, double * arr, size_t size)
{
    size_t idx;

    printf("%s[", str);
    for (idx = 0; idx < size - 1; ++idx)
    {
        printf("%f, ", arr[idx]);
    }
    printf("%f]\n", arr[size-1]);
}

int main()
{
    size_t idx;
    Nft_Val_T time_vals[256]; // = {1, 0, -1, 0, 1, 0, -1, 0};

    for (idx = 0; idx < N_ELEMS(time_vals); ++idx)
    {
        time_vals[idx] = sin( 2 * M_PI / 64.0 * idx);
    }

    Nft_Val_T freq_vals[N_ELEMS(time_vals)];

    printarr("time_vals: ", time_vals, N_ELEMS(time_vals));

    NFT(time_vals, freq_vals, N_ELEMS(freq_vals));
    printarr("freq_vals: ", freq_vals, N_ELEMS(freq_vals));

    return 0;
}
