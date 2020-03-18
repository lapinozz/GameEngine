#include <engine/key.hpp>

#include <unordered_map>

namespace anton_engine {
    bool is_mouse_axis(Key const k) {
        return k == Key::mouse_x || k == Key::mouse_y || k == Key::mouse_scroll;
    }

    bool is_gamepad_axis(Key const k) {
        return k == Key::gamepad_right_stick_x_axis || k == Key::gamepad_right_stick_y_axis || k == Key::gamepad_left_stick_x_axis ||
               k == Key::gamepad_left_stick_y_axis || k == Key::gamepad_left_trigger || k == Key::gamepad_right_trigger;
    }

    bool is_gamepad_stick(Key const k) {
        return k == Key::gamepad_right_stick_x_axis || k == Key::gamepad_right_stick_y_axis || k == Key::gamepad_left_stick_x_axis ||
               k == Key::gamepad_left_stick_y_axis;
    }

    std::string key_to_string(Key key) {
        // clang-format off
        static std::unordered_map<Key, std::string> key_string({
            {Key::none, "none"},
            {Key::any_key, "any_key"},
            {Key::mouse_x, "mouse_x"},
            {Key::mouse_y, "mouse_y"},
            {Key::mouse_scroll, "mouse_scroll"},
            {Key::mouse_horiz_scroll, "mouse_horiz_scroll"},
            {Key::left_mouse_button, "left_mouse_button"},
            {Key::right_mouse_button, "right_mouse_button"},
            {Key::middle_mouse_button, "middle_mouse_button"},
            {Key::thumb_mouse_button_1, "thumb_mouse_button_1"},
            {Key::thumb_mouse_button_2, "thumb_mouse_button_2"},
            {Key::mouse_button_6, "mouse_button_6"},
            {Key::mouse_button_7, "mouse_button_7"},
            {Key::mouse_button_8, "mouse_button_8"},
            {Key::escape, "escape"},
            {Key::enter, "enter"},
            {Key::tab, "tab"},
            {Key::caps_lock, "caps_lock"},
            {Key::spacebar, "spacebar"},
            {Key::backspace, "backspace"},
            {Key::left_alt, "left_alt"},
            {Key::right_alt, "right_alt"},
            {Key::left_shift, "left_shift"},
            {Key::right_shift, "right_shift"},
            {Key::left_control, "left_control"},
            {Key::right_control, "right_control"},
            {Key::numpad_0, "numpad_0"},
            {Key::numpad_1, "numpad_1"},
            {Key::numpad_2, "numpad_2"},
            {Key::numpad_3, "numpad_3"},
            {Key::numpad_4, "numpad_4"},
            {Key::numpad_5, "numpad_5"},
            {Key::numpad_6, "numpad_6"},
            {Key::numpad_7, "numpad_7"},
            {Key::numpad_8, "numpad_8"},
            {Key::numpad_9, "numpad_9"},
            {Key::numpad_add, "numpad_add"},
            {Key::numpad_subtract, "numpad_subtract"},
            {Key::numpad_divide, "numpad_divide"},
            {Key::numpad_multiply, "numpad_multiply"},
            {Key::numpad_decimal, "numpad_decimal"},
            {Key::numpad_enter, "numpad_enter"},
            {Key::numlock, "numlock"},
            {Key::left, "left"},
            {Key::right, "right"},
            {Key::up, "up"},
            {Key::down, "down"},
            {Key::insert, "insert"},
            {Key::home, "home"},
            {Key::page_up, "page_up"},
            {Key::page_down, "page_down"},
            {Key::end, "end"},
            {Key::del, "del"},
            {Key::zero, "zero"},
            {Key::one, "one"},
            {Key::two, "two"},
            {Key::three, "three"},
            {Key::four, "four"},
            {Key::five, "five"},
            {Key::six, "six"},
            {Key::seven, "seven"},
            {Key::eight, "eight"},
            {Key::nine, "nine"},
            {Key::a, "a"},
            {Key::b, "b"},
            {Key::c, "c"},
            {Key::d, "d"},
            {Key::e, "e"},
            {Key::f, "f"},
            {Key::g, "g"},
            {Key::h, "h"},
            {Key::i, "i"},
            {Key::j, "j"},
            {Key::k, "k"},
            {Key::l, "l"},
            {Key::m, "m"},
            {Key::n, "n"},
            {Key::o, "o"},
            {Key::p, "p"},
            {Key::q, "q"},
            {Key::r, "r"},
            {Key::s, "s"},
            {Key::t, "t"},
            {Key::u, "u"},
            {Key::v, "v"},
            {Key::w, "w"},
            {Key::x, "x"},
            {Key::y, "y"},
            {Key::z, "z"},
            {Key::slash, "slash"},
            {Key::comma, "comma"},
            {Key::dot, "dot"},
            {Key::semicolon, "semicolon"},
            {Key::left_bracket, "left_bracket"},
            {Key::right_bracket, "right_bracket"},
            {Key::minus, "minus"},
            {Key::equals, "equals"},
            {Key::apostrophe, "apostrophe"},
            {Key::tick, "tick"},
            {Key::backward_slash, "backward_slash"},
            {Key::f1, "f1"},
            {Key::f2, "f2"},
            {Key::f3, "f3"},
            {Key::f4, "f4"},
            {Key::f5, "f5"},
            {Key::f6, "f6"},
            {Key::f7, "f7"},
            {Key::f8, "f8"},
            {Key::f9, "f9"},
            {Key::f10, "f10"},
            {Key::f11, "f11"},
            {Key::f12, "f12"},
            {Key::pause, "pause"},
            {Key::gamepad_left_stick_x_axis, "gamepad_left_stick_x_axis"},
            {Key::gamepad_left_stick_y_axis, "gamepad_left_stick_y_axis"},
            {Key::gamepad_right_stick_x_axis, "gamepad_right_stick_x_axis"},
            {Key::gamepad_right_stick_y_axis, "gamepad_right_stick_y_axis"},
            {Key::gamepad_left_trigger, "gamepad_left_trigger"},
            {Key::gamepad_right_trigger, "gamepad_right_trigger"},
            {Key::gamepad_button_0, "gamepad_button_0"},
            {Key::gamepad_button_1, "gamepad_button_1"},
            {Key::gamepad_button_2, "gamepad_button_2"},
            {Key::gamepad_button_3, "gamepad_button_3"},
            {Key::gamepad_button_4, "gamepad_button_4"},
            {Key::gamepad_button_5, "gamepad_button_5"},
            {Key::gamepad_button_6, "gamepad_button_6"},
            {Key::gamepad_button_7, "gamepad_button_7"},
            {Key::gamepad_button_8, "gamepad_button_8"},
            {Key::gamepad_button_9, "gamepad_button_9"},
            {Key::gamepad_button_10, "gamepad_button_10"},
            {Key::gamepad_button_11, "gamepad_button_11"},
            {Key::gamepad_button_12, "gamepad_button_12"},
            {Key::gamepad_button_13, "gamepad_button_13"},
            {Key::gamepad_button_14, "gamepad_button_14"},
            {Key::gamepad_button_15, "gamepad_button_15"},
            {Key::gamepad_button_16, "gamepad_button_16"},
            {Key::gamepad_button_17, "gamepad_button_17"},
            {Key::gamepad_button_18, "gamepad_button_18"},
            {Key::gamepad_button_19, "gamepad_button_19"}
        });
        // clang-format on
        return key_string.at(key);
    }

    Key key_from_string(std::string const& str) {
        // clang-format off
        static std::unordered_map<std::string, Key> string_key({
            {"none", Key::none},
            {"any_key", Key::any_key},
            {"mouse_x", Key::mouse_x},
            {"mouse_y", Key::mouse_y},
            {"mouse_scroll", Key::mouse_scroll},
            {"mouse_horiz_scroll", Key::mouse_horiz_scroll},
            {"left_mouse_button", Key::left_mouse_button},
            {"right_mouse_button", Key::right_mouse_button},
            {"middle_mouse_button", Key::middle_mouse_button},
            {"thumb_mouse_button_1", Key::thumb_mouse_button_1},
            {"thumb_mouse_button_2", Key::thumb_mouse_button_2},
            {"mouse_button_6", Key::mouse_button_6},
            {"mouse_button_7", Key::mouse_button_7},
            {"mouse_button_8", Key::mouse_button_8},
            {"escape", Key::escape},
            {"enter", Key::enter},
            {"tab", Key::tab},
            {"caps_lock", Key::caps_lock},
            {"spacebar", Key::spacebar},
            {"backspace", Key::backspace},
            {"left_alt", Key::left_alt},
            {"right_alt", Key::right_alt},
            {"left_shift", Key::left_shift},
            {"right_shift", Key::right_shift},
            {"left_control", Key::left_control},
            {"right_control", Key::right_control},
            {"numpad_0", Key::numpad_0},
            {"numpad_1", Key::numpad_1},
            {"numpad_2", Key::numpad_2},
            {"numpad_3", Key::numpad_3},
            {"numpad_4", Key::numpad_4},
            {"numpad_5", Key::numpad_5},
            {"numpad_6", Key::numpad_6},
            {"numpad_7", Key::numpad_7},
            {"numpad_8", Key::numpad_8},
            {"numpad_9", Key::numpad_9},
            {"numpad_add", Key::numpad_add},
            {"numpad_subtract", Key::numpad_subtract},
            {"numpad_divide", Key::numpad_divide},
            {"numpad_multiply", Key::numpad_multiply},
            {"numpad_decimal", Key::numpad_decimal},
            {"numpad_enter", Key::numpad_enter},
            {"numlock", Key::numlock},
            {"left", Key::left},
            {"right", Key::right},
            {"up", Key::up},
            {"down", Key::down},
            {"insert", Key::insert},
            {"home", Key::home},
            {"page_up", Key::page_up},
            {"page_down", Key::page_down},
            {"end", Key::end},
            {"del", Key::del},
            {"zero", Key::zero},
            {"one", Key::one},
            {"two", Key::two},
            {"three", Key::three},
            {"four", Key::four},
            {"five", Key::five},
            {"six", Key::six},
            {"seven", Key::seven},
            {"eight", Key::eight},
            {"nine", Key::nine},
            {"a", Key::a},
            {"b", Key::b},
            {"c", Key::c},
            {"d", Key::d},
            {"e", Key::e},
            {"f", Key::f},
            {"g", Key::g},
            {"h", Key::h},
            {"i", Key::i},
            {"j", Key::j},
            {"k", Key::k},
            {"l", Key::l},
            {"m", Key::m},
            {"n", Key::n},
            {"o", Key::o},
            {"p", Key::p},
            {"q", Key::q},
            {"r", Key::r},
            {"s", Key::s},
            {"t", Key::t},
            {"u", Key::u},
            {"v", Key::v},
            {"w", Key::w},
            {"x", Key::x},
            {"y", Key::y},
            {"z", Key::z},
            {"slash", Key::slash},
            {"comma", Key::comma},
            {"dot", Key::dot},
            {"semicolon", Key::semicolon},
            {"left_bracket", Key::left_bracket},
            {"right_bracket", Key::right_bracket},
            {"minus", Key::minus},
            {"equals", Key::equals},
            {"apostrophe", Key::apostrophe},
            {"tick", Key::tick},
            {"backward_slash", Key::backward_slash},
            {"f1", Key::f1},
            {"f2", Key::f2},
            {"f3", Key::f3},
            {"f4", Key::f4},
            {"f5", Key::f5},
            {"f6", Key::f6},
            {"f7", Key::f7},
            {"f8", Key::f8},
            {"f9", Key::f9},
            {"f10", Key::f10},
            {"f11", Key::f11},
            {"f12", Key::f12},
            {"pause", Key::pause},
            {"gamepad_left_stick_x_axis", Key::gamepad_left_stick_x_axis},
            {"gamepad_left_stick_y_axis", Key::gamepad_left_stick_y_axis},
            {"gamepad_right_stick_x_axis", Key::gamepad_right_stick_x_axis},
            {"gamepad_right_stick_y_axis", Key::gamepad_right_stick_y_axis},
            {"gamepad_left_trigger", Key::gamepad_left_trigger},
            {"gamepad_right_trigger", Key::gamepad_right_trigger},
            {"gamepad_button_0", Key::gamepad_button_0},
            {"gamepad_button_1", Key::gamepad_button_1},
            {"gamepad_button_2", Key::gamepad_button_2},
            {"gamepad_button_3", Key::gamepad_button_3},
            {"gamepad_button_4", Key::gamepad_button_4},
            {"gamepad_button_5", Key::gamepad_button_5},
            {"gamepad_button_6", Key::gamepad_button_6},
            {"gamepad_button_7", Key::gamepad_button_7},
            {"gamepad_button_8", Key::gamepad_button_8},
            {"gamepad_button_9", Key::gamepad_button_9},
            {"gamepad_button_10", Key::gamepad_button_10},
            {"gamepad_button_11", Key::gamepad_button_11},
            {"gamepad_button_12", Key::gamepad_button_12},
            {"gamepad_button_13", Key::gamepad_button_13},
            {"gamepad_button_14", Key::gamepad_button_14},
            {"gamepad_button_15", Key::gamepad_button_15},
            {"gamepad_button_16", Key::gamepad_button_16},
            {"gamepad_button_17", Key::gamepad_button_17},
            {"gamepad_button_18", Key::gamepad_button_18},
            {"gamepad_button_19", Key::gamepad_button_19}
        });
        // clang-format on

        return string_key.at(str);
    }
} // namespace anton_engine
