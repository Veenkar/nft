/*******************************************************************************
 * nft.c
 *
 *
 *
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "nft.h"
#include <math.h>

/*******************************************************************************
 * Define Macros
 ******************************************************************************/

/*******************************************************************************
 * Function-Like Macros
 ******************************************************************************/
#define FREQ_SIN(freq, x)   ( sin(2.0 * M_PI * (x) * (freq)) )
#define FREQ_COS(freq, x)   ( cos(2.0 * M_PI * (x) * (freq)) )
#define SQ(x)               ( (x) * (x) )

/*******************************************************************************
 * Type Declarations
 ******************************************************************************/

/*******************************************************************************
 * Object Declarations
 ******************************************************************************/

/*******************************************************************************
 * Functions Declarations
 ******************************************************************************/

/*******************************************************************************
 * Functions Definitions
 ******************************************************************************/
void NFT(Nft_Val_T * time_vals_in, Nft_Val_T * freq_vals_out, size_t size)
{
    size_t time_idx, freq_idx;

    /* to get frequency-domain values */
    /* for each frequency imagine a sinusiod */
    for (freq_idx = 0; freq_idx < size; ++freq_idx)
    {
        Nft_Val_T real = 0.0, imag = 0.0;

        /* each point on the sinusiod */
        for (time_idx = 0; time_idx < size; ++time_idx)
        {
            /* has to be multiplied by the corresponding time-domain value */
            real += time_vals_in[time_idx] * FREQ_SIN(freq_idx, (double)time_idx/size);
            imag += time_vals_in[time_idx] * FREQ_COS(freq_idx, (double)time_idx/size);
        }

        /* value for that frequency is the sum of multiplied plots */
        freq_vals_out[freq_idx] = sqrt( SQ(real) + SQ(imag) );
    }
}

/*******************************************************************************
 * End nft.c
 ******************************************************************************/