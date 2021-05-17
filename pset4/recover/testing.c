//testing
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;

typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} __attribute__((__packed__))
JPEGFILEHEADER;

typedef struct 
{
int image_start;
int image_end;
} 
IMAGEFILE;

int main(int argc, char *argv[])
{

    // Define allowable filters
    char *filters = "begr";

    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    // Ensure only one filter
    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "Only one filter allowed.\n");
        return 2;
    }

    // Ensure proper usage
    if (argc != optind + 2)
    {
        fprintf(stderr, "Usage: filter [flag] infile outfile\n");
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    JPEGFILEHEADER bf;
    fread(&bf, sizeof(JPEGFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    JPEGFILEHEADER bi;
    fread(&bi, sizeof(JPEGFILEHEADER), 1, inptr);

    int height;
    int width ;

    // Allocate memory for image
    IMAGEFILE(*image)
    [width] = calloc(height, width * sizeof(IMAGEFILE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

      // Write outfile's JPEGFILEHEADER
    fwrite(&bf, sizeof(JPEGFILEHEADER), 1, outptr);

    // Write outfile's JPEGFILEHEADER
    fwrite(&bi, sizeof(JPEGFILEHEADER), 1, outptr);

    // Write new pointer to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(IMAGEFILE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Free memory for image
    free(image);

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    return 0;
}
