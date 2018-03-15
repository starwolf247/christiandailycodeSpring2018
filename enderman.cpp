#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
	ALLEGRO_DISPLAY *Win = NULL;

	al_init();
	al_init_primitives_addon();

	Win = al_create_display(600, 600);

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_draw_filled_rectangle(250,250, 450, 450, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(250, 350, 300,400, al_map_rgb(128, 0, 128));
	al_draw_filled_rectangle(400, 350, 450, 400,  al_map_rgb(139, 0, 139));
	al_draw_filled_rectangle(300, 600, 400, 300, al_map_rgb(0, 0, 0));
	

	al_flip_display();

	al_rest(20);

	al_destroy_display(Win);
}