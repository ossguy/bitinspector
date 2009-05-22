/*
 * bitprocessor.h - bit processing widget declarations
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

#ifndef H_BITPROCESSOR
#define H_BITPROCESSOR

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QTableWidget>

class BitProcessor : public QWidget
{
	Q_OBJECT

public:
	BitProcessor(QWidget* parent = 0);

public slots:
	void decodeBits();

private:
	QLabel* instructions;
	QLabel* example_bits;
	QTextEdit* input;
	QPushButton* inspect;
	QLabel* status;
	QLabel* label_input;
	QLabel* label_t1;
	QLabel* label_t2;
	QLabel* label_t3;
	QLabel* out_t1;
	QLabel* out_t2;
	QLabel* out_t3;
	QTableWidget* fields;
	QPushButton* show_input;
	QPushButton* hide_input;
	QPushButton* another;
};

#endif // H_BITPROCESSOR
