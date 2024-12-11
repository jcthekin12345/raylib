#ifndef LIBMANAGER_H
#define LIBMANAGER_H

#include <iostream>
#include <string>
#include <vector>

class LibManager {
	std::string_view memberName{};
	std::string_view borrowedBookName{};
	std::vector<std::string> members{};
	const std::string accountNumber{};

	static std::string_view generateAccountNumber() {
		static int counter = 0;
		return "ACC" + std::to_string(++counter);
	}

	static std::string_view memberCount() {
		static int counter = 0;
		return "There are " + std::to_string(++counter) + " members.";
	}
public:
	LibManager(const std::string_view& name, const std::string_view& bookName) 
		: memberName{name}
		, borrowedBookName{bookName}
		, accountNumber{ generateAccountNumber() }
	{
		std::cout << "New library member: " << memberName << std::endl;
		std::cout << memberCount() << std::endl;
	}
};

#endif