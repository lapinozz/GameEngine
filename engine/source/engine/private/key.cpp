#include "key.hpp"

#include <unordered_map>

std::string key_to_string(Key key) {
    // clang-format off
    static std::unordered_map<Key, std::string> key_string({
        {Key::any_key, "any_key"},
        {Key::mouse_x, "mouse_x"},
        {Key::mouse_y, "mouse_y"},
        {Key::mouse_scroll, "mouse_scroll"},
        {Key::mouse_scroll_up, "mouse_scroll_up"},
        {Key::mouse_scroll_down, "mouse_scroll_down"},
        {Key::mouse_0, "mouse_0"},
        {Key::mouse_1, "mouse_1"},
        {Key::mouse_2, "mouse_2"},
        {Key::mouse_3, "mouse_3"},
        {Key::mouse_4, "mouse_4"},
        {Key::mouse_5, "mouse_5"},
        {Key::mouse_6, "mouse_6"},
        {Key::mouse_7, "mouse_7"},
        {Key::escape, "escape"},
        {Key::enter, "enter"},
        {Key::tab, "tab"},
        {Key::caps_lock, "caps_lock"},
        {Key::spacebar, "spacebar"},
        {Key::backspace, "backspace"},
        {Key::keypad_0, "keypad_0"},
        {Key::keypad_1, "keypad_1"},
        {Key::keypad_2, "keypad_2"},
        {Key::keypad_3, "keypad_3"},
        {Key::keypad_4, "keypad_4"},
        {Key::keypad_5, "keypad_5"},
        {Key::keypad_6, "keypad_6"},
        {Key::keypad_7, "keypad_7"},
        {Key::keypad_8, "keypad_8"},
        {Key::keypad_9, "keypad_9"},
        {Key::keypad_slash, "keypad_slash"},
        {Key::keypad_period, "keypad_period"},
        {Key::keypad_asteriks, "keypad_asteriks"},
        {Key::keypad_minus, "keypad_minus"},
        {Key::keypad_plus, "keypad_plus"},
        {Key::keypad_enter, "keypad_enter"},
        {Key::left, "left"},
        {Key::right, "right"},
        {Key::up, "up"},
        {Key::down, "down"},
        {Key::insert, "insert"},
        {Key::home, "home"},
        {Key::page_up, "page_up"},
        {Key::page_down, "page_down"},
        {Key::end, "end"},
        {Key::delete_key, "delete_key"},
        {Key::one, "one"},
        {Key::two, "two"},
        {Key::three, "three"},
        {Key::four, "four"},
        {Key::five, "five"},
        {Key::six, "six"},
        {Key::seven, "seven"},
        {Key::eight, "eight"},
        {Key::nine, "nine"},
        {Key::zero, "zero"},
        {Key::minus, "minus"},
        {Key::plus, "plus"},
        {Key::tilde, "tilde"},
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
        {Key::left_curly_bracket, "left_curly_bracket"},
        {Key::right_curly_bracket, "right_curly_bracket"},
        {Key::pipe, "pipe"},
        {Key::colon, "colon"},
        {Key::semicolon, "semicolon"},
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
        {Key::gamepad_button_1, "gamepad_button_19"}
    });
    // clang-format on
    return key_string.at(key);
}

Key key_from_string(std::string const& str) {
    // clang-format off
    static std::unordered_map<std::string, Key> string_key({
        {"any_key", Key::any_key},
        {"mouse_x", Key::mouse_x},
        {"mouse_y", Key::mouse_y},
        {"mouse_scroll", Key::mouse_scroll},
        {"mouse_scroll_up", Key::mouse_scroll_up},
        {"mouse_scroll_down", Key::mouse_scroll_down},
        {"mouse_0", Key::mouse_0},
        {"mouse_1", Key::mouse_1},
        {"mouse_2", Key::mouse_2},
        {"mouse_3", Key::mouse_3},
        {"mouse_4", Key::mouse_4},
        {"mouse_5", Key::mouse_5},
        {"mouse_6", Key::mouse_6},
        {"mouse_7", Key::mouse_7},
        {"escape", Key::escape},
        {"enter", Key::enter},
        {"tab", Key::tab},
        {"caps_lock", Key::caps_lock},
        {"spacebar", Key::spacebar},
        {"backspace", Key::backspace},
        {"keypad_0", Key::keypad_0},
        {"keypad_1", Key::keypad_1},
        {"keypad_2", Key::keypad_2},
        {"keypad_3", Key::keypad_3},
        {"keypad_4", Key::keypad_4},
        {"keypad_5", Key::keypad_5},
        {"keypad_6", Key::keypad_6},
        {"keypad_7", Key::keypad_7},
        {"keypad_8", Key::keypad_8},
        {"keypad_9", Key::keypad_9},
        {"keypad_slash", Key::keypad_slash},
        {"keypad_period", Key::keypad_period},
        {"keypad_asteriks", Key::keypad_asteriks},
        {"keypad_minus", Key::keypad_minus},
        {"keypad_plus", Key::keypad_plus},
        {"keypad_enter", Key::keypad_enter},
        {"left", Key::left},
        {"right", Key::right},
        {"up", Key::up},
        {"down", Key::down},
        {"insert", Key::insert},
        {"home", Key::home},
        {"page_up", Key::page_up},
        {"page_down", Key::page_down},
        {"end", Key::end},
        {"delete_key", Key::delete_key},
        {"one", Key::one},
        {"two", Key::two},
        {"three", Key::three},
        {"four", Key::four},
        {"five", Key::five},
        {"six", Key::six},
        {"seven", Key::seven},
        {"eight", Key::eight},
        {"nine", Key::nine},
        {"zero", Key::zero},
        {"minus", Key::minus},
        {"plus", Key::plus},
        {"tilde", Key::tilde},
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
        {"left_curly_bracket", Key::left_curly_bracket},
        {"right_curly_bracket", Key::right_curly_bracket},
        {"pipe", Key::pipe},
        {"colon", Key::colon},
        {"semicolon", Key::semicolon},
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