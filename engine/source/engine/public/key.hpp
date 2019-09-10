#ifndef ENGINE_KEY_HPP_INCLUDE
#define ENGINE_KEY_HPP_INCLUDE

#include <string>

namespace anton_engine {
    enum class Key {
        none,
        any_key,

        mouse_x,
        mouse_y,
        mouse_scroll,
        left_mouse_button,
        right_mouse_button,
        middle_mouse_button,
        thumb_mouse_button_1,
        thumb_mouse_button_2,
        mouse_button_6,
        mouse_button_7,
        mouse_button_8,

        escape,
        enter,
        tab,
        caps_lock,
        spacebar,
        backspace,
        left_alt,
        right_alt,
        left_shift,
        right_shift,

        numpad_0,
        numpad_1,
        numpad_2,
        numpad_3,
        numpad_4,
        numpad_5,
        numpad_6,
        numpad_7,
        numpad_8,
        numpad_9,
        numpad_slash,
        numpad_period,
        numpad_asteriks,
        numpad_minus,
        numpad_plus,
        numpad_enter,
        num_lock,

        left,
        right,
        up,
        down,

        insert,
        home,
        page_up,
        page_down,
        end,
        delete_key,

        one,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        zero,
        minus,
        plus,
        tilde,

        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m,
        n,
        o,
        p,
        q,
        r,
        s,
        t,
        u,
        v,
        w,
        x,
        y,
        z,

        left_curly_bracket,
        right_curly_bracket,
        pipe,
        colon,
        semicolon,

        f1,
        f2,
        f3,
        f4,
        f5,
        f6,
        f7,
        f8,
        f9,
        f10,
        f11,
        f12,

        gamepad_left_stick_x_axis,
        gamepad_left_stick_y_axis,
        gamepad_right_stick_x_axis,
        gamepad_right_stick_y_axis,
        gamepad_left_trigger,
        gamepad_right_trigger,

        gamepad_button_0,
        gamepad_button_1,
        gamepad_button_2,
        gamepad_button_3,
        gamepad_button_4,
        gamepad_button_5,
        gamepad_button_6,
        gamepad_button_7,
        gamepad_button_8,
        gamepad_button_9,
        gamepad_button_10,
        gamepad_button_11,
        gamepad_button_12,
        gamepad_button_13,
        gamepad_button_14,
        gamepad_button_15,
        gamepad_button_16,
        gamepad_button_17,
        gamepad_button_18,
        gamepad_button_19,
    };

    namespace utils {
        namespace key {
            bool is_mouse_axis(Key key);
            bool is_gamepad_axis(Key key);
        } // namespace key
    }     // namespace utils

    std::string key_to_string(Key);
    Key key_from_string(std::string const&);
} // namespace anton_engine

#endif // !ENGINE_KEY_HPP_INCLUDE
