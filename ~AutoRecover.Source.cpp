#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<vector>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 800;
const int BOUNCER_SIZE = 0;
const int ELEMENTWIDTH = 100;

class element {
private:
	int xpos;
	int ypos;
	int index;
	bool lifted;
	ALLEGRO_BITMAP *image;

public:
	void initElement(int x, int y, int i, ALLEGRO_BITMAP *picture);
	void drawElement();
	void PrintInfo();
	bool clicked(int x, int y);
	void liftUp();
	bool isLifted();
	void move(int x, int y);
	void PutDown();


};


int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool redraw = true;

	al_init();
	al_init_image_addon();
	al_install_mouse();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	ALLEGRO_BITMAP *airPic = al_load_bitmap("air.jpg");
	ALLEGRO_BITMAP *waterPic = al_load_bitmap("water.png");
	ALLEGRO_BITMAP *firePic = al_load_bitmap("fire.png");
	ALLEGRO_BITMAP *earthPic = al_load_bitmap("earth.png");
	ALLEGRO_BITMAP *plantPic = al_load_bitmap("plant.png");
	element air;
	element water;
	element fire;
	element earth;
	element plant;

	air.initElement(50, 50, 1, airPic);
	water.initElement(300, 100, 2, waterPic);
	fire.initElement(100, 400, 3, firePic);
	earth.initElement(200, 200, 4, earthPic);
	plant.initElement(500, 250, 4, plantPic);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (air.isLifted()) {
				air.move(bouncer_x, bouncer_y);
			}
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;


		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (air.clicked(bouncer_x, bouncer_y))
				if (air.isLifted() == false)
					air.liftUp();
				else
					air.PutDown();
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {

		}


		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);

			air.drawElement();
			water.drawElement();
			fire.drawElement();
			earth.drawElement();
			plant.drawElement();

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void element::initElement(int x, int y, int i, ALLEGRO_BITMAP *picture) {
	xpos = x;
	ypos = y;
	index = i;
	lifted = false;
	image = picture;
}
void element::drawElement() {
	al_draw_bitmap(image, xpos, ypos, 0);
}
void element::PrintInfo() {}

bool element::clicked(int x, int y) {

	//distance formula
	if (sqrt((((xpos + ELEMENTWIDTH / 2) - x)*((xpos + ELEMENTWIDTH / 2) - x)) + (((ypos + ELEMENTWIDTH / 2) - y)*((ypos + ELEMENTWIDTH / 2) - y))) < ELEMENTWIDTH / 2) {
		cout << "element clicked!" << endl;
		return true;

	}
	else
		return false;


}

void element::liftUp() {
	lifted = true;

}

void element::PutDown() {
	lifted = false;

}

bool element::isLifted() {

	return lifted;
}

void element::move(int x, int y) {
	xpos = x - ELEMENTWIDTH / 2;
	ypos = y - ELEMENTWIDTH / 2;


}