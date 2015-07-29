#include <pebble.h>
  #include "main.h"
  #include "splash.h"

//Windows
static Window *main_window;

//Text Layers
TextLayer *result1;
TextLayer *result2;
TextLayer *result3;
TextLayer *result4;
TextLayer *result5;
TextLayer *result6;

//Fonts
static GFont result_font;

//Bitmaps
static BitmapLayer *splash;
static BitmapLayer *results;
static BitmapLayer *background_layer;
static GBitmap *background_bitmap;

//Variables
uint8_t die1;
uint8_t die2;
uint8_t die3;
uint8_t die4;
uint8_t die5;
uint8_t die6;
uint8_t die_num = 6;
uint8_t side_num = 6;
//static int millis = 1000;
//static char millis_buffer[4] = "";

//What to do on twist
static void tap_handler(AccelAxisType axis, int32_t direction) {
	APP_LOG(APP_LOG_LEVEL_INFO, "Detected Tap/Twist");
	static char side_buffer[3] = "";
	snprintf(side_buffer, sizeof(side_buffer), "%d", side_num);
	
	//set die 1
	die1 = ((rand() % side_num) + 1);
	static char die1_buffer[2] = "";
	snprintf(die1_buffer, sizeof(die1_buffer), "%d", die1);
	APP_LOG(APP_LOG_LEVEL_INFO, die1_buffer);
	text_layer_set_text(result1, die1_buffer);
	
	//set die 2
	die2 = ((rand() % side_num) + 1);
	static char die2_buffer[2] = "";
	snprintf(die2_buffer, sizeof(die2_buffer), "%d", die2);
	APP_LOG(APP_LOG_LEVEL_INFO, die2_buffer);
	if (die_num >= 2) {
	text_layer_set_text(result2, die2_buffer);
	text_layer_set_background_color(result2, GColorWhite);
	}
	
	//set die 3
	die3 = ((rand() % side_num) + 1);
	static char die3_buffer[2] = "";
	snprintf(die3_buffer, sizeof(die3_buffer), "%d", die3);
	APP_LOG(APP_LOG_LEVEL_INFO, die3_buffer);
	if (die_num >= 3) {
	text_layer_set_text(result3, die3_buffer);
	text_layer_set_background_color(result3, GColorWhite);
	}
	
	//set die 4
	die4 = ((rand() % side_num) + 1);
	static char die4_buffer[2] = "";
	snprintf(die4_buffer, sizeof(die4_buffer), "%d", die4);
	APP_LOG(APP_LOG_LEVEL_INFO, die4_buffer);
	if (die_num >= 4) {
	text_layer_set_text(result4, die4_buffer);
	text_layer_set_background_color(result4, GColorWhite);
	}
	
	//set die 5
	die5 = ((rand() % side_num) + 1);
	static char die5_buffer[2] = "";
	snprintf(die5_buffer, sizeof(die5_buffer), "%d", die5);
	APP_LOG(APP_LOG_LEVEL_INFO, die5_buffer);
	if (die_num >= 5) {
	text_layer_set_text(result5, die5_buffer);
	text_layer_set_background_color(result5, GColorWhite);
	}
	
	//set die 6
	die6 = ((rand() % side_num) + 1);
	static char die6_buffer[2] = "";
	snprintf(die6_buffer, sizeof(die6_buffer), "%d", die6);
	APP_LOG(APP_LOG_LEVEL_INFO, die6_buffer);
	if (die_num >= 6) {
	text_layer_set_text(result6, die6_buffer);
	text_layer_set_background_color(result6, GColorWhite);
	}
	
	// Send a long vibration to the user wrist
	vibes_short_pulse();
}

//Make window
void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
  background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
  background_layer = bitmap_layer_create(GRect(0, 0, 144, 164));
  bitmap_layer_set_bitmap(background_layer, background_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(background_layer));
	
	//Wait for a bit
	//void psleep(int millis_buffer);
		
	//Show Results background
 	background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_RESULTS);
 	background_layer = bitmap_layer_create(GRect(0, 0, 144, 164));
 	bitmap_layer_set_bitmap(background_layer, background_bitmap);
 	layer_add_child(window_get_root_layer(main_window), bitmap_layer_get_layer(background_layer));
	
	//Subscribe to Accelerometer tap service
	accel_tap_service_subscribe(tap_handler);
	
	//Text Layer 1
	result1 = text_layer_create(GRect(27, 10, 36, 36));
	text_layer_set_background_color(result1, GColorWhite);
	text_layer_set_text_color(result1, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result1));
	text_layer_set_text_alignment(result1, GTextAlignmentCenter);
	
	//Text Layer 2
	result2 = text_layer_create(GRect(81, 10, 36, 36));
	text_layer_set_background_color(result2, GColorClear);
	text_layer_set_text_color(result2, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result2));
	text_layer_set_text_alignment(result2, GTextAlignmentCenter);
	
	//Text Layer 3
	result3 = text_layer_create(GRect(27, 59, 36, 36));
	text_layer_set_background_color(result3, GColorClear);
	text_layer_set_text_color(result3, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result3));
	text_layer_set_text_alignment(result3, GTextAlignmentCenter);
	
	//Text Layer 4
	result4 = text_layer_create(GRect(81, 59, 36, 36));
	text_layer_set_background_color(result4, GColorClear);
	text_layer_set_text_color(result4, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result4));
	text_layer_set_text_alignment(result4, GTextAlignmentCenter);
	
	//Text Layer 5
	result5 = text_layer_create(GRect(27, 108, 36, 36));
	text_layer_set_background_color(result5, GColorClear);
	text_layer_set_text_color(result5, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result5));
	text_layer_set_text_alignment(result5, GTextAlignmentCenter);
	
	//Text Layer 6
	result6 = text_layer_create(GRect(81, 108, 36, 36));
	text_layer_set_background_color(result6, GColorClear);
	text_layer_set_text_color(result6, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result6));
	text_layer_set_text_alignment(result6, GTextAlignmentCenter);
	
	//Text Font
	result_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROBOTO_30));
	text_layer_set_font(result1, result_font);
	text_layer_set_font(result2, result_font);
	text_layer_set_font(result3, result_font);
	text_layer_set_font(result4, result_font);
	text_layer_set_font(result5, result_font);
	text_layer_set_font(result6, result_font);
}

static void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
 	text_layer_destroy(result1);
	text_layer_destroy(result2);
	text_layer_destroy(result3);
	text_layer_destroy(result4);
	text_layer_destroy(result5);
	text_layer_destroy(result6);
}

void push_main_window(){
  window_stack_push(main_window, true);
}

static void init() {
	//give millis a value
	//millis = 10000;
	// Create main Window element and assign to pointer
  main_window = window_create();
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(main_window, (WindowHandlers) {
    .load = main_window_load,
    //.unload = main_window_unload
  });
	
	//Random Number Generator!
	srand(time(NULL));
	
}

static void deinit() {
    // Destroy Window
    window_destroy(main_window);
}

int main(void) {
  init();
  splash_window_push();
  app_event_loop();
  deinit();
}