// AllegroHelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
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
	Resolution res;
	res.x = 640;
	res.y = 480;

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY* display = al_create_display(res.x, res.y);
	ALLEGRO_FONT* font = al_load_ttf_font("Raleway-Regular.ttf", 64, 0);

	Coords textLocation;

	while (true) {
		textLocation.x = rand() % res.x;
		textLocation.y = rand() % res.y;
		textLocation.z = 0;

		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_text(font, al_map_rgb(0, 125, 255), textLocation.x, textLocation.y, textLocation.z, "Hello World!");

		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_font(font);

    return 0;
}

