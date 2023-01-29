#pragma once
#include <iostream>
class Logger {
public:
	enum LEVEL {INFO, ERROR, WARNING };
	static void LOG(std::string message,LEVEL level) {
		switch (level) {
		case INFO: 
			message = "INFO - "+message;
			break;
		case ERROR: 
			message = "ERROR -" + message;
			break;
		case WARNING: 
			message = "WARNING - " + message;
			break;
		}
		
		std::cout << message << std::endl;
	}
};