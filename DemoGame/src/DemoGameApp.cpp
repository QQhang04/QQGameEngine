#include <QQhang.h>

class GameDemo : public QQhang::Application {
public:
	GameDemo() {

	}

	~GameDemo() {

	}

	void Run() {

	}
};

QQhang::Application* QQhang::CreateApplication() {
	return new GameDemo();
}