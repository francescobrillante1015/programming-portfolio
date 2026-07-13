#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)  // Loop over each row
    {
        for (int j = 0; j < width; j++)  // Loop over each column
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calculate the average of the red, green, and blue values and round it
            int avg = round((red + green + blue) / 3.0);  // Use 3.0 to ensure floating point division

            // Set all RGB values to the average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)  // Loop over each row
    {
        for (int j = 0; j < width; j++)  // Loop over each column
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Apply the sepia filter formula
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            // Clamp the values to be in the range 0-255
            image[i][j].rgbtRed = fmin(255, fmax(0, sepiaRed));
            image[i][j].rgbtGreen = fmin(255, fmax(0, sepiaGreen));
            image[i][j].rgbtBlue = fmin(255, fmax(0, sepiaBlue));
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)  // Loop over each row
    {
        for (int j = 0; j < width / 2; j++)  // Only go up to the middle of the row
        {
            // Swap the pixels horizontally
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store blurred results
    RGBTRIPLE temp[height][width];

    // Loop through all pixels in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            // Iterate through the neighboring pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighboring pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += image[ni][nj].rgbtRed;
                        greenSum += image[ni][nj].rgbtGreen;
                        blueSum += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color for the current pixel and round it
            temp[i][j].rgbtRed = round(redSum / (float) count);
            temp[i][j].rgbtGreen = round(greenSum / (float) count);
            temp[i][j].rgbtBlue = round(blueSum / (float) count);
        }
    }

    // Copy the blurred result back into the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
