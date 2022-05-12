#ifndef IMG_PROCESS_H
#define IMG_PROCESS_H

int bmp_read(char *filename, char **data, char **palette, char **header);
int bmp_write(char *filename, char *data, char *palette, char *header);
int bmp_rotage(int angle, char **data, char **palette, char**header);
int bmp_to_gary(char **data, char **palette, char**header);
int bmp_position(char *position_data, char *data, int *x, int *y);

#endif //IMG_PROCESS_H
