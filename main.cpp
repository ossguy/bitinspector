#include <QApplication>
#include "bitprocessor.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	BitProcessor bp;
	bp.show();

	return app.exec();
}
