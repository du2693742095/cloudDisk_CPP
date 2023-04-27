#include "LogInstance.h"

LogInstance::LogInstance()
{
	Init();
}

~LogInstance::LogInstance()
{

}

void LogInstance::SetLowestPriority(type& level);

void LogInstance::Emerg(const std::string& msg)
{

}

void LogInstance::Fatal(const std::string& msg)
{


}

void LogInstance::Alert(const std::string& msg)
{

}

void LogInstance::Warn(const std::string& msg)
{

}

void LogInstance::Notice(const std::string& msg)
{

}

void LogInstance::Info(const std::string& msg)
{

}

void LogInstance::Debug(const std::string& msg)
{

}

void LogInstance::Notice(const std::string& msg)
{

}



void LogInstance::Init()
{
	m_logInstance = new LogInstance();
	m_logInstance->setLayout(new log4cpp::BasicLayout());
	
}

void LogInstance::destory();
