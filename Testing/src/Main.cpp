#include <StandardLogger.h>

int main(int argc, char** argv) {
	F515_StandardLogger::Logger logger;
	/* NOTE -- FIX GET TIME -- remove '\n' after time*/

	logger.setLoggerLevel((int)F515_StandardLogger::LoggerLevels::INFO);
	logger.info("Logger Successfully Started!");

	return 0;
}