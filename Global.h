/*
 * Definitions of enumeration types and structures with global range.
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <vector>

class ColorsPalette;
class TaskKeyboardPrototype;

enum Color {
	Red, Brown, Orange, Yellow, Green, Teal, Blue, Purple, Pink
};

enum ChessColor {
	B, W
};

enum KeyState {
	DEFAULT, GOOD, BAD
};

enum WhichKey {
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_0,
	KEY_a,
	KEY_s,
	KEY_z,
	KEY_h,
	KEY_m,

	KEY_q,
	KEY_w,
	KEY_e,
	KEY_r,
};

struct SettingsListGameColorsChessboard {
	int nRounds;
	int time4Remember;
	ColorsPalette *chosenPalette;
};

struct SettingsListGameKeyboardMaster {
	int nRounds;
	std::vector<TaskKeyboardPrototype> chosenTasks;
};

#endif /* GLOBAL_H_ */
