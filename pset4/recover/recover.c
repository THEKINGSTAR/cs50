#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>
#include <cs50.h>

/*
//Pseudocode 

Open memory card

Repeat until end of card:
        Reeat 512 bytes into a buffer
        If start of new JPEG
            If first JPEG
                ......
            Else
                ......

        Else
            If already found JPEG

                //KEEP WRITING
                ......

close any remainig files

*/

typedef uint8_t BYTE;

char *jpeg_detect(char *file_name);
int find_jpeg =0;


//------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    // Ensure proper usage
    if (argc != optind +1 )
    {
        fprintf(stderr, "Usage: ./recover image\n");
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

    //jpeg_detect(infile);

        // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }


    sprintf(outfile,"%03i.jpg",2);
    fread(outptr,512,1,inptr);
    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    /*
 // Allocate memory for image
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }
    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Free memory for image
    free(image);


    */
}

//------------------------------------------------------------------------------------------------------------------------
//loking for jpg
/*
char *jpeg_detect(char *file_name)
{
    fread(data,size,number,file_name);
    //loop throw the start mem untl found the jpeg incress "find_jpeg" after the last location of the jpeg
    //
    int frist_bytes ;
    int second_bytes ;
    int third_bytes ;

    if (frist_bytes == 0xff &&second_bytes == 0xd8 && third_bytes == 0xff)
    {
        // if all true the start of the file is jpeg , loking for the end 
    }

    int last_frist_bytes;
    int last_second_bytes;
    int last_third_bytes;

    if (last_frist_bytes && last_second_bytes && last_third_bytes)
    {

    }

    

}
*/


