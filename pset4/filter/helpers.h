#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>
#include "bmp.h"

//-----------------------------------------------------------------------------------------

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);



//-----------------------------------------------------------------------------------------




/*
sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
*/

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);




//-----------------------------------------------------------------------------------------


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);





//-----------------------------------------------------------------------------------------
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);
