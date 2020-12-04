#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
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
                float avarage_red = round((original[i][j].rgbtRed + original[i][j + j_next_to].rgbtRed + original[i + i_next_to][j].rgbtRed +
                                           original[i + i_next_to][j + j_next_to].rgbtRed) /
                                          4.0);
                int round_avarage_red = round(avarage_red);

                float avarage_green = round((original[i][j].rgbtGreen + original[i][j + j_next_to].rgbtGreen + original[i + i_next_to][j].rgbtGreen + original[i + i_next_to][j + j_next_to].rgbtGreen) / 4.0);
                int round_avarage_green = round(avarage_green);

                float avarage_blue = round((original[i][j].rgbtBlue + original[i][j + j_next_to].rgbtBlue + original[i + i_next_to][j].rgbtBlue +
                                            original[i + i_next_to][j + j_next_to].rgbtBlue) /
                                           4.0);
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

                    float avarage_red = round((original[i][j].rgbtRed + original[i][j - 1].rgbtRed + original[i][j + 1].rgbtRed +
                                               original[i + 1][j - 1].rgbtRed + original[i + 1][j].rgbtRed + original[i + 1][j + 1].rgbtRed) /
                                              6.0);
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
                        float avarage_red = round((original[i - 1][j].rgbtRed + original[i - 1][j + 1].rgbtRed + original[i][j].rgbtRed +
                                                   original[i][j + 1].rgbtRed + original[i + 1][j].rgbtRed + original[i + 1][j + 1].rgbtRed) /
                                                  6.0);
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
// Detect edges

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //filters corner pixels
            if ((i == 0 || i == height - 1) && (j == 0 || j == width - 1))
            {
                //calaculate the avarage of suorded other (3) three pixel + the corner pixel (avarage of the 4)
                float gx_red = 0;
                float gx_green = 0;
                float gx_blue = 0;

                float gy_red = 0;
                float gy_green = 0;
                float gy_blue = 0;
                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                int i_next_to = 0;
                int j_next_to = 0;
                //top left pixel
                if (i == 0 && j == 0)
                {
                    i_next_to = 1;
                    j_next_to = 1;
gx_red   = round(0*(original[i][j].rgbtRed)   +2*(original[i][j + j_next_to].rgbtRed)   +0*(original[i + i_next_to][j].rgbtRed)   +1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gx_green = round(0*(original[i][j].rgbtGreen) +2*(original[i][j + j_next_to].rgbtGreen) +0*(original[i + i_next_to][j].rgbtGreen) +1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gx_blue  = round(0*(original[i][j].rgbtBlue)  +2*(original[i][j + j_next_to].rgbtBlue)  +0*(original[i + i_next_to][j].rgbtBlue)  +1*(original[i + i_next_to][j + j_next_to].rgbtBlue)); 

gy_red   = round(0*(original[i][j].rgbtRed)   +0*(original[i][j + j_next_to].rgbtRed)   +2*(original[i + i_next_to][j].rgbtRed)   +1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gy_green = round(0*(original[i][j].rgbtGreen) +0*(original[i][j + j_next_to].rgbtGreen) +2*(original[i + i_next_to][j].rgbtGreen) +1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gy_blue  = round(0*(original[i][j].rgbtBlue)  +0*(original[i][j + j_next_to].rgbtBlue)  +2*(original[i + i_next_to][j].rgbtBlue)  +1*(original[i + i_next_to][j + j_next_to].rgbtBlue));
                }
                //top far right pixel
                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                else if (i == 0 && j == width - 1)
                {
                    i_next_to = 1;
                    j_next_to = -1;
gx_red   = round(0*(original[i][j].rgbtRed)   +-2*(original[i][j + j_next_to].rgbtRed)   +0*(original[i + i_next_to][j].rgbtRed)   +-1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gx_green = round(0*(original[i][j].rgbtGreen) +-2*(original[i][j + j_next_to].rgbtGreen) +0*(original[i + i_next_to][j].rgbtGreen) +-1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gx_blue  = round(0*(original[i][j].rgbtBlue)  +-2*(original[i][j + j_next_to].rgbtBlue)  +0*(original[i + i_next_to][j].rgbtBlue)  +-1*(original[i + i_next_to][j + j_next_to].rgbtBlue)); 

gy_red   = round(0*(original[i][j].rgbtRed)   +0*(original[i][j + j_next_to].rgbtRed)   +2*(original[i + i_next_to][j].rgbtRed)   +1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gy_green = round(0*(original[i][j].rgbtGreen) +0*(original[i][j + j_next_to].rgbtGreen) +2*(original[i + i_next_to][j].rgbtGreen) +1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gy_blue  = round(0*(original[i][j].rgbtBlue)  +0*(original[i][j + j_next_to].rgbtBlue)  +2*(original[i + i_next_to][j].rgbtBlue)  +1*(original[i + i_next_to][j + j_next_to].rgbtBlue));
                }

                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                //buttom left pixel
                else if (i == height - 1 && j == 0)
                {
                    i_next_to = -1;
                    j_next_to = 1;
gx_red   = round(0*(original[i][j].rgbtRed)   +2*(original[i][j + j_next_to].rgbtRed)   +0*(original[i + i_next_to][j].rgbtRed)   +1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gx_green = round(0*(original[i][j].rgbtGreen) +2*(original[i][j + j_next_to].rgbtGreen) +0*(original[i + i_next_to][j].rgbtGreen) +1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gx_blue  = round(0*(original[i][j].rgbtBlue)  +2*(original[i][j + j_next_to].rgbtBlue)  +0*(original[i + i_next_to][j].rgbtBlue)  +1*(original[i + i_next_to][j + j_next_to].rgbtBlue)); 

gy_red   = round(0*(original[i][j].rgbtRed)   +0*(original[i][j + j_next_to].rgbtRed)   +-2*(original[i + i_next_to][j].rgbtRed)   +-1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gy_green = round(0*(original[i][j].rgbtGreen) +0*(original[i][j + j_next_to].rgbtGreen) +-2*(original[i + i_next_to][j].rgbtGreen) +-1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gy_blue  = round(0*(original[i][j].rgbtBlue)  +0*(original[i][j + j_next_to].rgbtBlue)  +-2*(original[i + i_next_to][j].rgbtBlue)  +-1*(original[i + i_next_to][j + j_next_to].rgbtBlue));
                }
                //buttom far right pixel
                else if (i == height - 1 && j == width - 1)
                {
                    i_next_to = -1;
                    j_next_to = -1;
gx_red   = round(0*(original[i][j].rgbtRed)   +-2*(original[i][j + j_next_to].rgbtRed)   +0*(original[i + i_next_to][j].rgbtRed)   +-1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gx_green = round(0*(original[i][j].rgbtGreen) +-2*(original[i][j + j_next_to].rgbtGreen) +0*(original[i + i_next_to][j].rgbtGreen) +-1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gx_blue  = round(0*(original[i][j].rgbtBlue)  +-2*(original[i][j + j_next_to].rgbtBlue)  +0*(original[i + i_next_to][j].rgbtBlue)  +-1*(original[i + i_next_to][j + j_next_to].rgbtBlue)); 

gy_red   = round(0*(original[i][j].rgbtRed)   +0*(original[i][j + j_next_to].rgbtRed)   +-2*(original[i + i_next_to][j].rgbtRed)   +-1*(original[i + i_next_to][j + j_next_to].rgbtRed));
gy_green = round(0*(original[i][j].rgbtGreen) +0*(original[i][j + j_next_to].rgbtGreen) +-2*(original[i + i_next_to][j].rgbtGreen) +-1*(original[i + i_next_to][j + j_next_to].rgbtGreen));                                      
gy_blue  = round(0*(original[i][j].rgbtBlue)  +0*(original[i][j + j_next_to].rgbtBlue)  +-2*(original[i + i_next_to][j].rgbtBlue)  +-1*(original[i + i_next_to][j + j_next_to].rgbtBlue));
                }
                int round_gx_red   = round(gx_red);
                int round_gx_green = round(gx_green);
                int round_gx_blue  = round(gx_blue);
                
                int round_gy_red   = round(gy_red);
                int round_gy_green = round(gy_green);
                int round_gy_blue  = round(gy_blue);

                int g_red   = round(sqrt((round_gx_red * round_gx_red) + (round_gy_red * round_gy_red)));
                int g_green = round(sqrt((round_gx_green * round_gx_green) + (round_gy_green * round_gy_green)));
                int g_blue  = round(sqrt((round_gx_blue * round_gx_blue) + (round_gy_blue * round_gy_blue)));
                if (g_red > 255)
                {
                    g_red = 255;
                }
                if (g_green > 255)
                {
                    g_green = 255;
                }
                if (g_blue > 255)
                {
                    g_blue = 255;
                }
                image[i][j].rgbtRed   = g_red ;
                image[i][j].rgbtGreen = g_green ;
                image[i][j].rgbtBlue  = g_blue ;
            }
            //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // filters edge pixel
            else if (((i == 0 || i == height - 1) && (j > 0 || j == width - 2)) || (i > 0 && (j == 0 || j == width - 1)))
            {
                float gx_red = 0;
                float gx_green = 0;
                float gx_blue = 0;

                float gy_red = 0;
                float gy_green = 0;
                float gy_blue = 0;
                //calaculate the avarage of suorded three pixel plus the pixel (avarage of the 6)
                //for example i =0 , j = 1
                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */

               //edge on top
                if (i == 0 && (j > 0 || j == width - 2))
                {

                     gx_red = round((0*original[i][j].rgbtRed + -2*original[i][j - 1].rgbtRed + 2*original[i][j + 1].rgbtRed +
                                          -1*original[i + 1][j - 1].rgbtRed + 0*original[i + 1][j].rgbtRed + 1*original[i + 1][j + 1].rgbtRed));

                     gx_green = round((0*original[i][j].rgbtGreen +-2* original[i][j - 1].rgbtGreen +2* original[i][j + 1].rgbtGreen +
                                           -1* original[i + 1][j - 1].rgbtGreen + 0*original[i + 1][j].rgbtGreen +1* original[i + 1][j + 1].rgbtGreen));

                     gx_blue = round((0*original[i][j].rgbtBlue + -2*original[i][j - 1].rgbtBlue + 2* original[i][j + 1].rgbtBlue +
                                           -1*original[i + 1][j - 1].rgbtBlue + 0*original[i + 1][j].rgbtBlue + 1*original[i + 1][j + 1].rgbtBlue));
                    //------------------------------------------------------------------------------------------------------------------------------
                     gy_red = round((0*original[i][j].rgbtRed +0* original[i][j - 1].rgbtRed + 0*original[i][j + 1].rgbtRed +
                                     1*original[i + 1][j - 1].rgbtRed + 2*original[i + 1][j].rgbtRed + 1*original[i + 1][j + 1].rgbtRed));

                     gy_green = round((0*original[i][j].rgbtGreen + 0*original[i][j - 1].rgbtGreen + 0*original[i][j + 1].rgbtGreen +
                                       1*original[i + 1][j - 1].rgbtGreen + 2*original[i + 1][j].rgbtGreen +1* original[i + 1][j + 1].rgbtGreen));

                     gy_blue = round((0*original[i][j].rgbtBlue + 0*original[i][j - 1].rgbtBlue + 0*original[i][j + 1].rgbtBlue +
                                      1*original[i + 1][j - 1].rgbtBlue + 2*original[i + 1][j].rgbtBlue + 1*original[i + 1][j + 1].rgbtBlue));
                }

                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                //edge on edge on left or right
                if (i > 0 && (j == 0 || j == width - 1))
                {
                    //edge on left
                    if (j == 0)
                    {
                         gx_red = round((0*original[i - 1][j].rgbtRed + 1*original[i - 1][j + 1].rgbtRed + 0*original[i][j].rgbtRed +
                                            2*  original[i][j + 1].rgbtRed + -0*original[i + 1][j].rgbtRed + 1*original[i + 1][j + 1].rgbtRed) );

                         gx_green = round((0*original[i - 1][j].rgbtGreen + 1*original[i - 1][j + 1].rgbtGreen + 0*original[i][j].rgbtGreen +
                                             2*   original[i][j + 1].rgbtGreen + -0*original[i + 1][j].rgbtGreen + 1*original[i + 1][j + 1].rgbtGreen) );

                         gx_blue = round((0*original[i - 1][j].rgbtBlue +1* original[i - 1][j + 1].rgbtBlue + 0*original[i][j].rgbtBlue +
                                             2*  original[i][j + 1].rgbtBlue + -0*original[i + 1][j].rgbtBlue +1* original[i + 1][j + 1].rgbtBlue));
                         //------------------------------------------------------------------------------------------------------------------------------
                         gy_red = round((-2*original[i - 1][j].rgbtRed + -1*original[i - 1][j + 1].rgbtRed + 0*original[i][j].rgbtRed +
                                        0* original[i][j + 1].rgbtRed + 2*original[i + 1][j].rgbtRed + 1*original[i + 1][j + 1].rgbtRed));

                         gy_green = round((-2*original[i - 1][j].rgbtGreen + -1*original[i - 1][j + 1].rgbtGreen +0* original[i][j].rgbtGreen +
                                          0* original[i][j + 1].rgbtGreen + 2*original[i + 1][j].rgbtGreen + 1*original[i + 1][j + 1].rgbtGreen));

                         gy_blue = round((-2*original[i - 1][j].rgbtBlue + -1*original[i - 1][j + 1].rgbtBlue + 0*original[i][j].rgbtBlue +
                                         0* original[i][j + 1].rgbtBlue + 2*original[i + 1][j].rgbtBlue + 1*original[i + 1][j + 1].rgbtBlue));
                    }
                    /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                    //----------------------------
                    /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                    //edge on right
                    if (j == width - 1)
                    {
                        gx_red = round((0*original[i - 1][j].rgbtRed + -1*original[i - 1][j - 1].rgbtRed +0* original[i][j].rgbtRed +
                                        -2*original[i][j - 1].rgbtRed + 0*original[i + 1][j].rgbtRed + -1*original[i + 1][j - 1].rgbtRed) );

                        gx_green = round((0*original[i - 1][j].rgbtGreen +-1* original[i - 1][j - 1].rgbtGreen + 0*original[i][j].rgbtGreen +
                                           -2*original[i][j - 1].rgbtGreen + 0*original[i + 1][j].rgbtGreen + -1*original[i + 1][j - 1].rgbtGreen) );

                        gx_blue = round((0*original[i - 1][j].rgbtBlue + -1*original[i - 1][j - 1].rgbtBlue +0* original[i][j].rgbtBlue +
                                         -2*original[i][j - 1].rgbtBlue + 0*original[i + 1][j].rgbtBlue +-1* original[i + 1][j - 1].rgbtBlue) );
                        //------------------------------------------------------------------------------------------------------------------------------
                        gy_red = round((-2*original[i - 1][j].rgbtRed + -1*original[i - 1][j - 1].rgbtRed + 0*original[i][j].rgbtRed +
                                       0* original[i][j - 1].rgbtRed + 2*original[i + 1][j].rgbtRed + 1*original[i + 1][j - 1].rgbtRed));

                        gy_green = round((-2*original[i - 1][j].rgbtGreen +-1* original[i - 1][j - 1].rgbtGreen + 0*original[i][j].rgbtGreen +
                                          0* original[i][j - 1].rgbtGreen +2* original[i + 1][j].rgbtGreen + 1*original[i + 1][j - 1].rgbtGreen));

                        gy_blue = round((-2*original[i - 1][j].rgbtBlue + -1*original[i - 1][j - 1].rgbtBlue +0* original[i][j].rgbtBlue +
                                        0* original[i][j - 1].rgbtBlue + 2*original[i + 1][j].rgbtBlue +1* original[i + 1][j - 1].rgbtBlue));
                    }
                }

                /*
                -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
                */
                //----------------------------
                /*
                -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
                */
                //edge on on buttom
                if (i == height - 1 && (j > 0 || j == width - 2))
                {

                    gx_red = round((-1*original[i - 1][j - 1].rgbtRed +0* original[i - 1][j].rgbtRed + 1*original[i - 1][j + 1].rgbtRed +
                                    -2*original[i][j - 1].rgbtRed + 0*original[i][j].rgbtRed + 2*original[i][j + 1].rgbtRed) );

                    gx_green = round((-1*original[i - 1][j - 1].rgbtGreen +0* original[i - 1][j].rgbtGreen +1* original[i - 1][j + 1].rgbtGreen +
                                      -2*original[i][j - 1].rgbtGreen +0* original[i][j].rgbtGreen + 2*original[i][j + 1].rgbtGreen) );

                    gx_blue = round((-1*original[i - 1][j - 1].rgbtBlue + 0*original[i - 1][j].rgbtBlue + 1*original[i - 1][j + 1].rgbtBlue +
                                     -2*original[i][j - 1].rgbtBlue +0* original[i][j].rgbtBlue + 2*original[i][j + 1].rgbtBlue));
                    //------------------------------------------------------------------------------------------------------------------------------

                    gy_red = round((-1*original[i - 1][j - 1].rgbtRed + -2*original[i - 1][j].rgbtRed + -1*original[i - 1][j + 1].rgbtRed +
                                    0*original[i][j - 1].rgbtRed + 0*original[i][j].rgbtRed + 0*original[i][j + 1].rgbtRed));

                    gy_green = round((-1*original[i - 1][j - 1].rgbtGreen +-2* original[i - 1][j].rgbtGreen +-1* original[i - 1][j + 1].rgbtGreen +
                                      0*original[i][j - 1].rgbtGreen + 0*original[i][j].rgbtGreen + 0*original[i][j + 1].rgbtGreen));

                    gy_blue = round((-1*original[i - 1][j - 1].rgbtBlue + -2*original[i - 1][j].rgbtBlue +-1* original[i - 1][j + 1].rgbtBlue +
                                     0*original[i][j - 1].rgbtBlue + 0*original[i][j].rgbtBlue + 0*original[i][j + 1].rgbtBlue));
                }
                int round_gx_red = round(gx_red);
                int round_gx_green = round(gx_green);
                int round_gx_blue = round(gx_blue);

                int round_gy_red = round(gy_red);
                int round_gy_green = round(gy_green);
                int round_gy_blue = round(gy_blue);

                int g_red = round(sqrt((round_gx_red * round_gx_red) + (round_gy_red * round_gy_red)));
                int g_green = round(sqrt((round_gx_green * round_gx_green) + (round_gy_green * round_gy_green)));
                int g_blue = round(sqrt((round_gx_blue * round_gx_blue) + (round_gy_blue * round_gy_blue)));
                if (g_red > 255)
                {
                    g_red = 255;
                }
                if (g_green > 255)
                {
                    g_green = 255;
                }
                if (g_blue > 255)
                {
                    g_blue = 255;
                }
                image[i][j].rgbtRed = g_red;
                image[i][j].rgbtGreen = g_green;
                image[i][j].rgbtBlue = g_blue;
            }
            //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            // filters middle pixel
            /*
            -------GX
                    # -1  #  0  #  1  #
                    # -2  #  0  #  2  #
                    # -1  #  0  #  1  #
            */
                //----------------------------
                /*
            -------Gy
                    # -1  # -2  # -1  #
                    #  0  #  0  #  0  #
                    #  1  #  2  #  1  #
            */

                else if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
                {
                    float gx_red = 0;
                    float gx_green = 0;
                    float gx_blue = 0;

                    float gy_red = 0;
                    float gy_green = 0;
                    float gy_blue = 0;

                    int pixel_ith = i - 1;

                    int gx[3][3] =
                        {
                            {-1, 0, 1},
                            {-2, 0, 2},
                            {-1, 0, 1}};
                    int gy[3][3] =
                        {
                            {-1, -2, -1},
                            {0, 0, 0},
                            {1, 2, 1}};

                    for (int bi = 0; bi < 3; bi++)
                    {
                        int pixel_jth = j - 1;
                        for (int bj = 0; bj < 3; bj++)
                        {
                            //calculating the gx >>>>>>>
                            gx_red   = gx_red   + gx[bi][bj] * (original[pixel_ith][pixel_jth].rgbtRed);
                            gx_green = gx_green + gx[bi][bj] * (original[pixel_ith][pixel_jth].rgbtGreen);
                            gx_blue  = gx_blue  + gx[bi][bj] * (original[pixel_ith][pixel_jth].rgbtBlue);

                            gy_red   = gy_red   + gy[bi][bj] * (original[pixel_ith][pixel_jth].rgbtRed);
                            gy_green = gy_green + gy[bi][bj] * (original[pixel_ith][pixel_jth].rgbtGreen);
                            gy_blue  = gy_blue  + gy[bi][bj] * (original[pixel_ith][pixel_jth].rgbtBlue);
                            pixel_jth++;
                        }
                        pixel_ith++;
                    }

   

                    float new_red = round((gx_red * gx_red) + (gy_red * gy_red));
                    int round_new_red = round(sqrt(new_red));
                    if (round_new_red > 255)
                    {
                        round_new_red = 255;
                    }

                    float new_green = round((gx_green * gx_green) + (gy_green * gy_green));
                    int round_new_green = round(sqrt(new_green));
                    if (round_new_green > 255)
                    {
                        round_new_green = 255;
                    }

                    float new_blue = round((gx_blue * gx_blue) + (gy_blue * gy_blue));
                    int round_new__blue = round(sqrt(new_blue));
                    if (round_new__blue > 255)
                    {
                        round_new__blue = 255;
                    }

                    image[i][j].rgbtRed = round_new_red;
                    image[i][j].rgbtGreen = round_new_green;
                    image[i][j].rgbtBlue = round_new__blue;
            }
        }
    }

    return;
}

/*
//compile command

clang -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o filter filter.c helpers.c


*/

/*

> check50 cs50/problems/2020/x/filter/more
Connecting.........
Authenticating.....
Verifying..........
Preparing.....
Uploading..............
Waiting for results..................................................................
Results for cs50/problems/2020/x/filter/more generated by check50 v3.1.2
:) helpers.c exists
:) filter compiles
:) grayscale correctly filters single pixel with whole number average
:) grayscale correctly filters single pixel without whole number average
:) grayscale leaves alone pixels that are already gray
:) grayscale correctly filters simple 3x3 image
:) grayscale correctly filters more complex 3x3 image
:) grayscale correctly filters 4x4 image
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
:) edges correctly filters middle pixel
:) edges correctly filters pixel on edge
:) edges correctly filters pixel in corner
:) edges correctly filters 3x3 image
:) edges correctly filters 4x4 image
To see the results in your browser go to https://submit.cs50.io/check50/5e00947b4ceaf9b13c6168959e50879cbe6241ce


*/