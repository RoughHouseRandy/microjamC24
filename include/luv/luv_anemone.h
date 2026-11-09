#pragma once

#include <bn_display.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include <bn_fixed.h>
#include <bn_random.h>
#include <bn_size.h>
#include "luv/luv_methods.h"

//Create a namespace to ensure all variables within are scoped to the instance.
namespace luv {
    class luv_anemone {

        /**
         * Anemone constructor
         * @param _pos_x the starting x position
         * @param _pos_y the starting y position
         */
        public:
        bn::fixed _pos_x;
        bn::fixed _pos_y;
        bn::sprite_ptr _sprite;
        bn::size _size;
        bn::rect _bounding_box; //Bounding box of the anemone
        
        luv_anemone();
    };
}