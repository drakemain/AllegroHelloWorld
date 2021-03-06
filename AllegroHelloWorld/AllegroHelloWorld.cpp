// AllegroHelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

struct Coords {
	int x;
	int y;
	int z;
};

struct Resolution {
	int x;
	int y;
};

int main()
{
	std::cout << "Init." << std::endl;
	Resolution res;
	res.x = 640;
	res.y = 480;

	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY* display = al_create_display(res.x, res.y);
	ALLEGRO_FONT* font = al_load_ttf_font("Raleway-Regular.ttf", 64, 0);
	ALLEGRO_EVENT_QUEUE* events = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0);

	if (timer) {
		std::cout << "Timer created" << std::endl;
	}

	al_register_event_source(events, al_get_keyboard_event_source());
	al_register_event_source(events, al_get_display_event_source(display));
	al_register_event_source(events, al_get_timer_event_source(timer));

	Coords textLocation;
	textLocation.x = rand() % res.x;
	textLocation.y = rand() % res.y;
	textLocation.z = 0;

	bool isRunning = true;

	al_start_timer(timer);

	std::cout << "Begin." << std::endl;
	while (isRunning) {
		ALLEGRO_EVENT event;
		bool wasEvent = al_get_next_event(events, &event);

		if (wasEvent) {
			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				std::cout << "End." << std::endl;
				isRunning = false;
			}

			if (event.type == ALLEGRO_EVENT_TIMER) {
				std::cout << "Timer event." << std::endl;

				textLocation.x = rand() % res.x;
				textLocation.y = rand() % res.y;
				textLocation.z = 0;

			}
		}
		

		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_text(font, al_map_rgb(0, 125, 255), textLocation.x, textLocation.y, textLocation.z, "Hello World!");

		al_flip_display();
	}

	al_destroy_display(display);
	al_uninstall_keyboard();
	al_destroy_font(font);
	al_destroy_event_queue(events);

    return 0;
}

