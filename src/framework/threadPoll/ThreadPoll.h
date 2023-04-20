/**
 * @file threadPoll.h
 * @brief 线程池
 * @author lemon 
 * @date 2023-04-20
 */

#ifndef __THREADPOLL_H__
#define __THREADPOLL_H__

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>

/**
 * @brief 线程池
 */
class ThreadPoll {
public:
    ThreadPoll(size_t threadNum = 4);
    ~ThreadPoll();

    template<typename F, typename... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

private:
    std::vector<std::thread> m_workers;
    std::queue<std::function<void()>> m_tasks;

    std::mutex m_queueMutex;
    std::condition_variable m_condition;
    bool m_stop;
};

#endif