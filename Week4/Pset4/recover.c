#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    BYTE Block[512];

    if (argc < 2)
    {
        printf("Usage: recover image\n");
        return 1;
    }
    char *infile = argv[1];
    FILE *file = fopen(infile, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }
    char filename[8];
    int filenumber = 0;
    FILE *outfile = NULL;
    do
    {
        if ((Block[0] == 0xff) && (Block[1] == 0xd8) && (Block[2] == 0xff) && (Block[3] % 224 == 0))
        {
            if(outfile != NULL)
            {
                fclose(outfile);
            }
            sprintf(filename, "%03d%s", filenumber,".jpg");
            filenumber++;
            outfile = fopen(filename, "w");
            fwrite(Block, sizeof(BYTE), 512, outfile);
        }
        else if (outfile != NULL)
        {
            fwrite(Block, sizeof(BYTE), 512, outfile);
        }

    }
    while (fread(Block, sizeof(BYTE), 512, file));

    fclose(file);
    return 0;

}
