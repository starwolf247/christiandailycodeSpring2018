
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<iostream>

using namespace std;

int main() {
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_BITMAP*diamond = NULL;
	ALLEGRO_BITMAP*ruby = NULL;
	ALLEGRO_BITMAP*pink = NULL;
	ALLEGRO_BITMAP*green = NULL;
	int level[10][10] = {
		4,1,1,1,1,1,1,1,1,2,
		4,2,2,2,4,4,3,0,3,2,
		4,3,2,3,1,1,3,4,3,2,
		4,3,2,3,4,4,3,3,3,2,
		4,3,2,3,1,1,3,1,3,2,
		4,2,2,2,1,1,3,4,3,2,
		4,2,3,4,4,3,2,1,3,2,
		4,3,1,2,1,4,2,4,1,2,
		4,2,3,4,1,2,3,4,1,2,
		4,3,3,3,3,3,3,3,3,2,
		};
		al_init();
		al_init_image_addon();

		display = al_create_display(400, 400);


		diamond = al_load_bitmap("Diamond.png");
		ruby = al_load_bitmap("ruby.jpg");
		pink = al_load_bitmap("pink crystal.jpg");
		green = al_load_bitmap("green cristal.jpg");



			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{

					if (level[x][y] == 1)
						al_draw_bitmap(diamond, y * 40, x * 40, NULL);
					if (level[x][y] == 2)
						al_draw_bitmap(ruby, y * 40, x * 40, NULL);
					if (level[x][y] == 3)
						al_draw_bitmap(pink, y * 40, x * 40, NULL);
					if (level[x][y] == 4)
						al_draw_bitmap(green, y * 40, x * 40, NULL);

					al_flip_display();

					al_rest(.1);
				}
			}
		al_destroy_bitmap(diamond);
		al_destroy_bitmap(ruby);
		al_destroy_bitmap(pink);
		al_destroy_bitmap(green);
		al_destroy_display(display);
	}
