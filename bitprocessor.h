#ifndef H_BITPROCESSOR
#define H_BITPROCESSOR

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class BitProcessor : public QWidget
{
	Q_OBJECT

public:
	BitProcessor(QWidget* parent = 0);

public slots:
	void decodeBits();

private:
	QTextEdit* input;
	QPushButton* inspect;
};

#endif // H_BITPROCESSOR
