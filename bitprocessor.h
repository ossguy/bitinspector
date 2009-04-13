#ifndef H_BITPROCESSOR
#define H_BITPROCESSOR

#include <QObject>

class BitProcessor : public QObject
{
	Q_OBJECT

public slots:
	void decodeBits();
};

#endif // H_BITPROCESSOR
