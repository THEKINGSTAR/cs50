#include <stdio.h>
#include <math.h>
#include "helpers.h"

/*
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
*/

// Convert image to grayscale
//claculate the avarage (RED GREEN BLUE) VALUE for darkeer and lighter gray
/*
---------------------------------
red     --  50
---------------------------------
green   --  190
---------------------------------
blue    --  90
---------------------------------
    Average  = (50+190+90)/3  = 110
#################################
---------------------------------
red     --  110
---------------------------------
green   --  110
---------------------------------
blue    --  110
---------------------------------
//if the value is not int round it to nearst range aka 109.8 = 110
*/
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float avarage = round((red + green + blue) / 3.0);
            int round_avarage = round(avarage);

            //printf("%i",avarage);

            if (red == green && red > 0)
            {
                image[i][j].rgbtBlue = red;
            }
            else if (red == blue && red > 0)
            {
                image[i][j].rgbtGreen = red;
            }
            else if (green == blue && green > 0)
            {
                image[i][j].rgbtRed = green;
            }
            else
            {
                image[i][j].rgbtRed = round_avarage;
                image[i][j].rgbtGreen = round_avarage;
                image[i][j].rgbtBlue = round_avarage;
            }
        }
    }

    return;
}

//------------------------------------------------------------------------
/*
sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
*/

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Original
            int originalRed = round(image[i][j].rgbtRed);
            int originalGreen = round(image[i][j].rgbtGreen);
            int originalBlue = round(image[i][j].rgbtBlue);

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            //color in deciml shoud not exed 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // int row[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            int left_red = image[i][j].rgbtRed;
            int left_green = image[i][j].rgbtGreen;
            int left_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = left_red;
            image[i][width - j - 1].rgbtGreen = left_green;
            image[i][width - j - 1].rgbtBlue = left_blue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    /*
        # .  # .  # .  #
        # .  # .  # .  #
        # .  # .  # .  #
        # .  # .  # .  #
        # .  # .  # .  #
    */

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //filters corner pixels
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1))
            {

                int i_next_to = 0;
                int j_next_to = 0;
                //top left pixel
                if (i == 0 && j == 0)
                {
                    i_next_to = 1;
                    j_next_to = 1;
                }
                //top far right pixel
                else if (i == 0 && j == width - 1)
                {
                    i_next_to = 1;
                    j_next_to = -1;
                }
                //buttom left pixel
                else if (i == height - 1 && j == 0)
                {
                    i_next_to = -1;
                    j_next_to = 1;
                }
                //buttom far right pixel
                else if (i == height - 1 && j == width - 1)
                {
                    i_next_to = -1;
                    j_next_to = -1;
                }

                //calaculate the avarage of suorded other (3) three pixel + the corner pixel (avarage of the 4)
                float avarage_red = round((original[i][j].rgbtRed + original[i][j + j_next_to].rgbtRed + original[i + i_next_to][j].rgbtRed + original[i + i_next_to][j + j_next_to].rgbtRed) / 4.0);
                int round_avarage_red = round(avarage_red);

                float avarage_green = round((original[i][j].rgbtGreen + original[i][j + j_next_to].rgbtGreen + original[i + i_next_to][j].rgbtGreen + original[i + i_next_to][j + j_next_to].rgbtGreen) / 4.0);
                int round_avarage_green = round(avarage_green);

                float avarage_blue = round((original[i][j].rgbtBlue + original[i][j + j_next_to].rgbtBlue + original[i + i_next_to][j].rgbtBlue + original[i + i_next_to][j + j_next_to].rgbtBlue) / 4.0);
                int round_avarage_blue = round(avarage_blue);

                image[i][j].rgbtRed = round_avarage_red;
                image[i][j].rgbtGreen = round_avarage_green;
                image[i][j].rgbtBlue = round_avarage_blue;
            }
            //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // filters edge pixel
            //first or last row calaculation
            //else if ((i == 0 && j > 0 && j < width - 2) || (i > 0 && i < height - 2 && j == 0) || (i > 0 && i < hight - 2 && j == width - 1))
            else if (((i == 0 || i == height - 1) && (j > 0 || j == width - 2)) || (i > 0 && (j == 0 || j == width - 1)))
            {
                int round_avarage_red = 0;
                int round_avarage_green = 0;
                int round_avarage_blue = 0;
                //calaculate the avarage of suorded three pixel plus the pixel (avarage of the 6)
                //for example i =0 , j = 1

                if (i == 0 && (j > 0 || j == width - 2))
                {

                    float avarage_red = round((original[i][j].rgbtRed + original[i][j - 1].rgbtRed + original[i][j + 1].rgbtRed + original[i + 1][j - 1].rgbtRed + original[i + 1][j].rgbtRed + original[i + 1][j + 1].rgbtRed) / 6.0);
                    round_avarage_red = round(avarage_red);

                    float avarage_green = round((original[i][j].rgbtGreen + original[i][j - 1].rgbtGreen + original[i][j + 1].rgbtGreen + original[i + 1][j - 1].rgbtGreen + original[i + 1][j].rgbtGreen + original[i + 1][j + 1].rgbtGreen) / 6.0);
                    round_avarage_green = round(avarage_green);

                    float avarage_blue = round((original[i][j].rgbtBlue + original[i][j - 1].rgbtBlue + original[i][j + 1].rgbtBlue + original[i + 1][j - 1].rgbtBlue + original[i + 1][j].rgbtBlue + original[i + 1][j + 1].rgbtBlue) / 6.0);
                    round_avarage_blue = round(avarage_blue);
                }

                if (i > 0 && (j == 0 || j == width - 1))
                {
                    if (j == 0)
                    {
                        float avarage_red = round((original[i - 1][j].rgbtRed + original[i - 1][j + 1].rgbtRed + original[i][j].rgbtRed + original[i][j + 1].rgbtRed + original[i + 1][j].rgbtRed + original[i + 1][j + 1].rgbtRed) / 6.0);
                        round_avarage_red = round(avarage_red);

                        float avarage_green = round((original[i - 1][j].rgbtGreen + original[i - 1][j + 1].rgbtGreen + original[i][j].rgbtGreen + original[i][j + 1].rgbtGreen + original[i + 1][j].rgbtGreen + original[i + 1][j + 1].rgbtGreen) / 6.0);
                        round_avarage_green = round(avarage_green);

                        float avarage_blue = round((original[i - 1][j].rgbtBlue + original[i - 1][j + 1].rgbtBlue + original[i][j].rgbtBlue + original[i][j + 1].rgbtBlue + original[i + 1][j].rgbtBlue + original[i + 1][j + 1].rgbtBlue) / 6.0);
                        round_avarage_blue = round(avarage_blue);
                    }
                    if (j == width - 1)
                    {
                        float avarage_red = round((original[i - 1][j].rgbtRed + original[i - 1][j - 1].rgbtRed + original[i][j].rgbtRed + original[i][j - 1].rgbtRed + original[i + 1][j].rgbtRed + original[i + 1][j - 1].rgbtRed) / 6.0);
                        round_avarage_red = round(avarage_red);

                        float avarage_green = round((original[i - 1][j].rgbtGreen + original[i - 1][j - 1].rgbtGreen + original[i][j].rgbtGreen + original[i][j - 1].rgbtGreen + original[i + 1][j].rgbtGreen + original[i + 1][j - 1].rgbtGreen) / 6.0);
                        round_avarage_green = round(avarage_green);

                        float avarage_blue = round((original[i - 1][j].rgbtBlue + original[i - 1][j - 1].rgbtBlue + original[i][j].rgbtBlue + original[i][j - 1].rgbtBlue + original[i + 1][j].rgbtBlue + original[i + 1][j - 1].rgbtBlue) / 6.0);
                        round_avarage_blue = round(avarage_blue);
                    }
                }
                if (i == height - 1 && (j > 0 || j == width - 2))
                {

                    float avarage_red = round((original[i - 1][j - 1].rgbtRed + original[i - 1][j].rgbtRed + original[i - 1][j + 1].rgbtRed + original[i][j - 1].rgbtRed + original[i][j].rgbtRed + original[i][j + 1].rgbtRed) / 6.0);
                    round_avarage_red = round(avarage_red);

                    float avarage_green = round((original[i - 1][j - 1].rgbtGreen + original[i - 1][j].rgbtGreen + original[i - 1][j + 1].rgbtGreen + original[i][j - 1].rgbtGreen + original[i][j].rgbtGreen + original[i][j + 1].rgbtGreen) / 6.0);
                    round_avarage_green = round(avarage_green);

                    float avarage_blue = round((original[i - 1][j - 1].rgbtBlue + original[i - 1][j].rgbtBlue + original[i - 1][j + 1].rgbtBlue + original[i][j - 1].rgbtBlue + original[i][j].rgbtBlue + original[i][j + 1].rgbtBlue) / 6.0);
                    round_avarage_blue = round(avarage_blue);
                }

                image[i][j].rgbtRed = round_avarage_red;
                image[i][j].rgbtGreen = round_avarage_green;
                image[i][j].rgbtBlue = round_avarage_blue;
            }
            //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // filters middle pixel
            //check if the pixl is sourounded with 9 pixel or not
            // get the original pixel vlaue red blue green and add them to new value befule calcualte the avarage
            else if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
            {
                float red = 0;
                float green = 0;
                float blue = 0;
                int pixel_ith = i - 1;

                for (int bi = 0; bi < 3; bi++)
                {
                    int pixel_jth = j - 1;
                    for (int bj = 0; bj < 3; bj++)
                    {

                        red = red + original[pixel_ith][pixel_jth].rgbtRed;
                        green = green + original[pixel_ith][pixel_jth].rgbtGreen;
                        blue = blue + original[pixel_ith][pixel_jth].rgbtBlue;

                        pixel_jth++;
                    }
                    pixel_ith++;
                }

                float avarage_red = round(red / 9.0);
                int round_avarage_red = round(avarage_red);

                float avarage_green = round(green / 9.0);
                int round_avarage_green = round(avarage_green);

                float avarage_blue = round(blue / 9.0);
                int round_avarage_blue = round(avarage_blue);

                image[i][j].rgbtRed = round_avarage_red;
                image[i][j].rgbtGreen = round_avarage_green;
                image[i][j].rgbtBlue = round_avarage_blue;
            }
        }
    }

    return;
}

//helper function to claculate the surunded fo pixel
//deprecated :)
/*
int pixel_count(int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {




        }

    }

}
*/

//###############################################################################################################################################################
/*
~/pset4/filter/ $ check50 cs50/problems/2020/x/filter/less
Connecting.....
Authenticating....
Verifying......
Preparing.....
Uploading............
Waiting for results.................................................................
Results for cs50/problems/2020/x/filter/less generated by check50 v3.1.2
:) helpers.c exists
:) filter compiles
:) grayscale correctly filters single pixel with whole number average
:) grayscale correctly filters single pixel without whole number average
:) grayscale leaves alone pixels that are already gray
:) grayscale correctly filters simple 3x3 image
:) grayscale correctly filters more complex 3x3 image
:) grayscale correctly filters 4x4 image
:) sepia correctly filters single pixel
:) sepia correctly filters simple 3x3 image
:) sepia correctly filters more complex 3x3 image
:) sepia correctly filters 4x4 image
:) reflect correctly filters 1x2 image
:) reflect correctly filters 1x3 image
:) reflect correctly filters image that is its own mirror image
:) reflect correctly filters 3x3 image
:) reflect correctly filters 4x4 image
:) blur correctly filters middle pixel
:) blur correctly filters pixel on edge
:) blur correctly filters pixel in corner
:) blur correctly filters 3x3 image
:) blur correctly filters 4x4 image
To see the results in your browser go to https://submit.cs50.io/check50/a5eeaf52af7ead5db3c8c3767c4be5b4b07d183c

*/
//###############################################################################################################################################################
