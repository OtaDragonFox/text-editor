#pragma once
#include <cstdint>


// https://en.cppreference.com/w/cpp/types/integer


typedef int8_t f_i8;
typedef uint8_t f_ui8;

enum element_type {
	ELEMENT,
	CONTAINER
};



// comes to 128 bytes
// each specific types willbe handeled differently
// by the message interpreter AE the UI_face on
//event function

struct ui_event_data {
	union {
		char c[16];
		f_i8 f_i8[16];
	} data;
};



struct vec2 {
	float x;
	float y;

	vec2(float in_x = 0, float in_y = 0) {
		x = in_x;
		y = in_y;
	}
};



struct ui_padding {
	float top, left, right, bottom;
};

struct ui_corners {
	vec2 t_left, t_right, b_left, b_right;

	ui_corners(
		vec2 in_t_left, vec2 in_t_right,
		vec2 in_b_left, vec2 in_b_right) {
		t_left = in_t_left;
		t_right = in_t_right;
		b_left = in_b_left;
		b_right = in_b_right;
	}

	ui_corners(
		) {
		t_left = {};
		t_right = {};
		b_left = {};
		b_right = {};
	}
};
