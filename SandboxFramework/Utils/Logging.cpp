#include "Logging.h"

namespace Sandbox::Logging
{
	std::ostream& operator<<(std::ostream& os, const LogLevel& level)
	{
		switch (level)
		{
		case Error:
			os << "ERROR";
			break;
		case Warning:
			os << "WARNING";
			break;
		case Info:
			os << "INFO";
			break;
		}

		return os;
	}

	Logger::Logger(std::function<bool(Logging::LogLevel, const std::string&, const std::string&)> predicate,
		std::function<void(Logging::LogLevel, const std::string&, const std::string&)> action)
		: predicate(predicate), action(action)
	{ }

	void Logger::SetEnabled(bool enabled)
	{
		Logger::enabled = enabled;
	}
	void Logger::Log(Logging::LogLevel level, const std::string& tag, const std::string& message) const
	{
		if (enabled && predicate(level, tag, message))
			action(level, tag, message);
	}

	bool LogManager::Subscribe(const std::string& name,
		std::function<bool(Logging::LogLevel, const std::string&, const std::string&)> predicate,
		std::function<void(Logging::LogLevel, const std::string&, const std::string&)> action)
	{
		std::unordered_map<std::string, Logger>::iterator it = loggerMap.find(name);
		if (it == loggerMap.end())
		{
			loggerMap[name] = Logger(predicate, action);
			return true;
		}
		else return false;
	}

	bool LogManager::Enable(const std::string& name)
	{
		std::unordered_map<std::string, Logger>::iterator it = loggerMap.find(name);
		if (it != loggerMap.end())
		{
			it->second.SetEnabled(true);
			return true;
		}
		else return false;
	}

	bool LogManager::Disable(const std::string& name)
	{
		std::unordered_map<std::string, Logger>::iterator it = loggerMap.find(name);
		if (it != loggerMap.end())
		{
			it->second.SetEnabled(false);
			return true;
		}
		else return false;
	}

	bool LogManager::Unsubscribe(const std::string& name)
	{
		std::unordered_map<std::string, Logger>::iterator it = loggerMap.find(name);
		if (it != loggerMap.end())
		{
			loggerMap.erase(it);
			return true;
		}
		else return false;
	}

	void LogManager::Log(Logging::LogLevel level, const std::string& tag, const std::string& message) const
	{
		for (std::pair<std::string, Logger> kvp : loggerMap)
		{
			kvp.second.Log(level, tag, message);
		}
	}
}