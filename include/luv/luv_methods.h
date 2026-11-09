#include <bn_rect.h>
#include <bn_fixed.h>
#include <bn_random.h>
#include <bn_size.h>
#include <bn_display.h>
#include <bn_sprite_ptr.h>

/**
 * File that contains commmon methods and variables for the luv classes and interfaces
 */

//Set the the bounds of the screen
static constexpr int MAX_X = bn::display::width() / 2;
static constexpr int MIN_X = - bn::display::width() / 2;
static constexpr int MAX_Y = bn::display::height() / 2;
static constexpr int MIN_Y = - bn::display::height() / 2;

//Create RNG seed
bn::random seed;

//Method to generate random x  coordinate
bn::fixed generate_random_x() {
    bn::fixed random_x = seed.get_fixed(MIN_X, MAX_X);
    return random_x;
}

//Method to generate random y coordinate
bn::fixed generate_random_y() {
    bn::fixed random_y = seed.get_fixed(MIN_Y, MAX_Y);
    return random_y;
}

//Methods to generate bounding box
bn::rect generate_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
    return bn::rect(sprite.x().round_integer(),
                    sprite.y().round_integer(),
                    box_size.width(),
                    box_size.height());
}
