#include "luv/luv_methods.h"

namespace luv {
    /**
     * File that contains commmon methods and variables for the luv classes and interfaces
     */

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

    //Method to generate a random anemone position
    bn::fixed generate_random_anemone_y() {
        bn::fixed random_y = seed.get_fixed(0, MAX_Y);
        return random_y;
    }

    //Methods to generate bounding box
    bn::rect generate_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(sprite.x().round_integer(),
                        sprite.y().round_integer(),
                        box_size.width(),
                        box_size.height());
    }
}