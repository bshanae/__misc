#include "engine.h"

static UCHAR		*helper_BMP(
					int *width,
					int *height,
					const char *path,
					short *bits_per_pixel)
{
	UCHAR			header[54];
	UCHAR			*data;
	UINT			data_size;
	FILE			*file;

	if (!ft_str_suffix(path, ".bmp"))
		ft_raise_error(NULL, "Bad texture extension");
	file = fopen(path,"rb");
	if (!file)
		ft_raise_error(NULL, "Bad texture file");
	if (fread(header, 1, 54, file) != 54)
		ft_raise_error(NULL, "Bad BMP file");
	if (header[0] != 'B' || header[1] != 'M')
		ft_raise_error(NULL, "Bad BMP file");

	data_size = *(int *)&(header[0x22]);
	*bits_per_pixel = *(short *)&(header[0x001c]);

	*width = *(int *)&(header[0x12]);
	*height = *(int *)&(header[0x16]);

	if (!data_size)
		data_size = *width * *height * 3;
	data = ft_malloc(NULL, data_size);
	fread(data, 1, data_size, file);
	fclose(file);
	return (data);
}

t_texture 			texture_create(const char *path)
{
	t_texture		texture;
	short 			bits_per_pixel;
	int 			width;
	int 			height;
	UCHAR			*data;

	glGenTextures(1, &texture);
	texture_bind(&texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	data = helper_BMP(&width, &height, path, &bits_per_pixel);
	if (bits_per_pixel == 24)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	else if (bits_per_pixel == 32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
	else
		ft_raise_error(NULL, "Can't parse BMP file");
	glGenerateMipmap(GL_TEXTURE_2D);
	free(data);
	texture_bind(NULL);

	return (texture);
}

void				texture_destroy(t_texture *texture)
{
	glDeleteTextures(1, texture);
}
void 				texture_bind(t_texture *texture)
{
	glBindTexture(GL_TEXTURE_2D, texture ? *texture : 0);
}