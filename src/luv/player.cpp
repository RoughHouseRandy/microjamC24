#include "luv/player.h"

#include <bn_keypad.h>
#include "bn_sprite_items_luv_fish.h"

namespace luv
{
    /**
     * player constructor
     */
    player::player(bn::fixed_point starting_position, bn::fixed speed) :
     _sprite(bn::sprite_items::luv_fish),                                                                  
     _sprite_actions(bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3)),                                                                 
     _speed(speed)
    {
    }

    void player::update()
    {
        _update_position();
        _update_animation();
    }

    /**
     * reads dpad movement
     */
    void luv::player::_update_position()
    {
        if (bn::keypad::left_held())
        {
            _sprite.set_x(_sprite.x() - _speed);
        }
        if (bn::keypad::right_held())
        {
            _sprite.set_x(_sprite.x() + speed);
        }
        if (bn::keypad::up_held())
        {
            _sprite.set_y(_sprite.y() - speed);
        }
        if (bn::keypad::down_held)
        {
            _sprite.set_y(_sprite.y() + speed);
        }
    }

    void luv::player::_update_animation(){
        if(bn::keypad::left_held()){
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(),0,1,2,3);
        }
        if (bn::keypad::right_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        if (bn::keypad::up_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        if (bn::keypad::down_held())
        {
            _sprite_action = bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3);
        }
        _sprite_action.update();
    }

    bool player::found_hiding_spot() const {
        return (_sprite.x() == 40 && _sprite.y() == 40);
    }
}