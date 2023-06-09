/**
 * @file LogForAll.h
 * @brief log文件
 * @author lemon
 * @date 2023-04-20
 */

#ifndef __LOGFORALL_H__
#define __LOGFORALL_H__

#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/log4cplus.h>
#include "LogGlobal.h"


class LOGAPI LogInstance
{
public:
	enum type{ ERROR = 0, WARN, INFO, DEBUG };

	static LogInstance* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new LogInstance();
		}
		return m_instance;
	}

	void Error(const std::string& msg);

	void Warn(const std::string& msg);

	void Info(const std::string& msg);

	void Debug(const std::string& msg);

private:
	LogInstance();
	~LogInstance();
	LogInstance(const LogInstance&) = delete;
	LogInstance& operator = (const LogInstance&) = delete;

private:
	static LogInstance* m_instance;
	log4cplus::Logger m_log;
};

#define postfix(msg)  (std::string(msg).append(" [ ")\
	.append(__FILE__).append(":").append(__func__)\
	.append(":").append(std::to_string(__LINE__)).append(" ] "))

#define LOGAPI LOG_ERROR(msg) Mylog::myLogger->error(postfix(msg))
#define LOGAPI LOG_WARN(msg)  Mylog::myLogger->warn(postfix(msg))
#define LOGAPI LOG_INFO(msg)  Mylog::myLogger->info(postfix(msg))
#define LOGAPI LOG_DEBUG(msg) Mylog::myLogger->debug(postfix(msg))

#endif // !__LOGFORALL_H__
