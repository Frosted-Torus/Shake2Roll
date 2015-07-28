#include <pebble.h>

//Windows
static Window *main_window;

//Text Layers

//Fonts

//Bitmaps
static BitmapLayer *splash;
static BitmapLayer *results;
static BitmapLayer *background_layer;
static GBitmap *background_bitmap;

//Variables
unsigned short dice;

//What to do on twist
static void tap_handler(AccelAxisType axis, int32_t direction) {
	APP_LOG(APP_LOG_LEVEL_INFO, "Detected Tap/Twist");
}

//Make window
static void main_window_load(Window *window) {
  // Create GBitmap, then set to created BitmapLayer
  background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
  background_layer = bitmap_layer_create(GRect(0, 1, 144, 180));
  bitmap_layer_set_bitmap(background_layer, background_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(background_layer));
	
	//Subscribe to Accelerometer tap service
	accel_tap_service_subscribe(tap_handler);
}

//static void main_window_unload(Window *window) {}

static void init() {
	// Create main Window element and assign to pointer
  main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(main_window, (WindowHandlers) {
    .load = main_window_load,
    //.unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
	window_stack_push(main_window, true);
	
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