#ifndef H_BITPROCESSOR
#define H_BITPROCESSOR

#include <QObject>
#include <QTextEdit>

class BitProcessor : public QObject
{
	Q_OBJECT

public:
	BitProcessor(QTextEdit* input);

public slots:
	void decodeBits();

private:
	QTextEdit* input;
};

#endif // H_BITPROCESSOR
