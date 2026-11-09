#include "luv_hide_and_seak.h"
#include "mj/mj_game_list.h"
#include "bn_regular_bg_items_seafloor.h"

// String arrays for the credits can go in an anonymous namespace
namespace
{
    constexpr bn::string_view code_credits[] = {"Corey Brown", "Russell Fisher"};
    constexpr bn::string_view graphics_credits[] = {"Kenney Game Assets"};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(luv::luv_hide_and_seak) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace luv
{
    luv_hide_and_seak::luv_hide_and_seak([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data) :
    mj::game("luv"),
    _player({20,20}, 2),
    _background(bn::regular_bg_items::seafloor.create_bg(0,0))
    {}

    bn::string<16> luv_hide_and_seak::title() const {
        return "Hide and Fast!";
    }

    int luv_hide_and_seak::total_frames() const
    {
        return 300;
    }

    mj::game_result luv_hide_and_seak::play([[maybe_unused]] const mj::game_data& data){

        mj::game_result result(victory(), false);
        return result;
    }

    bool luv_hide_and_seak::victory() const {
        return false;
    }

    void luv_hide_and_seak::fade_in([[maybe_unused]] const mj::game_data& data){

    }

    void luv_hide_and_seak::fade_out([[maybe_unused]] const mj::game_data& data){
        
    }

}
