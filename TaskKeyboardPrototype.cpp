#include "TaskKeyboardPrototype.h"

TaskKeyboardPrototype::TaskKeyboardPrototype() {}

TaskKeyboardPrototype::TaskKeyboardPrototype(TaskSet set) {
	switch (set) {
	case TASK_SC_LINGS: {
		keys.push_back(KEY_5);
		keys.push_back(KEY_s);
		keys.push_back(KEY_z);
		keys.push_back(KEY_6);
		keys.push_back(KEY_s);
		keys.push_back(KEY_z);
		keys.push_back(KEY_7);
		keys.push_back(KEY_s);
		keys.push_back(KEY_z);
	}
		break;
	case TASK_SC_HYDRAS: {
		keys.push_back(KEY_5);
		keys.push_back(KEY_s);
		keys.push_back(KEY_h);
		keys.push_back(KEY_6);
		keys.push_back(KEY_s);
		keys.push_back(KEY_h);
		keys.push_back(KEY_7);
		keys.push_back(KEY_s);
		keys.push_back(KEY_h);
	}
		break;
	case TASK_SC_RINES: {
		keys.push_back(KEY_5);
		keys.push_back(KEY_m);
		keys.push_back(KEY_6);
		keys.push_back(KEY_m);
		keys.push_back(KEY_7);
		keys.push_back(KEY_m);
	}
		break;
	case TASK_1A2A3A: {
		keys.push_back(KEY_1);
		keys.push_back(KEY_a);
		keys.push_back(KEY_2);
		keys.push_back(KEY_a);
		keys.push_back(KEY_3);
		keys.push_back(KEY_a);
	}
		break;
	case TASK_1A2A3A4A: {
		keys.push_back(KEY_1);
		keys.push_back(KEY_a);
		keys.push_back(KEY_2);
		keys.push_back(KEY_a);
		keys.push_back(KEY_3);
		keys.push_back(KEY_a);
		keys.push_back(KEY_4);
		keys.push_back(KEY_a);
	}
		break;
	}

}

TaskKeyboardPrototype::TaskKeyboardPrototype(std::vector<WhichKey> & keys) {
	this->keys = keys;
}

std::vector<WhichKey> & TaskKeyboardPrototype::getKeys() {
	return keys;
}

TaskKeyboardPrototype::~TaskKeyboardPrototype() {
}

