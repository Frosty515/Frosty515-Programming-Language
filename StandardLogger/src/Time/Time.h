#pragma once

#include <stdint.h>
#include <string>

#include "../Core.h"

/* NOTE: Daylight savings not supported */

namespace F515_StandardTime {

	class FROSTY515_API Time {
	public:
		Time();
		~Time();

		int64_t getCurrentTime();

		std::string formatTimeInAUForm(int64_t time);
		std::string formatUTCTimeInAUForm(int64_t time);
	};

}