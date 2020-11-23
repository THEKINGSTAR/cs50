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
    RGBTRIPLE original_image_pixel[height][width] ;
    for (int i = 0; i <height; i++)
    {
        for (int  j = 0; j < width; j++)
        {
            original_image_pixel[i][j] = image[i][j] ;
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
            //check if the pixl is sourounded with 9 pixel or not , if trun
            //calculate the avarage rede , avarage green , avarage blue
            //if not take what surounded and
            int red   = original_image_pixel[i][j].rgbtRed;
            int green = original_image_pixel[i][j].rgbtGreen;
            int blue  = original_image_pixel[i][j].rgbtBlue;
            
            //the avarage of the current pixel
            float avarage = round((red + green + blue) / 3.0);
            int round_avarage = round(avarage);


            //courners calclulation
            if ((i==0|| i==height-1) && (j==0||j==width-1))
            {
                //calaculate the avarage of suorded three pixel plus the pixel (avarage of the 4)
                float avarage_red = round((original_image_pixel[i][j].rgbtRed + original_image_pixel[i][j+1].rgbtRed + original_image_pixel[i+1][j].rgbtRed + original_image_pixel[i+1][j+1].rgbtRed) / 3.0);
                int round_avarage_red = round(avarage_red);

                float avarage_green = round((original_image_pixel[i][j].rgbtGreen + original_image_pixel[i][j + 1].rgbtGreen + original_image_pixel[i + 1][j].rgbtGreen + original_image_pixel[i + 1][j + 1].rgbtGreen) / 3.0);
                int round_avarage_green = round(avarage_green);

                float avarage_blue = round((original_image_pixel[i][j].rgbtBlue + original_image_pixel[i][j + 1].rgbtBlue + original_image_pixel[i + 1][j].rgbtBlue + original_image_pixel[i + 1][j + 1].rgbtBlue) / 3.0);
                int round_avarage_blue = round(avarage_blue);

                image[i][j].rgbtRed = round_avarage_red;
                image[i][j].rgbtGreen = round_avarage_green;
                image[i][j].rgbtBlue = round_avarage_blue;
            }

            //first or last row calaculation
            else if (((i == 0 || i == height - 1) && (j > 0 || j == width - 2)) || (i > 0 && (j == 0 || j == width - 1)))
            {
                //calaculate the avarage of suorded three pixel plus the pixel (avarage of the 6)
                //for example i =0 , j = 1
                float avarage_red = round((original_image_pixel[i][j].rgbtRed + original_image_pixel[i][j - 1].rgbtRed + original_image_pixel[i][j + 1].rgbtRed + original_image_pixel[i + 1][j - 1].rgbtRed + original_image_pixel[i + 1][j].rgbtRed + original_image_pixel[i + 1][j + 1].rgbtRed) / 3.0);
                int round_avarage_red = round(avarage_red);

                float avarage_green = round((original_image_pixel[i][j].rgbtGreen + original_image_pixel[i][j - 1].rgbtGreen + original_image_pixel[i][j + 1].rgbtGreen + original_image_pixel[i + 1][j - 1].rgbtGreen + original_image_pixel[i + 1][j].rgbtGreen + original_image_pixel[i + 1][j + 1].rgbtGreen) / 3.0);
                int round_avarage_green = round(avarage_green);

                float avarage_blue = round((original_image_pixel[i][j].rgbtBlue + original_image_pixel[i][j - 1].rgbtBlue + original_image_pixel[i][j + 1].rgbtBlue + original_image_pixel[i + 1][j - 1].rgbtBlue + original_image_pixel[i + 1][j].rgbtBlue + original_image_pixel[i + 1][j + 1].rgbtBlue) / 3.0);
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