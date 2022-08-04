#include "Logger.h"
#include <iostream>
#include <sstream>

namespace F515_StandardLogger {

	/* Public methods: */

	Logger::Logger() {
		#ifdef F515_DEBUG
			m_LoggerLevel = INFO;
		#else
			#ifdef F515_RELEASE
				m_LoggerLevel = WARN;
			#else
				m_LoggerLevel = INFO;
			#endif
		#endif
	}
	Logger::~Logger() {

	}

	void Logger::info(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = INFO;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::info(const char* message) {
		MessageFormat out;
		out.loggerLevel = INFO;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::trace(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = TRACE;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::trace(const char* message) {
		MessageFormat out;
		out.loggerLevel = TRACE;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::warn(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = WARN;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::warn(const char* message) {
		MessageFormat out;
		out.loggerLevel = WARN;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::error(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = ERROR;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::error(const char* message) {
		MessageFormat out;
		out.loggerLevel = ERROR;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::fatal(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = FATAL;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::fatal(const char* message) {
		MessageFormat out;
		out.loggerLevel = FATAL;
		out.message = message;
		out.time = m_Time.getCurrentTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::setLoggerLevel(const int& level) {
		if (level > -1 && level < 5)
			m_LoggerLevel = level;
		else
			error("Invalid Log Level");
	}

	void Logger::ClearLog() {
		m_Log.clear();
	}

	std::string Logger::GetLog() {
		std::stringstream ss;
		std::vector<MessageFormat> tempLog = m_Log;
		for (MessageFormat m : tempLog) {
			std::string temp;

			switch (m.loggerLevel) {
			case INFO:
				temp = "INFO: ";
				break;
			case TRACE:
				temp = "TRACE: ";
				break;
			case WARN:
				temp = "WARNING: ";
				break;
			case ERROR:
				temp = "ERROR: ";
				break;
			case FATAL:
				temp = "FATAL ERROR: ";
				break;
			default:
				error("Invalid LoggerLevel");
				return "Error Generating Log!";
			}

			ss << '<' << m_Time.formatTimeInAUForm(m.time) << "> " << temp << m.message << '\n';
		}
		return ss.str();
	}
	const char* Logger::GetCLog() {
		std::stringstream ss;
		std::vector<MessageFormat> tempLog = m_Log;
		for (MessageFormat m : tempLog) {
			std::string temp;

			switch (m.loggerLevel) {
			case INFO:
				temp = "INFO: ";
				break;
			case TRACE:
				temp = "TRACE: ";
				break;
			case WARN:
				temp = "WARNING: ";
				break;
			case ERROR:
				temp = "ERROR: ";
				break;
			case FATAL:
				temp = "FATAL ERROR: ";
				break;
			default:
				error("Invalid LoggerLevel");
				return "Error Generating Log!";
			}

			ss << '<' << m_Time.formatTimeInAUForm(m.time) << "> " << temp << m.message << '\n';
		}
		return ss.str().c_str();
	}


	/* Private methods: */

	void Logger::registerMessageForOutput(MessageFormat format) {
		if (!(m_LoggerLevel <= format.loggerLevel))
			return;

		uint8_t colour;
		std::string temp;

		switch (format.loggerLevel) {
		case INFO:
			colour = 37;
			temp = "INFO: ";
			break;
		case TRACE:
			colour = 93;
			temp = "TRACE: ";
			break;
		case WARN:
			colour = 33;
			temp = "WARNING: ";
			break;
		case ERROR:
			colour = 31;
			temp = "ERROR: ";
			break;
		case FATAL:
			colour = 91;
			temp = "FATAL ERROR: ";
			break;
		default:
			error("Invalid LoggerLevel");
			return;
		}

		std::stringstream ss;

		/* << "\x1B[" << colour << 'm' */
		/* << "\x1B[0m" */
		ss << '<' << m_Time.formatTimeInAUForm(format.time) << "> " << temp << format.message;


		std::cout << ss.str() << std::endl;
	}

	/* NOTE: */
	/* Struct Constructor and Destructor */
	/* Just used so instances can be made */

	MessageFormat::MessageFormat() : loggerLevel(0), message(""), time(0) {

	}
	MessageFormat::~MessageFormat() {

	}
}