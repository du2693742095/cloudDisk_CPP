/*****************************************************************//**
 * \file   NonCopyable.h
 * \brief  不可复制
 * 
 * \author lemon
 * \date   April 2023
 *********************************************************************/

template <typename TYPE>
class NonCopyable
{
public:
    /// Default inline constructor
    NonCopyable() {}

    /// Default inline destructor
    virtual ~NonCopyable() {}

private:
    /// private (non defined) copy constructor to prevent
    /// copying of the object
    NonCopyable(const NonCopyable& Source) = default;

    /// private (non defined) assignment operator to prevent
    /// copy assignment of the object
    const NonCopyable& operator= (const NonCopyable& Source) = delete;

};