#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = al_create_display(500, 500);

	al_clear_to_color(al_map_rgb(255, 255, 255));
	while (1) {
		//al_draw_rectangle(10, 10, 40, 40, al_map_rgb(40, 30, 30), 2);

		al_draw_filled_circle(rand() % 490, rand() % 490, rand() % 490, al_map_rgb(rand() , rand() , rand() ));

		al_draw_triangle(rand() % 490, rand() % 490, rand() % 490, rand() % 490, rand() % 490, rand() % 490, al_map_rgb(rand() , rand() , rand()), rand()%50);

		al_flip_display();

		al_rest(.01);
	}

	al_destroy_display(display);

}