#include "logForAll.h"
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>
#include <filesystem>

LogInstance* LogInstance::m_instance = new LogInstance();
log4cplus::Initializer initializer;//必须先初始化

LogInstance::LogInstance()
{
	auto path = std::filesystem::current_path();
	auto logConfigPath = path.string() + "log4cplus.conf";
	if (!std::filesystem::exists(logConfigPath))
	{
		std::cerr << "log config is Not exist in current directory!" << std::endl;
		abort();
	}
	try
	{
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log4cplus.conf"));
	}
	catch (...)
	{
		std::cerr << "log configure occur problem!" << std::endl;
	}
}

LogInstance::~LogInstance()
{
	if (m_instance)
	{
		delete m_instance;
		m_log.shutdown();
	}
}

void LogInstance::Error(const std::string& msg)
{
	LOG4CPLUS_ERROR(m_log, LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void LogInstance::Warn(const std::string& msg)
{
	LOG4CPLUS_WARN(m_log, LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void LogInstance::Info(const std::string& msg)
{
	LOG4CPLUS_INFO(m_log, LOG4CPLUS_STRING_TO_TSTRING(msg));
}

void LogInstance::Debug(const std::string& msg)
{
	LOG4CPLUS_DEBUG(m_log, LOG4CPLUS_STRING_TO_TSTRING(msg));
}


