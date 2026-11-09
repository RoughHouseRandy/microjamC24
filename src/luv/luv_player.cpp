#include "luv/luv_player.h"

#include <bn_keypad.h>
#include "bn_sprite_items_luv_fish.h"

namespace luv
{
    /**
     * player constructor
     */
    luv_player::luv_player(bn::fixed_point starting_position, bn::fixed speed) :
     _sprite(bn::sprite_items::luv_fish.create_sprite(starting_position)),                                                                  
     _sprite_action(bn::create_sprite_animate_action_forever(_sprite, 4, bn::sprite_items::luv_fish.tiles_item(), 0, 1, 2, 3)),                                                                 
     _speed(speed),
     _size({16, 16}),
     _bounding_box(generate_bounding_box(_sprite, _size))
    {
    }

    void luv_player::update()
    {
        _update_position();
        
        if(bn::keypad::any_held()){
            _update_animation();
        }
    }

    /**
     * reads dpad movement
     */
    void luv::luv_player::_update_position()
    {
        if (bn::keypad::left_held())
        {
            _sprite.set_x(_sprite.x() - _speed);
        }
        if (bn::keypad::right_held())
        {
            _sprite.set_x(_sprite.x() + _speed);
        }
        if (bn::keypad::up_held())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }
    }

    void luv::luv_player::_update_animation(){
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

    bool luv_player::found_hiding_spot() const {
        return (_sprite.x() == 40 && _sprite.y() == 40);
    }
}