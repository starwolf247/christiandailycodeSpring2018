#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <iostream>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
//const int BOUNCER2_SIZE = 32;

enum MYKEYS {
	KEY_LEFT, KEY_RIGHT
};
//enum MYKEYS2 {
//	KEY_W, KEY_S, KEY_A, KEY_D
//};

bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);


//matt wuz here

class brick {
private:
	int xPos;
	int yPos;
	bool isdead;

public:
	void initbrick(int x, int y);
	void drawbrick();
	bool brickcollision(int ballx, int bally, int ballw, int ballh);
	void kill();
	bool dead();
};
int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer3 = NULL;


	//location of the paddle
	float bouncer_x = 350;
	float bouncer_y = 400;
	/*float bouncer2_x = 50;
	float bouncer2_y = SCREEN_H / 2.0 - BOUNCER2_SIZE / 2.0;*/
	float bouncer3_x = 200;
	float bouncer3_y = 200;
	float bouncer3_dx = -4.0, bouncer3_dy = 4.0;
	bool key[4] = { false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_audio(); //audio for the game
	al_install_keyboard();
	al_init_primitives_addon();
	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	//scale of paddl
	bouncer = al_create_bitmap(BOUNCER_SIZE + 100, BOUNCER_SIZE + 5);

	/*bouncer2 = al_create_bitmap(BOUNCER2_SIZE, BOUNCER2_SIZE + 100);*/

	bouncer3 = al_create_bitmap(32, 32); // the ball shape

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	//al_set_target_bitmap(bouncer2);*/

	/*al_clear_to_color(al_map_rgb(100, 0, 35));*/
	al_set_target_bitmap(bouncer3);

	al_clear_to_color(al_map_rgb(255, 0, 255)); //this sets the BOUNCER's color!
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue(); //events of the game

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	brick b1;
	b1.initbrick(10, 10); //possision
	brick b2;
	b2.initbrick(200, 10);
	brick b3;
	b3.initbrick(350, 10);
	brick b4;
	b4.initbrick(350, 10);
	brick b5;
	b5.initbrick(500, 10);
	brick b6;
	b6.initbrick(10, 90);
	brick b7;
	b7.initbrick(200, 90);
	brick b8;
	b8.initbrick(350, 90);
	brick b9;
	b9.initbrick(350, 90);
	brick b10;
	b10.initbrick(500, 90);
	brick b11;
	b11.initbrick(10, 170);
	brick b12;
	b12.initbrick(200, 170);
	brick b13;
	b13.initbrick(350, 170);
	brick b14;
	b14.initbrick(350, 170);
	brick b15;
	b15.initbrick(500, 170);


		al_start_timer(timer);
	/*al_reserve_samples(1);*/



	//sample = al_load_sample("ness.wav");

	//sample2 = al_load_sample("cloud.wav");
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			/*if (key[KEY_UP] && bouncer_y >= 4.0) {
				bouncer_y -= 10.0;


			if (key[KEY_DOWN] && bouncer_y <= SCREEN_H - 132 - 4.0) {
				bouncer_y += 10.0;
			}*/

			if (key[KEY_LEFT] && bouncer_x >= 4.0) { //direction
				bouncer_x -= 4.0; //speed
			}

			if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - 132 - 4.0) {
				bouncer_x += 4.0;
			}
			/*if (key2[KEY_W] && bouncer2_y >= 4.0) {
				bouncer2_y -= 4.0;
			}

			if (key2[KEY_S] && bouncer2_y <= SCREEN_H - 132 - 4.0) {
				bouncer2_y += 4.0;
			}*/

			/*if (key2[KEY_A] && bouncer2_x >= 4.0) {
				bouncer2_x -= 4.0;
			}

			if (key2[KEY_D] && bouncer2_x <= SCREEN_W - BOUNCER2_SIZE - 4.0) {
				bouncer2_x += 4.0;
			}*/
			if (bouncer3_x < 0 || bouncer3_x > 640 - 32) {
				bouncer3_dx = -bouncer3_dx;
			}
			if (bouncer3_y < 0 || bouncer3_y > 480 - 32) {
				bouncer3_dy = -bouncer3_dy;
			}
			bouncer3_x += bouncer3_dx;
			bouncer3_y += bouncer3_dy;

			if (collision(bouncer3_x, bouncer3_y, 32, 32, bouncer_x, bouncer_y, 32, 132) == true) {
				bouncer3_dx = -bouncer3_dx;
				bouncer3_dy = -bouncer3_dy;
				/*al_play_sample(sample, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);*/
			}

			/*	al_play_sample(sample2, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);*/

			redraw = true;

		}
		if (b1.dead() == false && b1.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) { //brick break
			bouncer3_dy = -bouncer3_dy;
			b1.kill();
		}
		if (b2.dead() == false && b2.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b2.kill();
		}
		if (b3.dead() == false && b3.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b3.kill();
		}
		if (b4.dead() == false && b4.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b4.kill();
		}
		if (b5.dead() == false && b5.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b5.kill();
		}
		if (b6.dead() == false && b6.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b6.kill();
		}
		if (b7.dead() == false && b7.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b7.kill();
		}
		if (b8.dead() == false && b8.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b8.kill();
		}
		if (b9.dead() == false && b9.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b9.kill();
		}
		if (b10.dead() == false && b10.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b10.kill();
		}
		if (b11.dead() == false && b11.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b11.kill();
		}
		if (b12.dead() == false && b12.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b12.kill();
		}
		if (b13.dead() == false && b13.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b13.kill();
		}
		if (b14.dead() == false && b14.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b14.kill();
		}
		if (b15.dead() == false && b15.brickcollision(bouncer3_x, bouncer3_y, 32, 32) == true) {
			bouncer3_dy = -bouncer3_dy;
			b15.kill();
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
				/*case ALLEGRO_KEY_UP:
					key[KEY_UP] = true;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_DOWN] = true;
					break;*/

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

				////case ALLEGRO_KEY_W:
				//	key2[KEY_W] = true;
				//	break;

				//case ALLEGRO_KEY_S:
				//	key2[KEY_S] = true;
				//	break;

				//case ALLEGRO_KEY_A:
				//	key2[KEY_A] = true;
				//	break;

				//case ALLEGRO_KEY_D:
				//	key2[KEY_D] = true;
				//	break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
				/*case ALLEGRO_KEY_UP:
					key[KEY_UP] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_DOWN] = false;
					break;*/

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

				/*case ALLEGRO_KEY_W:
					key2[KEY_W] = false;
					break;

				case ALLEGRO_KEY_S:
					key2[KEY_S] = false;
					break;

				case ALLEGRO_KEY_A:
					key2[KEY_A] = false;
					break;

				case ALLEGRO_KEY_D:
					key2[KEY_D] = false;
					break;

				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;*/
			}

		}
			if (redraw && al_is_event_queue_empty(event_queue)) {
				redraw = false;

				al_clear_to_color(al_map_rgb(0, 0, 0));
				if (b1.dead() == false)
				b1.drawbrick();
				if (b2.dead() == false)
				b2.drawbrick();
				if (b3.dead() == false)
				b3.drawbrick();
				if (b4.dead() == false)
				b4.drawbrick();
				if (b5.dead() == false)
				b5.drawbrick();
				if (b6.dead() == false) //brick break
				b6.drawbrick();
				if (b7.dead() == false)
				b7.drawbrick();
				if (b8.dead() == false)
				b8.drawbrick();
				if (b9.dead() == false)
				b9.drawbrick();
				if (b10.dead() == false)
				b10.drawbrick();
				if (b11.dead() == false)
				b11.drawbrick();
				if (b12.dead() == false)
				b12.drawbrick();
				if (b13.dead() == false)
				b13.drawbrick();
				if (b14.dead() == false)
				b14.drawbrick();
				if (b15.dead() == false)
				b15.drawbrick();
				al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);


				/*al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);*/

				al_draw_bitmap(bouncer3, bouncer3_x, bouncer3_y, 0);

				al_flip_display();
			}
			//end main
		}
		al_destroy_bitmap(bouncer);
		/*al_destroy_bitmap(bouncer2);*/
		al_destroy_bitmap(bouncer3);
		al_destroy_timer(timer);
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);

		return 0;
	}
	

	bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) { //paddle
		if ((x1 + w1 > x2) && (x1 < x2 + w2) && (y1 + h1 > y2) && (y1 < h2 + y2))
			return true;
		else
			return false;
	}
	void brick::initbrick(int x, int y) { //position of the bricks
		xPos = x;
		yPos = y;
		isdead = false;
	}

	void brick::drawbrick() { // make the brick
		al_draw_filled_rectangle(xPos, yPos, xPos + 100, yPos + 50, al_map_rgb(165, 42, 42));
	}

	bool brick::brickcollision(int ballx, int bally, int ballw, int ballh) { // bricks
		if ((xPos + 100 > ballx) && (xPos < ballx + ballw) && (yPos + 32 > bally) && (yPos < ballh + bally))
			return true;
		else
			return false;
	}

	void brick::kill() {
		isdead = true;

	}

	bool brick::dead() {
		return isdead;
	
	}
