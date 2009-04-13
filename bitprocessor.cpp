#include "bitprocessor.h"
#include <iostream> // TODO: debugging; remove 

BitProcessor::BitProcessor(QTextEdit* input)
	: input(input)
{}

void BitProcessor::decodeBits()
{
	std::cout << "in decodeBits" << std::endl; // TODO: debugging; remove
	std::cout << "\tinput: " << input->toPlainText().toStdString()
		<< std::endl; // TODO: debugging; remove
}
