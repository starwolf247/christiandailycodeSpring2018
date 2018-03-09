#include <iostream>
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
using namespace std;

class frenchfries
{
private:
	int xPos;
	int yPos;

public:
	void initfood(int x, int y);
	void drawfood(ALLEGRO_BITMAP*potato);
};
int main() {
	ALLEGRO_DISPLAY *display = NULL;

	al_init();
	al_init_image_addon();
	display = al_create_display(1000, 1000);
	ALLEGRO_BITMAP *potato = al_load_bitmap("potato.png");

	frenchfries i1;
	//loads bitmaps from folder
	i1.initfood(100, 120);
	while (1) {
		i1.drawfood(potato);
		al_flip_display();

	}
	al_destroy_display(display);
}

void frenchfries::initfood(int x, int y) {
	xPos = x;
	yPos = y;
}
void frenchfries::drawfood(ALLEGRO_BITMAP *potato) {
	al_draw_bitmap(potato, rand()%1000, rand()%1000, 0);
}
