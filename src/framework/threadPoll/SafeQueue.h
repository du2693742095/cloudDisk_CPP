/**
 * @file SafeQueue.cpp
 * @brief 线程安全的任务队列
 * @author lemon 
 * @date 2023-04-20
 */

#include <queue>
#include <mutex>
#include <functional>

class SafeQueue {
public:
    SafeQueue() = default;
    ~SafeQueue() = default;

    SafeQueue(const SafeQueue&)=delete;
    SafeQueue& operator =(const SafeQueue&)=delete;

    /**
     * @brief 向队列中添加任务
     * @param task 任务
     */
    void enqueue(std::function<void()> task);

    /**
     * @brief 从队列中取出任务
     * @return 任务
     */
    std::function<void()> dequeue();

    /**
     * @brief 获取队列中任务的数量
     * @return 任务数量
     */
    size_t size();

private:
    std::queue<std::function<void()>> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condition;
};