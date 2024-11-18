#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =
                round((image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue) /
                      3.0); // Take average of red, green and blue
                            // Update pixel values
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{ // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // convert all pixels with the formula for sepia
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255) // checks for edge cases
            {
                sepiaRed = 255;
            }
            else if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed; // converts the original image with the filter
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{ // buffer to swap
    RGBTRIPLE buffer;
    for (int i = 0; i < height; i++) // bested for loops to go pixel for pixel
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j]; // swap methodology
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
            // swap each pixel
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // create a copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        { // checks in the for loops
            float sum_red = 0, sum_blue = 0, sum_green = 0, total_pixels = 0;
            for (int updated_i = i - 1; updated_i < i + 2;
                 updated_i++) // looks for every adjacent pixel
            {
                for (int updated_j = j - 1; updated_j < j + 2; updated_j++)
                {
                    if (updated_i >= 0 && updated_j >= 0 && updated_i < height && updated_j < width)
                    { // sums all the color numbers to make the average latter
                        sum_red += image[updated_i][updated_j].rgbtRed;
                        sum_green += image[updated_i][updated_j].rgbtGreen;
                        sum_blue += image[updated_i][updated_j].rgbtBlue;
                        total_pixels++; // counts every pixel that's adjacent for the average
                    }
                }
            } // uses the copy of the image to use the new colors for the blur effect
            copy[i][j].rgbtRed = round(sum_red / total_pixels);
            copy[i][j].rgbtGreen = round(sum_green / total_pixels);
            copy[i][j].rgbtBlue = round(sum_blue / total_pixels);
        }
    } // gets the value from the copy for the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
