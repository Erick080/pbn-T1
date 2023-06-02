#include <stdio.h>
#include "lib_ppm.h"

void calculate_color(struct image_s *image,unsigned int red, unsigned int green, unsigned int blue,int y,int x);

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s new_image;
	struct image_s *zoomed = &new_image;
	int i, j, r,c;

	r = read_ppm("lena.ppm", image);
	

	if (r == 0)
	{
		//triplicando a resolucao da imagem
		
		zoomed -> height = image -> height * 3;
		zoomed -> width = image -> width * 3;

		c = new_ppm(zoomed, zoomed -> height, zoomed -> width);

		unsigned int pixred,pixgreen,pixblue = 0; //vao armazenar o r,g,b de cada pixel a ser analizado
		int heightzoom,widthzoom = 0; //vao armazenar as posicoes onde devem ser inseridas cores na imagem nova
		for (j = 0; j < image->height; j++)
		{
			
			for (i = 0; i < image->width; i++)
			{
				pixred = image -> pix[j * image -> width + i].r;
				pixgreen = image -> pix[j * image -> width + i].g;
				pixblue = image -> pix[j * image -> width + i].b;

				calculate_color(zoomed,pixred,pixgreen,pixblue,heightzoom,widthzoom);
				widthzoom +=3;
			}
			widthzoom = 0;
			heightzoom += 3;
		}


		write_ppm("lena_copy.ppm", zoomed);
				

		free_ppm(zoomed);
	}

	
}

void calculate_color(struct image_s *image,unsigned int red,unsigned int green,unsigned int blue,int y,int x){
	//calcula red
	if (red < 75){
		image -> pix[y * image -> width + x].r = 0;
		image -> pix[(y+1) * image -> width + x].r = 0;
		image -> pix[(y+2) * image -> width + x].r = 0;
	} else if(red < 135){
		image -> pix[y * image -> width + x].r = 0;
		image -> pix[(y+1) * image -> width + x].r = 255;
		image -> pix[(y+2) * image -> width + x].r = 0;

	}else if(red < 180){
		image -> pix[y * image -> width + x].r = 255;
		image -> pix[(y+1) * image -> width + x].r = 0;
		image -> pix[(y+2) * image -> width + x].r = 255;
	}else if(red < 256){
		image -> pix[y * image -> width + x].r = 255;
		image -> pix[(y+1) * image -> width + x].r = 255;
		image -> pix[(y+2) * image -> width + x].r = 255;
	}

	//calcula green
	if(green < 75){
		image -> pix[y * image -> width + x].g = 0;
		image -> pix[(y+1) * image -> width + x].g = 0;
		image -> pix[(y+2) * image -> width + x].g = 0;
	} else if(green < 135){
		image -> pix[y * image -> width + x].g = 0;
		image -> pix[(y+1) * image -> width + x].g = 255;
		image -> pix[(y+2) * image -> width + x].g = 0;
	} else if(green < 180){
		image -> pix[y * image -> width + x].g = 255;
		image -> pix[(y+1) * image -> width + x].g = 0;
		image -> pix[(y+2) * image -> width + x].g = 255;
	} else if(red < 256){
		image -> pix[y * image -> width + x].g = 255;
		image -> pix[(y+1) * image -> width + x].g = 255;
		image -> pix[(y+2) * image -> width + x].g = 255;
	}

	//calcula blue
	if(blue < 75){
		image -> pix[y * image -> width + x].b = 0;
		image -> pix[(y+1) * image -> width + x].b = 0;
		image -> pix [(y+2) * image -> width + x].b = 0;
	} else if (blue < 135){
		image -> pix[y * image -> width + x].b = 0;
		image -> pix[(y+1) * image -> width + x].b = 255;
		image -> pix [(y+2) * image -> width + x].b = 0;
	} else if(blue < 180){
		image -> pix[y * image -> width + x].b = 255;
		image -> pix[(y+1) * image -> width + x].b = 0;
		image -> pix [(y+2) * image -> width + x].b = 255;
	} else if(blue < 256){
		image -> pix[y * image -> width + x].b = 255;
		image -> pix[(y+1) * image -> width + x].b = 255;
		image -> pix [(y+2) * image -> width + x].b = 255;
	}
}
