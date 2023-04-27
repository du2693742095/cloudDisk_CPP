/**
 * @file LogForAll.h
 * @brief 日志
 * @author lemon
 * @date 2023-04-20
 */

#ifndef __LOGFORALL_H__
#define __LOGFORALL_H__

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"


// @todo: 之后可以单独开个线程做日志
class LogInstance
{
public:
	enum type{ EMERG = 0, FATAL, ALERT, ERROR, WARN, NOTICE, INFO, DEBUG };

	static LogInstance* GetInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new LogInstance();
		}
		return m_instance;
	}

	void SetLowestPriority(type& level);

	void Emerg(const std::string& msg);
	void Fatal(const std::string& msg);
	void Alert(const std::string& msg);
	void Warn(const std::string& msg);
	void Notice(const std::string& msg);
	void Info(const std::string& msg);
	void Debug(const std::string& msg);
	void Notice(const std::string& msg);


private:
	LogInstance() = default;
	~LogInstance() = default;
	LogInstance(const LogInstance&) = delete;
	LogInstance& operator = (const LogInstance&) = delete;

	void Init();
	void destory();

private:
	static LogInstance* m_instance;
	log4cpp::Category* m_root;
};



#endif // !__LOGFORALL_H__
