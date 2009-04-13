#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget widget;
	QVBoxLayout layout;

	widget.setMinimumWidth(500); // can show most track boxes without scroll

	QTextEdit input(&widget);
	input.setMinimumHeight(205); // usually shows all of the Track 1 data
	QPushButton inspect("&Inspect", &widget);

	layout.addWidget(&input);
	layout.addWidget(&inspect);
	widget.setLayout(&layout);

	widget.show();
	return app.exec();
}
