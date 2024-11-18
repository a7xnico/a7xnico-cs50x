#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
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
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];                   // creates a copy of the image
    int gx_array[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1}; // the gx and gy values for the edges
    int gy_array[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) // nested for loops to treat every pixel
        {
            int gx_red = 0, gx_green = 0, gx_blue = 0, gy_red = 0, gy_green = 0,
                gy_blue = 0; // final values
            int counter = 0; // counter restars to 0 after every loop
            for (int updated_i = i - 1; updated_i < i + 2; updated_i++) // checks for adjacent pixel
            {
                for (int updated_j = j - 1; updated_j < j + 2; updated_j++)
                {
                    if (!(updated_i < 0 || updated_j < 0 || updated_i >= height ||
                          updated_j >= width)) // handles edge cases in the borders of the image
                    {                          // formula to calculate the gx and gy
                        gx_red += gx_array[counter] * image[updated_i][updated_j].rgbtRed;
                        gx_green += gx_array[counter] * image[updated_i][updated_j].rgbtGreen;
                        gx_blue += gx_array[counter] * image[updated_i][updated_j].rgbtBlue;
                        gy_red += gy_array[counter] * image[updated_i][updated_j].rgbtRed;
                        gy_green += gy_array[counter] * image[updated_i][updated_j].rgbtGreen;
                        gy_blue += gy_array[counter] * image[updated_i][updated_j].rgbtBlue;
                    }
                    counter++;
                }
            } // more formulas, the sqrt of the sum of gx and gy both powered to 2
            int final_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int final_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int final_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            // gives these values to the copy previously made
            copy[i][j].rgbtRed =
                (final_red > 255) ? 255 : final_red; // these are if statements but made shorter
            copy[i][j].rgbtGreen = (final_green > 255) ? 255 : final_green;
            copy[i][j].rgbtBlue = (final_blue > 255) ? 255 : final_blue;
        }
    } // nested for loops to give the values to all the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
