#ifndef _LOGGER_H
#define _LOGGER_H

#include <string>
#include <vector>
#include "../Core.h"
#include "../Time/Time.h"

#define INFO  0x4c6f6700
#define TRACE 0x4c6f6701
#define WARN  0x4c6f6702
#define ERROR 0x4c6f6703
#define FATAL 0x4c6f6704

namespace F515_StandardLogger {

	struct FROSTY515_API MessageFormat {
	public:
		MessageFormat();
		~MessageFormat();

		std::string message;
		int loggerLevel;
		int64_t time;
	};

	class FROSTY515_API Logger {
	public:
		Logger();
		~Logger();

		void info(const std::string& message);
		void info(const char* message);

		void trace(const std::string& message);
		void trace(const char* message);

		void warn(const std::string& message);
		void warn(const char* message);

		void error(const std::string& message);
		void error(const char* message);

		void fatal(const std::string& message);
		void fatal(const char* message);

		void setLoggerLevel(const int& level);

		void ClearLog();

		std::string GetLog();
		const char* GetCLog();

	private:
		int m_LoggerLevel;
		std::vector<MessageFormat> m_Log;
		F515_StandardTime::Time m_Time;

	private:
		void registerMessageForOutput(MessageFormat format);
	};
}

#endif /* _LOGGER_H */