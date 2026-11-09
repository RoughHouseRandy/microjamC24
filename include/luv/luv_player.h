#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_display.h>

namespace luv {
    // the bounds of the screen
    class luv_player {
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

        public:
        /**
         * player constructor
         * 
         * @param starting_position the location to spawn the player
         * @param speed the pixels/frame the player moves in each direction.
         */
        luv_player(bn::fixed_point starting_position, bn::fixed speed);

        /**
         * reads keypad inputs to move the character
         */
        void update();

        /**
         * Returns whether the player has found a hiding spot
         * 
         * @return true if the player has found a succesful hiding spot, false if not. 
         */
        bool found_hiding_spot() const;

    private:
     //sprite to display the characters
        bn::sprite_ptr _sprite;
        bn::sprite_animate_action<4> _sprite_action;
        //the pixels the player moves
        bn::fixed _speed;

        /**
         * Reads D-pad movement to move the player
         */
        void _update_position();

        /**
         * reads the player dpad movement and updates the sprite animation.
         */
        void _update_animation();
    };
     
}