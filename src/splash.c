#include <pebble.h>
#include "splash.h"
#include "main.h"
  
BitmapLayer *torus_layer;
GBitmap *torus_bitmap;

void torus_handler (){
  window_stack_pop(true);
  push_main_window();
}

void splash_window_load(Window *window){
  GRect bounds = layer_get_bounds(window_get_root_layer(window));
  AppTimer *animation_timer = app_timer_register(1000, torus_handler, NULL);
  torus_bitmap = gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
 	torus_layer = bitmap_layer_create(bounds);
 	bitmap_layer_set_bitmap(torus_layer, torus_bitmap);
  bitmap_layer_set_background_color(torus_layer, GColorBlack);
 	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(torus_layer));
}
  
void splash_window_unload(Window *window){
  gbitmap_destroy(torus_bitmap);
  bitmap_layer_destroy(torus_layer);
}
  
void splash_window_push(){
  Window *splash_window = window_create();
  window_set_window_handlers(splash_window, (WindowHandlers){
    .load = splash_window_load,
    .unload = splash_window_unload
  });
  window_stack_push(splash_window, true);
}