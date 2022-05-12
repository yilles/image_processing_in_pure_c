#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "img_process.h"

int bmp_read(char *filename, char **data, char **palette, char **header) 
{
  FILE *fp;
  char ID[2];
  int file_size, data_offset, header_size, width, height, data_size, bits_per_pixel;

  fp = fopen(filename, "rb");
  if (fp != NULL)
  {
    *header = (char *)malloc(54 * sizeof(char));
    fread(*header, sizeof(char), 54, fp);
    memcpy(ID, *header, 2 * sizeof(char));
    memcpy(&header_size, *header + 14, sizeof(int));

    //memcpy(&width, *header + 18, sizeof(int));
    //memcpy(&height, *header + 22, sizeof(int));
    //memcpy(&bits_per_pixel, *header + 28, sizeof(int));
    //memcpy(&file_size, *header + 2, sizeof(int));
    //printf("The ID of image is: %s\n", ID);
    //printf("The header size of image is: %d\n", header_size);
    //printf("The size of image is: %d x %d\n", width, height);
    //printf("The bits per pixel of image is: %d\n", bits_per_pixel);
    //printf("The file size of image is: %d\n", file_size);

    if (strstr(ID, "BM") && header_size == 40)
    {
      memcpy(&data_offset, *header + 10, sizeof(int));
      memcpy(&data_size, *header + 34, sizeof(int));
      *palette = (char *)malloc(data_offset - 54);
      *data = (char *)malloc(data_size);

      //printf("The data offset of image is: %d\n", data_offset);
      //printf("The data size of image is: %d\n", data_size);
      
      fread(*palette, sizeof(char), data_offset - 54, fp);
      fread(*data, sizeof(char), data_size, fp);

      fclose(fp);
      return 0;
    }
    else
    {
      fclose(fp);
      return 1;
    }
  }
  else
    return 1;
}

int bmp_write(char *filename, char *data, char *palette, char *header)
{
  FILE *fp;
  char ID[2];
  int file_size, data_offset, header_size, width, height, data_size, bits_per_pixel;

  if (data != NULL && palette != NULL && header != NULL)
  {
    memcpy(ID, header, 2 * sizeof(char));
    memcpy(&header_size, header + 14, sizeof(int));

    //memcpy(&width, header + 18, sizeof(int));
    //memcpy(&height, header + 22, sizeof(int));
    //memcpy(&bits_per_pixel, header + 28, sizeof(int));
    //memcpy(&file_size, header + 2, sizeof(int));
    //printf("The ID of image is: %s\n", ID);
    //printf("The header size of image is: %d\n", header_size);
    //printf("The size of image is: %d x %d\n", width, height);
    //printf("The bits per pixel of image is: %d\n", bits_per_pixel);
    //printf("The file size of image is: %d\n", file_size);
    if (strstr(ID, "BM") && header_size == 40)
    {
      fp = fopen(filename, "wb");
      if (fp != NULL)
      {
        memcpy(&data_offset, header + 10, sizeof(int));
        memcpy(&data_size, header + 34, sizeof(int));
        //printf("The data offset of image is: %d\n", data_offset);
        //printf("The data size of image is: %d\n", data_size);
      
        fwrite(header, sizeof(char), 54, fp);
        fwrite(palette, sizeof(char), data_offset - 54, fp);
        fwrite(data, sizeof(char), data_size, fp);

        fclose(fp);
        return 0;
      }
      else
        return 1;
    }
    else
      return 1;
  }
  else
      return 1;
}

int bmp_rotage(int angle, char **data, char **palette, char**header)
{
  int width, height;
  memcpy(&width, *header + 18, sizeof(int));
  memcpy(&height, *header + 22, sizeof(int));
  printf("%d\n", width);
  printf("%d\n", height);
  memcpy(*header + 18, &height, sizeof(int));
  memcpy(*header + 22, &width, sizeof(int));
  memcpy(&width, *header + 18, sizeof(int));
  memcpy(&height, *header + 22, sizeof(int));
  printf("%d\n", width);
  printf("%d\n", height);
  return 0;
}
