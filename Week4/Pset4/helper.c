#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float value = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            image[i][j].rgbtBlue = round(value);
            image[i][j].rgbtGreen = round(value);
            image[i][j].rgbtRed = round(value);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            int sepiaRed = round((image[i][j].rgbtBlue * 0.189 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtRed * 0.393));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            int sepiaGreen = round((image[i][j].rgbtBlue * 0.168 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtRed * 0.349));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            int sepiaBlue = round((image[i][j].rgbtBlue * 0.131 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtRed * 0.272));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            else if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {

            tmpImage[i][j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tmpImage[i][j].rgbtBlue;

            tmpImage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tmpImage[i][j].rgbtGreen;

            tmpImage[i][j].rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tmpImage[i][j].rgbtRed;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE imgCopy[height][width];
	float avgRed;
	float avgGreen;
	float avgBlue;

	//create a copy of original image to save original pixel values
	for (int row = 0; row < height; row++)
	{
		for (int w = 0; w < width; w++)
		{
			imgCopy[row][w].rgbtRed = image[row][w].rgbtRed;
			imgCopy[row][w].rgbtGreen = image[row][w].rgbtGreen;
			imgCopy[row][w].rgbtBlue = image[row][w].rgbtBlue;


		}
	}

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			//if the pixel is on the top left edge
			if (w == 0 && h == 0)
			{
				avgRed = (float)(imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 4;

				avgGreen = (float)(imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 4;
				avgRed = round(avgRed);
				avgBlue = round(avgBlue);
				avgGreen = round(avgGreen);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on the lower left edge
			else if (w == 0 && h == (height - 1))
			{
				avgRed =(float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 4;

				avgGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 4;
				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                                image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on top Right
			else if (h == 0 && w == (width - 1))
			{
				avgRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed)/ 4;

				avgGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 4;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on lower right
			else if(h == (height - 1) && w == (width - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed) / 4;

		 		avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue) / 4;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen) / 4;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on left side

			else if (w == 0 && (h > 0 && h < height - 1))
			{
				avgRed = (float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
      //if the pixel is on right side
			else if (w == (width - 1) && (h > 0 && h < height - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
                                image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on upper side
			else if (h == 0 && (w > 0 &&  w < width - 1))
			{
				avgRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on lower side
			else if  (h == height - 1 && (w > 0 && w < width - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 6;
				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
      //if the pixel is on the middle and can form a 3x3 grid
			else
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 9;
				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 9;

				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 9;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}

		}
	}
    return;
}
