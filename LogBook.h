/*
 * LogBook for save data about players results.
 */

#ifndef LOGBOOK_H_
#define LOGBOOK_H_

#include <fstream>
#include <ctime>
#include <vector>

class LogBook {
public:
	LogBook();

	void writeRecord(int, int, int);
	void saveToHTML();

	virtual ~LogBook();
private:
	std::fstream file;
	std::fstream html;
	std::vector <std::string> line;
};

#endif /* LOGBOOK_H_ */
