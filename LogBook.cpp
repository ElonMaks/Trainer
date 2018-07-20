#include "LogBook.h"

LogBook::LogBook() {
	// Create text file for write in app mode
	file.open("records.txt", std::ios::out | std::ios::app);
}

void LogBook::writeRecord(int nrRo, int score, int secondsForReveal) {
	time_t now = time(0);
	char* dt = ctime(&now);
	// Write data, number of current round, score and time given for user for reveal fields
	file << dt << nrRo << '\n' << score << '\n' << secondsForReveal << std::endl;
}

void LogBook::saveToHTML() {
	file.close(); // saveoToHTML have to be called after finishing writing records

	// Open the file again to get each data
	file.open("records.txt", std::ios::in);
	if (file.good()) {
		std::string s;
		while (!file.eof()) {
			getline(file, s);
			line.push_back(s);
		}
	}
	file.close();

	// Covert everything into html and put elements into table
	html.open("records.html", std::ios::out);
	if (html.good()) {
		html<<
		"<!DOCTYPE html>"<<
		"<html>"<<
		"<body>"<<
		"<table style='width:100%'>"<<
		"<tr>"<<
		   "<th>Data</th>"<<
		   "<th>Round n°</th>"<<
		   "<th>Score</th>"<<
		   "<th>Reveal time</th>"<<
		 "</tr>";
		for (unsigned int i = 0; i < line.size(); i++) {
			if (i % 4 == 0)
				html << "<tr>";
			html<<"<td>"<<line[i]<<"</td>";
			if (i % 4 == 3)
				html << "</tr>";
		}
		html<<
		"</table>"<<
		"</body>"<<
		"</html>";
	}
	html.close();
	// TODO After refreshing html course, add css file
}

LogBook::~LogBook() {
}

