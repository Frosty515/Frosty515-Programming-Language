#include "Logger.h"
#include <iostream>
#include <sstream>

namespace F515_StandardLogger {

	/* Public methods: */

	Logger::Logger() : m_LoggerLevel(0) {
		
	}
	Logger::~Logger() {

	}

	void Logger::info(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::INFO;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::info(const char* message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::INFO;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::trace(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::TRACE;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::trace(const char* message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::TRACE;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::warn(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::WARN;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::warn(const char* message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::WARN;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::error(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::ERROR;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::error(const char* message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::ERROR;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}

	void Logger::fatal(const std::string& message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::FATAL;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
		m_Log.push_back(out);
		registerMessageForOutput(out);
	}
	void Logger::fatal(const char* message) {
		MessageFormat out;
		out.loggerLevel = (int)LoggerLevels::FATAL;
		out.message = message;
		out.time = m_Time.getCurrentLocalTime();
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
			case 0:
				temp = "INFO: ";
				break;
			case 1:
				temp = "TRACE: ";
				break;
			case 2:
				temp = "WARNING: ";
				break;
			case 3:
				temp = "ERROR: ";
				break;
			case 4:
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
			case 0:
				temp = "INFO: ";
				break;
			case 1:
				temp = "TRACE: ";
				break;
			case 2:
				temp = "WARNING: ";
				break;
			case 3:
				temp = "ERROR: ";
				break;
			case 4:
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
		if (!(m_LoggerLevel >= format.loggerLevel))
			return;

		uint8_t colour;
		std::string temp;

		switch (format.loggerLevel) {
		case 0:
			colour = 37;
			temp = "INFO: ";
			break;
		case 1:
			colour = 93;
			temp = "TRACE: ";
			break;
		case 2:
			colour = 33;
			temp = "WARNING: ";
			break;
		case 3:
			colour = 31;
			temp = "ERROR: ";
			break;
		case 4:
			colour = 91;
			temp = "FATAL ERROR: ";
			break;
		default:
			error("Invalid LoggerLevel");
			return;
		}


		std::cout << "\x1B[" << colour << "m" << '<' << m_Time.formatTimeInAUForm(format.time) << "> " << temp << format.message << "\x1B[0m" << std::endl;

	}

	/* NOTE */
	/* Struct Constructor and Destructor */
	/* Just used so instances can be made */
	MessageFormat::MessageFormat() : loggerLevel(0), message(""), time(0) {

	}
	MessageFormat::~MessageFormat() {

	}
}