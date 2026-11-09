#pragma once

#include <bn_display.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include <bn_fixed.h>
#include <bn_random.h>

//Create a namespace to ensure all variables within are scoped to the instance.
namespace luv {
    class luv_anemone {
        //Set the the bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

        //Create RNG seed
        bn::random seed;

        //Methods to generate random x and y coordinates
        bn::fixed generate_random_x() {
            bn::fixed random_x = seed.get_fixed(MIN_X, MAX_X);
            return random_x;
        }

        bn::fixed generate_random_y() {
            bn::fixed random_y = seed.get_fixed(MIN_Y, MAX_Y);
            return random_y;
        }

        /**
         * Anemone constructor
         * @param pos_x the starting x position
         * @param pos_y the starting y position
         */
        public:
        bn::fixed pos_x;
        bn::fixed pos_y;
        bn::sprite_ptr sprite;
        bn::rect bounding_box; //Bounding box of the anemone
        
        luv_anemone(bn::fixed pos_x, bn::fixed pos_y);
    };
}