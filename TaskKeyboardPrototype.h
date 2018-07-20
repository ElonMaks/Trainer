/*
 * Prototype for keyboard task which means vector of key enumeration type
 * WhichKey depending on TaskSet argument.
 *
 * Example: task is declared with argument(TASK_LINGS). Rsult is vector of keys:
 * {KEY_5, KEY_S, KEY_Z, KEY_6, KEY_S, KEY_Z, KEY_7, KEY_S, KEY_Z}
 * todo however it can also contains custom vector of key prototypes.
 */

#ifndef TASKKEYBOARDPROTOTYPE_H_
#define TASKKEYBOARDPROTOTYPE_H_

#include "Global.h"
#include <vector>

enum TaskSet {
	TASK_SC_LINGS, TASK_SC_HYDRAS, TASK_SC_RINES, TASK_1A2A3A, TASK_1A2A3A4A,
};

class TaskKeyboardPrototype {
public:
	TaskKeyboardPrototype();
	TaskKeyboardPrototype(TaskSet set);

	std::vector<WhichKey> & getKeys();

	virtual ~TaskKeyboardPrototype();
protected:
	// All keys to press, ordered
	std::vector<WhichKey> keys;

	friend class TaskKeyboard;
	friend class TaskKeyboardThumbnail;
	friend class TaskKeyboardToSelect;

};

#endif /* TASKKEYBOARDPROTOTYPE_H_ */
