#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	ALLEGRO_DISPLAY *Win = NULL;

	al_init();
	al_init_primitives_addon();

	Win = al_create_display(600, 600);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	//al_draw_filled_rectangle(300, 200, 350, 20, al_map_rgb(60, 595, 500));

	al_draw_filled_rectangle(500, 550, 400, 600, al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(200, 400, 400, 600, al_map_rgb(255, 0, 0));
	al_draw_filled_triangle(300, 250, 200, 400, 400, 400, al_map_rgb(0, 0, 0));

	al_draw_filled_circle(500, 100, 75, al_map_rgb(255, 255, 0));

	al_draw_filled_circle(100, 100, 75, al_map_rgb(128, 128, 128));
	al_draw_filled_circle(150, 100, 75, al_map_rgb(128, 128, 128));
	al_draw_filled_circle(200, 100, 75, al_map_rgb(128, 128, 128));

	al_flip_display();

	al_rest(20);

	al_destroy_display(Win);
}