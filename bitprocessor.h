#ifndef H_BITPROCESSOR
#define H_BITPROCESSOR

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

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
	QLineEdit* out_t1;
	QLineEdit* out_t2;
	QLineEdit* out_t3;
	QPushButton* another;
};

#endif // H_BITPROCESSOR
