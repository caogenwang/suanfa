#include <pthread.h>
class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex,nullptr);
    }
    ~singleton(){
        if (p != nullptr)
        {
            delete p;
        }
    }
private:
    static singleton* p;
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
};
 
pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;
singleton* singleton::initance()
{
    if (p == NULL)
    {
        pthread_mutex_lock(&mutex);
        if (p == NULL)
            p = new singleton();
        pthread_mutex_unlock(&mutex);
    }
    return p;
}