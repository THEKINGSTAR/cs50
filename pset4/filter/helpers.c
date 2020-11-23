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

            float avarage = round((red + green + blue) / 3);
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
    return;
}
