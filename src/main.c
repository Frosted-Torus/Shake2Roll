#include <pebble.h>
	
#define NUM_MENU_SECTIONS 1
#define DICE_MENU_ITEMS 6
#define SIDES_MENU_ITEMS 29

static Window *main_window;
static SimpleMenuLayer *menu_layer;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem dice_menu_items[DICE_MENU_ITEMS];
static SimpleMenuItem sides_menu_items[SIDES_MENU_ITEMS];
unsigned char die1;
unsigned char die2;
unsigned char die3;
unsigned char die4;
unsigned char die5;
unsigned char die6;
unsigned char number_die;
unsigned char number_sides;

static void tap_handler(AccelAxisType axis, int32_t direction) {
	
	//Vibrate on shake
	void vibes_long_pulse(void);
	
	//Give the first die a random value
	die1 = (rand() % 6) + 1;
	
	//die 2
	if (number_die > 1) {
		die2 = (rand() % 6) + 1;
		
		//die 3
		if (number_die > 2) {
			die3 = (rand() % 6) + 1;
			
			//die 4
			if (number_die > 3) {
				die4 = (rand() % 6) + 1;
				
				//die 5
				if (number_die > 4) {
					die5 = (rand() % 6) + 1;
					
					// die 6
					if (number_die > 5) {
						die6 = (rand() % 6) + 1;
					}
				}
			}
			
		}
	}
}

static void main_window_load(Window *window) {
	
	//"Subscribe" to "Tap" handler
	accel_tap_service_subscribe(tap_handler);
}

static void main_window_unload(Window *window) {
	
}

static void init() {
	
	//Sets up more random random number
	srand(time(NULL));
}

static void deinit() {
	
}

int main(void) {
	
}