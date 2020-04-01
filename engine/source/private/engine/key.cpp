#include <engine/key.hpp>

#include <core/atl/flat_hash_map.hpp>

namespace anton_engine {
    bool is_mouse_axis(Key const k) {
        return k == Key::mouse_x | k == Key::mouse_y | k == Key::mouse_scroll;
    }

    bool is_gamepad_axis(Key const k) {
        return k == Key::gamepad_right_stick_x_axis | k == Key::gamepad_right_stick_y_axis | k == Key::gamepad_left_stick_x_axis |
               k == Key::gamepad_left_stick_y_axis | k == Key::gamepad_left_trigger | k == Key::gamepad_right_trigger;
    }

    bool is_gamepad_stick(Key const k) {
        return k == Key::gamepad_right_stick_x_axis | k == Key::gamepad_right_stick_y_axis | k == Key::gamepad_left_stick_x_axis |
               k == Key::gamepad_left_stick_y_axis;
    }

    static atl::Flat_Hash_Map<Key, atl::String_View> construct_key_string_map() {
        atl::Flat_Hash_Map<Key, atl::String_View> key_string(atl::reserve, 139);
        key_string.emplace(Key::none, "none");
        key_string.emplace(Key::any_key, "any_key");
        key_string.emplace(Key::mouse_x, "mouse_x");
        key_string.emplace(Key::mouse_y, "mouse_y");
        key_string.emplace(Key::mouse_scroll, "mouse_scroll");
        key_string.emplace(Key::mouse_horiz_scroll, "mouse_horiz_scroll");
        key_string.emplace(Key::left_mouse_button, "left_mouse_button");
        key_string.emplace(Key::right_mouse_button, "right_mouse_button");
        key_string.emplace(Key::middle_mouse_button, "middle_mouse_button");
        key_string.emplace(Key::thumb_mouse_button_1, "thumb_mouse_button_1");
        key_string.emplace(Key::thumb_mouse_button_2, "thumb_mouse_button_2");
        key_string.emplace(Key::mouse_button_6, "mouse_button_6");
        key_string.emplace(Key::mouse_button_7, "mouse_button_7");
        key_string.emplace(Key::mouse_button_8, "mouse_button_8");
        key_string.emplace(Key::escape, "escape");
        key_string.emplace(Key::enter, "enter");
        key_string.emplace(Key::tab, "tab");
        key_string.emplace(Key::caps_lock, "caps_lock");
        key_string.emplace(Key::spacebar, "spacebar");
        key_string.emplace(Key::backspace, "backspace");
        key_string.emplace(Key::left_alt, "left_alt");
        key_string.emplace(Key::right_alt, "right_alt");
        key_string.emplace(Key::left_shift, "left_shift");
        key_string.emplace(Key::right_shift, "right_shift");
        key_string.emplace(Key::left_control, "left_control");
        key_string.emplace(Key::right_control, "right_control");
        key_string.emplace(Key::numpad_0, "numpad_0");
        key_string.emplace(Key::numpad_1, "numpad_1");
        key_string.emplace(Key::numpad_2, "numpad_2");
        key_string.emplace(Key::numpad_3, "numpad_3");
        key_string.emplace(Key::numpad_4, "numpad_4");
        key_string.emplace(Key::numpad_5, "numpad_5");
        key_string.emplace(Key::numpad_6, "numpad_6");
        key_string.emplace(Key::numpad_7, "numpad_7");
        key_string.emplace(Key::numpad_8, "numpad_8");
        key_string.emplace(Key::numpad_9, "numpad_9");
        key_string.emplace(Key::numpad_add, "numpad_add");
        key_string.emplace(Key::numpad_subtract, "numpad_subtract");
        key_string.emplace(Key::numpad_divide, "numpad_divide");
        key_string.emplace(Key::numpad_multiply, "numpad_multiply");
        key_string.emplace(Key::numpad_decimal, "numpad_decimal");
        key_string.emplace(Key::numpad_enter, "numpad_enter");
        key_string.emplace(Key::numlock, "numlock");
        key_string.emplace(Key::left, "left");
        key_string.emplace(Key::right, "right");
        key_string.emplace(Key::up, "up");
        key_string.emplace(Key::down, "down");
        key_string.emplace(Key::insert, "insert");
        key_string.emplace(Key::home, "home");
        key_string.emplace(Key::page_up, "page_up");
        key_string.emplace(Key::page_down, "page_down");
        key_string.emplace(Key::end, "end");
        key_string.emplace(Key::del, "del");
        key_string.emplace(Key::zero, "zero");
        key_string.emplace(Key::one, "one");
        key_string.emplace(Key::two, "two");
        key_string.emplace(Key::three, "three");
        key_string.emplace(Key::four, "four");
        key_string.emplace(Key::five, "five");
        key_string.emplace(Key::six, "six");
        key_string.emplace(Key::seven, "seven");
        key_string.emplace(Key::eight, "eight");
        key_string.emplace(Key::nine, "nine");
        key_string.emplace(Key::a, "a");
        key_string.emplace(Key::b, "b");
        key_string.emplace(Key::c, "c");
        key_string.emplace(Key::d, "d");
        key_string.emplace(Key::e, "e");
        key_string.emplace(Key::f, "f");
        key_string.emplace(Key::g, "g");
        key_string.emplace(Key::h, "h");
        key_string.emplace(Key::i, "i");
        key_string.emplace(Key::j, "j");
        key_string.emplace(Key::k, "k");
        key_string.emplace(Key::l, "l");
        key_string.emplace(Key::m, "m");
        key_string.emplace(Key::n, "n");
        key_string.emplace(Key::o, "o");
        key_string.emplace(Key::p, "p");
        key_string.emplace(Key::q, "q");
        key_string.emplace(Key::r, "r");
        key_string.emplace(Key::s, "s");
        key_string.emplace(Key::t, "t");
        key_string.emplace(Key::u, "u");
        key_string.emplace(Key::v, "v");
        key_string.emplace(Key::w, "w");
        key_string.emplace(Key::x, "x");
        key_string.emplace(Key::y, "y");
        key_string.emplace(Key::z, "z");
        key_string.emplace(Key::slash, "slash");
        key_string.emplace(Key::comma, "comma");
        key_string.emplace(Key::dot, "dot");
        key_string.emplace(Key::semicolon, "semicolon");
        key_string.emplace(Key::left_bracket, "left_bracket");
        key_string.emplace(Key::right_bracket, "right_bracket");
        key_string.emplace(Key::minus, "minus");
        key_string.emplace(Key::equals, "equals");
        key_string.emplace(Key::apostrophe, "apostrophe");
        key_string.emplace(Key::tick, "tick");
        key_string.emplace(Key::backward_slash, "backward_slash");
        key_string.emplace(Key::f1, "f1");
        key_string.emplace(Key::f2, "f2");
        key_string.emplace(Key::f3, "f3");
        key_string.emplace(Key::f4, "f4");
        key_string.emplace(Key::f5, "f5");
        key_string.emplace(Key::f6, "f6");
        key_string.emplace(Key::f7, "f7");
        key_string.emplace(Key::f8, "f8");
        key_string.emplace(Key::f9, "f9");
        key_string.emplace(Key::f10, "f10");
        key_string.emplace(Key::f11, "f11");
        key_string.emplace(Key::f12, "f12");
        key_string.emplace(Key::pause, "pause");
        key_string.emplace(Key::gamepad_left_stick_x_axis, "gamepad_left_stick_x_axis");
        key_string.emplace(Key::gamepad_left_stick_y_axis, "gamepad_left_stick_y_axis");
        key_string.emplace(Key::gamepad_right_stick_x_axis, "gamepad_right_stick_x_axis");
        key_string.emplace(Key::gamepad_right_stick_y_axis, "gamepad_right_stick_y_axis");
        key_string.emplace(Key::gamepad_left_trigger, "gamepad_left_trigger");
        key_string.emplace(Key::gamepad_right_trigger, "gamepad_right_trigger");
        key_string.emplace(Key::gamepad_button_0, "gamepad_button_0");
        key_string.emplace(Key::gamepad_button_1, "gamepad_button_1");
        key_string.emplace(Key::gamepad_button_2, "gamepad_button_2");
        key_string.emplace(Key::gamepad_button_3, "gamepad_button_3");
        key_string.emplace(Key::gamepad_button_4, "gamepad_button_4");
        key_string.emplace(Key::gamepad_button_5, "gamepad_button_5");
        key_string.emplace(Key::gamepad_button_6, "gamepad_button_6");
        key_string.emplace(Key::gamepad_button_7, "gamepad_button_7");
        key_string.emplace(Key::gamepad_button_8, "gamepad_button_8");
        key_string.emplace(Key::gamepad_button_9, "gamepad_button_9");
        key_string.emplace(Key::gamepad_button_10, "gamepad_button_10");
        key_string.emplace(Key::gamepad_button_11, "gamepad_button_11");
        key_string.emplace(Key::gamepad_button_12, "gamepad_button_12");
        key_string.emplace(Key::gamepad_button_13, "gamepad_button_13");
        key_string.emplace(Key::gamepad_button_14, "gamepad_button_14");
        key_string.emplace(Key::gamepad_button_15, "gamepad_button_15");
        key_string.emplace(Key::gamepad_button_16, "gamepad_button_16");
        key_string.emplace(Key::gamepad_button_17, "gamepad_button_17");
        key_string.emplace(Key::gamepad_button_18, "gamepad_button_18");
        key_string.emplace(Key::gamepad_button_19, "gamepad_button_19");
        return key_string;
    }

    atl::String_View key_to_string(Key key) {
        static atl::Flat_Hash_Map<Key, atl::String_View> key_string = construct_key_string_map();
        return key_string.find_or_emplace(key)->value;
    }

    static atl::Flat_Hash_Map<u64, Key> construct_string_key_map() {
        atl::Flat_Hash_Map<u64, Key> string_key;
        string_key.emplace(atl::hash("none"), Key::none);
        string_key.emplace(atl::hash("any_key"), Key::any_key);
        string_key.emplace(atl::hash("mouse_x"), Key::mouse_x);
        string_key.emplace(atl::hash("mouse_y"), Key::mouse_y);
        string_key.emplace(atl::hash("mouse_scroll"), Key::mouse_scroll);
        string_key.emplace(atl::hash("mouse_horiz_scroll"), Key::mouse_horiz_scroll);
        string_key.emplace(atl::hash("left_mouse_button"), Key::left_mouse_button);
        string_key.emplace(atl::hash("right_mouse_button"), Key::right_mouse_button);
        string_key.emplace(atl::hash("middle_mouse_button"), Key::middle_mouse_button);
        string_key.emplace(atl::hash("thumb_mouse_button_1"), Key::thumb_mouse_button_1);
        string_key.emplace(atl::hash("thumb_mouse_button_2"), Key::thumb_mouse_button_2);
        string_key.emplace(atl::hash("mouse_button_6"), Key::mouse_button_6);
        string_key.emplace(atl::hash("mouse_button_7"), Key::mouse_button_7);
        string_key.emplace(atl::hash("mouse_button_8"), Key::mouse_button_8);
        string_key.emplace(atl::hash("escape"), Key::escape);
        string_key.emplace(atl::hash("enter"), Key::enter);
        string_key.emplace(atl::hash("tab"), Key::tab);
        string_key.emplace(atl::hash("caps_lock"), Key::caps_lock);
        string_key.emplace(atl::hash("spacebar"), Key::spacebar);
        string_key.emplace(atl::hash("backspace"), Key::backspace);
        string_key.emplace(atl::hash("left_alt"), Key::left_alt);
        string_key.emplace(atl::hash("right_alt"), Key::right_alt);
        string_key.emplace(atl::hash("left_shift"), Key::left_shift);
        string_key.emplace(atl::hash("right_shift"), Key::right_shift);
        string_key.emplace(atl::hash("left_control"), Key::left_control);
        string_key.emplace(atl::hash("right_control"), Key::right_control);
        string_key.emplace(atl::hash("numpad_0"), Key::numpad_0);
        string_key.emplace(atl::hash("numpad_1"), Key::numpad_1);
        string_key.emplace(atl::hash("numpad_2"), Key::numpad_2);
        string_key.emplace(atl::hash("numpad_3"), Key::numpad_3);
        string_key.emplace(atl::hash("numpad_4"), Key::numpad_4);
        string_key.emplace(atl::hash("numpad_5"), Key::numpad_5);
        string_key.emplace(atl::hash("numpad_6"), Key::numpad_6);
        string_key.emplace(atl::hash("numpad_7"), Key::numpad_7);
        string_key.emplace(atl::hash("numpad_8"), Key::numpad_8);
        string_key.emplace(atl::hash("numpad_9"), Key::numpad_9);
        string_key.emplace(atl::hash("numpad_add"), Key::numpad_add);
        string_key.emplace(atl::hash("numpad_subtract"), Key::numpad_subtract);
        string_key.emplace(atl::hash("numpad_divide"), Key::numpad_divide);
        string_key.emplace(atl::hash("numpad_multiply"), Key::numpad_multiply);
        string_key.emplace(atl::hash("numpad_decimal"), Key::numpad_decimal);
        string_key.emplace(atl::hash("numpad_enter"), Key::numpad_enter);
        string_key.emplace(atl::hash("numlock"), Key::numlock);
        string_key.emplace(atl::hash("left"), Key::left);
        string_key.emplace(atl::hash("right"), Key::right);
        string_key.emplace(atl::hash("up"), Key::up);
        string_key.emplace(atl::hash("down"), Key::down);
        string_key.emplace(atl::hash("insert"), Key::insert);
        string_key.emplace(atl::hash("home"), Key::home);
        string_key.emplace(atl::hash("page_up"), Key::page_up);
        string_key.emplace(atl::hash("page_down"), Key::page_down);
        string_key.emplace(atl::hash("end"), Key::end);
        string_key.emplace(atl::hash("del"), Key::del);
        string_key.emplace(atl::hash("zero"), Key::zero);
        string_key.emplace(atl::hash("one"), Key::one);
        string_key.emplace(atl::hash("two"), Key::two);
        string_key.emplace(atl::hash("three"), Key::three);
        string_key.emplace(atl::hash("four"), Key::four);
        string_key.emplace(atl::hash("five"), Key::five);
        string_key.emplace(atl::hash("six"), Key::six);
        string_key.emplace(atl::hash("seven"), Key::seven);
        string_key.emplace(atl::hash("eight"), Key::eight);
        string_key.emplace(atl::hash("nine"), Key::nine);
        string_key.emplace(atl::hash("a"), Key::a);
        string_key.emplace(atl::hash("b"), Key::b);
        string_key.emplace(atl::hash("c"), Key::c);
        string_key.emplace(atl::hash("d"), Key::d);
        string_key.emplace(atl::hash("e"), Key::e);
        string_key.emplace(atl::hash("f"), Key::f);
        string_key.emplace(atl::hash("g"), Key::g);
        string_key.emplace(atl::hash("h"), Key::h);
        string_key.emplace(atl::hash("i"), Key::i);
        string_key.emplace(atl::hash("j"), Key::j);
        string_key.emplace(atl::hash("k"), Key::k);
        string_key.emplace(atl::hash("l"), Key::l);
        string_key.emplace(atl::hash("m"), Key::m);
        string_key.emplace(atl::hash("n"), Key::n);
        string_key.emplace(atl::hash("o"), Key::o);
        string_key.emplace(atl::hash("p"), Key::p);
        string_key.emplace(atl::hash("q"), Key::q);
        string_key.emplace(atl::hash("r"), Key::r);
        string_key.emplace(atl::hash("s"), Key::s);
        string_key.emplace(atl::hash("t"), Key::t);
        string_key.emplace(atl::hash("u"), Key::u);
        string_key.emplace(atl::hash("v"), Key::v);
        string_key.emplace(atl::hash("w"), Key::w);
        string_key.emplace(atl::hash("x"), Key::x);
        string_key.emplace(atl::hash("y"), Key::y);
        string_key.emplace(atl::hash("z"), Key::z);
        string_key.emplace(atl::hash("slash"), Key::slash);
        string_key.emplace(atl::hash("comma"), Key::comma);
        string_key.emplace(atl::hash("dot"), Key::dot);
        string_key.emplace(atl::hash("semicolon"), Key::semicolon);
        string_key.emplace(atl::hash("left_bracket"), Key::left_bracket);
        string_key.emplace(atl::hash("right_bracket"), Key::right_bracket);
        string_key.emplace(atl::hash("minus"), Key::minus);
        string_key.emplace(atl::hash("equals"), Key::equals);
        string_key.emplace(atl::hash("apostrophe"), Key::apostrophe);
        string_key.emplace(atl::hash("tick"), Key::tick);
        string_key.emplace(atl::hash("backward_slash"), Key::backward_slash);
        string_key.emplace(atl::hash("f1"), Key::f1);
        string_key.emplace(atl::hash("f2"), Key::f2);
        string_key.emplace(atl::hash("f3"), Key::f3);
        string_key.emplace(atl::hash("f4"), Key::f4);
        string_key.emplace(atl::hash("f5"), Key::f5);
        string_key.emplace(atl::hash("f6"), Key::f6);
        string_key.emplace(atl::hash("f7"), Key::f7);
        string_key.emplace(atl::hash("f8"), Key::f8);
        string_key.emplace(atl::hash("f9"), Key::f9);
        string_key.emplace(atl::hash("f10"), Key::f10);
        string_key.emplace(atl::hash("f11"), Key::f11);
        string_key.emplace(atl::hash("f12"), Key::f12);
        string_key.emplace(atl::hash("pause"), Key::pause);
        string_key.emplace(atl::hash("gamepad_left_stick_x_axis"), Key::gamepad_left_stick_x_axis);
        string_key.emplace(atl::hash("gamepad_left_stick_y_axis"), Key::gamepad_left_stick_y_axis);
        string_key.emplace(atl::hash("gamepad_right_stick_x_axis"), Key::gamepad_right_stick_x_axis);
        string_key.emplace(atl::hash("gamepad_right_stick_y_axis"), Key::gamepad_right_stick_y_axis);
        string_key.emplace(atl::hash("gamepad_left_trigger"), Key::gamepad_left_trigger);
        string_key.emplace(atl::hash("gamepad_right_trigger"), Key::gamepad_right_trigger);
        string_key.emplace(atl::hash("gamepad_button_0"), Key::gamepad_button_0);
        string_key.emplace(atl::hash("gamepad_button_1"), Key::gamepad_button_1);
        string_key.emplace(atl::hash("gamepad_button_2"), Key::gamepad_button_2);
        string_key.emplace(atl::hash("gamepad_button_3"), Key::gamepad_button_3);
        string_key.emplace(atl::hash("gamepad_button_4"), Key::gamepad_button_4);
        string_key.emplace(atl::hash("gamepad_button_5"), Key::gamepad_button_5);
        string_key.emplace(atl::hash("gamepad_button_6"), Key::gamepad_button_6);
        string_key.emplace(atl::hash("gamepad_button_7"), Key::gamepad_button_7);
        string_key.emplace(atl::hash("gamepad_button_8"), Key::gamepad_button_8);
        string_key.emplace(atl::hash("gamepad_button_9"), Key::gamepad_button_9);
        string_key.emplace(atl::hash("gamepad_button_10"), Key::gamepad_button_10);
        string_key.emplace(atl::hash("gamepad_button_11"), Key::gamepad_button_11);
        string_key.emplace(atl::hash("gamepad_button_12"), Key::gamepad_button_12);
        string_key.emplace(atl::hash("gamepad_button_13"), Key::gamepad_button_13);
        string_key.emplace(atl::hash("gamepad_button_14"), Key::gamepad_button_14);
        string_key.emplace(atl::hash("gamepad_button_15"), Key::gamepad_button_15);
        string_key.emplace(atl::hash("gamepad_button_16"), Key::gamepad_button_16);
        string_key.emplace(atl::hash("gamepad_button_17"), Key::gamepad_button_17);
        string_key.emplace(atl::hash("gamepad_button_18"), Key::gamepad_button_18);
        string_key.emplace(atl::hash("gamepad_button_19"), Key::gamepad_button_19);
        return string_key;
    }

    Key key_from_string(atl::String_View const str) {
        static atl::Flat_Hash_Map<u64, Key> string_key = construct_string_key_map();
        u64 const h = atl::hash(str);
        return string_key.find_or_emplace(h)->value;
    }
} // namespace anton_engine
