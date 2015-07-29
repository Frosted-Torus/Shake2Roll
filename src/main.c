#include <pebble.h>

//Windows
static Window *main_window;

//Text Layers
TextLayer *result;

//Fonts
static GFont result_font;

//Bitmaps
static BitmapLayer *splash;
static BitmapLayer *results;
static BitmapLayer *background_layer;
static GBitmap *background_bitmap;

//Variables
uint8_t dice;
int millis = 100000;

//What to do on twist
static void tap_handler(AccelAxisType axis, int32_t direction) {
	APP_LOG(APP_LOG_LEVEL_INFO, "Detected Tap/Twist");
	dice = ((rand() % 6) + 1);
	static char dice_buffer[2] = "";
	snprintf(dice_buffer, sizeof(dice_buffer), "%d", dice);
	APP_LOG(APP_LOG_LEVEL_INFO, dice_buffer);
	text_layer_set_text(result, dice_buffer);
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
	void psleep(int millis);
		
	//Show Results background
 	background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_RESULTS);
 	background_layer = bitmap_layer_create(GRect(0, 0, 144, 164));
 	bitmap_layer_set_bitmap(background_layer, background_bitmap);
 	layer_add_child(window_get_root_layer(main_window), bitmap_layer_get_layer(background_layer));
	
	//Subscribe to Accelerometer tap service
	accel_tap_service_subscribe(tap_handler);
	
	//Text Layer
	result = text_layer_create(GRect(27, 10, 36, 36));
	text_layer_set_background_color(result, GColorWhite);
	text_layer_set_text_color(result, GColorBlack);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(result));
	text_layer_set_text_alignment(result, GTextAlignmentCenter);
	
	//Text Font
	result_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_ROBOTO_30));
	text_layer_set_font(result, result_font);
	
}

static void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
  text_layer_destroy(result);
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

 	//Show the Window on the watch, with animated=true
	window_stack_push(main_window, true);
	
	//Random Number Generator!
	srand(time(NULL));
	
}

static void deinit() {
    // Destroy Window
    window_destroy(main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}