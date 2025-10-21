module;

#include <QCoreApplication>
#include <QThread>

export module qt;

class QtThread : public QThread
{
public:
    QCoreApplication* app = nullptr;
    std::function<void(QCoreApplication*)> onStarted;

    void run() override
    {
        int argc = 0;
        char** argv = nullptr;
        QCoreApplication localApp(argc, argv);
        app = &localApp;

        if(onStarted) onStarted(app);

        localApp.exec();
    }
};

export inline QtThread qt;

export inline int qtInitializer = []() ->int
{
    qt.start();
    return 0;
}();

export void qtAdd(std::function<void()> f)
{
    QMetaObject::invokeMethod(qt.app, f, Qt::QueuedConnection);
}