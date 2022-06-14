#include "Time.h"

#include <ctime>
#include <sstream>

namespace F515_StandardTime {

	Time::Time() {
	}

	Time::~Time() {

	}

	int64_t Time::getCurrentTime() {
		return time(0);
	}

	std::string Time::formatTimeInAUForm(int64_t time) {
		std::stringstream ss;
		tm t = localtime(&time)[0];
		if (t.tm_isdst > 0) {
			return "Error getting time";
			/* NOTE: Daylight savings not supported */
		}
		ss << t.tm_hour << ':' << t.tm_min << ':' << t.tm_sec << ' ' << t.tm_mday << '/';
		int month = t.tm_mon++;
		int year = t.tm_year + 1900;
		ss << month << '/' << year;
		return ss.str();
	}

	std::string Time::formatUTCTimeInAUForm(int64_t time) {
		std::stringstream ss;
		tm t = gmtime(&time)[0];
		if (t.tm_isdst > 0) {
			return "Error getting time";
			/* NOTE: Daylight savings not supported */
		}
		ss << t.tm_hour << ':' << t.tm_min << ':' << t.tm_sec << ' ' << t.tm_mday << '/';
		int month = t.tm_mon++;
		int year = t.tm_year + 1900;
		ss << month << '/' << year;
		return ss.str();
	}

}