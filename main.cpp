#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget widget;
	QVBoxLayout layout;

	widget.setMinimumWidth(500); // can show most track boxes without scroll

	QTextEdit input(&widget);
	input.setMinimumHeight(205); // usually shows all of the Track 1 data

	layout.addWidget(&input);
	widget.setLayout(&layout);

	widget.show();
	return app.exec();
}
