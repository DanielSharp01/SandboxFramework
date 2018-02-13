#pragma once

#include <functional>
#include <string>
#include <iostream>
#include <unordered_map>

namespace Sandbox::Logging
{
	enum LogLevel
	{
		Error = 0,
		Warning = 1,
		Info = 2
	};

	std::ostream& operator<<(std::ostream& os, const LogLevel& level);

	class Logger
	{
	private:
		bool enabled = true;
		std::function<bool(Logging::LogLevel, const std::string&, const std::string&)> predicate;
		std::function<void(Logging::LogLevel, const std::string&, const std::string&)> action;
	public:
		Logger() = default;
		Logger(std::function<bool(Logging::LogLevel, const std::string&, const std::string&)> predicate,
			std::function<void(Logging::LogLevel, const std::string&, const std::string&)> action);

		void SetEnabled(bool enabled);
		void Log(Logging::LogLevel level, const std::string& tag, const std::string& message) const;
	};

	class LogManager
	{
	private:
		std::unordered_map<std::string, Logger> loggerMap;
	public:
		inline static LogManager& Get()
		{
			static LogManager instance;
			return instance;
		}
		bool Subscribe(const std::string& name,
			std::function<bool(Logging::LogLevel, const std::string&, const std::string&)> predicate,
			std::function<void(Logging::LogLevel, const std::string&, const std::string&)> action);
		bool Enable(const std::string& name);
		bool Disable(const std::string& name);
		bool Unsubscribe(const std::string& name);
		void Log(Logging::LogLevel level, const std::string& tag, const std::string& message) const;
	};
}