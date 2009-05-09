/*
 * bitprocessor.cpp - bit processing widget for decoding bits
 * This file is part of Bit Inspector.
 *
 * Copyright (C) 2009  Denver Gingerich <denver@ossguy.com>
 *
 * The contents of this file can be redistributed and/or modified under the
 * terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see http://www.gnu.org/licenses/.
 *
 */

#include "bitprocessor.h"
#include "bitconvert.h"
#include <iostream> // TODO: debugging; remove 
#include <QVBoxLayout>
#include <QHBoxLayout>

BitProcessor::BitProcessor(QWidget* parent)
	: QWidget(parent)
{
	input = new QTextEdit;
	inspect = new QPushButton(tr("&Inspect"));
	out_t1 = new QLineEdit;
	out_t2 = new QLineEdit;
	out_t3 = new QLineEdit;
	show_input = new QPushButton(tr("S&how Input"));
	hide_input = new QPushButton(tr("&Hide Input"));
	another = new QPushButton(tr("Inspect &Another"));

	// hide widgets for output mode
	out_t1->hide();
	out_t2->hide();
	out_t3->hide();
	another->hide();
	show_input->hide();
	hide_input->hide();

	// arrange input and output widgets in layout
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(input);
	layout->addWidget(inspect);
	layout->addWidget(out_t1);
	layout->addWidget(out_t2);
	layout->addWidget(out_t3);

	QHBoxLayout* out_buttons = new QHBoxLayout;
	out_buttons->addWidget(show_input);
	out_buttons->addWidget(hide_input);
	out_buttons->addWidget(another);
	layout->addLayout(out_buttons);

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
	connect(inspect, SIGNAL(released()), show_input, SLOT(show()));
	connect(inspect, SIGNAL(released()), another, SLOT(show()));

	// on "Inspect Another", show input widgets and hide output widgets
	connect(another, SIGNAL(released()), input, SLOT(show()));
	connect(another, SIGNAL(released()), inspect, SLOT(show()));
	connect(another, SIGNAL(released()), out_t1, SLOT(hide()));
	connect(another, SIGNAL(released()), out_t2, SLOT(hide()));
	connect(another, SIGNAL(released()), out_t3, SLOT(hide()));
	connect(another, SIGNAL(released()), show_input, SLOT(hide()));
	connect(another, SIGNAL(released()), hide_input, SLOT(hide()));
	connect(another, SIGNAL(released()), another, SLOT(hide()));

	// on "Show Input", show the input textbox and replace with "Hide Input"
	connect(show_input, SIGNAL(released()), input, SLOT(show()));
	connect(show_input, SIGNAL(released()), show_input, SLOT(hide()));
	connect(show_input, SIGNAL(released()), hide_input, SLOT(show()));

	// on "Hide Input", hide the input textbox and replace with "Show Input"
	connect(hide_input, SIGNAL(released()), input, SLOT(hide()));
	connect(hide_input, SIGNAL(released()), hide_input, SLOT(hide()));
	connect(hide_input, SIGNAL(released()), show_input, SLOT(show()));
}

void BitProcessor::decodeBits()
{
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
		// TODO: for debugging; replace with graphical error output
		std::cout << "\tdecode error (" << rv << "): "
			<< bc_strerror(rv) << std::endl;
	} else {
		if (NULL == result.t1) {
			out_t1->clear();
		} else {
			out_t1->setText(QString(result.t1));
		}
		if (NULL == result.t2) {
			out_t2->clear();
		} else {
			out_t2->setText(QString(result.t2));
		}
		if (NULL == result.t3) {
			out_t3->clear();
		} else {
			out_t3->setText(QString(result.t3));
		}
	}

	free(in.t1);
	free(in.t2);
	free(in.t3);

	bc_decoded_free(&result);
}
