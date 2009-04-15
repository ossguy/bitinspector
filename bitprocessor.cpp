#include "bitprocessor.h"
#include "bitconvert.h"
#include <iostream> // TODO: debugging; remove 
#include <QVBoxLayout>

BitProcessor::BitProcessor(QWidget* parent)
	: QWidget(parent)
{
	input = new QTextEdit;
	inspect = new QPushButton(tr("&Inspect"));
	out_t1 = new QLineEdit;
	out_t2 = new QLineEdit;
	out_t3 = new QLineEdit;
	another = new QPushButton(tr("Inspect &Another"));

	// hide widgets for output mode
	out_t1->hide();
	out_t2->hide();
	out_t3->hide();
	another->hide();

	// arrange input and output widgets in layout
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(input);
	layout->addWidget(inspect);
	layout->addWidget(out_t1);
	layout->addWidget(out_t2);
	layout->addWidget(out_t3);
	layout->addWidget(another);
	setLayout(layout);

	setWindowTitle(tr("Bit Inspector"));

	// on "Inspect", decode the bits in the input box
	connect(inspect, SIGNAL(released()), this, SLOT(decodeBits()));

	// on "Inspect", hide input widgets and show output widgets
	connect(inspect, SIGNAL(released()), input, SLOT(hide()));
	connect(inspect, SIGNAL(released()), inspect, SLOT(hide()));
	connect(inspect, SIGNAL(released()), out_t1, SLOT(show()));
	connect(inspect, SIGNAL(released()), out_t2, SLOT(show()));
	connect(inspect, SIGNAL(released()), out_t3, SLOT(show()));
	connect(inspect, SIGNAL(released()), another, SLOT(show()));

	// on "Inspect Another", show input widgets and hide output widgets
	connect(another, SIGNAL(released()), input, SLOT(show()));
	connect(another, SIGNAL(released()), inspect, SLOT(show()));
	connect(another, SIGNAL(released()), out_t1, SLOT(hide()));
	connect(another, SIGNAL(released()), out_t2, SLOT(hide()));
	connect(another, SIGNAL(released()), out_t3, SLOT(hide()));
	connect(another, SIGNAL(released()), another, SLOT(hide()));
}

void BitProcessor::decodeBits()
{
	std::cout << "in decodeBits" << std::endl; // TODO: debugging; remove
	std::cout << "\tinput: " << input->toPlainText().toStdString()
		<< std::endl; // TODO: debugging; remove

	struct bc_input in;
	struct bc_decoded result;

	QStringList tracks = input->toPlainText().split('\n');

	if (tracks.isEmpty()) {
		in.t1 = NULL;
	} else {
		std::string t1 = tracks.takeFirst().toStdString();
		in.t1 = (char*)malloc(t1.length() + 1);
		strcpy(in.t1, t1.c_str());
	}

	if (tracks.isEmpty()) {
		in.t2 = NULL;
	} else {
		std::string t2 = tracks.takeFirst().toStdString();
		in.t2 = (char*)malloc(t2.length() + 1);
		strcpy(in.t2, t2.c_str());
	}

	if (tracks.isEmpty()) {
		in.t3 = NULL;
	} else {
		std::string t3 = tracks.takeFirst().toStdString();
		in.t3 = (char*)malloc(t3.length() + 1);
		strcpy(in.t3, t3.c_str());
	}

	int rv = bc_decode(&in, &result);
	if (rv) {
		std::cout << "\tdecode error (" << rv << "): "
			<< bc_strerror(rv) << std::endl;
	} else {
		if (NULL == result.t1) {
			std::cout << "\ttrack 1 has no data" << std::endl;
		} else {
			std::cout << "\ttrack 1: " << result.t1 << std::endl;
		}
		if (NULL == result.t2) {
			std::cout << "\ttrack 2 has no data" << std::endl;
		} else {
			std::cout << "\ttrack 2: " << result.t2 << std::endl;
		}
		if (NULL == result.t3) {
			std::cout << "\ttrack 3 has no data" << std::endl;
		} else {
			std::cout << "\ttrack 3: " << result.t3 << std::endl;
		}
	}

	free(in.t1);
	free(in.t2);
	free(in.t3);

	bc_decoded_free(&result);
}
