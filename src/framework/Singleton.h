/**
 * @file Singleton.h
 * @brief 单例类模板
 * @author lemon 
 * @date 2023-04-20
 */

/**
 * @brief Singleton class template
 * @tparam T The type of the class to be a singleton
 */
template<typename T>
class Singleton{
public:
    static T& get_instance(){
        static T instance;
        return instance;
    }

    virtual ~Singleton() = default;

    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;

protected:
    Singleton(){}

};